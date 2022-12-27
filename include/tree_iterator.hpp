#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft {

/************************** [ TREE NODE ] **************************/

	template<class T>
	struct tree_node
	{
		tree_node<T>	*_parent;
		tree_node<T>	*_left;
		tree_node<T>	*_right;
		T				_value;

		tree_node() : _parent(NULL), _left(NULL), _right(NULL), _value(NULL) {}
		tree_node(const T &pair = T()) : _parent(NULL), _left(NULL), _right(NULL), _value(pair) {}
	};

/************************** [ TREE ITER ] **************************/
	template<class T>
	class tree_iterator : public std::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			typedef T												iterator_type;
			typedef	typename iterator_traits<T>::value_type			value_type;
			typedef typename iterator_traits<T>::difference_type	difference_type;
			typedef typename iterator_traits<T>::pointer			pointer;
			typedef typename iterator_traits<T>::reference			reference;
			typedef typename iterator_traits<T>::iterator_category	iterator_category;

		private:
			typedef tree_node<value_type>*		node_pointer;
			node_pointer _current;
			node_pointer _root;
			
		public:
			tree_iterator() : _current(NULL), _root(NULL) {}
			tree_iterator(node_pointer ptr, node_pointer root) : _current(ptr), _root(root) {}
		
			template<class Iter>
			tree_iterator(const tree_iterator<Iter> &other)
			{ 
				_current = other.base();
				_root = other.root();
			}

			~tree_iterator() {}

			template<class Iter>
			tree_iterator &operator=(const tree_iterator<Iter> &other)
			{	
				_current = other.base();
				_root = other.root();
				return (*this);
			}

			node_pointer base() const
			{ return (_current); }

			node_pointer root() const
			{ return (_root); }

			reference operator*() const
			{ return (_current->_value); }

			pointer operator->() const
			{ return (&(_current->_value)); }

			tree_iterator &operator++()
			{
				if (_current == NULL)
				{
					_current = _root;
					while (_current->_left != NULL)
						_current = _current->_left;
				}
				else if (_current->_right != NULL)
				{
					_current = _current->_right;
					while (_current->_left != NULL)
						_current = _current->_left;
				}
				else
				{
					while (_current->_parent && (_current == _current->_parent->_right))
						_current = _current->_parent;
					if (_current->_parent)
						_current = _current->_parent;
					else
						_current = NULL;
				}
				return (*this);
			}

			tree_iterator operator++(int)
			{
				tree_iterator temp = *this;
				++(*this);
				return (temp);
			}

			tree_iterator &operator--()
			{
				if (_current == NULL)
				{
					_current = _root;
					while (_current->_right != NULL)
						_current = _current->_right;
				}
				else if (_current->_left != NULL)
				{
					_current = _current->_left;
					while(_current->_right != NULL)
						_current = _current->_right;
				}
				else
				{
					while (_current->_parent && (_current == _current->_parent->_left))
						_current = _current->_parent;
					if (_current->_parent)
						_current = _current->_parent;
					else
						_current = NULL;
				}
				return (*this);
			}

			tree_iterator operator--(int)
			{
				tree_iterator temp = *this;
				--(*this);
				return (temp);
			}
	};

	template<class Iterator1, class Iterator2>
	bool operator==(const tree_iterator<Iterator1> &lhs, const tree_iterator<Iterator2> &rhs)
	{ return (lhs.base() == rhs.base()); }

	template<class Iterator1, class Iterator2>
	bool operator!=(const ft::tree_iterator<Iterator1> &lhs, const ft::tree_iterator<Iterator2> &rhs)
	{ return (!(lhs.base() == rhs.base())); }

}


#endif