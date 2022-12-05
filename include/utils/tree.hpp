#ifndef TREE_HPP
# define TREE_HPP

# include <memory>
# include <functional>
# include <algorithm>
# include "./pair.hpp"
# include "../iterators/tree_iterator.hpp"
# include "../utils/sfinae.hpp"

namespace ft
{

template<class Key, class Type, class Compare = std::less<Type>, class Allocator = std::allocator<tree_node<Type> > >
class tree
{
	public:
		// typedef Key																key_type;
		// typedef Type															value_type;
		// typedef Compare															value_compare;
		// typedef	std::less<Key>													key_compare;
		// typedef Allocator														allocator_type;
		// typedef typename Allocator::template rebind<tree_node<Type> >::other	node_allocator;
		// typedef std::size_t											size_type;
		// typedef tree_iterator<value_type>							iterator;
		// // typedef const_tree_iterator<const value_type> 					const_iterator;
		// typedef const_tree_iterator<value_type> 					const_iterator;
		// typedef tree_node<value_type>*								node_pointer;

		typedef Key																key_type;
		typedef Type															value_type;
		typedef Compare															value_compare;
		typedef	std::less<Key>													key_compare;
		typedef Allocator														allocator_type;
		typedef typename Allocator::template rebind<tree_node<Type> >::other	node_allocator;
		typedef std::size_t											size_type;
		typedef typename std::ptrdiff_t								difference_type;
		typedef tree_iterator<value_type>	iterator;
		typedef tree_iterator<const value_type> const_iterator;
		// typedef tree_iterator<value_type>							iterator;
		// typedef const_tree_iterator<const value_type> 					const_iterator;
		// typedef const_tree_iterator<value_type> 					const_iterator;
		typedef tree_node<value_type>*								node_pointer;

	private:
		node_pointer			_root;
		node_pointer			_begin;
		node_pointer			_end;
		size_type					_size;
		value_compare			_value_compare;
		allocator_type			_allocator;

	public:
		tree() : _root(NULL), _begin(NULL), _end(NULL), _size(0) {}
		tree(const value_compare &comp, const allocator_type &a) : _root(NULL), _begin(NULL), _end(NULL), _size(0) 
		{ 
			_value_compare = comp; 
			_allocator = a;
		}
	
		template<class InputIterator>
		tree (InputIterator first, InputIterator last, const Compare &comp, const Allocator &alloc)
		{
			_allocator = alloc;
			_value_compare = comp;
			insert(first, last);
		}

		tree(const tree &other )
		{
			*this = other;
			return (*this);
		}

		~tree() 
		{
			clear_all_elements();
		}

		tree &operator=(const tree &other)
		{
			_root = other.get_root();
			_begin = other.get_begin();
			_end = other.get_end();
			_size = other.get_size();
			_allocator = other.get_allocator();
			_value_compare = other.get_value_compare();
		
			return (*this);
		}

// getters
		node_pointer get_root() const
		{ return (_root); }

		node_pointer get_begin() const
		{ return (_begin); }

		node_pointer get_end() const
		{ return (_end); }

		size_type get_size() const
		{ return (_size); }

		value_compare get_value_compare() const
		{ return (_value_compare); }

		allocator_type get_allocator() const 
		{ return (_allocator); }

// rotate & check balance
		node_pointer	right_rotate(node_pointer node)
		{ //eg. node == 1; no
			node_pointer temp = node->_left;
			node->_left = temp->_right;
			if (temp->_right)
			{
				// node->_left = temp->_right;
				temp->_right->_parent = node;
			}
			if (node->_parent == NULL)
			{
				temp->_parent = NULL;
				_root = temp;
			}
			else
			{
				node->_parent->_left = temp;
				temp->_parent = node->_parent;
			}
			temp->_right = node;
			node->_parent = temp;
			
			return (temp);
		}

		node_pointer	left_rotate(node_pointer node)
		{ 	// eg: node == c; node->right == d;
			node_pointer temp = node->_right;
			node->_right = temp->_left;
			if (temp->_left)
			{
				// node->_right = temp->_left;
				temp->_left->_parent = node;
			}
			if (node->_parent == NULL)
			{
				temp->_parent = NULL;
				_root = temp;
			}
			else
			{
				node->_parent->_right = temp;
				temp->_parent = node->_parent;
			}
			temp->_left = node;
			node->_parent = temp;

			return (temp);
		}

