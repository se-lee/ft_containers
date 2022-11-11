#ifndef TREE_HPP
# define TREE_HPP

# include <memory>
# include <functional>
# include "pair.hpp"
# include "../iterators/bidirectional_iterator.hpp"
# include "../iterators/tree_iterator.hpp"

namespace ft
{
/************************** [ TREE CLASS ] **************************/

	// template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >class tree;

	template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > > 
	class tree
	{
		public:
			typedef	Key												key_type;
			typedef T												mapped_type;
			typedef	typename ft::pair<const key_type, mapped_type>	value_type;
			typedef Compare											value_compare;
			typedef Allocator										allocator_type;

			typedef	typename Allocator::pointer						pointer;
			typedef typename Allocator::const_pointer				const_pointer;
			typedef typename std::size_t							size_type;
			typedef typename std::ptrdiff_t							difference_type;

			typedef tree_iterator<value_type>						iterator;
			typedef const_tree_iterator<value_type> 				const_iterator; 

		private:
			tree_node<value_type>	*_root_node;
			tree_node<value_type>	*_begin_node;
			tree_node<value_type>	*_end_node;
			allocator_type			_allocator;
			value_compare			_value_compare;
			size_t					_size;

		public:
			tree() : _root_node(NULL), _begin_node(NULL), _end_node(NULL) {}
			explicit tree(const value_compare &comp) : _root_node(NULL), _begin_node(NULL), _end_node(NULL), _allocator(NULL), _value_compare(comp) {}
			explicit tree(const allocator_type &a) : _root_node(NULL), _begin_node(NULL), _end_node(NULL), _allocator(a), _value_compare(NULL) {}
			tree(const value_compare &comp, const allocator_type &a) : _root_node(NULL), _begin_node(NULL), _end_node(NULL), _allocator(a), _value_compare(comp) {}
	
			template<class InputIterator>
			tree (InputIterator first, InputIterator last, const Compare &comp = Compare(), const Allocator &alloc = Allocator())
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
				clear();
			}

			tree &operator=(const tree &other)
			{
				_root_node = other._root_node;
				_begin_node = other._begin_node;
				_end_node = other._end_node;
				_allocator = other._allocator;
				_value_compare = other._value_compare;
			
				return (*this);
			}

			size_t	size()
			{ return (_size); }

			bool empty() const { return (_begin_node == _end_node); }

			iterator begin() { return (iterator(_begin_node)); }
			const_iterator begin() const { return (const_iterator(_begin_node)); }

			iterator end() { return (iterator(_end_node)); }
			const_iterator end() const { return (const_itertor(_end_node)); };

			size_type max_size();

			void clear()
			{
				_allocator.destroy(_root_node);
				_size = 0;
				_begin_node = _end_node;
				_end_node->_left = NULL;
			}


			void swap();

			template<class value_type>
			bool is_left_child(tree_node<value_type> *x) const
			{ return (x == x->_parent->_left); }

			template<class value_type>
			bool is_right_child(tree_node<value_type> *x) const
			{ return (x == x->_parent->_right); }

			template<class value_type>
			void set_parent(tree_node<value_type> *x, tree_node<value_type> *p)
			{ x->_parent = p; }

/* Rotation系のやつ */
			template<class value_type>
			void	tree_left_rotate(tree_node<value_type> *x) const
			{
				tree_node<value_type> *y = x->_right;

				x->_right = y->_left;
				if (x->_right != NULL)
					x->_right -> set_parent(x);
				y->parent = x->_parent;
				if (is_left_child(x))
					x->_parent->_left = y;
				else
					x->_parent->_right = y;
					y->_left = x;
					x->set_parent(y);
			}

			tree_node<value_type> *create_node(const value_type &value)
			{
				tree_node<value_type>	*new_node;
				new_node = _allocator.allocate(1);
				_allocator.construct(new_node, value);

				return (new_node);
			}


	// returns NULL if value doesnt exist in tree
	// returns reference to the node that has duplicate value
			tree_node<value_type> *find_equal(tree_node<value_type> &parent, const value_type &value)
			{
				tree_node<value_type> *_temp_root = _root_node;

				if (_temp_root != NULL)
				{
					while (true)
					{
						if (value_compare() (value, _temp_root->_pair_value)) {
							if (_temp_root->_left != NULL)
								_temp_root = _temp_root->_left;
							else {
								parent = _temp_root;
								return (parent._left);
							}
						}
						else if (value_compare()(_temp_root->_pair_value, value)){ //
							if (_temp_root->_right != NULL)
								_temp_root = _temp_root->_right;
							else {
								parent = _temp_root;
								return (_temp_root->_right);
						}
						else {
							parent = _temp_root;
							return (&)
						}
					}
				}
			}

			void insert_node_at(tree_node<value_type> *parent, tree_node<value_type> *child, tree_node<value_type> *new_node)
			{
				new_node->_left = NULL;
				new_node->_right = NULL;
				new_node->_parent = parent;
				child = new_node;
				
				if (_begin_node->_left != NULL)
					_begin_node = _begin_node->_left; //
				
				//balance_after_insert;
				_size++;
			}


		/*
			挿入された場合には、first に挿入された要素へのイテレータ、 second に true が設定される。
			挿入されなかった場合には、 first に x と等価のキーを持つ要素へのイテレータ、 second に false が設定される。
		*/
			ft::pair<iterator, bool>	insert(const value_type &value)
			{
				iterator it = begin();

				// if key already exists in the tree, return iterator to the value and false;
					return (ft::pair<iterator, bool> (it, false));




				// if key doesnt exist, create a new node
				// if there is no root node, set new node as the root;
				// else, search for the place to insert new_node;

				tree_node<value_type>	*new_node;
				new_node = insert_node(value);
				if (_root_node == NULL)
					new_node = _root_node;

				return (ft::pair<iterator, bool> it, true);

			}


			iterator insert(const_iterator it, const value_type &x);

			template<class InputIterator>
			void insert(InputIterator first, InputIterator last);

	// erase
			iterator erase( iterator pos );
			iterator erase( iterator first, iterator last );
			size_type erase( const Key &key );


// rotate


	};

	};
}

#endif