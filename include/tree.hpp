#ifndef TREE_HPP
# define TREE_HPP

# include <memory>
# include <functional>
# include <algorithm>
# include "pair.hpp"
# include "tree_iterator.hpp"
# include "reverse_iterator.hpp"
# include "sfinae.hpp"

namespace ft
{
	template<class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
	class tree
	{
		public:
			typedef T																value_type;
			typedef Compare															value_compare;
			typedef Allocator														allocator_type;
			typedef tree_node<T>													node_type;
			typedef typename Allocator::template rebind<tree_node <T> >::other		node_allocator;
			typedef std::size_t														size_type;
			typedef typename Allocator::pointer										pointer;
			typedef typename Allocator::const_pointer								const_pointer;
			typedef typename Allocator::difference_type								difference_type;
			typedef tree_iterator<T *>												iterator; //ok
			typedef tree_iterator<const T *>										const_iterator; //ok
			typedef tree_node<value_type>*											node_pointer;

			tree() : _root(NULL), _begin(NULL), _end(NULL), _size(0) {}
			tree(const value_compare &comp, const node_allocator &a) 
			: _root(NULL), _begin(NULL), _end(NULL), _size(0) 
			{ 
				_value_comp = comp; 
				_allocator = a;
			}
		
			template<class InputIterator>
			tree (InputIterator first, InputIterator last, const Compare &comp, const node_allocator &alloc,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			: _allocator(alloc), _value_comp(comp)
			{
				size_type	range_size = last - first;
				_begin = _allocator.allocate(range_size);
				_end = _begin + range_size;
				
				for (size_type i = 0; i < range_size; ++i, ++first)
					insert(*first);
				insert(first, last);
			}

			tree(const tree &other) : _allocator(other._allocator), _value_comp(other._value_comp), _root(NULL), _begin(NULL), _end(NULL), _size(0)
			{
				for (iterator it = other.begin(); it != other.end(); ++it)
					insert(*it);
			}	

			~tree() 
			{ remove_all(); }

			tree &operator=(const tree &other)
			{
				if (this != &other)
				{
					clear();
					_value_comp = other._value_comp;
					_allocator = other._allocator;
					for (iterator it = other.begin(); it != other.end(); ++it)
					{
						insert(*it);
					}
				}
				return (*this);
			}

			size_t	size() const
			{ return (_size); }

			bool empty() const { return (!_size); }

			iterator begin() 
			{ return (iterator(_begin, _root)); }

			const_iterator begin() const 
			{ return (const_iterator(_begin, _root)); }

			iterator end() 
			{ return (iterator(NULL, _root)); }
			
			const_iterator end() const 
			{ return (const_iterator(NULL, _root)); }

			size_type max_size() const
			{ return (std::numeric_limits<size_type>::max() / sizeof(tree_node<T>)); }
			
			void clear()
			{
				remove_branch(_root);
				_size = 0;
				_root = NULL;
				_begin = NULL;
				_end = NULL;
			}

			void swap(tree	&other)
			{
				node_pointer	temp_root = _root;
				node_pointer	temp_begin = _begin;
				node_pointer	temp_end = _end;
				size_t			temp_size = _size;
				value_compare	temp_value_compare = _value_comp;
				allocator_type	temp_allocator = _allocator;

				_root = other._root;
				_begin = other._begin;
				_end = other._end;
				_size = other._size;
				_value_comp = other._value_comp;
				_allocator = other._allocator;

				other._root = temp_root;
				other._begin = temp_begin;
				other._end = temp_end;
				other._size = temp_size;
				other._value_comp = temp_value_compare;
				other._allocator = temp_allocator;
			}

			bool is_left_child(node_pointer node) const
			{ 
				if (node->_parent)
					return (node == node->_parent->_left); 
				else
					return (false);
			}

			bool is_right_child(node_pointer node) const
			{ return (node == node->_parent->_right); }

			bool is_leaf(node_pointer node) const
			{
				if ((node->_left == NULL) && (node->_right == NULL))
					return (true);
				else
					return (false);
			}

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

		// insert with value
			ft::pair<iterator, bool> insert(const value_type &value)
			{
				node_pointer new_node;
				new_node = find_insert_position(value, _root);
				return (insert_node(value, new_node));
			}

		// insert with hint : inserts value in the position as close as possible to the position just prior to pos
			iterator insert(iterator position, const value_type &value)
			{
				node_pointer pos = position.base();
				if (pos == _root)
					return (insert(value).first);
				if (position == end())
					pos = _end;
				if (_value_comp(value, pos->_value))
				{
					if (_value_comp(value, _root->_value))
						return (insert(value).first);
					else
						return (insert_node(value, find_insert_position(value, pos->_parent)).first);
				}
				else
					return (insert(value).first);
			}

		// erase
			void	erase (iterator position)
			{
				node_pointer target = position.base();
				if (target == NULL)
					return ;
				node_pointer pos = NULL;
				if ((target == _end) && (target == _begin)) // last one node of the tree
					return (clear());
				if (is_leaf(target)) // target has no child
				{
					if (is_left_child(target))
						target->_parent->_left = NULL;
					else
						target->_parent->_right = NULL;
					pos = target->_parent;
				}
				else // target has child
					pos = erase_node(target);
				balance_fix(pos);
				delete_node(target);
				_begin = find_min_node(_root);
				_end = find_max_node(_root);
				_size--;

			}

			size_type	erase (const value_type &value)
			{
				iterator it = find(value);
				if (it != end())
				{
					erase(it);
					return (1);
				}
				else
					return (0);
			}

			void erase(iterator first, iterator last)
			{
				for (;first != last;)
					erase(first++);
			}

			allocator_type get_allocator() const { return (_allocator); }

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
				if (it != end() && !_value_comp(value, *it) && !_value_comp(*it, value))
					return (it);
				return (end());
			}