		// node_pointer	left_right_rotate(node_pointer node)
		// {
		// 	node->_left = left_rotate(node->_left);
		// 	return (right_rotate(node));
		// }

		// node_pointer	right_left_rotate(node_pointer node)
		// {
		// 	node->_right = right_rotate(node->_right);
		// 	return (left_rotate(node));
		// }

		node_pointer	left_right_rotate(node_pointer node)
		{
			node->_right = left_rotate(node->_left);
			return (right_rotate(node));
		}

		node_pointer	right_left_rotate(node_pointer node)
		{
			node->_left = right_rotate(node->_right);
			return (left_rotate(node));
		}

		int	get_height(node_pointer node)
		{
			if (node == NULL)
				return (-1);
			else if (node->_left == NULL && node->_right == NULL)
				return (0);
			return (std::max(get_height(node->_left), get_height(node->_right)) + 1);
		}

		int	get_balance_factor(node_pointer node)
		{
			if (node == NULL)
				return (-1);
			else if (node->_left == NULL && node->_right == NULL)
				return (0);
			return (get_height(node->_left) - get_height(node->_right));
		}

		bool	is_balanced(node_pointer node)
		{ return (std::abs(get_balance_factor(node)) < 2); }

		void fix_balance(node_pointer node)
		{
			if (node == NULL)
				return ;
 			if (!is_balanced(node))
			{
				if (get_balance_factor(node) > 0) // left-heavy
				{
					if (get_balance_factor(node->_left) > 0)
					{
						std::cout << node->_value.first << " :right rotate" << std::endl;
						right_rotate(node);
					}
					else// if (get_balance_factor(node->_left) < 0)
					{
						// std::cout << node->_value.first << ": left-right" << std::endl;
						// left_right_rotate(node);
						std::cout << node->_value.first << ": right left" << std::endl;
						right_left_rotate(node);
					}
				}
				else// if (get_balance_factor(node) < 0) // right-heavy
				{
					if (get_balance_factor(node->_right) < 0 )
					{
						std::cout << node->_value.first << ": left rotate" << std::endl;
						left_rotate(node);
					}
					else// if (get_balance_factor(node->_right) > 0 )
					{
						// std::cout << node->_value.first << ": right left" << std::endl;
						// right_left_rotate(node);
						std::cout << node->_value.first << ": left-right" << std::endl;
						left_right_rotate(node);
					}
				}
			}
			return (fix_balance(node->_parent));
		}


		size_t	size() const
		{ return (_size); }

		bool empty() const { return (!_size); }

		iterator begin() 
		{ return (iterator(_root, _begin)); }

		const_iterator begin() const 
		{ return (const_iterator(_root, _begin)); }

		iterator end() 
		{
			if (_end == NULL)
				return (begin());
			return (iterator(_root, NULL)); 
		}
		
		const_iterator end() const 
		{ 
			if (_end == NULL)
				return (begin());
			return (const_iterator(_root, NULL)); 
		}

		iterator root() 
		{ return (iterator(_root)); }
		
		const_iterator root() const 
		{ return (const_iterator(_root)); }

		size_type max_size();

		void clear()
		{
			_allocator.destroy(_root);
			_size = 0;
			_begin = _end;
			_end->_left = NULL;
		}

		void clear_all_elements()
		{
			for (node_pointer ptr = _begin; ptr != _end; ptr++)
				_allocator.destroy(ptr);
			_size = 0;
		}

		void swap(tree	&other)
		{
			node_pointer	temp_root = _root;
			node_pointer	temp_begin = _begin;
			node_pointer	temp_end = _end;
			size_t			temp_size = _size;
			value_compare	temp_value_compare = _value_compare;
			allocator_type	temp_allocator = _allocator;

			_root = other._root;
			_begin = other._begin;
			_end = other._end;
			_size = other._size;
			_value_compare = other._value_compare;
			_allocator = other._allocator;

			other._root = temp_root;
			other._begin = temp_begin;
			other._end = temp_end;
			other._size = temp_size;
			other._value_compare = temp_value_compare;
			other._allocator = temp_allocator;

		}

