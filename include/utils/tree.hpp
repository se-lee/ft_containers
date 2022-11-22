#ifndef TREE_HPP
# define TREE_HPP

# include <memory>
# include <functional>
# include "./pair.hpp"
# include "../iterators/tree_iterator.hpp"

namespace ft
{

template<class Type, class Compare = std::less<Type>, class Allocator = std::allocator<tree_node<Type> > >
class tree
{
	public:
		typedef Type												value_type;
		typedef Compare												value_compare;
		typedef Allocator											allocator_type;
		typedef typename Allocator::template rebind<tree_node<Type> >::other node_allocator;
		typedef std::size_t											size_type;
		typedef tree_iterator<value_type>							iterator;
		typedef const_tree_iterator<value_type> 					const_iterator;

	private:
		tree_node<value_type>	*_root;
		tree_node<value_type>	*_begin;
		tree_node<value_type>	*_end;
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
			return (const_itertor(_root, NULL)); 
		}

		iterator root() 
		{ return (iterator(_root)); }
		
		const_iterator root() const 
		{ return (iterator(_root)); }

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
			for (tree_node<value_type> *ptr = _begin; ptr != _end; ptr++)
				_allocator.destroy(ptr);
			_size = 0;
		}

		void swap();

		bool is_left_child(tree_node<value_type> *x) const
		{ 
			if (x->_parent)
				return (x == x->_parent->_left); 
			else
				return (false);
		}

		bool is_right_child(tree_node<value_type> *x) const
		{ return (x == x->_parent->_right); }

		void set_parent(tree_node<value_type> *x, tree_node<value_type> *p)
		{ x->_parent = p; }

		void	tree_left_rotate(tree_node<value_type> *x) const
		{
			tree_node<value_type> *y = x->_right;

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

		tree_node<value_type>	*find_insert_place(tree_node<value_type> *root, const value_type &value)
		{
			while (true) {
				if (value_compare() (value.first, root->_value.first)) {
					if (root->_left != NULL)
						root = root->_left;
					else
						return (root->_left);
				}
				else if (value_compare() (root->_value, value)) {
					if (root->_right != NULL)
						root = root->_right;
					else
						return (root->_right);
				}
				else {
					return (root);
				}
			}
		}

		tree_node<value_type>	*find_insert_position(const value_type &value)
		{
			tree_node<value_type> *parent_node = NULL;
			tree_node<value_type> *current_node = _root;
			while (current_node != NULL)
			{
				parent_node = current_node;
				// std::cout << "parent_node: " << parent_node << "| current_node: " << current_node << std::endl;
				if (_value_compare(value, current_node->_value)) {
					if (current_node->_left == NULL)
					{
						return (current_node);
					}
					else // current_node->_left != NULL
					{
						current_node = current_node->_left;
					}
				}
				else if (_value_compare(current_node->_value, value)) {
					if (current_node->_right == NULL)
					{
						return (current_node);
					}
					else
					{
						current_node = current_node->_right;
					}
				}
				else // if value == current_node value
					return (current_node);
			}
			return (parent_node);
		}

		ft::pair<iterator, bool> insert_node(const value_type &value, tree_node<value_type> *insert_pos)
		{
			// std::cout << "insert_pos: " << insert_pos << std::endl; 
			tree_node<value_type>	*new_node;
			new_node = _allocator.allocate(1);
			_allocator.construct(new_node, value);
			new_node->_parent = insert_pos;
			std::cout << "new_node: " << new_node << "| parent: " << new_node->_parent << " | insert_pos: " << insert_pos << std::endl;
			if (insert_pos == NULL)
			{
				_root = new_node;
				_begin = new_node;
				_end = new_node;
			}
			else if (_value_compare(new_node->_value, insert_pos->_value))
			{
				insert_pos->_left = new_node;
			}
			else if (_value_compare(insert_pos->_value, new_node->_value))
			{
				insert_pos->_right = new_node;
			}
			else //duplicate
			{
				_allocator.destroy(new_node);
				_allocator.deallocate(new_node, 1);
				return (ft::make_pair(iterator(_root, insert_pos), false));
			}
			// check balance;
			std::cout << std::boolalpha;
			std::cout << "left: " << is_left_child(new_node) << std::endl;
			if (_value_compare(new_node->_value, _begin->_value))
				_begin = new_node;
			if (_value_compare(_end->_value, new_node->_value))
				_end = new_node;
			_size++;
			// std::cout << "_begin: " << _begin << " | _end: " << _end << std::endl;
			return (ft::make_pair(iterator(_root, new_node), true));
		}

		void	update_begin(tree_node<value_type> *inserted_node)
		{
			if (_begin == _end || _value_compare(inserted_node->_value, _begin->_value))
				_begin = inserted_node;
		}

		ft::pair<iterator, bool> insert(const value_type &value)
		{
			tree_node<value_type>	*new_node_pos;
			new_node_pos = find_insert_position(value);
			return (insert_node(value, new_node_pos));
		}


// new_node にInsert placeのポインター代入。NULLでなければ重複あり、Nullであれば重複なし
			// if key doesnt exist, create a new node
			// if there is no root node, set new node as the root;
			// else, search for the place to insert new_node;

		iterator insert(const_iterator it, const value_type &x);

		template<class InputIterator>
		void insert(InputIterator first, InputIterator last);

// erase
		iterator erase( iterator pos );
		iterator erase( iterator first, iterator last );
		// size_type erase( const Key &key );

		allocator_type get_allocator() const { return (_allocator); }

// rotate


};

}

#endif