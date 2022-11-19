#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

namespace ft {

/************************** [ TREE NODE ] **************************/

	template<class T>
	struct tree_node
	{
		tree_node<T>	*_parent;
		tree_node<T>	*_left;
		tree_node<T>	*_right;
		T				_value; //first, second;

		tree_node() : _parent(NULL), _left(NULL), _right(NULL), _value(NULL) {}
		tree_node(const T &pr) : _parent(NULL), _left(NULL), _right(NULL), _value(pr) {}

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
			typedef T*									pointer;

		private:
			tree_node<value_type>	*_current;

		public:
			tree_iterator() {}
			tree_iterator(tree_node<value_type> *ptr) : _current(ptr) {}
			tree_iterator(tree_iterator const &other) : _current(other._current) {}
			tree_iterator &operator=(const tree_iterator &other)
			{	
				_current = other._current;
				return (*this);
			}
			~tree_iterator() {}

			reference operator*() const { return (_current->_value); }
			pointer operator->() const { return (&_current->_value); }


/*************[ お試し ]**************************/

			bool is_left_child(tree_node<value_type> *x) const
			{
				if (x->_parent != NULL)
					return (x == x->_parent->_left);
				else
					return false;
			}

			tree_node<value_type>	*tree_min(tree_node<value_type> *x) const
			{
				while (x->_left != NULL)
					x = x->_left;
				return (x);
			}

			// returns pointer to the right-most node under x node
			tree_node<value_type>	*tree_max(tree_node<value_type> *x) const
			{
				while(x->_right != NULL)
					x = x->_right;
				return (x);
			}

			// returns pointer to the next in-order node after x
			tree_node<value_type>	*tree_next(tree_node<value_type> *x) const
			{
				if (x->_right != NULL)
					return (tree_min(x->_right));
				while (!is_left_child(x))
					x = x->_parent;
				return (x->_parent);
			}

			tree_node<value_type>	*tree_next_iter(tree_node<value_type> *x) const
			{
				if (x->_right != NULL)
					return (tree_min(x->_right));
				while (!is_left_child(x))
					x = x->_parent;
				return (x->_parent);
				
			}

			tree_node<value_type> *tree_prev_iter(tree_node<value_type> *x) const
			{
				if (x->_left != NULL)
					return (tree_max(x->_left));
				tree_node<value_type> *y = x;
				while (is_left_child(y))
					y = x->_parent;
				return (y->_parent);
			}

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


/*************[ お試し ]**************************/



			tree_iterator &operator++() 
			{
				_current = tree_next_iter(_current);
				// std::cout <<"_current: " << _current << " | parent: " << _current->_parent<< std::endl;

				return (*this);
			}

			tree_iterator operator++(int)
			{
				// std::cout <<"_current: " << _current << " | parent: " << _current->_parent<< std::endl;
				tree_iterator temp = *this;
				++(*this);
				return (temp);
			}

			tree_iterator &operator--()
			{
				_current = tree_prev_iter(_current);
				return (*this);
			}

			tree_iterator operator--(int)
			{
				tree_iterator temp = *this;
				--(*this);
				return (temp);
			}

			tree_node<value_type> *base() const
			{ return (_current); }

	};

	template<class Iterator1, class Iterator2>
	bool operator==(const ft::tree_iterator<Iterator1> &x, const ft::tree_iterator<Iterator2> &y)
	{ return (x.base() == y.base()); }

	template<class Iterator1, class Iterator2>
	bool operator!=(const ft::tree_iterator<Iterator1> &x, const ft::tree_iterator<Iterator2> &y)
	{ return (!(x.base() == y.base())); }


/************************** [ CONST TREE ITER ] **************************/

	template<class T>
	class const_tree_iterator
	{
		public:
			typedef ft::bidirectional_iterator_tag		iterator_category;
			typedef T								value_type;
			typedef ptrdiff_t							difference_type;
			typedef T&								reference;
			typedef T*								pointer;

		private:
			tree_node<T>	*_current;

		public:
			const_tree_iterator() {}
			const_tree_iterator(tree_node<T> *ptr) :_current(ptr) {}
			const_tree_iterator(const_tree_iterator &other) : _current(other._current) {}
			const_tree_iterator &operator=(const_tree_iterator &other)
			{	
				_current = other._current;
				return (*this);
			}
			~const_tree_iterator() {}

			reference operator*() const { return (_current->_value); }
			pointer operator->() const { return (&_current->_value); }

/*************[ お試し ]**************************/
			bool is_left_child(tree_node<value_type> *x) const
			{
				if (x->_parent != NULL)
					return (x = x->_parent->_left);
				else
					return (false);
			}
			tree_node<value_type>	*tree_min(tree_node<value_type> *x) const
			{
				while (x->_left != NULL)
					x = x->_left;
				return (x);
			}

			// returns pointer to the right-most node under x node
			tree_node<value_type>	*tree_max(tree_node<value_type> *x) const
			{
				while(x->_right != NULL)
					x = x->_right;
				return (x);
			}

			// returns pointer to the next in-order node after x
			tree_node<value_type>	*tree_next(tree_node<value_type> *x) const
			{
				if (x->_right != NULL)
					return (tree_min(x->_right));
				while (!is_left_child(x))
					x = x->_parent;
				return (x->_parent);
			}

			tree_node<value_type>	*tree_next_iter(tree_node<value_type> *x) const
			{
				if (x->_right != NULL)
					return (tree_min(x->_right));
				while (!is_left_child(x))
					x = x->_parent;
				if (x->_parent)
					return (x->_parent);
				else
					return (NULL);
			}

			tree_node<value_type> *tree_prev_iter(tree_node<value_type> *x) const
			{
				if (x->_left != NULL)
					return (tree_max(x->_left));
				tree_node<value_type> *y = x;
				while (is_left_child(y))
					y = x->_parent;
				return (y->_parent);
			}

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


/*************[ お試し ]**************************/

			const_tree_iterator &operator++() 
			{
				_current = tree_next_iter(_current);
				std::cout << "const _current: " << &_current << std::endl;
				return (*this);
			}

			const_tree_iterator operator++(int)
			{
				const_tree_iterator temp = *this;
				++(*this);
				return (temp);
			}

			const_tree_iterator &operator--()
			{
				_current = tree_prev_iter(_current);
				return (*this);
			}

			const_tree_iterator operator--(int)
			{
				const_tree_iterator temp = *this;
				--(*this);
				return (temp);
			}

			tree_node<value_type> *base() const
			{ return (_current); }

	};

	template<class Iterator1, class Iterator2>
	bool operator==(const ft::const_tree_iterator<Iterator1> &x, const ft::const_tree_iterator<Iterator2> &y)
	{ return (x.base() == y.base()); }

	template<class Iterator1, class Iterator2>
	bool operator!=(const ft::const_tree_iterator<Iterator1> &x, const ft::const_tree_iterator<Iterator2> &y)
	{ return (!(x.base() == y.base())); }

}


#endif