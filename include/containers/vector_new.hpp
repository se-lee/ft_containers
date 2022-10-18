#ifndef VECTOR_NEW_HPP
# define VECTOR_NEW_HPP

# include <iostream>
# include <iterator>
# include "../utils/reverse_iterator.hpp"
# include "../utils/random_access_iterator.hpp"
# include "../utils/sfinae.hpp"


namespace ft
{
	template<class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef	T				value_type;
			typedef Alloc			allocator_type;
			typedef std::size_t		size_type;
			typedef std::ptrdiff_t	difference_type;
			typedef T&				reference;
			typedef const T& 		const_reference;
			typedef T*				pointer;
			typedef const T*		const_pointer;
			typedef ft::random_access_iterator<pointer>	iterator;
			typedef ft::random_access_iterator<const_pointer> const_iterator;
			typedef ft::reverse_iterator<T>	reverse_iterator;
			typedef const ft::reverse_iterator<T>	const_reverse_iterator;

			// using value_type	= T;
			// using pointer		= T *;
			// using const_pointer	= const pointer;
			// using reference		= value_type &;
			// using const_reference = const value_type &;
			// using allocator_type = Allocator;

			// using iterator		= pointer;
			// using const_iterator = const_pointer;
			// using reverse_iterator = ft::reverse_iterator<iterator>;
			// using const_reverse_iterator = ft::reverse_iterator<const_iterator>;
		
		protected:
			pointer _first;
			pointer _last;
			pointer _reserved_last;
			allocator_type _alloc;

		public:
			vector() {}

			vector(const allocator_type &alloc) : alloc(alloc){}

			explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) {}

			vector(size_type n, const allocator_type &alloc) :vector(alloc)
			{ resize(size); }

			vector(size_type size, const_reference value, const allocator_type &alloc) :vector(alloc)
			{ resize(size, value); }



			~vector()
			{
				if (size() > 0)
				{
					for (size_type i = 0; i < size(); i++)
						_alloc.destroy(_first + i);
				}
				if (capacity() > 0)
					_alloc.deallocate(_first, capacity());
			}
	
			iterator begin() const
			{ return (_first); }

			iterator end() const
			{ return (_last); }

			reverse_iterator rbegin()
			{ return (reverse_iterator{_last}); } //型変換

			size_type size() const
			{ return (end() - begin()); }

			bool empty() const
			{ return (size() == 0); }

			size_type capacity() const
			{ return (_reserved_last - _first); }

			reference operator[](size_type i)
			{ return (_first[i]); }

			const_reference operator[](size_type i) const
			{ return (_first[i]); }

			reference at(size_type i)
			{
				if (i >= size())
					throw std::out_of_range("index is out of range.");
				
				return (_first[i]);
			}

			const_reference at(size_type i)
			{
				if( i >= size())
					throw std::out_of_range("index is out of range.");
				
				return (_first[i]);
			}

			reference front()
			{ return (first); }
			
			const_reference front() const
			{ return (first); }

			reference back()
			{ return (_last - 1); }

			const_reference back() const
			{ return (_last - 1); }

			pointer data()
			{ return (_first); }

			const_pointer data() const
			{ return (_first); }

			void reserve(size_type size)
			{
				if (size <= capacity())
					return ;
				pointer ptr = allocate(size);

				pointer old_first = _first;
				pointer old_last = _last;
				size_type old_capacity = capacity();

				_first = ptr;
				_last = _first;
				_reserved_last = _first + size;

				for (pointer old_iter = old_first; old_iter != old_last; ++old_iter, ++_last)
					construct (_last, std::move(*old_ptr));

				for (reverse_iterator riter = reverse_iterator(old_last, rend = reverse_iterator(old_first);
					riter != rend; ++riter))
					destroy (&*riter);
			}

			void resize(size_type n)
			{
				if (n < size())
				{
					size_type diff = size() - n;
					destroy_until(rbegin() + diff);
					_last = _first + n;
				}
				else if (n > size())
				{
					reserve(n);
					for (; _last != _reserved_last; ++_last)
						construct(_last);
				}
			}

			void push_back(const_reference value)
			{
				if (size() + 1 > capacity())
					reserve(size() + 1);
				construct(_last, value);
				++_last;
			}

	};
}

#endif