#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{
	template<class T>
	class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
	{
		protected:
			T*	_current;
		
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type; 
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef T*	pointer;
			typedef T&	reference;

			random_access_iterator() : _current(NULL) {}
			random_access_iterator(pointer ptr) : _current(ptr) {}
			explicit random_access_iterator(const random_access_iterator &other) : _current(other._current) {}
			random_access_iterator &operator=(const random_access_iterator &other) 
			{
				if (this == &other)
					return (*this);
				_current = other._current;
				return (*this);
			}
			~random_access_iterator() {} 

			pointer	base() const 
			{ return (_current); }
			
			reference operator*() const
			{ return (*_current); }

			pointer operator->() const
			{ return (&(operator*())); }

			reference operator[] (difference_type n) const
			{ return (*(*this + n)); }

			random_access_iterator	&operator++() 
			{
				++_current;
				return (*this);
			}

			random_access_iterator &operator--()
			{
				--_current;
				return (*this);
			}

			random_access_iterator operator++(int)
			{
				random_access_iterator temp = *this;
				++_current;
				return (temp);
			}

			random_access_iterator operator--(int)
			{
				random_access_iterator temp = *this;
				--_current;
				return (*this);
			}

			random_access_iterator operator+(difference_type n) const
			{
				return (random_access_iterator(_current + n));
			}

			random_access_iterator operator-(difference_type n) const
			{
				return (random_access_iterator(_current - n));
			}

			random_access_iterator &operator+=(difference_type n) const
			{
				_current += n;
				return (*this);
			}

			random_access_iterator &operator-=(difference_type n) const
			{
				_current -= n;
				return (*this);
			}
	};

	template <class Iterator1, class Iterator2> 
	bool operator== (const ft::random_access_iterator<Iterator1> &lhs, const ft::random_access_iterator<Iterator2> &rhs)
	{ return (lhs.base() == rhs.base()); }

	template <class Iterator1, class Iterator2>
	bool operator!= (const ft::random_access_iterator<Iterator1> &lhs, const ft::random_access_iterator<Iterator2> &rhs)
	{ return (lhs != rhs); }

	template <class Iterator1, class Iterator2>
	bool operator< (const ft::random_access_iterator<Iterator1> &lhs, const ft::random_access_iterator<Iterator2> &rhs)
	{ return (lhs < rhs); }

	template <class Iterator1, class Iterator2>
	bool operator<= (const ft::random_access_iterator<Iterator1> &lhs, const ft::random_access_iterator<Iterator2> &rhs)
	{ return (lhs <= rhs); }

	template <class Iterator1, class Iterator2>
	bool operator> (const ft::random_access_iterator<Iterator1> &lhs, const ft::random_access_iterator<Iterator2> &rhs)
	{ return (lhs > rhs); }
	
	template <class Iterator1, class Iterator2>
	bool operator>= (const ft::random_access_iterator<Iterator1> &lhs, const ft::random_access_iterator<Iterator2> &rhs)
	{ return (lhs >= rhs); }

	/* operator+ */
	template <class Iterator>
	ft::random_access_iterator<Iterator> operator+ (
		typename ft::random_access_iterator<Iterator>::difference_type n, 
		const ft::random_access_iterator<Iterator> &it)
	{ return (ft::random_access_iterator<Iterator>(it.base() + n)); }

	/* operator- */
	template <class Iterator>
	typename ft::random_access_iterator<Iterator>::difference_type operator- (
		const ft::random_access_iterator<Iterator> &lhs, 
		const ft::random_access_iterator<Iterator> &rhs)
	{ return (lhs.base() - rhs.base()); }



}




#endif