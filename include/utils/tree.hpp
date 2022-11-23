#ifndef TREE_HPP
# define TREE_HPP

# include <memory>
# include <functional>
# include "./pair.hpp"
# include "../iterators/tree_iterator.hpp"

namespace ft
{

template<class Key, class Type, class Compare = std::less<Type>, class Allocator = std::allocator<tree_node<Type> > >
class tree
{
	public:
		typedef Key													key_type;
		typedef Type												value_type;
		typedef Compare												value_compare;
		typedef	std::less<Key>										key_compare;
		typedef Allocator											allocator_type;
		typedef typename Allocator::template rebind<tree_node<Type> >::other node_allocator;
		typedef std::size_t											size_type;
		typedef tree_iterator<value_type>							iterator;
		typedef const_tree_iterator<value_type> 					const_iterator;
		typedef tree_node<value_type>*								node_pointer;

	private:
		node_pointer			_root;
		node_pointer			_begin;
		node_pointer			_end;
		size_t					_size;
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
			_root = other._root;
			_begin = other._begin;
			_end = other._end;
			_allocator = other._allocator;
			_value_compare = other._value_compare;
		
			return (*this);
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

		void swap();

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

		bool	has_duplicate_value(const value_type &value, iterator &it)
		{
			for (it = begin(); it != end(); it++)
				if (!_value_compare(*it, value) && !_value_compare(value, *it))
					return (true);
			return (false);
		}

		// node_pointer find_insert_place(node_pointer root, const value_type &value)
		// {
		// 	while (true) {
		// 		if (value_compare() (value.first, root->_value.first)) {
		// 			if (root->_left != NULL)
		// 				root = root->_left;
		// 			else
		// 				return (root->_left);
		// 		}
		// 		else if (value_compare() (root->_value, value)) {
		// 			if (root->_right != NULL)
		// 				root = root->_right;
		// 			else
		// 				return (root->_right);
		// 		}
		// 		else {
		// 			return (root);
		// 		}
		// 	}
		// }

		node_pointer find_insert_position(const value_type &value)
		{
			node_pointer parent_node = NULL;
			node_pointer current_node = _root;
			while (current_node != NULL)
			{
				parent_node = current_node;
				// std::cout << "parent_node: " << parent_node << "| current_node: " << current_node << std::endl;
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

		ft::pair<iterator, bool> insert_node(const value_type &value, node_pointer insert_pos)
		{
			// std::cout << "insert_pos: " << insert_pos << std::endl; 
			node_pointer new_node;
			new_node = _allocator.allocate(1);
			_allocator.construct(new_node, value);
			new_node->_parent = insert_pos;
			// std::cout << "new_node: " << new_node << "| parent: " << new_node->_parent << " | insert_pos: " << insert_pos << std::endl;
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
			else //duplicate
			{
				_allocator.destroy(new_node);
				_allocator.deallocate(new_node, 1);
				return (ft::make_pair(iterator(_root, insert_pos), false));
			}
			// check balance;
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

		// insert with hint
		// iterator insert(iterator position, const value_type &value)
		// {
		// 	node_pointer new_node;
		// 	// check position
		// 	return (insert_node(value, new_node).first);
		// }


		template<class InputIterator>
		void insert(InputIterator first, InputIterator last);

		void	remove(node_pointer root, node_pointer *ptr);


// erase
		iterator	erase(iterator poistion);

		size_type	erase(const value_type &k);

		iterator	erase(iterator first, iterator last);

		allocator_type get_allocator() const { return (_allocator); }

// rotate & check balance
		// left-heavy
		void	right_rotate();
		void	left_right_rotate();

		// right-heavy
		void	left_rotate();
		void	right_left_rotate();

		// check balance
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

		int	check_balance()


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

			void printAVL(const std::string& prefix, const node_pointer node, bool isLeft)
			{
				if(node != NULL)
				{
					std::cout << prefix;
					std::cout << (isLeft ? "└──L:" : "└──R:" );
					// print the value of the node
					std::cout << "[" << node->_value.first << " -- ";
					std::cout << node->_value.second << "] : [h " << get_height(node) << " b " << get_balance_factor(node) << "] "<< std::endl;
					// enter the next tree level - left and right branch
					printAVL( prefix + (isLeft ? "│   " : "    "), node->_left, true);
					printAVL( prefix + (isLeft ? "│   " : "    "), node->_right, false);
				}
			}

			node_pointer get_root()
			{ return (_root); }

			// void printTree()
			// {
			// 	printAVL("", _root, false);
			// }



};

}

#endif