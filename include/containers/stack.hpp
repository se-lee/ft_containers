/*stack
It will use your vector class as default underlying container. But it must still be
compatible with other containers, the STL ones included
*/
#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft 
{
	template<class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef Container					container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;
		
		protected:
			Container	_stack;
		
		public:

/* --- [ Constructors ] --- */
	explicit stack (const Container &cont = Container()) : _stack(cont) {}

/* --- [ Destructor ] --- */
	~stack();

/* Operator = */
	stack &operator= (const stack &other)
	{ 
		_stack = other;
		return (*this); 
	}


/* --- [ Element access ] --- */
/* top : 次の要素へアクセスする */
	reference top ()
	{ return (*(_stack._last)); }

	const_reference top () const
	{ return (*(_stack._last)); }

/* --- [ Capacity ] --- */
/* empty: */
	bool empty () const
	{ return (_stack.begin() == _stack.end()); }

/* size: */
	size_type size() const
	{ return (_stack.size()); }

/* --- [ Modifiers ] --- */
/* push: */
	// push back

/* pop: */
	// pop back

	};

/* --- [ Non-member function overloads ] --- */
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