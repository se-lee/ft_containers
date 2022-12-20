#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft 
{
	template<class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef Container							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;
		
		protected:
			Container	_stack;

			template<class T1, class Container1>
			friend bool operator==(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);

			template<class T1, class Container1>
			friend bool operator<(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);

		
		public:

/* --- [ Constructors ] --- */
	explicit stack (const Container &cont = Container()) : _stack(cont) {}

/* --- [ Destructor ] --- */
	~stack() { }

/* Operator = */
	stack &operator= (const stack &other)
	{ 
		_stack = other._stack;
		return (*this); 
	}


/* --- [ Element access ] --- */
/* top : 次の要素へアクセスする */
	reference top ()
	{ return (_stack.back()); }

	const_reference top () const
	{ return (_stack.back()); }

/* --- [ Capacity ] --- */
/* empty: */
	bool empty () const
	{ return (_stack.begin() == _stack.end()); }

/* size: */
	size_type size() const
	{ return (_stack.size()); }

/* --- [ Modifiers ] --- */
/* push: */
	void push(const value_type &value)
	{ _stack.push_back(value); }

/* pop: */
	// pop back
	void pop()
	{ _stack.pop_back(); }

	};

/* --- [ Non-member function overloads ] --- */
	template<class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return (lhs._stack == rhs._stack); };

	template<class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return (!(lhs == rhs)); };

	template<class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return (lhs._stack < rhs._stack); };

	template<class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return ((lhs < rhs) || (lhs == rhs)); };

	template<class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return (!(lhs <= rhs)); };

	template<class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{ return ((lhs > rhs) || (lhs == rhs)); };

	template<class T, class Container>
	void swap(stack<T, Container> &lhs, stack<T, Container> &rhs )
	{ lhs._stack.swap(rhs); }

}

#endif
