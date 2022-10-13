#ifndef OLD_REVERSE_ITERATOR_HPP
# define OLD_REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"


namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
		protected:
			Iterator	_current;

		public: 
			typedef Iterator 										iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type	difference_type;
			typedef typename iterator_traits<Iterator>::pointer			pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;
		
		/* --- Constructors / Desctructor --- */	
			/* default */
			reverse_iterator() {};
			
			/* initialization */
			explicit reverse_iterator(iterator_type x) 
			{
				this->_current = x;
			};

			/* copy */
			template <class U>
			reverse_iterator (const reverse_iterator<U> &rev_it) 
			{
				this->_current = rev_it._current;
				return (*this);
			};

			~reverse_iterator() {};

		/* --- Member functions --- */
			/* base - the value that is pointed by the iterator */
			iterator_type base() const
			{
				return (_current);
				/* returns a copy of base iterator, which iterates in the opposite direction */
			};

			/* operator* : dereference iterator */
			reference operator*() const 
			{
				return (*it);
				/* returns a reference to the element pointed by the iterator */
			};

			/* operator+ : addition operator */
			reverse_iterator operator+ (difference_type n) const // n - number of elements to offset
			{
				it -= n;
				return (*this);
				/* returns an iterator pointing to the element n positions away */
			};

			/* operator++ : increment iterator position */
			reverse_iterator& operator++() // pre-increment version
			{
				--it;
				return (*this);
				// the pre-increment version returns *this
			};

			reverse_iterator operator++(int) // post-increment version
			{
				reverse_iterator temp = *this;
				--it;
				return (temp);
				// the post-increment version returns the previous value of *this before the call
			};

			/* operator+= : advances the reverse_iterator by n element positions*/ 
			reverse_iterator &operator+= (difference_type n)
			{
				it -= n;
				return (*this);
			};

			/* operator- */
			reverse_iterator operator- (difference_type n) const
			{
				return (it + n);
			};

			/* operator-- */
			reverse_iterator &operator--()
			{
				++it;
				return (*this);
			};

			reverse_iterator operator--(int)
			{
				reverse_iterator temp = *this;
				++it;
				return (temp);
			};

			/* operator-= */
			reverse_iterator &operator-= (difference_type n)
			{
				it += n;
				return (*this);
			};

			/* operator-> */
			pointer operator->() const
			{
				return (&(operator*()));
			};

			/* operator[] */
			reference operator[] (difference_type n) const
			{
				return (it[-n - 1]);
			};
		};
		/* --- non-member function overloads --- */
		/* relational operators */
		template <class Iterator> 
		bool operator== (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
		{ return (lhs == rhs); };

		template <class Iterator>
		bool operator!= (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
		{ return (lhs != rhs); };

		template <class Iterator>
		bool operator< (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
		{ return (lhs < rhs); };

		template <class Iterator>
		bool operator<= (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
		{ return (lhs <= rhs); };

		template <class Iterator>
		bool operator> (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
		{ return (lhs > rhs); };
		
		template <class Iterator>
		bool operator>= (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
		{ return (lhs >= rhs); };

		/* operator+ */
		template <class Iterator>
		reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
		{ return (rev_it - n); };

		/* operator- */
		template <class Iterator>
		typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
		{ return (lhs.base() - rhs.base()); };

}

#endif
