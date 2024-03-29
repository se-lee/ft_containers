#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <algorithm>
# include <iterator>
# include "reverse_iterator.hpp"
# include "vector_iterator.hpp"
# include "sfinae.hpp"
# include "algorithm.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef	T													value_type;
			typedef	Allocator											allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef vector_iterator<pointer>							iterator;
			typedef vector_iterator<const_pointer>						const_iterator;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>				const_reverse_iterator;
			typedef typename std::ptrdiff_t								difference_type;
			typedef std::size_t											size_type;

		protected:
			allocator_type		_allocator;
			pointer				_begin;
			pointer				_end;
			pointer				_capacity_end;
		
		public:
	/* --- [ Constructors ] --- */
	/* empty container constructor (default constructor) */
		explicit vector (const allocator_type &alloc = allocator_type()) 
		{
			_allocator = alloc;
			_begin = NULL;
			_end = NULL;
			_capacity_end = NULL;
		}

	/* fill constructor */
		explicit vector (size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
		{
			_allocator = alloc;
			_begin = _allocator.allocate(n);
			_end = _begin + n;
			_capacity_end = _end;

			if (n > 0)
			{
				for (size_type i = 0; i < n; i++)
					_allocator.construct(_begin + i, val);
			}
		}

	/* range constructor */
		template <class InputIterator>
		vector	(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		: _allocator(alloc)
		{
			size_type	range_size = last - first;
			_begin = _allocator.allocate(range_size);
			_end = _begin + range_size;
			_capacity_end = _end;

			for (size_type i = 0; i < range_size; ++i, ++first)
				_allocator.construct(&_begin[i], *first);
		}

	/* copy constructor */
		vector (const vector &x)
		{
			_allocator = x._allocator;
			_begin = _allocator.allocate(x.size());
			_end = _begin + x.size();
			_capacity_end = _begin + x.size();
		
			if (x.size() > 0)
			{
				for(size_type i = 0; i < x.size(); i++)
					_allocator.construct(&_begin[i], x[i]);
			}
		}

	/* --- [ Destructor ] --- */
		~vector()
		{
			if (size() > 0)
			{
				for (size_type i = 0; i < size(); i++)
					_allocator.destroy(_begin + i);
			}
			if (capacity() > 0)
				_allocator.deallocate(_begin, capacity());
		}

	/* Operator = */
		/* assign content - assigns new contents to the container, replacing its current contents, and modifying its size accordingly */
		vector	&operator= (const vector &x)
		{
			_allocator = x._allocator;
			reserve(x.capacity());
			assign(x.begin(), x.end());

			return (*this);
		}

	/* --- [ Iterators ] ---  */
		iterator begin()
		{ return (iterator(_begin)); }

		const_iterator begin() const
		{ return (const_iterator(_begin)); }

		iterator end()
		{ return (iterator(_end)); }

		const_iterator end() const
		{ return (const_iterator( _end)); }

		reverse_iterator rbegin()
		{ return (reverse_iterator(end())); }

		const_reverse_iterator rbegin() const
		{ return (const_reverse_iterator(end())); }

		reverse_iterator rend()
		{ return (reverse_iterator(begin())); }

		const_reverse_iterator rend() const
		{ return (const_reverse_iterator(begin())); }


	/* --- [ Capacity ] --- */
		size_type size() const
		{ return (_end - _begin); }

	/* max_size : the maximum number of elements the container is able to hold due to system or library 
	implementation limitations */
		size_type max_size() const
		{ return (_allocator.max_size()); }

	/* resize : resizes the container to contain [count] elements */
		void resize(size_type count, value_type value = value_type())
		{
			if (size() > count)
			{
				size_type diff = size() - count;
				for (size_type i = 0; i < diff; i++)
					_allocator.destroy(_begin + count + i);
				_end = _begin + count;
			}
			else if (size() < count)
			{
				if (capacity() * 2 > count)
					reserve(capacity() * 2);
				else
					reserve(count);
				for (; _end != _begin + count; _end++)
					_allocator.construct(_end, value);
			}
		}

	/* capacity :capacity of the currently allocated storage */
		size_type capacity() const
		{ return (_capacity_end - _begin); }

		bool empty() const
		{ return (begin() == end()); }

	/* reserve : increase the capacity of the vector*/
		void reserve(size_type new_cap)
		{
			if (capacity() >= new_cap)
				return ;
			pointer new_alloc = _allocator.allocate(new_cap);
			pointer temp_first = _begin;
			pointer temp_last = _end;
			size_type temp_capacity = capacity();

			_begin = new_alloc;
			_end = _begin;
			_capacity_end = new_alloc + new_cap;

			//copy old data
			for (pointer iter = temp_first; iter != temp_last; iter++, _end++)
				_allocator.construct(_end, *iter);
		
			//destroy & deallocate old data
			for (pointer iter = temp_first; iter != temp_last; iter++)
				_allocator.destroy(iter);
			_allocator.deallocate(temp_first, temp_capacity);
		}

	/* --- [ Element access ] --- */
		reference operator[] (size_type pos)
		{ return (_begin[pos]); }

		const_reference operator [] (size_type pos) const
		{ return (_begin[pos]); }


	/* at :returns a reference to the element at specified location [pos] */
		reference at(size_type pos)
		{ 
			if (pos > size())
				throw std::out_of_range ("vector");	
			return (_begin[pos]); 
		}

		const_reference at(size_type pos) const
		{ 
			if (pos > size())
				throw std::out_of_range ("vector");	
			return (_begin[pos]); 
		}


	/* front : returns a reference to the first element in the container */
		reference front()
		{ return (*_begin); }

		const_reference front( ) const
		{ return (*_begin); }


	/* back : returns a  reference to the last element in the container */
		reference back()
		{ return (*(_end - 1)); }

		const_reference back() const
		{ return (*(_end - 1)); }

	// /* data : the returned pointer compares equal to the address of the first element.*/
		T* data()
		{ return (_begin); }

		const T* data() const
		{ return (_begin); }


	/* --- [ Modifiers ] --- */
	/* assign : replaces the contents with count copies of value [value] */
		void	assign(size_type count, const T &value)
		{
			clear();
			if (capacity() < count)
				reserve(count);
			for (size_type i = 0; i < count; i++)
				_allocator.construct(_begin + i, value);
			_end = _begin + count;
		}

		template<class InputIterator>
		void	assign(InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			clear();
			size_type diff = last - first;
			if (capacity() < diff)
				reserve(diff);
			for(InputIterator iter = first; iter != last; ++iter, ++_end)
				_allocator.construct(_end, *iter);
		}

	/* push_back : Appends the given element value to the end of the container */
		void	push_back(const T& value)
		{
			if (capacity() < size() + 1) 
			{
				if (size() != 0)
					reserve(size() * 2);
				else
					reserve(1);
			}
			_allocator.construct(_end, value); 
			_end += 1;
		}

	/* pop_back */
		void	pop_back()
		{
			_allocator.destroy(_end - 1); 
			_end--;
		}

	/* insert */
		iterator insert (iterator position, const value_type &value)
		{
			size_type	pos_count = position - begin();
			insert(position, 1, value);
			return (begin() + pos_count);
		}

		void	insert(iterator position, size_type count, const value_type &value)
		{
			size_type	new_size = size() + count;
			size_type	pos_count = position - begin();

			if (new_size > capacity())
			{
				reserve(recommend_new_capacity(new_size));
			}
			// 後ろからいれる
			for (size_type i = 0; i < new_size - (pos_count + count); i++)
				_begin[new_size - 1 - i] = _begin[size() - 1 - i];
			for (size_type i = 0; i < count; i++)
				_begin[pos_count + i] = value;
			_end = _end + count;
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{ // iterator first から lastまでの同じ値を挿入（FirstからLastまでリストをコピー）
			size_type diff = last - first;
			size_type new_size = size() + diff;
			size_type pos_count = position - begin();
			
			if (size() < new_size)
			{
				if (capacity() < new_size && size())
					reserve(size() * 2);
				else
					reserve(new_size);
			}
			for (size_type i = 0; i < new_size - (pos_count + diff); i++)
				_begin[new_size - 1 - i] = _begin[size() - 1 - i];
			for (size_type i = 0; i < diff; i++, first++)
				_begin[pos_count + i] = *first;
			_end = _end + diff;
		}

		//destroy from end to new_last
		void	destruct_at_end(pointer new_last)
		{
			pointer	ptr = _end;
			while (ptr != new_last)
				_allocator.destroy(--ptr);
			_end = new_last;
		}

		/* erase : removes the element at [pos] / in the range [first, last]*/
		iterator	erase(iterator pos)
		{ return (erase(pos, pos + 1)); }

		iterator	erase(iterator first, iterator last)
		{
			difference_type diff = last - first;
			for (iterator it = first; it + diff != end(); it++)
				*it = *(it + diff);
			destruct_at_end(_end - diff);
			return (iterator(first));	
		}

	/* swap : コンテナの交換 */
		void	swap(vector &other)
		{
			allocator_type temp_alloc = _allocator;
			pointer temp_begin = _begin;
			pointer temp_end = _end;
			pointer temp_capacity_last = _capacity_end;
		
			_allocator = other._allocator;
			_begin = other._begin;
			_end = other._end;
			_capacity_end = other._capacity_end;

			other._allocator = temp_alloc;
			other._begin = temp_begin;
			other._end = temp_end;
			other._capacity_end = temp_capacity_last;
		}

	/* clear : erases all elements from the container, size() returns zero*/
		void	clear()
		{// size becomes zero, capacity remains the same
			for (pointer ite = _begin; ite != _end; ite++)
				_allocator.destroy(ite);
			_end = _begin;
		}

	/* --- [ Allocator ] --- */
		allocator_type get_allocator() const
		{ return (_allocator); }

		private:
		size_type	recommend_new_capacity(size_type new_size)
		{
			size_type max = max_size();
			if (new_size > max)
				throw std::length_error("exceeds max range");
			size_type temp_cap = capacity();
			if (temp_cap >= max / 2)
				return (max);
			return (std::max(temp_cap * 2, new_size));
		}

	};

/* --- [ Non-member function overloads ] --- */
	template<class T, class Allocator>
	bool operator== (const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
	{ return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin())); }

	template<class T, class Allocator>
	bool operator!= (const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
	{ return (!(lhs == rhs)); }

	template<class T, class Allocator>
	bool operator< (const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
	{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

	template<class T, class Allocator>
	bool operator<= (const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
	{ return (!(lhs > rhs)); }

	template<class T, class Allocator>
	bool operator> (const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
	{ return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end())); }

	template<class T, class Allocator>
	bool operator>= (const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
	{ return (!(lhs < rhs)); }

	template<class T, class Allocator>
	void	swap(vector<T, Allocator> &lhs, vector<T, Allocator> &rhs)
	{ lhs.swap(rhs); }

}

#endif