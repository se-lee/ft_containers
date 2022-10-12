#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <iterator>

namespace ft
{
	template<class T, class Allocator = std::allocator<T>>
	class vector
	{
		private:
			pointer first;
			pointer last;
			pointer reserved_last;
			allocator_type alloc;

		public:
			using value_type	= T;
			using pointer		= T *;
			using const_pointer	= const pointer;
			using reference		= value_type &;
			using const_reference = const value_type &;
			using allocator_type = Allocator;

			using iterator		= pointer;
			using const_iterator = const_pointer;
			using reverse_iterator = ft::reverse_iterator<iterator>;
			using const_reverse_iterator = ft::reverse_iterator<const_iterator>;


			vector() {}

			vector(const allocator_type &alloc) : alloc(alloc){}

			vector(size_type size, const allocator_type &alloc) :vector(alloc)
			{ resize(size); }

			vector(size_type size, const_reference value, const allocator_type &alloc) :vector(alloc)
			{ resize(size, value); }

			~vector()
			{
				clear();
				deallocate();
			}
	
			iterator begin() const
			{ return (first); }

			iterator end() const
			{ return (last); }

			reverse_iterator rbegin()
			{ return (reverse_iterator{last}); } //型変換

			size_type size() const
			{ return (end() - begin()); }

			bool empty() const
			{ return (size() == 0); }

			size_type capacity() const
			{ return (reserved_last - first); }

			reference operator[](size_type i)
			{ return (first[i]); }

			const_reference operator[](size_type i) const
			{ return (first[i]); }

			reference at(size_type i)
			{
				if (i >= size())
					throw std::out_of_range("index is out of range.");
				
				return (first[i]);
			}

			const_reference at(size_type i)
			{
				if( i >= size())
					throw std::out_of_range("index is out of range.");
				
				return (first[i]);
			}

			reference front()
			{ return (first); }
			
			const_reference front() const
			{ return (first); }

			reference back()
			{ return (last - 1); }

			const_reference back() const
			{ return (last - 1); }

			pointer data()
			{ return (first); }

			const_pointer data() const
			{ return (first); }

			void reserve(size_type size)
			{
				if (size <= capacity())
					return ;
				pointer ptr = allocate(size);

				pointer old_first = first;
				pointer old_last = last;
				size_type old_capacity = capacity();

				first = ptr;
				last = first;
				reserved_last = first + size;

				for (pointer old_iter = old_first; old_iter != old_last; ++old_iter, ++last)
					construct (last, std::move(*old_ptr));

				for (reverse_iterator riter = reverse_iterator(old_last, rend = reverse_iterator(old_first);
					riter != rend; ++riter))
					destroy (&*riter);
			}

			void resize(size_type n)
			{
				if (n < size())
				{
					size_type diff = size() - n;
					
				}
			}

	};

}


#endif