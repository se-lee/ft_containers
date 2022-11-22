#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include "iterator_traits.hpp"

/* https://cplusplus.com/reference/iterator/BidirectionalIterator/ */

namespace	ft
{
	template<class T>
	class bidirectional_iterator : public std::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			typedef	typename std::iterator<ft::bidirectional_iterator_tag, T>::value_type		value_type;
			typedef typename std::iterator<ft::bidirectional_iterator_tag, T>::difference_type	difference_type;
			typedef typename std::iterator<ft::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef T*		pointer;
			typedef T&		reference;

		protected:
			pointer	_current;
		
	
		public:
			bidirectional_iterator() : _current(NULL) {}
			bidirectional_iterator(pointer ptr) : _current(ptr) {}
			bidirectional_iterator(const bidirectional_iterator &other) : _current(other._current) {}
			bidirectional_iterator &operator=(const bidirectional_iterator &other)
			{
				_current = other._current;
				return (*this);
			}
			~bidirectional_iterator() {}

			pointer base() const
			{ return (_current); }

			reference operator*() const
			{ return (*_current); }

			pointer operator->() const
			{ return (&(operator*())); }

			bidirectional_iterator &operator++()
			{
				++_current;
				return (*this);
			}

			bidirectional_iterator &operator--()
			{
				--_current;
				return (*this);
			}

			bidirectional_iterator operator++(int)
			{
				bidirectional_iterator temp = *this;
				++_current;
				return (temp);
			}

			bidirectional_iterator operator--(int)
			{
				bidirectional_iterator temp = *this;
				--_current;
				return (temp);
			}
	};

	template <class Iterator1, class Iterator2> 
	bool operator== (const ft::bidirectional_iterator<Iterator1> &lhs, const ft::bidirectional_iterator<Iterator2> &rhs)
	{ return (lhs.base() == rhs.base()); }

	template <class Iterator1, class Iterator2>
	bool operator!= (const ft::bidirectional_iterator<Iterator1> &lhs, const ft::bidirectional_iterator<Iterator2> &rhs)
	{ return (lhs.base() != rhs.base()); }

}

#endif