#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory> // allocator<T>
# include "../utils/reverse_iterator.hpp"
# include "../utils/random_access_iterator.hpp"
# include "../utils/sfinae.hpp"
# include "../utils/algorithm.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> > // アロケータ：メモリの管理を請け負うクラス；生のメモリーの確保と解放を行うライブラリ
	class vector
	{
		public:
			typedef	T											value_type;
			typedef	Alloc										allocator_type;
			typedef std::size_t									size_type;
			typedef	std::ptrdiff_t								difference_type;
			typedef	T&											reference;
			typedef	const T&									const_reference;
			typedef	T*											pointer;
			typedef	const T*									const_pointer;
			typedef	typename ft::random_access_iterator<T>				iterator;
			typedef typename ft::random_access_iterator<const T>			const_iterator;
			typedef	typename ft::reverse_iterator<iterator>						reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;

		private:
			allocator_type		_allocator;
			pointer				_first;
			pointer				_last;
			pointer				_capacity_last;

	public:
/* [Constructors] */
/* empty container constructor (default constructor) */
	explicit vector (const allocator_type &alloc = allocator_type()) : _allocator(alloc), _first(NULL), _last(NULL), _capacity_last(NULL) {}

/* fill constructor */
	explicit vector (size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
	{
		_allocator = alloc;
		_first = _allocator.allocate(n);
		_last = _first + n;
		_capacity_last = _last;

		if (n > 0)
		{
			for (size_type i = 0; i < n; i++)
				_allocator.construct(_first + i, val);
		}
	}

/* range constructor */
	template <class InputIterator>
	vector	(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = NULL)
	: _allocator(alloc), _first(first), _last(last), _capacity_last(last)
	{
		std::cout << "range constructor called" << std::endl;
		size_type	range_size = last - first;
		_first = _allocator.allocate(range_size);

		for (size_type i = 0; i < range_size; ++i, ++first)
			_allocator.construct(_first + i, first);
	}

/* copy constructor */
	vector (const vector &x)
	{
		_allocator = x._allocator;
		_first = _allocator.allocate(x.capacity());
	
		if (x.size() > 0)
		{
			for(size_type i = 0; i < x.size(); i++)
				_allocator.construct(_first + i, x[i]);
		}
	}

/* Destructor */
	~vector()
	{
		if (size() > 0)
		{
			for (size_type i = 0; i < size(); i++)
				_allocator.destroy(_first + i);
		}
		if (capacity() > 0)
			_allocator.deallocate(_first, capacity());
	}

/* Operator = */
	/* assign content - assigns new contents to the container, replacing its current contents, and modifying its size accordingly */
	/* copies all the elements from x into the container.
		the container preserves its current allocator, which is used to allocate storage in case of reallocation */
	
	vector	&operator= (const vector &x)
	{
		for (iterator ite(x.begin()); ite != x.end(); ite++)
			push_back(ite.base());
		return (*this);
	}

/* --- Iterators ---  */
/* begin : returns an iterator to the beginning of a container or array*/
	iterator begin()
	{ return (_first); }

	const_iterator begin() const
	{ return (_first); }

/* end : returns a const_iterator if the vector obeject is const-qualified */
	iterator end()
	{ return (_last); }

	const_iterator end() const
	{ return (_last); }

/* rbegin */
	reverse_iterator rbegin()
	{ return (reverse_iterator(end())); }

	const_reverse_iterator rbegin() const
	{ return (const_reverse_iterator(end())); }


// /* rend */
	reverse_iterator rend()
	{ return (reverse_iterator(begin())); }

	const_reverse_iterator rend() const
	{ return (const_reverse_iterator(begin())); }


/* --- Capacity --- */
/* size : number of elements in the container */
	size_type size() const
	{ return (end() - begin()); }


/* max_size : the maximum number of elements the container is able to hold due to system or library 
implementation limitations */
	size_type max_size() const
	{ return (_allocator.max_size()); }

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
		if (size() > count)
		{
			size_type diff = size() - count;
			for (size_type i = 0; i < diff; i++)
				_allocator.destroy(_first + count + i);
			_last = _first + count;
			std::cout << "resized size: " << size() << std::endl;
		}
		else if (size() < count)
		{
			// 既存の数からCount分までを初期値で足す（後ろにつける）
			size_type diff = count - size();
			_last = _allocator.allocate(diff);
			_last = _last + diff;
			// _capacity_last =  + count;
		}
	}
	// void resize(size_type count, const value_type = T() );
	// void resize(size_type count, const value_type& value);

/* capacity :capacity of the currently allocated storage */

	size_type capacity() const
	{ return (_capacity_last - _first); }

/* empty : [true] if the container is empty, [false] if not empty */
	bool empty() const
	{ return (begin() == end()); }

/* reserve : increase the capacity of the vector*/
	void reserve(size_type new_cap)
	{
		if (capacity() >= new_cap)
			return ;
		pointer new_alloc = _allocator.allocate(new_cap);
		pointer temp_first = _first;
		pointer temp_last = _last;
		size_type temp_capacity = capacity();

		_first = new_alloc;
		_last = _first;
		_capacity_last = _first + new_cap;

		//copy old data
		for (pointer iter = temp_first; iter != temp_last; iter++, _last++)
			_allocator.construct(_last, *iter);
	
		//destroy & deallocate old data
		for (pointer iter = temp_first; iter != temp_last; iter++)
			_allocator.destroy(iter);
		_allocator.deallocate(temp_first, temp_capacity);
	}

/* --- Element access --- */
/* operator [] */

	reference operator[] (size_type pos)
	{ return (_first[pos]); }

	const_reference operator [] (size_type pos) const
	{ return (_first[pos]); }

/* at :returns a reference to the element at specified location [pos] */

	reference at(size_type pos)
	{ return (_first[pos]); }

	const_reference at(size_type pos) const
	{ return (_first[pos]); }


/* front : returns a reference to the first element in the container */
	reference front()
	{ return (*_first); }

	const_reference front( ) const
	{ return (*_first); }


/* back : returns a  reference to the last element in the container */
	reference back()
	{ return (*(_last - 1)); }

	const_reference back() const
	{ return (*(_last - 1)); }

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
		_allocator.construct(end(), value); 
		_last++;
	}

/* pop_back */
	void	pop_back()
	{ 
		_allocator.destroy(_last - 1); 
		_last--;
	}

/* insert */
	iterator insert (iterator poisiton, const value_type &val);
	void	insert (iterator position, size_type n, const value_type &val);

	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last);

/* erase */


/* swap */


/* clear */


/* --- Allocator --- */
/* get_allocator */
	allocator_type get_allocator() const
	{ return (_allocator); }

	};

/* --- Non-member function overloads --- */
/* operator== */
	template<class T, class Alloc>
	bool operator== (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{ 
		return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin())); 
	}

/* operator!= */
	template<class T, class Alloc>
	bool operator!= (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{ return (!(lhs == rhs)); }

/* operator< */
	template<class T, class Alloc>
	bool operator< (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{ 
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); 
	}

/* operator<= */
	template<class T, class Alloc>
	bool operator<= (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{ 
		return (!(lhs > rhs)); 
	}

/* operator> */
	template<class T, class Alloc>
	bool operator> (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{ 
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

/* operator>= */
	template<class T, class Alloc>
	bool operator>= (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{ 
		//!(x < y)
		return (!(lhs < rhs));
	}

/* std::swap(std::vector) */

}

#endif