		bool is_left_child(node_pointer x) const
		{ 
			if (x->_parent)
				return (x == x->_parent->_left); 
			else
				return (false);
		}

		bool is_right_child(node_pointer x) const
		{ return (x == x->_parent->_right); }

		void set_parent(node_pointer x, node_pointer p)
		{ x->_parent = p; }

		void	tree_left_rotate(node_pointer x) const
		{
			node_pointer y = x->_right;

			x->_right = y->_left;
			if (x->_right != NULL)
				x->_right -> set_parent(x);
			y->parent = x->_parent;
			if (x->_is_left_child)
				x->_parent->_left = y;
			else
				x->_parent->_right = y;
				y->_left = x;
				x->set_parent(y);
		}

		node_pointer find_insert_position(const value_type &value)
		{
			node_pointer parent_node = NULL;
			node_pointer current_node = _root;
			while (current_node != NULL)
			{
				parent_node = current_node;
				if (_value_compare(value, current_node->_value)) {
					if (current_node->_left == NULL)
						return (current_node);
					else // current_node->_left != NULL
						current_node = current_node->_left;
				}
				else if (_value_compare(current_node->_value, value)) {
					if (current_node->_right == NULL)
						return (current_node);
					else
						current_node = current_node->_right;
				}
				else // if value == current_node value
					return (current_node);
			}
			return (parent_node);
		}

// どのノードの下に入るか、Insert positionはNew Nodeの親； 関数呼び出すときに親となるノードを引数としてパスする
		ft::pair<iterator, bool> insert_node(const value_type &value, node_pointer insert_pos)
		{
			node_pointer new_node;
			new_node = _allocator.allocate(1);
			_allocator.construct(new_node, value);
			new_node->_parent = insert_pos;
			if (insert_pos == NULL)
			{
				_root = new_node;
				_begin = new_node;
				_end = new_node;
			}
			else if (_value_compare(new_node->_value, insert_pos->_value))
				insert_pos->_left = new_node;
			else if (_value_compare(insert_pos->_value, new_node->_value))
				insert_pos->_right = new_node;
			else
			{
				_allocator.destroy(new_node);
				_allocator.deallocate(new_node, 1);
				return (ft::make_pair(iterator(_root, insert_pos), false));
			}
			// fix_balance(new_node);
			if (_value_compare(new_node->_value, _begin->_value))
				_begin = new_node;
			if (_value_compare(_end->_value, new_node->_value))
				_end = new_node;
			_size++;
			return (ft::make_pair(iterator(_root, new_node), true));
		}

		void	update_begin(node_pointer inserted_node)
		{
			if (_begin == _end || _value_compare(inserted_node->_value, _begin->_value))
				_begin = inserted_node;
		}

		ft::pair<iterator, bool> insert(const value_type &value)
		{
			node_pointer new_node;
			new_node = find_insert_position(value);
			return (insert_node(value, new_node));
		}


// new_node にInsert placeのポインター代入。NULLでなければ重複あり、Nullであれば重複なし
			// if key doesnt exist, create a new node
			// if there is no root node, set new node as the root;
			// else, search for the place to insert new_node;

// 本家__tree より __find_equal（挿入のポジション探すFunction)、ヒントありとなし（通常）バージョンがある。 この場合ヒントありを参考に作成
// _rootから探す代わりにPositionから探す
// Inserts value in the position as close as possible to the position just prior to pos

		// iterator insert(iterator position, const value_type &value)
		// {
		// 	node_pointer new_node;
		// 	if (_value_compare(value, *position)) //value < position
		// 	{
		// 		if (position == begin())
		// 			new_node = find_insert_position(value, _begin);
		// 		else 
		// 		{
		// 			iterator temp = position;
		// 			--temp;
		// 			if (_value_compare(*temp, value))
		// 			{
		// 				if (temp.base()->_right == NULL)
		// 					new_node = find_insert_position
		// 				else
		// 					new_node = 
		// 			}

