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
		tree_node(const T &pair = T()) : _parent(NULL), _left(NULL), _right(NULL), _value(pair) {}
	};

/************************** [ TREE ITER ] **************************/
	template<class T>
	class tree_iterator : public std::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			typedef T												iterator_type;
			typedef	typename iterator_traits<T>::value_type			value_type;
			typedef typename iterator_traits<T>::difference_type	difference_type;
			typedef typename iterator_traits<T>::pointer			pointer;
			typedef typename iterator_traits<T>::reference			reference;
			typedef typename iterator_traits<T>::iterator_category	iterator_category;

		private:
			typedef tree_node<value_type>*		node_pointer;
			node_pointer _current;

		public:
			tree_iterator() : _current(NULL) {}
			tree_iterator(node_pointer ptr) : _current(ptr) {}
		
			template<class Iter>
			tree_iterator(const tree_iterator<Iter> &other)
			{ _current = other.base(); }

			~tree_iterator() {}

			template<class Iter>
			tree_iterator &operator=(const tree_iterator<Iter> &other)
			{	
				_current = other.base();
				return (*this);
			}

			node_pointer base() const
			{ return (_current); }

			reference operator*() const
			{ return (_current->_value); }

			pointer operator->() const
			{ return (&(_current->_value)); }

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
	};

	template<class Iterator1, class Iterator2>
	bool operator==(const tree_iterator<Iterator1> &lhs, const tree_iterator<Iterator2> &rhs)
	{ return (lhs.base() == rhs.base()); }

	template<class Iterator1, class Iterator2>
	bool operator!=(const ft::tree_iterator<Iterator1> &lhs, const ft::tree_iterator<Iterator2> &rhs)
	{ return (!(lhs.base() == rhs.base())); }

/************************** [ TREE REVERSE ITER ] **************************/

	template<class Iterator>
	class tree_reverse_iterator
	{
		protected:
			Iterator	_current;
		
		public:
			typedef Iterator	iterator_type;
			typedef typename	iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename	iterator_traits<Iterator>::value_type			value_type;
			typedef typename	iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename	iterator_traits<Iterator>::pointer				pointer;
			typedef typename	iterator_traits<Iterator>::reference			reference;
		

			tree_reverse_iterator() {}
			explicit tree_reverse_iterator(iterator_type x) : _current(x) {}
			template <class U>
			tree_reverse_iterator(const tree_reverse_iterator<U> &other) : _current(other.base()) {}

			template <class U>
			tree_reverse_iterator &operator=(const ft::tree_reverse_iterator<U> &other)
			{
				_current = other.base();
				return (*this);
			}

			~tree_reverse_iterator() {}

			iterator_type base() const
			{ return (_current); }

			reference operator*() const
			{
				Iterator temp = _current;
				return (*temp);
			}

			pointer operator->() const
			{
				return (&(operator*()));
			}

			reference operator[] (difference_type n) const
			{ return (*(*this + n)); }

			tree_reverse_iterator &operator++()
			{
				--_current;
				return (*this);
			}
			
			tree_reverse_iterator &operator--()
			{
				++_current;
				return (*this);
			}

			tree_reverse_iterator operator++(int)
			{
				tree_reverse_iterator temp = *this;
				--_current;
				return (temp);
			}

			tree_reverse_iterator operator--(int)
			{
				tree_reverse_iterator temp = *this;
				++_current;
				return (temp);
			}

			tree_reverse_iterator operator+(difference_type n) const
			{ return (tree_reverse_iterator(_current - n)); }

			tree_reverse_iterator operator-(difference_type n) const
			{ return (tree_reverse_iterator(_current + n)); }

			tree_reverse_iterator &operator+=(difference_type n)
			{
				_current -= n;
				return (*this);
			}

			tree_reverse_iterator &operator-=(difference_type n )
			{
				_current += n;
				return (*this);
			};
	};

	template <class Iterator1, class Iterator2> 
	bool operator== (const ft::tree_reverse_iterator<Iterator1> &lhs, const ft::tree_reverse_iterator<Iterator2> &rhs)
	{ return (lhs.base() == rhs.base()); };

	template <class Iterator1, class Iterator2>
	bool operator!= (const ft::tree_reverse_iterator<Iterator1> &lhs, const ft::tree_reverse_iterator<Iterator2> &rhs)
	{ return (lhs.base() != rhs.base()); };

	template <class Iterator1, class Iterator2>
	bool operator< (const ft::tree_reverse_iterator<Iterator1> &lhs, const ft::tree_reverse_iterator<Iterator2> &rhs)
	{ return (lhs.base() < rhs.base()); };

	template <class Iterator1, class Iterator2>
	bool operator<= (const ft::tree_reverse_iterator<Iterator1> &lhs, const ft::tree_reverse_iterator<Iterator2> &rhs)
	{ return (lhs.base() <= rhs.base()); };

	template <class Iterator1, class Iterator2>
	bool operator> (const ft::tree_reverse_iterator<Iterator1> &lhs, const ft::tree_reverse_iterator<Iterator2> &rhs)
	{ return (lhs.base() > rhs.base()); };
	
	template <class Iterator1, class Iterator2>
	bool operator>= (const ft::tree_reverse_iterator<Iterator1> &lhs, const ft::tree_reverse_iterator<Iterator2> &rhs)
	{ return (lhs.base() >= rhs.base()); };

	template <class Iterator>
	tree_reverse_iterator<Iterator> operator+ (typename ft::tree_reverse_iterator<Iterator>::difference_type n, const ft::tree_reverse_iterator<Iterator> &it)
	{ return (it - n); };

	template <class Iterator>
	typename tree_reverse_iterator<Iterator>::difference_type operator- (const ft::tree_reverse_iterator<Iterator> &lhs, const ft::tree_reverse_iterator<Iterator> &rhs)
	{ return (lhs.base() - rhs.base()); };

}


#endif