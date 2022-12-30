#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <functional>
# include <iterator>
# include "reverse_iterator.hpp"
# include "pair.hpp"
# include "iterator_traits.hpp"
# include "tree.hpp"
# include "algorithm.hpp"

namespace ft
{
	/************************** [ MAP CLASS ] **************************/

	template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key, T> >
	> class map
	{
		public:
			typedef Key																					key_type;
			typedef T																					mapped_type;
			typedef pair<const key_type, mapped_type>													value_type;
			typedef	Compare																				key_compare;
			typedef Allocator																			allocator_type;
			typedef value_type&																			reference;
			typedef const value_type&																	const_reference;

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
			typedef tree_iterator<pointer>							iterator;
			typedef tree_iterator<const_pointer>					const_iterator;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
			typedef	std::ptrdiff_t									difference_type;
			typedef std::size_t										size_type;

		private:
			value_compare	_value_comp;
			allocator_type	_allocator;
			key_compare		_key_comp;
			tree<value_type, value_compare, allocator_type>	_tree;

		public:
/* --- [ Constructors ] --- */
			explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
			: _tree(comp, alloc)
			{}

			template<class InputIterator>
			map (InputIterator first, InputIterator last, const Compare &comp = Compare(), const allocator_type &alloc = allocator_type())
			: _tree(comp, alloc)
			{ insert(first, last); } 
					
			map(const map &other)
			: _value_comp(other._value_comp), _allocator(other._allocator), _tree(other._tree)
			{ }

/* --- [ Destructor ] --- */
			~map() {}

/* --- [ Operator= ] --- */
			map &operator=(const map &other)
			{
				_value_comp = other._value_comp;
				_allocator = other._allocator;
				_key_comp = other._key_comp;
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
			{ return (reverse_iterator(end())); }

			const_reverse_iterator rbegin() const 
			{ return (const_reverse_iterator(end())); }

			reverse_iterator rend() 
			{ return (reverse_iterator(begin())); }

			const_reverse_iterator rend() const
			{ return (const_reverse_iterator(begin())); }

		
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
				if (pos == end())
					throw std::out_of_range("out of range");
				return (pos.base()->_value.second);
			}
			
			const mapped_type &at( const Key &key) const
			{
				iterator pos = find(key);
				if (pos == end())
					throw std::out_of_range("out of range");
				return (pos.base()->_value.second);
			}

			mapped_type& operator[]( const Key& key )
			{
				iterator pos = find(key);
				if (pos == end())
					pos = insert(ft::make_pair(key, mapped_type())).first;
				return (pos.base()->_value.second);
			}

/* --- [ Modifiers ] --- */
			void clear()
			{ _tree.clear(); }
			
			ft::pair<iterator, bool> insert(const value_type &value)
			{ return (_tree.insert(value)); }

			// insert with hint - insert value as close as possible to the position prior to [position]
			iterator insert(iterator position, const value_type &value)
			{ return (_tree.insert(position, value)); }

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				for (; first != last; ++first)
					_tree.insert(*first);
			} 

			void erase(iterator position)
			{ _tree.erase(position); }

			size_type erase(const key_type &key)
			{ return (_tree.erase(make_pair(key, mapped_type()))); }

			void erase(iterator first, iterator last)
			{ _tree.erase(first, last); }
		
			void swap( map &other )
			{ _tree.swap(other._tree); }


/* --- [ Observers ] --- */
			key_compare key_comp() const
			{ return (_key_comp); }
			value_compare value_comp() const
			{ return (_value_comp); }

/* --- [ Operations / Lookup ] --- */
			size_type	count( const Key &key ) const
			{ return (_tree.count(ft::make_pair(key, mapped_type()))); }

			iterator find( const Key &key )
			{ return (_tree.find(ft::make_pair(key, mapped_type()))); }

			const_iterator find( const Key &key ) const
			{ return (_tree.find(ft::make_pair(key, mapped_type()))); }

			ft::pair<iterator, iterator> equal_range( const Key &key )
			{ return ( _tree.equal_range(ft::make_pair(key, mapped_type()))); }

			ft::pair<const_iterator, const_iterator> equal_range( const Key &key ) const
			{ return (_tree.equal_range(ft::make_pair(key, mapped_type()))); }


			iterator lower_bound( const Key &key )
			{ return (_tree.lower_bound(ft::make_pair(key, mapped_type()))); }

			const_iterator lower_bound(const Key &key ) const
			{ return (_tree.lower_bound(ft::make_pair(key, mapped_type()))); }

			iterator upper_bound( const Key &key )
			{ return (_tree.upper_bound(ft::make_pair(key, mapped_type()))); }

			const_iterator upper_bound( const Key &key ) const
			{ return (_tree.upper_bound(ft::make_pair(key, mapped_type()))); }

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
	void swap( map<Key, T, Compare, Alloc> &lhs, map<Key, T, Compare, Alloc> &rhs)
	{ lhs.swap(rhs); }

}

#endif
