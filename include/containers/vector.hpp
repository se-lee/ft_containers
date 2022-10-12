#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory> // allocator<T>
# include "reverse_iterator.hpp"
# include "vector_iterator.hpp"
# include "sfinae.hpp"
# include "algorithm.hpp"

/* vectors are sequence containers that can change in size
their size can change dynamically, with their storage being handled automatically by the container
要素数にあわせて長さを変化させる
*/

namespace ft
{
	template <class T, class Alloc = std::allocator<T> > // アロケータ：メモリの管理を請け負うクラス；生のメモリーの確保と解放を行うライブラリ
	class vector
	{
		public:
			typedef	T										value_type;
			typedef	Alloc									allocator_type;	// std::allocator<value_type>
			typedef std::size_t								size_type;		// usually same as size_t
			typedef	std::ptrdiff_t							difference_type;
			typedef	T&										reference;
			typedef	const T&								const_reference;
			typedef	T*										pointer;
			typedef	const T*								const_pointer;
			typedef	ft::vector_iterator<pointer>			iterator;	// あとで直す
			typedef ft::vector_iterator<const_pointer>		const_iterator;
			typedef	ft::reverse_iterator<T>					reverse_iterator;
			typedef const ft::reverse_iterator<T>			const_reverse_iterator; // constどうする

/* Constructors */
	/* empty container constructor (default constructor) -- constructs an empty container, with no elements*/
	explicit vector (const allocator_type &alloc = allocator_type()) 
	{
		_allocator = alloc;
		_ptr = NULL;
		_capacity = 0;
		_size = 0;
	}; // Explicitをつけることで暗黙的型変換を防ぐ