        //         // if (compare_(*prev, value))
        //         // {
        //         //     if (prev.base()->right == nil_)
        //         //         return insert_node(value, prev.base()).first;
        //         //     else
        //         //         return insert_node(value, position.base()).first;
        //         // }
		// 		// 	new_node = find_insert_position(value);
		// 		// }
		// 	}
		// 	else if (_value_compare(*position, value))
		// 	{
		// 		new_node = find_insert_position(value, _root);
		// 	}
		// 	return (insert_node(value, new_node).first);
		// }

		template<class InputIterator>
		void	insert(InputIterator first, InputIterator last, 
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL);

// erase

		void		erase (iterator position)
		{ // usage eg. iter = find(value); -> erase(iter);
			if (position == end())
				return ;
			_allocator.destroy(position.base());
			_allocator.deallocate(position.base(), 1);

			fix_balance();//
			
		}

		size_type	erase (const value_type &value);

		void		erase(iterator first, iterator last);

// look up

		size_type	count(const value_type &value) const
		{
			const_iterator it = find(value);
			if (it == end())
				return (0);
			return (1);
		}

		iterator find(const value_type &value)
		{
			iterator it = lower_bound(value);
			if (it != end() && !_value_compare(value, *it) && !_value_compare(*it, value))
				return (it);
			return (end());
		}

		const_iterator find(const value_type &value) const
		{
			const_iterator it = lower_bound(value);
			if (it != end() && !_value_compare(value, *it) && !_value_compare(*it, value))
				return (it);
			return (end());			
		}
//与えられた値より小さくない最初の要素へのイテレータを取得する == イコールも含む
		iterator lower_bound(const value_type &value)
		{
			iterator it;
			node_pointer temp = _root;
			while (temp != NULL)
			{
				if (!_value_compare(temp->_value, value))
				{
					it = iterator(_root, temp);
					temp = temp->_left;
				}
				else
					temp = temp->_right;
			}
			return (it);
		}
	
		const_iterator lower_bound(const value_type &value) const
		{
			const_iterator it;
			node_pointer temp = _root;
			while (temp != NULL)
			{
				if (!_value_compare(temp->_value, value))
				{
					it = const_iterator(_root, temp);
					temp = temp->_left;
				}
				else
					temp = temp->_right;
			}
			return (it);
		}

//特定の値よりも大きい最初の要素へのイテレータを取得する
		iterator upper_bound( const value_type &value )
		{
			iterator it;
			node_pointer temp = _root;
			while (temp != NULL)
			{
				if (_value_compare(value, temp->_value))
				{
					it = iterator(_root, temp);
					temp = temp->_left;
				}
				else
					temp = temp->_right;
			}
			return (it);
		}

		const_iterator upper_bound( const value_type &value ) const
		{
			const_iterator it;
			node_pointer temp = _root;
			while (temp != NULL)
			{
				if (_value_compare(value, temp->_value))
				{
					it = iterator(_root, temp);
					temp = temp->_left;
				}
				else
					temp = temp->_right;
			}
			return (it);
		}

		ft::pair<iterator, iterator> equal_range(const value_type &value)
		{ return (make_pair(find(value), upper_bound(value))); }

		ft::pair<const_iterator, const_iterator> equal_range( const value_type &value ) const
		{ return (make_pair(find(value), upper_bound(value))); }

		void printAVL(const std::string& prefix, const node_pointer node, bool isLeft)
		{
			if(node != NULL)
			{
				std::cout << prefix;
				std::cout << (isLeft ? "└──L:" : "└──R:" );
				// print the value of the node
				std::cout << "[" << node->_value.first << " -- ";
				std::cout << node->_value.second << "] : [h " << get_height(node) << " b " << get_balance_factor(node) 
								<< " " << std::boolalpha << is_balanced(node) << " ] "<< std::endl;
				// enter the next tree level - left and right branch
				printAVL( prefix + (isLeft ? "│   " : "    "), node->_left, true);
				printAVL( prefix + (isLeft ? "│   " : "    "), node->_right, false);
			}
		}

		node_pointer get_root()
		{ return (_root); }

};

}

#endif