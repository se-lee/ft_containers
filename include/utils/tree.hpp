#ifndef TREE_HPP
# define TREE_HPP

# include "bidirectional_iterator.hpp"
# include "pair.hpp"
# include <memory>

namespace ft
{
/************************** [ TREE NODE ] **************************/
	template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> >
	> class tree;

	template<class Pair>
	struct tree_node
	{
		typedef	tree_node<Pair>	*pointer;
	
		pointer		_parent;
		pointer		_left;
		pointer		_right;
		Pair		_pair_value;

		tree_node() : _parent(NULL), _left(NULL), _right(NULL), _pair_value(NULL) {}
		tree_node(const Pair &pr) : _parent(NULL), _left(NULL), _right(NULL), _pair_value(pr) {}

	};

/************************** [ TREE ITER ] **************************/

	template<class Pair, class Container>
	class tree_iterator
	{
		public:
			typedef ft::bidirectional_iterator_tag		iterator_category;
			typedef Pair								value_type;
			typedef Container							container_type;
			typedef ptrdiff_t							difference_type;
			typedef Pair&								reference;
			typedef Pair*								pointer;

		private:
			container_type	*_container;
			tree_node<Pair>	*_current;

		public:
			tree_iterator() : _container(NULL), _current(NULL) {}
			tree_iterator(container_type *cont, tree_node<Pair> *ptr) : _container(cont),_current(ptr) {}
			tree_iterator(const tree_iterator &other) : _container(other._container), _current(other._current) {}
			tree_iterator &operator=(const tree_iterator &other)
			{	
				_container = other._container;
				_current = other._current;
				return (*this);
			}
			~tree_iterator() {}

			reference operator*() const { return (*_current); }
			pointer operator->() const { return (&(operator*())); }

			tree_iterator &operator++() 
			{
				_current = _container.tree_next_iter(_current);
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
				//tree_prev_iter
				_current = _container.tree_prev_iter(_current);
				return (*this);
			}

			tree_iterator operator--(int)
			{
				tree_iterator temp = *this;
				--(*this);
				return (temp);
			}
	};

	template<class Iterator1, class Iterator2, class Container>
	bool operator==(const ft::tree_iterator<Iterator1, Container> &x, const ft::tree_iterator<Iterator2, Container> &y)
	{ return (x == y); }

	template<class Iterator1, class Iterator2, class Container>
	bool operator!=(const ft::tree_iterator<Iterator1, Container> &x, const ft::tree_iterator<Iterator2, Container> &y)
	{ return (!(x == y)); }



/************************** [ CONST TREE ITER ] **************************/

	template<class Pair, class Container>
	class const_tree_iterator
	{
		public:
			typedef ft::bidirectional_iterator_tag		iterator_category;
			typedef Pair								value_type;
			typedef Container							container_type;
			typedef ptrdiff_t							difference_type;
			typedef Pair&								reference;
			typedef Pair*								pointer;

		private:
			container_type	*_container;
			tree_node<Pair>	*_current;

		public:
			tree_iterator() : _container(NULL), _current(NULL) {}
			tree_iterator(container_type *cont, tree_node<Pair> *ptr) : _container(cont),_current(ptr) {}
			tree_iterator(const tree_iterator &other) : _container(other._container), _current(other._current) {}
			tree_iterator &operator=(const tree_iterator &other)
			{	
				_container = other._container;
				_current = other._current;
				return (*this);
			}
			~tree_iterator() {}

			reference operator*() const { return (*_current); }
			pointer operator->() const { return (&(operator*())); }

			tree_iterator &operator++() 
			{
				_current = _container.tree_next_iter(_current);
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
				//tree_prev_iter
				_current = _container.tree_prev_iter(_current);
				return (*this);
			}

			tree_iterator operator--(int)
			{
				tree_iterator temp = *this;
				--(*this);
				return (temp);
			}
	};

	template<class Iterator1, class Iterator2, class Container>
	bool operator==(const ft::const_tree_iterator<Iterator1, Container> &x, const ft::const_tree_iterator<Iterator2, Container> &y)
	{ return (x == y); }

