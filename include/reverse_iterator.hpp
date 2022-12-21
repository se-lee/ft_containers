#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"


namespace ft
{
	template<class Iterator>
	class reverse_iterator
	{
		protected:
			Iterator	_current;
		
		public:
			typedef Iterator	iterator_type;
			typedef typename	iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename	iterator_traits<Iterator>::value_type			value_type;
			typedef typename	iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename	iterator_traits<Iterator>::pointer				pointer;
			typedef typename	iterator_traits<Iterator>::reference			reference;
		
			reverse_iterator() {}
			explicit reverse_iterator(iterator_type x) : _current(x) {}
			template <class U>
			reverse_iterator(const reverse_iterator<U> &other) : _current(other.base()) {}

			template <class U>
			reverse_iterator &operator=(const ft::reverse_iterator<U> &other)
			{
				_current = other.base();
				
				return (*this);
			}

			~reverse_iterator() {}

			iterator_type base() const
			{ return (_current); }

			reference operator*() const
			{
				Iterator temp = _current;
				// --temp;
				temp--;
				return (*temp);
			}

			pointer operator->() const
			{ return (&(operator*())); }

			reference operator[] (difference_type n) const
			{ return (*(*this + n)); }

			reverse_iterator &operator++()
			{
				--_current;
				return (*this);
			}
			
			reverse_iterator &operator--()
			{
				++_current;
				return (*this);
			}

			reverse_iterator operator++(int)
			{
				reverse_iterator temp = *this;
				--_current;
				return (temp);
			}

			reverse_iterator operator--(int)
			{
				reverse_iterator temp = *this;
				++_current;
				return (temp);
			}

			reverse_iterator operator+(difference_type n) const
			{ return (reverse_iterator(_current - n)); }

			reverse_iterator operator-(difference_type n) const
			{ return (reverse_iterator(_current + n)); }

			reverse_iterator &operator+=(difference_type n)
			{
				_current -= n;
				return (*this);
			}

			reverse_iterator &operator-=(difference_type n )
			{
				_current += n;
				return (*this);
			};
	};

	template <class Iterator1, class Iterator2> 
	bool operator== (const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs)
	{ return (lhs.base() == rhs.base()); };

	template <class Iterator1, class Iterator2>
	bool operator!= (const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs)
	{ return (lhs.base() != rhs.base()); };

	template <class Iterator1, class Iterator2>
	bool operator< (const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs)
	{ return (lhs.base() > rhs.base()); };

	template <class Iterator1, class Iterator2>
	bool operator<= (const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs)
	{ return (lhs.base() >= rhs.base()); };

	template <class Iterator1, class Iterator2>
	bool operator> (const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs)
	{ return (lhs.base() < rhs.base()); };
	
	template <class Iterator1, class Iterator2>
	bool operator>= (const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs)
	{ return (lhs.base() <= rhs.base()); };

	template <class Iterator>
	reverse_iterator<Iterator> operator+ (typename ft::reverse_iterator<Iterator>::difference_type n, const ft::reverse_iterator<Iterator> &it)
	{ return (it - n); };

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (const ft::reverse_iterator<Iterator> &lhs, const ft::reverse_iterator<Iterator> &rhs)
	{ return (lhs.base() - rhs.base()); };

}

#endif