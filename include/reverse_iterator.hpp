#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <iostream>
# include "iterator_traits.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
	
		public: 

			typedef Iterator 										iterator_type;
			typedef iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef iterator_traits<Iterator>::value_type			value_type;
			typedef iterator_traits<Iterator>::difference_type		difference_type;
			typedef iterator_traits<Iterator>::pointer				pointer;
			typedef iterator_traits<Iterator>::reference			reference;
		
		/* --- Constructors / Desctructor --- */	
			/* default */
			reverse_iterator();
			
			/* initialization */
			explicit reverse_iterator(iterator_type it);

			/* copy */
			template <class Iterator>
			reverse_iterator (const reverse_iterator<Iterator> &rev_it);

			~reverse_iterator();

		/* --- Member functions --- */
			/* base - the value that is pointed by the iterator */
			iterator_type base() const
			{
				return ();
				/* returns a copy of base iterator, which iterates in the opposite direction */
			}

			/* operator* : dereference iterator */
			reference operator*() const 
			{
				return ();
				/* returns a reference to the element pointed by the iterator */
			}

			/* operator+ : addition operator */
			reverse_iterator operator+ (difference_type n) const // n - number of elements to offset
			{
				return ();
				/* returns an iterator pointing to the element n positions away */
			}

			/* operator++ : increment iterator position */
			reverse_iterator& operator++() // pre-increment version
			{
				return ();
				// the pre-increment version returns *this
			}

			reverse_iterator operator++(int) // post-increment version
			{
				return ();
				// the post-increment version returns the previous value of *this before the call
			}

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

		private:

	};

}

#endif