	/* fill constructor -- constructs a container with n elements. Each element is a copy of val*/
	explicit vector (size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
	{
		_allocator = alloc;
		_ptr = _allocator.allocate(n); // is there any possibility of failing allocation?
		_capacity = n;
		_size = n;

		if (n > 0)
		{
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(_ptr + i, val);
		}
		
	};

	/* range constructor 
	-- constructs a container with as many elements as the range [first, last), with each element constructed from its corresponding element in that range, in the same order 
	1,2,3,4,5 だったら同じ順番で同じValueをいれる */
	template <class InputIterator>
	vector	(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = NULL)
	{
		std::cout << "range constructor called" << std::endl;
		size_type	range_size = last - first;
		_allocator = alloc;
		_ptr = _allocator.allocate(range_size);
		_capacity = range_size;
		_size = range_size;

		for (size_type i = 0; i < range_size; i++)
		{
			_allocator.construct(_ptr + i, first);
			first++;
		}
	};

	/* copy constructor -- constructs a container with a copy of each of the elements in x, in the same order */
	vector (const vector &x)
	{
		_allocator = x._allocator;
		_ptr = _allocator.allocate(x._capacity);
		_capacity = x._capacity;
		_size = x._size;

		if (_size > 0)
		{
			for(size_type i = 0; i < x._size; i++)
				_allocator.construct(_ptr + i, x[i]);
		}
	};

/* Destructor */
	~vector()
	{
		if (_size > 0)
		{
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(_ptr + i);
		}
		if (_capacity > 0)
			_allocator.deallocate(_ptr, _capacity);
		_size = 0;
		_capacity = 0;
	};


/* Operator = */
	/* assign content - assigns new contents to the container, replacing its current contents, and modifying its size accordingly */
	/* copies all the elements from x into the container.
		the container preserves its current allocator, which is used to allocate storage in case of reallocation */
	
	vector	&operator= (const vector &x)
	{
		for (iterator ite(x.begin()); ite != x.end(); ite++)
			push_back(ite.base());
		return (*this);
	};


/* --- Iterators ---  */
/* begin : returns an iterator to the beginning of a container or array*/
	iterator begin()
	{ return (iterator(_ptr)); };

	const_iterator begin() const
	{ return (const_iterator(_ptr)); };

/* end : returns a const_iterator if the vector obeject is const-qualified */
	iterator end()
	{
		_ptr + size();
		return (iterator(_ptr));
	};

	const_iterator end() const
	{
		_ptr + size();
		return (const_iterator(_ptr));
	};

/* rbegin */
	reverse_iterator rbegin()
	{ return (reverse_iterator(end())); };

	const_reverse_iterator rbegin() const
	{ return (const_reverse_iterator(end())); };


// /* rend */
	reverse_iterator rend()
	{ return (reverse_iterator(begin())); };

	const_reverse_iterator rend() const
	{ return (const_reverse_iterator(begin())); };


/* --- Capacity --- */
/* size : Returns the number of elements in the container, i.e. std::distance(begin(), end()). */
	size_type size() const
	{ return (_size); };


/* max_size */
/*
https://en.cppreference.com/w/cpp/container/vector/max_size
Returns the maximum number of elements the container is able to hold due to system or library 
implementation limitations, i.e. std::distance(begin(), end()) for the largest container. 
*/
	size_type max_size() const
	{ return (_allocator.max_size()); };

/* resize */
/* 
resizes the container to contain [count] elements 
if the current size is greater than [count], the container is reduced to its first [count] elements
if the current size is less than [count], 
	1) additional default-inserted elements are appended
	2) additional copies of [value] are appended

[count] : new size of the container
[value] : the value to initialize the new elements with
https://en.cppreference.com/w/cpp/container/vector/resize

*/
	void resize(size_type count)
	{
		if (_size > count)
		{
			
			// 最初の Count個分だけ残して、あとはすべて消す (allocator/destroy) - capacityはそのまま残る
			
		}
		else // _size < count
		{
			// 既存の数からCount分までを初期値で足す（後ろにつける）
			_ptr + _size = _allocator.allocate(count - _size);
			
			if (_capacity < count)
				_capacity = count;
		}
	};
	void resize(size_type count, const value_type = T() );
	void resize(size_type count, const value_type& value);

/* capacity :capacity of the currently allocated storage
https://en.cppreference.com/w/cpp/container/vector/capacity
 */

	size_type capacity() const
	{ return (_capacity); };

/* empty : [true] if the container is empty, [false] if not empty
https://en.cppreference.com/w/cpp/container/vector/empty
*/
	bool empty() const
	{ return (_size == 0); };

// /* reserve */
// /*
// https://en.cppreference.com/w/cpp/container/vector/reserve

// increase the capacity of the vector (the total number of elements that the vector cann hold without requiring reallocation)
// to a value that's greater or equal to new_cap. if new_cap is greater than the current capacity(), new storage is allocated,
// otherwise the function does nothing

// reserve() does not change size of the vector
// if new_cap is greater than capacity(), all iterators, including the past-the-end iterator,
// and all references to the elements are invalidated.
// Otherwise, no iterator or references are invalidated

// [new_cap] : new capacity of the vector, in number of elements

// */

// 	void reserve(size_type new_cap);


// /* --- Element access --- */
// /* operator [] */
// /*
// https://en.cppreference.com/w/cpp/container/vector/operator_at

// [pos] : position of the element to return
// */

	reference operator[] (size_type pos)
	{
		return (_ptr[pos]);
	};

	const_reference operator [] (size_type pos) const
	{
		return (_ptr[pos]);
	};

// /* at */
// /*
// https://en.cppreference.com/w/cpp/container/vector/at

// returns a reference to the element at specified location [pos], with boounds checking.
// if [pos] is not within the range of the container, an exception of type std::out_of_range is thrown

// [pos] : position of the element to return
// */

// 	reference at(size_type pos)
// 	{
// 		return (/* reference to the requested element */);
// 	}
// 	const_reference at(size_type pos) const;


// /* front */
// /*
// https://en.cppreference.com/w/cpp/container/vector/front

// returns a reference to the first element in the container
// calling front on an empty container is undefined

// */

// 	reference front()
// 	{
// 		return (/* reference to the first element */);
// 	}
// 	const_reference front( ) const;


// /* back */
// /*
// https://en.cppreference.com/w/cpp/container/vector/back

// returns a  reference to the last element in the container
// calling back on an empty container causes undefined behavior
// */

// 	reference back()
// 	{
// 		return (/* reference to the last element */);
// 	}

// 	const_reference back() const;



// /* data */
// /*
// https://en.cppreference.com/w/cpp/container/vector/data

// returns pointer to the underlying array serving as element storage.
// the pointer is such that range[data(); data() + size()] is always a valid range,
// even if the container is empty (data() is not dereferenceable in that case)

// */

// 	T* data()
// 	{
// 		return (/* pointer to the underlying element storage*/);
// 	}

// 	const T* data() const;


/* --- Modifiers --- */
/* assign */


/* push_back */
/*
https://en.cppreference.com/w/cpp/container/vector/push_back
Appends the given element value to the end of the container

*/
	void	push_back(const T& value)
	{
		_allocator.construct(&(_ptr[_size]), value);
		_size++;
	};

/* pop_back */
	void	pop_back()
	{
		_allocator.destroy(end() - 1);
		_size--;
	};

/* insert */
	iterator insert (iterator poisiton, const value_type &val);
	void	insert (iterator position, size_type n, const value_type &val);

	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last);

/* erase */
/* swap */
/* clear */


		private:
			Alloc		_allocator;
			pointer		_ptr;
			size_type	_capacity;
			size_type	_size;

/* --- Allocator --- */
/* get_allocator */
	allocator_type get_allocator() const
	{
		return (_allocator);
	};

	/***あとで消す***/
	pointer		get_ptr()
	{ return (_ptr); };
	/****/

	};

/* --- Non-member function overloads --- */
/* operator== */
	template<class T, class Alloc>
	bool operator== (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{ return (*lhs == *rhs); };

/* operator!= */
	template<class T, class Alloc>
	bool operator!= (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{ return (lhs != rhs); };

/* operator< */
	template<class T, class Alloc>
	bool operator< (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{ return (lhs < rhs); };

/* operator<= */
	template<class T, class Alloc>
	bool operator<= (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{ return (lhs <= rhs); };

/* operator> */
	template<class T, class Alloc>
	bool operator> (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{ return (lhs > rhs); };
/* operator>= */
	template<class T, class Alloc>
	bool operator>= (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{ return (lhs >= rhs); };

/* std::swap(std::vector) */

}

#endif