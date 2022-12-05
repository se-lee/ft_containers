#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "iterator_traits.hpp"


namespace ft 
{
	template<class T>
	class vector_iterator/* : public std::iterator<ft::random_access_iterator_tag, Iterator>*/
	{
		public:
			typedef ft::random_access_iterator_tag	iterator_category;
			typedef T								value_type;
			typedef std::ptrdiff_t					difference_type;
			typedef T&								reference;
			typedef T*								pointer;

		private:
			pointer		_current;

/*
		public:
			typedef Iterator													iterator_type;
			typedef	typename iterator_traits<iterator_type>::value_type			value_type;
			typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
			typedef typename iterator_traits<iterator_type>::pointer			pointer;
			typedef typename iterator_traits<iterator_type>::reference			reference;
			typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
	

		private:
			iterator_type	_current;*/


		public:
			vector_iterator() : _current(NULL) {}

			explicit vector_iterator(pointer it) : _current(it) {}
		
			template<class Iter>
			vector_iterator(const vector_iterator<Iter> &vec_it)
			{
				*this = vec_it;
			}

			template<class Iter>
			vector_iterator &operator=(const vector_iterator &vec_it)
			{
				_current = vec_it._current;
				return (*this);
			}

			pointer	base() const
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

	template<class T>
	class const_vector_iterator
	{
		public:
			typedef ft::random_access_iterator_tag	iterator_category;
			typedef T								value_type;
			typedef std::ptrdiff_t					difference_type;
			typedef T&								reference;
			typedef T*								pointer;
			typedef T const &						const_reference;
			typedef T const *					const_pointer;

		private:
			const_pointer		_current;

		public:
			const_vector_iterator() : _current(NULL) {}

			/*explicit */const_vector_iterator(const_pointer it) : _current(it) {}
		
			const_vector_iterator(const const_vector_iterator &vec_it)
			{
				*this = vec_it;
			}

			// template<class Iter>
			const_vector_iterator &operator=(const const_vector_iterator &vec_it)
			{
				_current = vec_it._current;
				return (*this);
			}

			const_pointer	base() const
			{ return (_current); }

			const_reference	operator*() const
			{ return (*_current); }

			const_pointer	operator->() const
			{ return (&(*_current)); }

			const_vector_iterator	&operator++()
			{
				++_current;
				return (*this);
			}

			const_vector_iterator operator++(int)
			{
				const_vector_iterator temp(*this);
				++(*this);
				return (temp);
			}

			const_vector_iterator &operator--()
			{
				--_current;
				return (*this);
			}

			const_vector_iterator operator--(int)
			{
				const_vector_iterator temp(*this);
				--(*this);
				return (temp);
			}

			const_vector_iterator operator+(difference_type n) const
			{
				const_vector_iterator temp(_current + n);
				return (temp);
			}

			const_vector_iterator &operator+=(difference_type n)
			{
				_current += n;
				return (*this);
			}

			const_vector_iterator operator-(difference_type n) const
			{
				const_vector_iterator temp(_current - n);
				return (temp);
			}

			const_vector_iterator &operator-=(difference_type n)
			{
				_current -= n;
				return (*this);
			}

			const_reference	operator[](difference_type n) const
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



	// const_vector_iterator

	template<class Iter>
	bool	operator==(const const_vector_iterator<Iter> &lhs, const const_vector_iterator<Iter> &rhs)
	{ return (lhs.base() == rhs.base()); }

	template<class Iter>
	bool	operator!=(const const_vector_iterator<Iter> &lhs, const const_vector_iterator<Iter> &rhs)
	{ return (lhs.base() != rhs.base()); }

	template<class Iter>
	bool	operator<(const const_vector_iterator<Iter> &lhs, const const_vector_iterator<Iter> &rhs)
	{ return (lhs.base() < rhs.base()); }

	template<class Iter>
	bool	operator<=(const const_vector_iterator<Iter> &lhs, const const_vector_iterator<Iter> &rhs)
	{ return (lhs.base() <= rhs.base()); }

	template<class Iter>
	bool	operator>(const const_vector_iterator<Iter> &lhs, const const_vector_iterator<Iter> &rhs)
	{ return (lhs.base() > rhs.base()); }

	template<class Iter>
	bool	operator>=(const const_vector_iterator<Iter> &lhs, const const_vector_iterator<Iter> &rhs)
	{ return (lhs.base() >= rhs.base()); }

	template<class Iter>
	const_vector_iterator<Iter> operator+(typename const_vector_iterator<Iter>::difference_type n, const const_vector_iterator<Iter> &vec_it)
	{ 
		vec_it += n;
		return (vec_it);
	}

	template<class Iter>
	typename const_vector_iterator<Iter>::difference_type operator-(const const_vector_iterator<Iter> &lhs, const const_vector_iterator<Iter> &rhs)
	{ return (lhs.base() - rhs.base()); }

}

#endif
