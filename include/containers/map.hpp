#ifndef MAP_HPP
# define MAP_HPP

# include <memory> // allocator
# include <functional> // std::less
# include "../utils/random_access_iterator.hpp"
# include "../utils/reverse_iterator.hpp"
# include "../utils/pair.hpp"
# include "../utils/iterator_traits.hpp"
# include "../utils/bidirectional_iterator.hpp"
# include "../utils/tree.hpp"

namespace ft
{
/************************** [ MAP CLASS ] **************************/

/*
for the implementation of std::map::value_compare, the keyword
friend is allowed
*/
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> >
	> class map
	{
		public:
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef	Compare									key_compare;
			typedef Alloc									allocator_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;

			typedef typename Alloc::pointer									pointer;
			typedef typename Alloc::const_pointer							const_pointer;
			typedef tree_iterator<ft::tree_node<value_type> >		iterator;
			typedef tree_const_iterator<ft::tree_node<value_type> >	const_iterator;

			typedef	typename ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef	std::ptrdiff_t											difference_type;
			typedef std::size_t												size_type;

		private:
			typedef	ft::tree<T, Compare, Alloc>			_tree;

		public:
/* --- [ Constructors ] --- */
			map() : _tree() {}
			explicit map(const key_compare &comp, const Alloc &alloc = Alloc()) : _tree(/*value_comapre(comp)*/){}

			template<class InputIterator>
			map (InputIterator first, InputIterator last, const Compare &comp = Compare(), const Alloc &alloc = Alloc()) : _tree(/*value_comapre(comp */)
				{
					insert(first, last);
				}
			
			map(const map &other) 
			{
				/* copy elements */
				return (*this);
			}

/* --- [ Destructor ] --- */
			~map() 
			{
				if (size() > 0)
				{

				}
				/*
				This destroys all container elements, 
				and deallocates all the storage capacity allocated 
				by the map container using its allocator.*/
			}

/* --- [ Operator= ] --- */
			map &operator=(const map &other)
			{
				/* copy every element of [other] to [this] */
				return (*this);
			}

/* --- [ Iterators ] --- */
			iterator	begin()
			{ return (_tree.begin()); }
			
			const_iterator	begin()const 
			{ return (_tree.begin()); }

			iterator	end() 
			{ return (_tree.end()); }

			const_iterator end()const 
			{ return (_tree.end()); }

			reverse_iterator rbegin() 
			{ return (reverse_iterator(_tree.end())); }

			const_reverse_iterator rbegin() const 
			{ return (const_reverse_iterator(_tree.end())); }

			reverse_iterator rend() 
			{ return(reverse_iterator(_tree.begin())); }

			const_reverse_iterator rend() const
			{ return (const_reverse_iterator(_tree.begin())); }

		
/* --- [ Capacity ] --- */
			bool empty() const 
			{ return (_tree.begin() == _tree.end()); }

			size_type size() const
			{ return (_tree.end() - _tree.begin()); }

			size_type max_size() const 
			{ return (_tree.get_allocator().max_size()); }


/* --- [ Element access ] --- */
			T &at( const Key &key) 
			{}
			
			const T &at( const Key &key) const
			{}

/* --- [ Modifiers ] --- */
			// std::map<Key, T, Compare, Allocator>::clear
			void clear() 
			{// erases all elements from the container
			}

			ft::pair<iterator, bool> insert( const value_type &value);

			iterator insert(const_iterator it, const value_type &x);

			// template<class InputIterator>
			// void insert(std::initializer_list<value_type> init_list); 

			iterator erase( iterator pos );
			iterator erase( iterator first, iterator last );
			size_type erase( const Key &key );
			
			void swap( map &other );


/* --- [ Observers ] --- */
			key_compare key_comp() const;
			map::value_compare value_comp() const;

/* --- [ Operations / Lookup ] --- */
			size_type	count( const Key &key ) const;

			iterator find( const Key &key );
			const_iterator find( const Key &key ) const;

			ft::pair<iterator, iterator> equal_range( const Key &key );
			ft::pair<const_iterator, const_iterator> equal_range( const Key &key ) const;

			iterator lower_bound( const Key &key );
			const_iterator lower_bound(const Key &key ) const;

			iterator upper_bound( const Key &key );
			const_iterator upper_bound( const Key &key ) const;


/* --- [ Allocator ] --- */
			allocator_type get_allocator() const;

	};

}




#endif