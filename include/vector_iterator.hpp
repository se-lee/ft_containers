#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template<typename Vector>
	class vector_iterator
	{
		public:

//			typedef typename Iterator										iterator_type; //iterator_type is will be Vector
			typedef typename iterator_traits<Vector>::iterator_category	iterator_category;
			typedef typename iterator_traits<Vector>::value_type		value_type;
			typedef typename iterator_traits<Vector>::difference_type	difference_type;
			typedef typename iterator_traits<Vector>::pointer			pointer;
			typedef typename iterator_traits<Vector>::reference			reference;

	/* --- Constructors / Destructor --- */
			vector_iterator();
			explicit vector_iterator(iterator_type it);
			template <class Iterator>
			vector_iterator(const vector_iterator<Iterator> &vec_it);
			~vector_iterator();
		
		
	/* --- Member functions --- */
		/* base  */
		/* operator* : dereference iterator */
		reference operator*() const
		{
			return ();
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
			(*this)++;
			return (*this);
		}

		vector_iterator operator++(int) //post-increment
		{
			vector_iterator temp = *this;
			++(*this);
			return (temp);
		}


		/* operator+= : advance iterator */
		vector_iterator &operator+=(difference_type	n)
		{
			return (*this);
		}

		/* operator- : subtraction operator */

		/* operator-- : decrement iterator position */

		/* operator-= : derease iterator */

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

		private:


	};

}

#endif