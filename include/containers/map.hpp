#ifndef MAP_HPP
# define MAP_HPP

# include <memory> // allocator
# include <functional> // std::less
# include "../iterators/random_access_iterator.hpp"
# include "../iterators/reverse_iterator.hpp"
# include "../utils/pair.hpp"
# include "../iterators/iterator_traits.hpp"
# include "../iterators/bidirectional_iterator.hpp"
# include "../utils/tree.hpp"

namespace ft
{
/************************** [ MAP CLASS ] **************************/

	// template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<tree_node<pair<const Key, T> > >
	template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key, T> >
	> class map
	{
		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef pair<const key_type, mapped_type>				value_type;
			typedef	Compare											key_compare;
			// value_compare
			typedef Allocator										allocator_type;
			// typedef typename Allocator::template rebind<tree_node<value_type> >::other node_allocator;
			typedef std::allocator<ft::tree_node<value_type> >		tree_alloc;
			typedef value_type&										reference;
			typedef const value_type&								const_reference;


			class value_compare : public std::binary_function<value_type, value_type, bool>
			 {
				friend class map;

				protected:
					Compare		comp;
					value_compare(Compare c) : comp(c) {}

				public:	
					value_compare() {}

					typedef bool			result_type;
					typedef value_type		first_argument_type;
					typedef value_type		second_argument_type;

					bool operator() (const value_type &x, const value_type &y) const
					{ return (comp(x.first, y.first)); }

			};

			typedef typename Allocator::pointer													pointer;
			typedef typename Allocator::const_pointer											const_pointer;
			// typedef typename ft::tree<value_type, value_compare, tree_alloc>::iterator			iterator;
			// typedef typename ft::tree<value_type, value_compare, tree_alloc>::const_iterator	const_iterator;

			typedef tree_iterator<value_type>								iterator;
			typedef const_tree_iterator<value_type> 						const_iterator;
			typedef	typename ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef	std::ptrdiff_t											difference_type;
			typedef std::size_t												size_type;

		private:
			value_compare	_vcompare;
			allocator_type	_allocator;
			tree<value_type, value_compare, tree_alloc>		_tree;

		public:
/* --- [ Constructors ] --- */
			explicit map(const key_compare &comp = key_compare(), const tree_alloc &alloc = tree_alloc()) : _vcompare(comp), _allocator(alloc), _tree(_vcompare, alloc)
			{}

			template<class InputIterator>
			map (InputIterator first, InputIterator last, const Compare &comp = value_compare(), const tree_alloc &alloc = tree_alloc()) : _vcompare(comp), _allocator(alloc), _tree(first, last, _vcompare, alloc)
			{
				// _key_comp = comp;
				// _alloc = alloc;
				// insert(first, last);
			}
			
			map(const map &other) 
			{
				*this = other;
				return (*this);
			}

/* --- [ Destructor ] --- */
			~map() 
			{
				_tree.~tree();
				/*
				This destroys all container elements, 
				and deallocates all the storage capacity allocated 
				by the map container using its allocator.*/
			}

/* --- [ Operator= ] --- */
			map &operator=(const map &other)
			{
				_tree = other._tree;
				// _key_comp = other._key_comp;
				// _alloc = other._alloc;
				/* copy every element of [other] to [this] */
				return (*this);
			}

/* --- [ Iterators ] --- */
			iterator	begin()
			{ return (_tree.begin()); }
			
			const_iterator	begin() const 
			{ return (_tree.begin()); }

			iterator	end() 
			{ return (_tree.end()); }

			const_iterator end() const 
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
			{ return ( _tree.empty); }

			size_type size() const
			{ return (_tree.size()); }

			size_type max_size() const 
			{ return (_tree.get_allocator().max_size()); }


/* --- [ Element access ] --- */
			T &at( const Key &key) ;
			
			const T &at( const Key &key) const;

/* --- [ Modifiers ] --- */
			// std::map<Key, T, Compare, Allocator>::clear
			void clear() ;
			// erases all elements from the container
			

			ft::pair<iterator, bool> insert(const value_type &value)
			{
				return (_tree.insert(value));
			}

			iterator insert(const_iterator it, const value_type &x);

			// template<class InputIterator>
			// void insert(std::initializer_list<value_type> init_list); 
			template<class InputIterator>
			void insert(InputIterator first, InputIterator last);

			iterator erase( iterator pos );
			iterator erase( iterator first, iterator last );
			size_type erase( const Key &key );
			
			void swap( map &other );


/* --- [ Observers ] --- */
			key_compare key_comp() const;
			// map::value_compare value_comp() const;

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
			allocator_type get_allocator() const { return (_tree.get_allocator()); }


	};
}


#endif