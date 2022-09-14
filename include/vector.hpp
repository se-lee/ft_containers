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
	/* empty container constructor (default constructor)
		-- constructs an empty container, with no elements*/
	explicit vector (const allocator_type &alloc = allocator_type()); // Explicitをつけることで暗黙的型変換を防ぐ

	/* fill constructor 
		-- constructs a container with n elements. Each element is a copy of val*/
	explicit vector (size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
	{
		this->_allocator = alloc;
		this->_ptr = this->_allocator.allocate(n); // is there any possibility of failing allocation?
		this->_capacity = n;
		this->_size = n;

		if (this->_size > 0)
		{
			for (size_type i = 0; i < this->_size; i++)
				this->_allocator.construct(this->_ptr + i, val);
		}
	}

	/* range constructor 
		-- constructs a container with as many elements as the range [first, last), with each element constructed from its corresponding element in that range, in the same order 
			1,2,3,4,5 だったら同じ順番で同じValueをいれる
	*/
	template <class InputIterator>
		vector	(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type())
		{
			size_type	range_size = std::distance(first, last);
			this->_allocator = alloc;
			this->_ptr = this->_allocator.allocate(range_size);
			this->_capacity = range_size;
			this->_size = range_size;

			/*
			first からひとつずつずらして？値を入れる。どうやって？ぽいんた？
			*/

		}

	/* copy constructor
		-- constructs a container with a copy of each of the elements in x, in the same order */
	vector (const vector &x)
	{
		this->_allocator = x._allocator;
		this->_ptr = this->_allocator.allocate(x._capacity);
		this->_capacity = x._capacity;
		this->_size = x._size;

		if (this->_size > 0)
		{
			for(size_type i = 0; i < x._size; i++)
				this->_allocator.construct(this->_ptr + i, x[i];)
		}
	}
	/* the container keeps an internal copy of alloc, which is used to allocate storage throughout its lifetime. */
	/* the copy constructor creates a container that keeps and uses a copy of x's allocator */


/* Destructor */
	~vector()
	{
		if (this->_size > 0)
		{
			for (size_type i = 0; i < this->_size; i++)
				this->_allocator.destroy(_ptr + i);
		}
		if (this->_capacity > 0)
			this->_allocator.deallocate(this->_ptr, this->_capacity);
		this->_size = 0;
		this->_capacity = 0;
	}


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
			Alloc		_allocator;
			pointer		_ptr;
			size_type	_capacity;
			size_type	_size;
	};
}

#endif