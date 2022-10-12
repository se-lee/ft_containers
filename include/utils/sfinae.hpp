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

	template <class T, T v>
	struct integral_constant
	{
		static const T value = v;
		typedef T value_type;
		typedef integral_constant<T, v> type;
		operator value_type() const { return value; }
	};

	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;

	template<class T> struct is_integral_base: public false_type {};
	
	template<> struct is_integral_base<bool> : public true_type {};
	template<> struct is_integral_base<char> : public true_type {};
	template<> struct is_integral_base<char16_t> : public true_type {};
	template<> struct is_integral_base<char32_t> : public true_type {};
	template<> struct is_integral_base<wchar_t> : public true_type {};
	template<> struct is_integral_base<signed char> : public true_type {};
	template<> struct is_integral_base<short int> : public true_type {};
	template<> struct is_integral_base<int> : public true_type {};
	template<> struct is_integral_base<long int> : public true_type {};
	template<> struct is_integral_base<long long int> : public true_type {};
	template<> struct is_integral_base<unsigned char> : public true_type {};
	template<> struct is_integral_base<unsigned short int> : public true_type {};
	template<> struct is_integral_base<unsigned int> : public true_type {};
	template<> struct is_integral_base<unsigned long int> : public true_type {};
	template<> struct is_integral_base<unsigned long long int> : public true_type {};

	template <class T>
	struct is_integral : public is_integral_base<typename remove_cv<T>::type> {}; // inherits from integral_constant (true / false)

}

#endif