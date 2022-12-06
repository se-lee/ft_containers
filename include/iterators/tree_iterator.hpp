#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft {

/************************** [ TREE NODE ] **************************/

	template<class T>
	struct tree_node
	{
		tree_node<T>	*_parent;
		tree_node<T>	*_left;
		tree_node<T>	*_right;
		T				_value;

		tree_node() : _parent(NULL), _left(NULL), _right(NULL), _value(NULL) {}
		tree_node(const T &pr) : _parent(NULL), _left(NULL), _right(NULL), _value(pr) {}

	};

/************************** [ TREE ITER ] **************************/
	template<class T>
	class tree_iterator : public std::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			// typedef ft::bidirectional_iterator_tag		iterator_category;
			// typedef T									value_type;
			// typedef std::ptrdiff_t						difference_type;
			// typedef T&									reference;
			// typedef T*									pointer;
			typedef T												iterator_type;
			typedef	typename iterator_traits<T>::value_type			value_type;
			typedef typename iterator_traits<T>::difference_type	difference_type;
			typedef typename iterator_traits<T>::pointer			pointer;
			typedef typename iterator_traits<T>::reference			reference;
			typedef typename iterator_traits<T>::iterator_category	iterator_category;
			

		private:
			tree_node<value_type> *_root;
			tree_node<value_type> *_current;

		public:
			tree_iterator() {}
			tree_iterator(tree_node<value_type> *rt, tree_node<value_type> *ptr) : _root(rt), _current(ptr) {}
			
			template<class Iter>
			tree_iterator(const tree_iterator<Iter> &other)
			{
				*this = other;
			}

			template<class Iter>
			tree_iterator &operator=(const tree_iterator<Iter> &other)
			{	
				_root = other.get_root();
				_current = other.base();
				return (*this);
			}
			~tree_iterator() {}

			reference operator*() const { return (_current->_value); }
			pointer operator->() const { return (&_current->_value); }


			tree_iterator &operator++()
			{
				if (_current->_right != NULL)
				{
					_current = _current->_right;
					while (_current->_left != NULL)
						_current = _current->_left;
				}
				else
				{
					while (_current->_parent && (_current == _current->_parent->_right))
						_current = _current->_parent;
					if (_current->_parent)
						_current = _current->_parent;
					else
						_current = NULL;
				}
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
				if (_current->_left != NULL)
				{
					_current = _current->_left;
					while(_current->_right != NULL)
						_current = _current->_right;
				}
				else
				{
					while (_current->_parent && (_current == _current->_parent->_left))
						_current = _current->_parent;
					if (_current->_parent)
						_current = _current->_parent;
					else
						_current = NULL;
				}
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

			tree_node<value_type> *get_root() const
			{ return (_root); }

	};


/************************** [ CONST TREE ITER ] **************************/

	template<class T>
	class const_tree_iterator
	{
		public:
			typedef ft::bidirectional_iterator_tag	iterator_category;
			typedef T								value_type;
			typedef std::ptrdiff_t					difference_type;
			typedef T&								reference;
			typedef T*								pointer;
			typedef const T&						const_reference;
			typedef const T*						const_pointer;

		private:
			tree_node<T>	*_root;
			tree_node<T>	*_current;

		public:
			const_tree_iterator() {}
			const_tree_iterator(tree_node<T> *rt, tree_node<T> *ptr) : _root(rt), _current(ptr) {}
			const_tree_iterator(const const_tree_iterator &other)
			{
				*this = other;
			}
			const_tree_iterator(const tree_iterator<value_type> &other)
			{
				*this = other;
			}
			const_tree_iterator &operator=(const const_tree_iterator &other)
			{	
				// _root = other._root;
				// _current = other._current;
				*this = other;
				return (*this);
			}
			~const_tree_iterator() {}

			const_reference operator*() const { return (_current->_value); }
			const_pointer operator->() const { return (&_current->_value); }

			const_tree_iterator &operator++()
			{
				if (_current->_right != NULL)
				{
					_current = _current->_right;
					while (_current->_left != NULL)
						_current = _current->_left;
				}
				else
				{
					while (_current->_parent && (_current == _current->_parent->_right))
						_current = _current->_parent;
					if (_current->_parent)
						_current = _current->_parent;
					else
						_current = NULL;
				}
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
				if (_current->_left != NULL)
				{
					_current = _current->_left;
					while(_current->_right != NULL)
						_current = _current->_right;
				}
				else
				{
					while (_current->_parent && (_current == _current->_parent->_left))
						_current = _current->_parent;
					if (_current->_parent)
						_current = _current->_parent;
					else
						_current = NULL;
				}
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


/************************** [ ITER NON MEMBER ] **************************/


	template<class Iterator1, class Iterator2>
	bool operator==(const ft::tree_iterator<Iterator1> &lhs, const ft::tree_iterator<Iterator2> &rhs)
	{ return (lhs.base() == rhs.base()); }

	template<class Iterator1, class Iterator2>
	bool operator!=(const ft::tree_iterator<Iterator1> &lhs, const ft::tree_iterator<Iterator2> &rhs)
	{ return (!(lhs.base() == rhs.base())); }


	template<class Iterator1, class Iterator2>
	bool operator==(const ft::const_tree_iterator<Iterator1> &lhs, const ft::const_tree_iterator<Iterator2> &rhs)
	{ return (lhs.base() == rhs.base()); }

	template<class Iterator1, class Iterator2>
	bool operator!=(const ft::const_tree_iterator<Iterator1> &lhs, const ft::const_tree_iterator<Iterator2> &rhs)
	{ return (!(lhs.base() == rhs.base())); }


}


#endif