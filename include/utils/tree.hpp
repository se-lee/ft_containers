#ifndef TREE_HPP
# define TREE_HPP

# include "bidirectional_iterator.hpp"
# include "pair.hpp"
# include <memory>

namespace ft
{
/************************** [ TREE NODE ] **************************/

	template<class Pair>
	struct tree_node
	{
		typedef	tree_node<Pair>*	pointer;
	
		pointer		_parent;
		pointer		_left;
		pointer		_right;
		Pair		_pair_value;

		node() : _parent(NULL), _left(NULL), _right(NULL), _pair_value(NULL){}
		node(const Pair &pr) : _parent(NULL), _left(NULL), _right(NULL), _pair_value(pr) {}


	};

/************************** [ TREE ITER ] **************************/

	template<class T>
	class tree_iterator
	{
		public:
			typedef ft::bidirectional_iterator_tag		iterator_category;
			typedef T									value_type;
			typedef ptrdiff_t							difference_type;
			typedef T&									reference;
			typedef typename T*							pointer;

		private:
			typedef tree_node<T>		_node;

			_node	*_root;
			_node	*_current;

		public:
			tree_iterator() : _root(NULL), _current(NULL) {}
			tree_iterator(pointer ptr) : _root(ptr), _current(NULL) {}
			tree_iterator(const tree_iterator &other) : _root(other._root), _current(other._current) {}
			tree_iterator &operator=(const tree_iterator &other)
			{
				_root = other._root;
				_current = other._current;
				return (*this);
			}
			~tree_iterator() {}

			reference operator*() const { return (get_np()->_value); }
			pointer operator->() const { return (pointer_traits<pointer>::pointer_to(get_np()->_value)); }
			tree_iterator &operator++() 
			{
				/* _ptr to next element */
				return (*this);
			}

			tree_iterator operator++(int)
			{
				tree_iterator temp = *this;
				++(*this);
				return (temp);
			}

			tree_iterator &operator--()
			{
				/* _ptr to previous element */
				return (*this);
			}

			tree_iterator operator--(int)
			{
				tree_iterator temp = *this;
				--(*this);
				return (temp);
			}

			bool operator==(const tree_iterator &x, const tree_iterator &y)
			{ return (x._ptr == y._ptr); }

			bool operator!=(const tree_iterator &x, const tree_iterator &y)
			{ return (!(x == y)); }
	};

	template<class T>
	class tree_const_iterator {}; // あとで↑ コピペする

/************************** [ TREE CLASS ] **************************/

	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T>>
	> class tree
	{
		public:
			typedef	Key											key_type;
			typedef T											mapped_type;
			typedef	ft::pair<const key_type, mapped_type>		value_type;
			typedef Compare										value_compare;
			typedef Alloc										allocator_type;

			typedef	typename Alloc::pointer						pointer;
			typedef typename Alloc::const_pointer				const_pointer;
			typedef typename std::size_t			size_type;
			typedef typename std::ptrdiff_t			difference_type;

			typedef tree_iterator<value_type>	iterator;
			typedef tree_const_iterator<value_type> const_iterator; 

		private:
			pointer				*_root_node;	
			pointer				*_begin_node; // rootとは違うもの？
			pointer				*_end_node;
			allocator_type		_allocator;

		public:
			explicit tree(const value_compare &comp);
			explicit tree(const allocator_type &a);
			tree(const value_comapre &comp, const allocator_type &a);
			tree(tree &t);

			~tree();

			tree &operator=(const tree &_t);

			iterator begin() { return (iterator(_begin_node); }
			const_iterator begin() { return (const_iterator(_begin_node)); }

			iterator end() { return (iterator(_en))}
			const_iterator end();

			size_type max_size();

			void clear();
			void swap();

			template<class T>
			bool is_left_child(tree_node<T> *x) const
			{ return (x == x->_parent->_left); }

			template<class T>
			bool is_right_child(tree_node<T> *x) const
			{ return (x == x->_parent->_right); }

			template<class T>
			void set_parent(tree_node<T> *x, tree_node<T> *p)
			{ x->_parent = p; }

			// returns pointer to the left-most node under x node
			template<class T>
			tree_node<T>	*tree_min(tree_node<T> *x) const
			{
				while (x->_left != NULL)
					x = x->_left;
				return (x);
			}

			// returns pointer to the right-most node under x node
			template<class T>
			tree_node<T>	*tree_max(tree_node<T> *x) const
			{
				while(x->_right != NULL)
					x = x->_right;
				return (x);
			}

			// returns pointer to the next in-order node after x
			template<class T>
			tree_node<T>	*tree_next(tree_node<T> *x) const
			{
				if (x->_right != NULL)
					return (tree_min(x->_right));
				while (!is_left_child(x))
					x = x->_parent;
				return (x->_parent);
			}

			template<class T>
			tree_node<T>	*tree_next_iter(tree_node<T> *x) const
			{
				if (x->_right != NULL)
					return (static_cast<tree_node<T>>(tree_min(x->_right)));
				while (!is_left_child(x))
					x = x->_parent;
				return (static_cast<tree_node>(x->_parent));
			}

		// Returns:  pointer to the previous in-order node before __x.
		// Precondition:  __x != nullptr.
		// Note: __x may be the end node.

			template<class T>
			tree_node *tree_prev_iter(tree_node<T> *x) const
			{
				if (x->_left != NULL)
					return (tree_max(x->_left));
				tree_node *y = static_cast<tree_node<T>>(x);
				while (is_left_child(y))
					y = x->_parent;
				return (y->_parent);
			}

		// returns pointer to a node which has no children
			template<class T>
			tree_node<T>	*tree_leaf(tree_node<T> x) const
			{
				while (true)
				{
					if (x->_left != NULL)
					{
						x = x->_left;
						continue ;
					}
					if (x->_right != NULL)
					{
						x = x->_right;
						continue ;
					}
					break ;
				}
				return (x);
			}

/* Rotation系のやつ */
	template<class T>
	void	tree_left_rotate(tree_node *x) const
	{
		tree_node *y = x->_right;

		x->_right = y->_left;
		if (x->_right != NULL)
			x->_right -> set_parent(x);
		y->parent = x->_parent;
		if (is_left_child(x))
			x->_parent->_left = y;
		else
			x->_parent->_right = y;
			y->_left = _x;
			x->set_parent(y);
	}

/*
map.insert(std::make_pair("AAA", 10));
*/

	pointer	create_node(const value_type &value)
	{
		pointer		*new_node;
		new_node = _allocator.allocate(1);
		_allocator.construct(new_node, value);

		return (new_node);
	}

	pointer	find_insert_place(const value_type &value)
	{
		// compare the value from the root;
		

	}



	pair<iterator, bool>	insert(const value_type &value)
	{
		pointer	*new_node;
		new_node = create_node(value);
		if (_root == NULL)
			new_node = _root_node;
		else if (_root != NULL)
		{
			// comapare the values, find right place for new_node to be inserted

		}
		return (/*  */);
	}

// erase
		iterator erase( iterator pos );
		iterator erase( iterator first, iterator last );
		size_type erase( const Key &key );

//	check balance


// rotate




	};
}

#endif