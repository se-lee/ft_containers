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
	template<class T>
	struct remove_cv { typedef T type; };

	template<class T>
	struct remove_cv<const T> { typedef T type; };

	template<class T>
	struct remove_cv<volatile T> { typedef T type; };
	
	template<class T>
	struct remove_cv<const volatile T> { typedef T type; };

	template <class T, T value>
	struct integral_constant
	{
		T value = v;
		typedef T value_type;
		typedef integral_constant<T, v> type;
		const value_type operator()(void) const { return value; } // revise
	};

	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;

	template<class T> struct is_integral_base: false_type {};
	
	template<> struct is_integral_base<bool> : true_type {};
	template<> struct is_integral_base<char> : true_type {};
	template<> struct is_integral_base<char16_t> : true_type {};
	template<> struct is_integral_base<char32_t> : true_type {};
	template<> struct is_integral_base<wchar_t> : true_type {};
	template<> struct is_integral_base<signed char> : true_type {};
	template<> struct is_integral_base<short int> : true_type {};
	template<> struct is_integral_base<int> : true_type {};
	template<> struct is_integral_base<long int> : true_type {};
	template<> struct is_integral_base<long long int> : true_type {};
	template<> struct is_integral_base<unsigned char> : true_type {};
	template<> struct is_integral_base<unsigned short int> : true_type {};
	template<> struct is_integral_base<unsigned int> : true_type {};
	template<> struct is_integral_base<unsigned long int> : true_type {};
	template<> struct is_integral_base<unsigned long long int> : true_type {};

	template <class T>
	struct is_integral : is_integral_base<remove_cv<T>::type> {}; // inherits from integral_constant (true / false)

}




#endif