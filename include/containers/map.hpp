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
/************************** [ MAP ITER ] **************************/
	template<class Node>
	class map_iterator
	{
		private:	
			typedef	typename Node::NodeTypes		node_types;
			typedef typename Node::pointer_traits	pointer_traits;
			// typedef typename node_types::iter_pointer		iter_pointer;

			Node _node;

		public:
			typedef ft::bidirectional_iterator_tag		iterator_category;
			typedef Node								value_type;
			typedef ptrdiff_t							difference_type;
			typedef value_type&							reference;
			typedef value_type*							pointer;


			map_iterator() {}
			map_iterator(Node nd) : _node(nd) {}
			
			reference operator*() const { return (_node->_value); }
			pointer operator->() const { return (pointer_traits<pointer>::pointer_to(_node->_get_value())); }
			map_iterator &operator++() 
			{
				++_node;
				return (*this);
			}

			map_iterator operator++(int)
			{
				map_iterator temp = *this;
				++(*this);
				return (temp);
			}

			map_iterator &operator--()
			{
				--_node;
				return (*this);
			}

			map_iterator operator--(int)
			{
				map_iterator temp = *this;
				--(*this);
				return (temp);
			}

			bool operator==(const map_iterator &x, const map_iterator &y)
			{ return (x._node == y._node); }

			bool operator!=(const map_iterator &x, const map_iterator &y)
			{ return (x._node != y._node); }

	};

/************************** [ CONST MAP ITER ] **************************/
	template<class Node>
	class map_const_iterator
	{
		private:	
			typedef	typename Node::NodeTypes		node_types;
			typedef typename Node::pointer_traits	pointer_traits;
			// typedef typename node_types::iter_pointer		iter_pointer;

			Node _node;

		public:
			typedef ft::bidirectional_iterator_tag		iterator_category;
			typedef Node								value_type;
			typedef ptrdiff_t							difference_type;
			typedef value_type&							reference;
			typedef value_type*							pointer;


			map_iterator() {}
			map_iterator(Node nd) : _node(nd) {}
			
			reference operator*() const { return (_node->_value); }
			pointer operator->() const { return (pointer_traits<pointer>::pointer_to(_node->_get_value())); }
			map_iterator &operator++() 
			{
				++_node;
				return (*this);
			}

			map_iterator operator++(int)
			{
				map_iterator temp = *this;
				++(*this);
				return (temp);
			}

			map_iterator &operator--()
			{
				--_node;
				return (*this);
			}

			map_iterator operator--(int)
			{
				map_iterator temp = *this;
				--(*this);
				return (temp);
			}

			bool operator==(const map_iterator &x, const map_iterator &y)
			{ return (x._node == y._node); }

			bool operator!=(const map_iterator &x, const map_iterator &y)
			{ return (x._node != y._node); }

	};

/************************** [ MAP CLASS ] **************************/

/*
Of course, for the implementation of std::map::value_compare, the keyword
friend is allowed
*/
	template < class Key,  // map::key_type
			class T,   // map::mapped_type
			class Compare = std::less<Key>, // map::key_compare
			class Alloc = std::allocator<ft::pair<const Key, T>> // map::allocator_type 
	> class map
	{
		public:
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef	Comapre									key_compare;
			typedef 										value_compare;
			typedef Alloc									allocator_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;

			typedef ft::allocator_traits<Alloc>::pointer					pointer;
			typedef ft::allocator_traits<Alloc>::const_pointer				const_pointer;
			typedef typename map_iterator<ft::tree_node<value_type>>		iterator;
			typedef typename map_const_iterator<ft::tree_node<value_type>>	const_iterator;

			typedef	typename ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef	std::ptrdiff_t											difference_type;
			typedef std::size_t												size_type;

		private:
			typedef	ft::tree<T, Compare, Alloc>			_tree;

		/*本家：
    typedef _VSTD::__value_type<key_type, mapped_type>             __value_type;
    typedef __map_value_compare<key_type, __value_type, key_compare> __vc;
    typedef typename __rebind_alloc_helper<allocator_traits<allocator_type>,
                                                 __value_type>::type __allocator_type;
    typedef __tree<__value_type, __vc, __allocator_type>   __base;
    typedef typename __base::__node_traits                 __node_traits;
    typedef allocator_traits<allocator_type>               __alloc_traits;


		__base	__tree;
		*/
		public:
/* --- [ Constructors ] --- */
			map() : _tree(/*value_comapre(key_comapre)*/) {}
			explicit map(const key_comapre &comp, const Alloc &alloc = Alloc()) : _tree(/*value_comapre(comp)*/){}

			template<class InputIterator>
			map (InputIterator first, InputIterator last, const Compare &comp = Comapre(), const Alloc &alloc = Alloc())
				: _tree(/*value_comapre(comp)*/)
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
			iterator	begin() { return (_tree.begin()); }
			const_iterator	begin()const { return (_tree.begin()); }

			iterator	end() { return (_tree.end()); }
			const_iterator end()const { return (_tree.end()); }

			reverse_iterator rbegin() { return (); }
			const_reverse_iterator rbegin() const { return (); }

			reverse_iterator rend() { return(); }
			const_reverse_iterator rend() const { return (); }

		
/* --- [ Capacity ] --- */
			bool empty() const { return (); }

			size_type size() const { return (); }

			size_type max_size() const { return (); }


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

			template<class InputIterator>
			void insert(std::initializer_list<value_type> init_list); 

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