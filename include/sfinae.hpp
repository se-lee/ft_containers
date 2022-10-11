#ifndef SFINAE_HPP
# define SFINAE_HPP

namespace ft
{
/***** [ enable_if ] *****/
	template<bool Cond, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T>
	{ typedef T type; }; 


/***** [ is_integral ] *****/


}




#endif