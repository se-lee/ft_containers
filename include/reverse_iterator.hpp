#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"


namespace ft
{
	template <class T>
	class reverse_iterator
	{
		protected:
			T			it;
			pointer		_current_element;

		public: 
			typedef  T 												iterator_type;
			typedef typename iterator_traits<T>::iterator_category	iterator_category;
			typedef typename iterator_traits<T>::value_type			value_type;
			typedef typename iterator_traits<T>::difference_type	difference_type;
			typedef typename iterator_traits<T>::pointer			pointer;
			typedef typename iterator_traits<T>::reference			reference;
		
		/* --- Constructors / Desctructor --- */	
			/* default */
			reverse_iterator() {};
			
			/* initialization */
			explicit reverse_iterator(iterator_type x) 
			{
				this->it = x;
			};

			/* copy */
			template <class U>
			reverse_iterator (const reverse_iterator<U> &rev_it) 
			{
				this->it = rev_it.it;
				return (*this);
			};

			~reverse_iterator() {};

		/* --- Member functions --- */
			/* base - the value that is pointed by the iterator */
			iterator_type base() const
			{
				return (*this->_current_element);
				/* returns a copy of base iterator, which iterates in the opposite direction */
			};

			/* operator* : dereference iterator */
			reference operator*() const 
			{
				return ();
				/* returns a reference to the element pointed by the iterator */
			};

			/* operator+ : addition operator */
			reverse_iterator operator+ (difference_type n) const // n - number of elements to offset
			{
				return ();
				/* returns an iterator pointing to the element n positions away */
			};

			/* operator++ : increment iterator position */
			reverse_iterator& operator++() // pre-increment version
			{
				return ();
				// the pre-increment version returns *this
			};

			reverse_iterator operator++(int) // post-increment version
			{
				return ();
				// the post-increment version returns the previous value of *this before the call
			};

			/* operator+= */
			/* operator- */
			/* operator-- */
			/* operator-= */
			/* operator-> */
			/* operator[] */

		/* --- non-member function overloads --- */
		/* relational operators */
		/* operator+ */
		/* operator- */

		protected:
			pointer		_current_element;

		private:

	};

}

#endif
