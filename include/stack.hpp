/*stack
It will use your vector class as default underlying container. But it must still be
compatible with other containers, the STL ones included
*/
#ifndef STACK_HPP
# define STACK_HPP

# include <vector>

namespace ft 
{
	template<class T, class Container = std::vector<T>>
	class stack
	{
		public:
			typedef Container			container_type;
			typedef T					value_type;

			// Container					container_type;
			// Container::value_type		value_type;
			// Container::size_type		size_type;
			// Container::reference		reference;
			// Container::const_reference	const_reference;

	};

	template<class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return (lhs == rhs); };

	template<class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return (lhs != rhs); };

	template<class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return (lhs < rhs); };

	template<class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return (lhs <= rhs); };

	template<class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return (lhs > rhs); };

	template<class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return (lhs >= rhs); };

}



#endif