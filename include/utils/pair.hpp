#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft 
{
	template<class T1, class T2>
	struct pair
	{
		typedef T1		first_type;
		typedef T2		second_type;

		first_type	first;
		second_type	second;

/* --- [ Constructors ] --- */
		//default
		pair() : first(), second() {}

		//initialization
		pair(const first_type &a, const second_type &b) : first(a), second(b) {}

		//copy
		template<class U1, class U2>
		pair (const pair<U1, U2> &pr) : first(pr.first), second(pr.second) {}

/* Operator = */
		pair &operator=(const pair &pr)
		{
			first = pr.first;
			second = pr.second;
			return (*this);
		}

	};

/* --- [ Non-member function overloads ] --- */

//make_pair (function template)
	template<class T1, class T2>
	pair<T1, T2> make_pair(T1 t, T2 u)
	{ return (pair<T1, T2>(t, u)); }

/* operator== */
	template<class T1, class T2>
	bool operator== (const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{ return ((lhs.first == rhs.first) && (lhs.second == rhs.second)); }

/* operator!= */
	template<class T1, class T2>
	bool operator!= (const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{ return (!(lhs == rhs)); }

/* operator< */
	template<class T1, class T2>
	bool operator< (const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{ return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second)); }

/* operator<= */
	template<class T1, class T2>
	bool operator<= (const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{ return (!(lhs > rhs)); }

/* operator> */
	template<class T1, class T2>
	bool operator> (const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{ return (lhs > rhs); }

/* operator>= */
	template<class T1, class T2>
	bool operator>= (const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{ return (!(lhs < rhs)); }

}


#endif