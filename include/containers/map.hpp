#ifndef MAP_HPP
# define MAP_HPP

# include <memory> // allocator
# include <functional> // std::less
# include "../utils/random_access_iterator.hpp"
# include "../utils/reverse_iterator.hpp"
# include "../utils/pair.hpp"
# include "../utils/iterator_traits.hpp"
# include "../"

namespace ft
{
	template < class Key,  // map::key_type
			class T,   // map::mapped_type
			class Compare = std::less<Key>,// map::key_compare
			class Alloc = std::allocator<ft::pair<const Key,T>> // map::allocator_type 
	> class map
	{
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef	Comapre									key_compare;
			typedef 										value_compare;
			typedef Alloc									allocator_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef ft::allocator_traits<Alloc>::pointer	pointer;
			typedef ft::allocator_traits<Alloc>::const_pointer	const_pointer;
			typedef typename/* bidirectional iterator to value_type(pair)*/	iterator;
			typedef typename/* bidirectional iterator to const value_type */	const_iterator;
			typedef	typename ft::reverse_iterator<iterator>	reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef	std::ptrdiff_t							difference_type;
			typedef std::size_t								size_type;


/* --- [ Constructors ] --- */
/* --- [ Destructor ] --- */
/* --- [ Iterators ] --- */
/* --- [ Capacity ] --- */
/* --- [ Element access ] --- */
/* --- [ Modifiers ] --- */
/* --- [ Observers ] --- */
/* --- [ Operations ] --- */
/* --- [ Allocator ] --- */



	};

}




#endif