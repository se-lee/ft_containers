#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template<class T>
	class vector_iterator
	{

		protected:
			pointer		_current_element;

		public:

//			typedef typename Iterator								iterator_type; //iterator_type is Vector
			typedef typename iterator_traits<T>::iterator_category	iterator_category;
			typedef typename iterator_traits<T>::value_type			value_type;
			typedef typename iterator_traits<T>::difference_type	difference_type;
			typedef typename iterator_traits<T>::pointer			pointer;
			typedef typename iterator_traits<T>::reference			reference;

	/* --- Constructors / Destructor --- */
			vector_iterator() {};
			vector_iterator(pointer ptr) { _current_element = ptr };
			explicit vector_iterator(iterator_type it);
			template <class Iterator>
			vector_iterator(const vector_iterator<Iterator> &vec_it) { _current_element = vec_it.base(); };
			~vector_iterator() {};

	/* --- Member functions --- */
		/* operator* : dereference iterator */
		reference operator*() const
		{ 
			return (*_current_element);
			// returns a rvalue reference to the element pointed by the iterator
		}

		/* operator+ : addition operator */
		vector_iterator	operator+(difference_type n) const
		{
			*this += n;
			return (*this);
		}

		/* operator++ : increment iterator position */
		vector_iterator	&operator++() //pre-increment
		{
			++_current_element;
			return (*this);
		}

		vector_iterator operator++(int) //post-increment
		{
			vector_iterator temp = *this;
			++_current_element;
			return (temp);
		}

		/* operator+= : advance iterator */
		vector_iterator &operator+=(difference_type	n)
		{
			
			return (*this);
		}

		/* operator- : subtraction operator */
		vector_iterator operator- (difference_type n) const
		{
			_current_element -= n;
			return (*this);
		}

		/* operator-- : decrement iterator position */
		vector_iterator &operator--()
		{
			_current_element--;
			return (*this);
		}

		vector_iterator operator--(int)
		{
			vector_iterator temp = *this;
			--(*this);
			return (temp);
		}

		/* operator-= : decrease iterator */
		vector_iterator &operator-= (difference_type n)
		{
			
			return (*this);
		}

		/* opeartor-> : dereference iterator */
		pointer	operator->() const
		{
			return ();
			// the operator return &**this ...?
		}

		/* operator[] : dereference iterator with offset */


	/* --- Relational operators --- */
		template <class Iterator1, class Iterator2>
		bool operator==(const vector_iterator<Iterator1> &lhs, const vector_iterator<Iterator2> &rhs)
		{ return (*lhs == *rhs); } // ? dereference? .base()? need to compare the value which is pointed by the iterator

		template <class Iterator1, class Iterator2>
		bool operator!=(const vector_iterator<Iterator1> &lhs, const vector_iterator<Iterator2> &rhs)
		{ return (*lhs != *rhs); }

		template <class Iterator1, class Iterator2>
		bool operator< (const vector_iterator<Iterator1> &lhs, const vector_iterator<Iterator2> &rhs)
		{ return (*lhs < *rhs); }

		template <class Iterator1, class Iterator2>
		bool operator<=(const vector_iterator<Iterator1> &lhs, const vector_iterator<Iterator2> &rhs);
		{ return (*lhs <= *rhs); }

		template <class Iterator1, class Iterator2>
		bool operator> (const vector_iterator<Iterator1> &lhs, const vector_iterator<Iterator2> &rhs);
		{ return (*lhs > *rhs); }

		template <class Iterator1, class Iterator2>
		bool operator>=(const vector_iterator<Iterator1> &lhs, const vector_iterator<Iterator2> &rhs);
		{ return (*lhs >= *rhs); }

	};
}

#endif