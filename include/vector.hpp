#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream> // 必要？
# include <memory> // allocator<T>

/* vectors are sequence containers that can change in size
their size can change dynamically, with their storage being handled automatically by the container
要素数にあわせて長さを変化させる
*/

namespace ft
{
	template <class T, class Alloc = std::allocator<T>> // アロケータ：メモリの管理を請け負うクラス；生のメモリーの確保と解放を行うライブラリ
	class vector
	{

		public:
			typedef	T						value_type;		// ;
			typedef	Alloc					allocator_type;	// std::allocator<value_type>
			typedef std::size_t				size_type;		// usually same as size_t
			typedef	std::ptrdiff_t			difference_type;
			typedef	T&						reference;
			typedef	const T&				const_reference;
			typedef	T*						pointer;
			typedef	const T*				const_pointer;
			typedef	iterator				iterator;
			typedef const iterator			const_interator;
			typedef	reverse_iterator		reverse_iterator;
			typedef const reverse_iterator	const_reverse_iterator;

/* Constructors */
	explicit vector (const allocator_type &alloc = allocator_type()); // Explicitをつけることで暗黙的型変換を防ぐ
	/* empty container constructor (default constructor)
		-- constructs an empty container, with no elements*/

	explicit vector (size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
	{
		this->_allocator = alloc;
		this->_ptr = this->_allocator.allocate(n); // is there any possibility of failing allocation?
		this->_size = n;
		this->_capacity = n;

		for (size_type i = 0; i < n; i++)
			this->_allocator.construct(this->_ptr + i, val);
	}
	/* fill constructor 
		-- constructs a container with n elements. Each element is a copy of val*/
	template <class InputIterator>
		vector	(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type())
		{
			
		}
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
		private:
			Alloc	_allocator;
			pointer	_ptr;
			size_t	_capacity;
			size_t	_size;

	};
}

#endif