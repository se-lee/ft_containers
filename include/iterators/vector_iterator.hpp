#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "iterator_traits.hpp"


namespace ft 
{
	template<class T>
	class vector_iterator : public std::iterator<ft::random_access_iterator_tag, T>
	{
		public:
			typedef T												iterator_type;
			typedef	typename iterator_traits<T>::value_type			value_type;
			typedef typename iterator_traits<T>::difference_type	difference_type;
			typedef typename iterator_traits<T>::pointer			pointer;
			typedef typename iterator_traits<T>::reference			reference;
			typedef typename iterator_traits<T>::iterator_category	iterator_category;
	
		private:
			iterator_type	_current;

		public:
			vector_iterator() : _current(NULL) {}

			explicit vector_iterator(iterator_type it) : _current(it) {}

			template<class Iter>
			vector_iterator(const vector_iterator<Iter> &vec_it)
			{
				*this = vec_it;
			}

			~vector_iterator() {}

			template<class Iter>
			vector_iterator &operator=(const vector_iterator<Iter> &vec_it)
			{
				_current = vec_it.base();
				return (*this);
			}

			iterator_type	base() const
			{ return (_current); }

			reference	operator*() const
			{ return (*_current); }

			pointer	operator->() const
			{ return (&(*_current)); }

			vector_iterator	&operator++()
			{
				++_current;
				return (*this);
			}

			vector_iterator operator++(int)
			{
				vector_iterator temp(*this);
				++(*this);
				return (temp);
			}

			vector_iterator &operator--()
			{
				--_current;
				return (*this);
			}

			vector_iterator operator--(int)
			{
				vector_iterator temp(*this);
				--(*this);
				return (temp);
			}

			vector_iterator operator+(difference_type n) const
			{
				vector_iterator temp(_current + n);
				return (temp);
			}

			vector_iterator &operator+=(difference_type n)
			{
				_current += n;
				return (*this);
			}

			vector_iterator operator-(difference_type n) const
			{
				vector_iterator temp(_current - n);
				return (temp);
			}

			vector_iterator &operator-=(difference_type n)
			{
				_current -= n;
				return (*this);
			}

			reference	operator[](difference_type n) const
			{
				return (*(_current + n));
			}
	};


	template<class Iter>
	bool	operator==(const vector_iterator<Iter> &lhs, const vector_iterator<Iter> &rhs)
	{ return (lhs.base() == rhs.base()); }

	template<class Iter>
	bool	operator!=(const vector_iterator<Iter> &lhs, const vector_iterator<Iter> &rhs)
	{ return (lhs.base() != rhs.base()); }

	template<class Iter>
	bool	operator<(const vector_iterator<Iter> &lhs, const vector_iterator<Iter> &rhs)
	{ return (lhs.base() < rhs.base()); }

	template<class Iter>
	bool	operator<=(const vector_iterator<Iter> &lhs, const vector_iterator<Iter> &rhs)
	{ return (lhs.base() <= rhs.base()); }

	template<class Iter>
	bool	operator>(const vector_iterator<Iter> &lhs, const vector_iterator<Iter> &rhs)
	{ return (lhs.base() > rhs.base()); }

	template<class Iter>
	bool	operator>=(const vector_iterator<Iter> &lhs, const vector_iterator<Iter> &rhs)
	{ return (lhs.base() >= rhs.base()); }

	template<class Iter>
	vector_iterator<Iter> operator+(typename vector_iterator<Iter>::difference_type n, const vector_iterator<Iter> &vec_it)
	{ 
		vec_it += n;
		return (vec_it);
	}

	template<class Iter>
	typename vector_iterator<Iter>::difference_type operator-(const vector_iterator<Iter> &lhs, const vector_iterator<Iter> &rhs)
	{ return (lhs.base() - rhs.base()); }

}

#endif
