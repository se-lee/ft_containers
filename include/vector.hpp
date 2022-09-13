#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory> // allocator<T>

/* vectors are sequence containers that can change in size
their size can change dynamically, with their storage being handled automatically by the container
*/

namespace ft
{
	template <class T, class Alloc = std::allocator<T>>
	class vector
	{
		private:
			Alloc	_allocator;
			int		_capacity;
			int		_size;

		public:
			typedef	T						value_type;
			typedef	Alloc					allocator_type;
			typedef std::size_t				size_type;
			typedef	std::ptrdiff_t			difference_type;
			typedef	T&						reference;
			typedef	const T&				const_reference;
			typedef	T*						pointer;
			typedef	const T*				const_pointer;
			typedef	iterator				iterator;
			typedef const iterator			const_interator;
			typedef	reverse_iterator		reverse_iterator;
			typedef const reverse_iterator	const_reverse_iterator;

/******* Member functions *******/
/*  parameters:
		alloc - allocator object; the container keeps and uses and internal copy of this allocator;
			member type [allocator_type] is the internal allocator type used by the container, defined in vector as an alias of its second template parameter(Alloc).

		n - initial container size(ie. the number of elements in the container at construction).
			member type [size_type] is and unsigned integral type
		
		val - value to fill the container with. Each of the n elements in the container will be initialized to a copy of this value.
			member type [value_type] is the type of elements in the container, defined in vector as an alias of its first template parameter(T).
			
		first, last - input iterators to the initial and final positions in a range.
			the range used is [first, last), which includes all the lements between first and last, including the element pointed by first but not the element pointed by last.
			the function template argument InputIterator shall be an input iterator type that points to elements of a type from which value_type objects can be constructed

		x - another vector object of the same type (with the same class template arguments T and Alloc), whose contents are either copied or acquired

		il - an initializer_list object;
			these objects are automatically constructed from initializer list declarators.
			membe type value_type is the type of the elements in the container, defined in vector as an alias of its first template parameter(T).
*/

/* Constructors */
	explicit vector (const allocator_type &alloc = allocator_type());
	/* empty container constructor (default constructor)
		-- constructs an empty container, with no elements*/

	explicit vector (size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()
	{
		// allocate memory
		this->_allocator = alloc;
		this->_size = n;
		this->_capacity = n;
	}
	/* fill constructor 
		-- constructs a container with n elements. Each element is a copy of val*/



	template <class InputIterator>
		vector	(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type());
	/* range constructor 
		-- constructs a container with as many elements as the range [first, last), with each element constructed from its corresponding element in that range, in the same order */

	vector (const vector &x);
	/* copy constructor
		-- constructs a container with a copy of each of the elements in x, in the same order */

	/* the container keeps an internal copy of alloc, which is used to allocate storage throughout its lifetime. */
	/* the copy constructor creates a container that keeps and uses a copy of x's allocator */



/* Destructor */
	~vector();

/* Operator = */
	/* assign content - assigns new contents to the container, replacing its current contents, and modifying its size accordingly */
	
	vector	&operator= (const vector &x);
	/* copies all the elements from x into the container.
		the container preserves its current allocator, which is used to allocate storage in case of reallocation */

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

#endif