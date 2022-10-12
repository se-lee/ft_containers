#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template<class Iterator>
	class vector_iterator
	{

		public:

			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;

	/* --- Constructors / Destructor --- */
			vector_iterator() {};
			vector_iterator(pointer ptr) 
			{ 
				_current_element = ptr; 
			};
			explicit vector_iterator(iterator_type it);
			template <class U>
			vector_iterator(const vector_iterator<U> &vec_it) 
			{ 
				_current_element = vec_it.base(); 
			};
			~vector_iterator() {};

	/* --- Member functions --- */
		/* operator* : dereference iterator */
		reference operator*() const
		{ 
			return (*_current_element);
			// returns a rvalue reference to the element pointed by the iterator
		};

		/* operator+ : addition operator */
		vector_iterator	operator+(difference_type n) const
		{
			*this += n;
			return (*this);
		};

		/* operator++ : increment iterator position */
		vector_iterator	&operator++() //pre-increment
		{
			++_current_element;
			return (*this);
		};

		vector_iterator operator++(int) //post-increment
		{
			vector_iterator temp = *this;
			++_current_element;
			return (temp);
		};

		/* operator+= : advance iterator */
		// vector_iterator &operator+=(difference_type	n)
		// {
		// 	return (*this);
		// };

		/* operator- : subtraction operator */
		vector_iterator operator- (difference_type n) const
		{
			_current_element -= n;
			return (*this);
		};

		/* operator-- : decrement iterator position */
		vector_iterator &operator--()
		{
			_current_element--;
			return (*this);
		};

		vector_iterator operator--(int)
		{
			vector_iterator temp = *this;
			--(*this);
			return (temp);
		};

		/* operator-= : decrease iterator */
		// vector_iterator &operator-= (difference_type n)
		// {
			
		// 	return (*this);
		// };

		/* opeartor-> : dereference iterator */
		pointer	operator->() const
		{
			return (this->_ptr);
			// the operator return &**this ...?
		};

		/* operator[] : dereference iterator with offset */
		protected:
			pointer		_current_element;
	};

	/* --- Relational operators --- */
		template <class Iterator>
		bool operator==(const vector_iterator<Iterator> &lhs, const vector_iterator<Iterator> &rhs)
		{ return (lhs == rhs); }; // ? dereference? .base()? need to compare the value which is pointed by the iterator

		template <class Iterator>
		bool operator!=(const vector_iterator<Iterator> &lhs, const vector_iterator<Iterator> &rhs)
		{ return (lhs != rhs); };

		template <class Iterator>
		bool operator< (const vector_iterator<Iterator> &lhs, const vector_iterator<Iterator> &rhs)
		{ return (lhs < rhs); };

		template <class Iterator>
		bool operator<=(const vector_iterator<Iterator> &lhs, const vector_iterator<Iterator> &rhs)
		{ return (lhs <= rhs); };

		template <class Iterator>
		bool operator> (const vector_iterator<Iterator> &lhs, const vector_iterator<Iterator> &rhs)
		{ return (lhs > rhs); };

		template <class Iterator>
		bool operator>=(const vector_iterator<Iterator> &lhs, const vector_iterator<Iterator> &rhs)
		{ return (lhs >= rhs); };
}

#endif