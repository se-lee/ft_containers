#ifndef MAP_HPP
# define MAP_HPP

# include <memory> // allocator
# include <functional> // std::less
# include "../utils/random_access_iterator.hpp"
# include "../utils/reverse_iterator.hpp"
# include "../utils/pair.hpp"
# include "../utils/iterator_traits.hpp"
# include "../utils/bidirectional_iterator.hpp"

namespace ft
{
	template < class Key,  // map::key_type
			class T,   // map::mapped_type
			class Compare = std::less<Key>,// map::key_compare
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

			typedef ft::allocator_traits<Alloc>::pointer	pointer;
			typedef ft::allocator_traits<Alloc>::const_pointer	const_pointer;
			typedef typename ft::bidirectional_iterator<ft::pair>	iterator;
			typedef typename ft::bidirectional_iterator<const ft::pair> const_iterator;

			/* 本家 std::mapでは 
			typedef __map_iterator<typename __base::iterator>   iterator;
			typedef __map_const_iterator<typename __base::const_iterator> const_iterator;
			となっている。
			 */


			typedef	typename ft::reverse_iterator<iterator>	reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef	std::ptrdiff_t							difference_type;
			typedef std::size_t								size_type;

		private:
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

			

/* --- [ Constructors ] --- */
/* --- [ Destructor ] --- */
/* --- [ Operator= ] --- */
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