			const_iterator find(const value_type &value) const
			{
				const_iterator it = lower_bound(value);
				if (it != end() && !_value_comp(value, *it) && !_value_comp(*it, value))
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
					if (!_value_comp(temp->_value, value))
					{
						it = iterator(temp, _root);
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
					if (!_value_comp(temp->_value, value))
					{
						it = const_iterator(temp, _root);
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
					if (_value_comp(value, temp->_value))
					{
						it = iterator(temp, _root);
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
					if (_value_comp(value, temp->_value))
					{
						it = iterator(temp, _root);
						temp = temp->_left;
					}
					else
						temp = temp->_right;
				}
				return (it);
			}

			ft::pair<iterator, iterator> equal_range(const value_type &value)
			{ return (ft::make_pair(lower_bound(value), upper_bound(value))); }

			ft::pair<const_iterator, const_iterator> equal_range( const value_type &value ) const
			{ return (ft::make_pair(lower_bound(value), upper_bound(value))); }

			void printAVL(const std::string& prefix, const node_pointer node, bool isLeft)
			{
				if(node != NULL)
				{
					std::cout << prefix;
					std::cout << (isLeft ? "└──L:" : "└──R:" );
					// print the value of the node
					std::cout << "[ " << node->_value.first << " -- ";
					std::cout << node->_value.second << "] : [h " << get_height(node) << " b " << get_balance_factor(node) 
									<< " " << std::boolalpha << is_balanced(node) << " ] "<< std::endl;
					// enter the next tree level - left and right branch
					printAVL( prefix + (isLeft ? "│   " : "    "), node->_left, true);
					printAVL( prefix + (isLeft ? "│   " : "    "), node->_right, false);
				}
			}
			node_pointer get_root()
			{ return (_root); }

			node_pointer get_begin()
			{ return (_begin); }

			node_pointer get_end()
			{ return (_end); }

		private:
			node_allocator			_allocator;
			value_compare			_value_comp;
			node_pointer			_root;
			node_pointer			_begin;
			node_pointer			_end;
			size_t					_size;

/* utils */
			node_pointer find_max_node(node_pointer node)
			{
				node_pointer current = node;
				while (current->_right != NULL)
					current = current->_right;
				return (current);
			}

			node_pointer find_min_node(node_pointer node)
			{
				node_pointer current = node;
				while (current->_left != NULL)
					current = current->_left;
				return (current);
			}

/* Balancing */
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


/* Rotations */
			node_pointer	right_rotate(node_pointer node)
			{
				node_pointer temp = node->_left;
				node->_left = temp->_right;
				if (temp->_right)
					temp->_right->_parent = node;
				if (node->_parent == NULL)
				{
					temp->_parent = NULL;
					_root = temp;
				}
				else
				{
					temp->_parent = node->_parent;
					if (is_left_child(node))
						node->_parent->_left = temp;
					else if (!is_left_child(node))
						node->_parent->_right = temp;
					temp->_parent = node->_parent;
				}
				temp->_right = node;
				node->_parent = temp;
				
				return (temp);
			}

			node_pointer	left_rotate(node_pointer node)
			{
				node_pointer temp = node->_right;
				node->_right = temp->_left;
				if (temp->_left)
					temp->_left->_parent = node;
				if (node->_parent == NULL)
				{
					temp->_parent = NULL;
					_root = temp;
				}
				else
				{
					temp->_parent = node->_parent;
					if (is_left_child(node))
						node->_parent->_left = temp;
					else if (!is_left_child(node))
						node->_parent->_right = temp;
					temp->_parent = node->_parent;
				}
				temp->_left = node;
				node->_parent = temp;

				return (temp);
			}

			node_pointer	left_right_rotate(node_pointer node)
			{
				node->_left = left_rotate(node->_left);
				return (right_rotate(node));
			}

			node_pointer	right_left_rotate(node_pointer node)
			{
				node->_right = right_rotate(node->_right);
				return (left_rotate(node));
			}

			void balance_fix(node_pointer node)
			{
				if (node == NULL)
					return ;
				if (is_balanced(node) == false)
				{
					if (get_balance_factor(node) > 0) // left-heavy
					{
						if (get_balance_factor(node->_left) > 0)
							right_rotate(node);
						else
							left_right_rotate(node);
					}
					else// right-heavy
					{
						if (get_balance_factor(node->_right) < 0 )
							left_rotate(node);
						else 
							right_left_rotate(node);
					}
				}
				return (balance_fix(node->_parent));
			}

/* Functions for insert */
			node_pointer find_insert_position(const value_type &value, node_pointer start_node)
			{
				node_pointer parent_node = NULL;
				node_pointer current_node = start_node;
				while (current_node != NULL)
				{
					parent_node = current_node;
					if (_value_comp(value, current_node->_value)) {
						if (current_node->_left == NULL)
							return (current_node);
						else // current_node->_left != NULL
							current_node = current_node->_left;
					}
					else if (_value_comp(current_node->_value, value)) {
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

	// どのノードの下に入るか、Insert positionはNew Nodeの親； 
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
				else if (_value_comp(new_node->_value, insert_pos->_value))
					insert_pos->_left = new_node;
				else if (_value_comp(insert_pos->_value, new_node->_value))
					insert_pos->_right = new_node;
				else
				{
					delete_node(new_node);
					return (ft::make_pair(iterator(insert_pos, _root), false));
				}
				balance_fix(new_node);
				if (_value_comp(new_node->_value, _begin->_value))
					_begin = new_node;
				if (_value_comp(_end->_value, new_node->_value))
					_end = new_node;
				_size++;
				return (ft::make_pair(iterator(new_node, _root), true));
			}


/* Functions for erase */
			void	delete_node(node_pointer node)
			{
				_allocator.destroy(node);
				_allocator.deallocate(node, 1);
			}

			void	remove_branch(node_pointer node)
			{
				if (node != NULL)
				{
					remove_branch(node->_left);
					remove_branch(node->_right);
					delete_node(node);
				}
			}

			void remove_all()
			{
				remove_branch(_root);
				_begin = NULL;
				_end = NULL;
				_root = NULL;
				_size = 0;
			}

			void	replace_node(node_pointer old_node, node_pointer new_node)	
			{
				if (old_node == _root)
					_root = new_node;
				else if (is_left_child(old_node))
					old_node->_parent->_left = new_node;
				else
					old_node->_parent->_right = new_node;
				new_node->_parent = old_node->_parent;
			}

			node_pointer	erase_node(node_pointer target)
			{
				if (target->_right == NULL) // has only left child
				{
					replace_node(target, target->_left);
					return (target->_left);
				}
				else if (target->_left == NULL) // has only right child
				{
					replace_node(target, target->_right);
					return (target->_right);
				}
				else
				{
					node_pointer temp = find_max_node(target->_left);
					if(temp->_parent != target)  //left max is not target's child
					{
						temp->_parent->_right = temp->_left; //put temp's prev node to parent's right
						if (temp->_left != NULL)
							temp->_left->_parent = temp->_parent;
						temp->_left = target->_left;
						target->_left->_parent = temp;
					}
					replace_node(target, temp);
					temp->_right = target->_right;
					temp->_right->_parent = temp;
					
					return (target->_left);
				}
			}

	};
}

#endif