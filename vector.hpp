#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <vector>

namespace ft
{



	template < typename T >
	class vecIter
	{
		public:
			typedef	T	value_type;
			typedef std::ptrdiff_t	difference_type;
			typedef T*	pointer;
			typedef const T* const_pointer;
			typedef	T&	reference;
			typedef const T&	const_reference;
		
		
	};

	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		private:

		public:
			typedef	T						value_type;
			typedef	Alloc					allocator_type;
			typedef std::size_t				size_type;
			typedef	std::ptrdiff_t			difference_type;
			typedef	T&						reference;
			typedef	const T&				const_reference;
			typedef	T*						pointer;
			typedef	const T*				const_pointer;
			typedef /*iterator*/			iterator;
			typedef const /*iterator*/		const_interator;
			typedef	/*rev iterator*/		reverse_iterator;
			typedef const /*rev iterator*/	const_reverse_iterator;

/******* Member functions *******/
/* Constructor */
		

/* Destructor */
/* Operator = */
/* assign */
/* get_allocator */

/* -- Element access -- */
/* at */
/* operator [] */
/* front */
/* back */
/* data */


/* -- Iterators --  */
/* begin */
/* end */
/* rbegin */
/* rend */


/* -- Capacity -- */
/* empty */
/* size */
/* max_size */
/* reserve */
/* capacity */


/* -- Modifiers -- */
/* clear */
/* insert */
/* erase */
/* push_back */
/* pop_back */
/* resize */
/* swap */
/* 
Non-member functions
operator==
operator!=
operator<
operator<=
operator>
operator>=

std::swap(std::vector)
 
 */



	};

}

/*
You also have to implement:
• iterators_traits
• reverse_iterator
• enable_if
Yes, it is C++11 but you will be able to implement it in a C++98 manner.
This is asked so you can discover SFINAE.
• is_integral
• equal and/or lexicographical_compare
• std::pair
• std::make_pair


*/

#endif