	template<class Iterator1, class Iterator2, class Container>
	bool operator!=(const ft::const_tree_iterator<Iterator1, Container> &x, const ft::const_tree_iterator<Iterator2, Container> &y)
	{ return (!(x == y)); }




/************************** [ TREE CLASS ] **************************/

	template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> >
	> class tree
	{
		public:
			typedef	Key												key_type;
			typedef T												mapped_type;
			typedef	typename ft::pair<const key_type, mapped_type>	value_type;
			typedef Compare											value_compare;
			typedef Allocator										allocator_type;

			typedef	typename Allocator::pointer						pointer;
			typedef typename Allocator::const_pointer				const_pointer;
			typedef typename std::size_t			size_type;
			typedef typename std::ptrdiff_t			difference_type;

			typedef typename tree_iterator<value_type>	iterator;
			typedef typename tree_const_iterator<value_type> const_iterator; 

		private:
			pointer				*_root_node;
			pointer				*_begin_node;
			pointer				*_end_node;
			allocator_type		_allocator;

		public:
			tree();
			explicit tree(const value_compare &comp);
			explicit tree(const allocator_type &a);
			tree(const value_compare &comp, const allocator_type &a);
			tree(tree &t);

			~tree();

			tree &operator=(const tree &_t);

			iterator begin() { return (iterator(_begin_node)); }
			const_iterator begin() const { return (const_iterator(_begin_node)); }

			iterator end() { return (iterator(_end_node)); }
			const_iterator end() const { return (const_itertor(_end_node)); };

			size_type max_size();

			void clear();
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

			// returns pointer to the left-most node under x node
			template<class value_type>
			tree_node<value_type>	*tree_min(tree_node<value_type> *x) const
			{
				while (x->_left != NULL)
					x = x->_left;
				return (x);
			}

			// returns pointer to the right-most node under x node
			template<class value_type>
			tree_node<value_type>	*tree_max(tree_node<value_type> *x) const
			{
				while(x->_right != NULL)
					x = x->_right;
				return (x);
			}

			// returns pointer to the next in-order node after x
			template<class value_type>
			tree_node<value_type>	*tree_next(tree_node<value_type> *x) const
			{
				if (x->_right != NULL)
					return (tree_min(x->_right));
				while (!is_left_child(x))
					x = x->_parent;
				return (x->_parent);
			}

			template<class value_type>
			tree_node<value_type>	*tree_next_iter(tree_node<value_type> *x) const
			{
				if (x->_right != NULL)
					return (static_cast<tree_node<value_type> >(tree_min(x->_right)));
				while (!is_left_child(x))
					x = x->_parent;
				return (static_cast<tree_node<value_type> >(x->_parent));
			}

			template<class value_type>
			tree_node<value_type> *tree_prev_iter(tree_node<value_type> *x) const
			{
				if (x->_left != NULL)
					return (tree_max(x->_left));
				tree_node<value_type> *y = static_cast<tree_node<value_type> >(x);
				while (is_left_child(y))
					y = x->_parent;
				return (y->_parent);
			}

		// returns pointer to a node which has no children
			template<class value_type>
			tree_node<value_type>	*tree_leaf(tree_node<value_type> x) const
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

/*
map.insert(std::make_pair("AAA", 10));
*/

	node_pointer	create_node(const value_type &value)
	{
		pointer		*new_node;
		new_node = _allocator.allocate(1);
		_allocator.construct(new_node, value);

		return (new_node);
	}

	pointer	find_insert_place(const value_type &value);

	ft::pair<iterator, bool>	insert(const value_type &value)
	{
		tree_	new_node;
		new_node = create_node(value);
		if (_root_node == NULL)
			new_node = _root_node;
		else if (_root_node != NULL)
		{
			// comapare the values, find right place for new_node to be inserted
		}
		return (ft::pair<iterator<new_node>, true>);
/*
(1), (2) : 戻り値としては、イテレータとbool値の組を返す。
挿入された場合には、first に挿入された要素へのイテレータ、 second に true が設定される。
挿入されなかった場合には、 first に x と等価のキーを持つ要素へのイテレータ、 second に false が設定される。
*/
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