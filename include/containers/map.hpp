#ifndef MAP_HPP
# define MAP_HPP

# include <memory> // allocator
# include <functional> // std::less
# include "../iterators/reverse_iterator.hpp"
# include "../utils/pair.hpp"
# include "../iterators/iterator_traits.hpp"
# include "../utils/tree.hpp"
# include "../utils/algorithm.hpp"

namespace ft
{
/************************** [ MAP CLASS ] **************************/
	template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key, T> >
	> class map
	{
		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef pair<const key_type, mapped_type>				value_type;
			typedef	Compare											key_compare;
			typedef Allocator										allocator_type;
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

			typedef typename Allocator::pointer						pointer;
			typedef typename Allocator::const_pointer				const_pointer;
			typedef tree_iterator<value_type *>						iterator;
			typedef tree_iterator<const value_type *> 				const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef	std::ptrdiff_t									difference_type;
			typedef std::size_t										size_type;

		private:
			// value_compare	_value_comp;
			// allocator_type	_allocator;
			tree<key_type, value_type, value_compare, tree_alloc>	_tree;

		public:
/* --- [ Constructors ] --- */
			explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = Allocator())
			: _tree(comp, alloc)
			{}

			template<class InputIterator>
			map (InputIterator first, InputIterator last, const Compare &comp = Compare(), const allocator_type &alloc = Allocator())
			: _tree(comp, alloc)
			{ insert(first, last); } 
					
			map(const map &other) : _tree(other._tree)
			{}

/* --- [ Destructor ] --- */
			~map() {}

/* --- [ Operator= ] --- */
			map &operator=(const map &other)
			{
				// _value_comp = other._value_comp;
				// _allocator = other._allocator;
				_tree = other._tree;
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
			{ return ( _tree.empty()); }

			size_type size() const
			{ return (_tree.size()); }

			size_type max_size() const 
			{ return (_tree.max_size()); }


/* --- [ Element access ] --- */
			mapped_type &at( const Key &key)
			{
				iterator pos = find(key);
				return (pos.base()->_value.second);
			}
			
			const mapped_type &at( const Key &key) const
			{
				iterator pos = find(key);
				return (pos.base()->_value.second);
			}

//  mapped_type& at (const key_type& k);const mapped_type& at (const key_type& k) const;

			mapped_type& operator[]( const Key& key )
			{
				iterator pos = find(key);
				return (pos.base()->_value.second);
			}

/* --- [ Modifiers ] --- */
			// std::map<Key, T, Compare, Allocator>::clear
			void clear()
			{ _tree.clear(); }
			// erases all elements from the container
			

			ft::pair<iterator, bool> insert(const value_type &value)
			{ return (_tree.insert(value)); }

			iterator insert(iterator position, const value_type &value)
			{ return (_tree.insert(position, value)); }

			template<class InputIterator>
			void insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
			{
				return (_tree.insert(first, last));
			}

			void erase(iterator position)
			{ _tree.erase(position); }

			size_type erase(const key_type &key)
			{ return (_tree.erase(make_pair(key, mapped_type()))); }

			void erase(iterator first, iterator last)
			{ _tree.erase(first, last); }
		
			
			void swap( map &other )
			{
				_tree.swap(other._tree);
			}


/* --- [ Observers ] --- */
			key_compare key_comp() const;
			value_compare value_comp() const;

/* --- [ Operations / Lookup ] --- */
			size_type	count( const Key &key ) const
			{ return (_tree.count(make_pair(key, mapped_type()))); }

			iterator find( const Key &key )
			{ return (_tree.find(make_pair(key, mapped_type()))); }

			const_iterator find( const Key &key ) const
			{ return (_tree.find(make_pair(key, mapped_type()))); }

			ft::pair<iterator, iterator> equal_range( const Key &key );
			ft::pair<const_iterator, const_iterator> equal_range( const Key &key ) const;

			iterator lower_bound( const Key &key )
			{
				return (_tree.lower_bound(make_pair(key, mapped_type())));
			}
			const_iterator lower_bound(const Key &key ) const
			{
				return (_tree.lower_bound(make_pair(key, mapped_type())));
			}

			iterator upper_bound( const Key &key )
			{
				return (_tree.upper_bound(make_pair(key, mapped_type())));
			}

			const_iterator upper_bound( const Key &key ) const
			{
				return (_tree.upper_bound(make_pair(key, mapped_type())));
			}

/* --- [ Allocator ] --- */
			allocator_type get_allocator() const { return (_tree.get_allocator()); }


			void printTree()
			{
				_tree.printAVL("", _tree.get_root(), false);
				std::cout << std::endl;
			}


	};

	template<class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{ return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin())); }

	template<class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{ return (!(lhs == rhs)); }

	template<class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

	template<class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{ return (!(lhs > rhs)); }

	template<class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{ return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end())); }

	template<class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{ return (!(lhs < rhs)); }

	template<class Key, class T, class Compare, class Alloc>
	void swap(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{ lhs.swap(rhs); }


}


#endif