#ifndef TREE_HPP
# define TREE_HPP

# include "bidirectional_iterator.hpp"
# include "pair.hpp"
# include <memory>

/*
- Nodeクラスを作る：各Nodeの生成、データ型としてTreeで使う
- tree iterator
- Treeクラス
*/


namespace ft
{
/************************** [ TREE NODE ] **************************/

	template<class Pair>
	struct tree_node
	{
		typedef	tree_node<Pair>*	pointer;
	
		pointer		_parent;
		pointer		_left;
		pointer		_right;
		Pair		_pair_value;

		node() : _parent(NULL), _left(NULL), _right(NULL), _pair_value() {}
		node(const Pair &pr) : _parent(NULL), _left(NULL), _right(NULL), _pair_value(pr) {}

	};

/************************** [ TREE ITER ] **************************/
	template<class T, class NodePtr, class DiffType>
	class tree_iterator
	{
		private:	
			typedef	/*_tree_node_types<NodePtr>*/			node_types;
			typedef	NodePtr									node_pointer;
			typedef typename node_types::iter_pointer		iter_pointer;

			iter_pointer _ptr;

		public:
			typedef bidirectional_iterator_tag						iterator_category;
			typedef T												value_type;
			typedef DiffType										difference_type;
			typedef value_type&										reference;
			typedef typename node_types::node_value_type_pointer	pointer;

			reference operator*() const { return (get_np()->_value); }
			pointer operator->() const { return (pointer_traits<pointer>::pointer_to(get_np()->_value)); }
			tree_iterator &operator++() 
			{
				/* _ptr to next element */
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
				/* _ptr to previous element */
				return (*this);
			}

			tree_iterator operator--(int)
			{
				tree_iterator temp = *this;
				--(*this);
				return (temp);
			}

			bool operator==(const tree_iterator &x, const tree_iterator &y)
			{ return (x._ptr == y._ptr); }

			bool operator!=(const tree_iterator &x, const tree_iterator &y)
			{ return (!(x == y)); }
	};

/************************** [ TREE CLASS ] **************************/

	template<class T, class Compare, class Alloc = std::allocator<T> >
	class tree
	{
		public:
			typedef	T			value_type;
			typedef Compare		value_compare;
			typedef Alloc		allocator_type;

			typedef typename allocator_traits<Alloc>::pointer				pointer;
			typedef typename allocator_traits<Alloc>::const_pointer			const_pointer;
			typedef typename allocator_traits<Alloc>::size_type				size_type;
			typedef typename allocator_traits<Alloc>::difference_type		difference_type;

			typedef tree_iterator<value_type, /* Node pointer,*/ difference_type>	iterator;
			typedef tree_const_iterator<value_type, /* node pointer, */ difference_type> const_iterator; 

		private:
			tree_node	*_begin_node;
			tree_node	*_end_node;

		public:

			explicit tree(const value_compare &comp);
			explicit tree(const allocator_type &a);
			tree(const value_comapre &comp, const allocator_type &a);
			tree(tree &t);

			~tree();

			tree &operator=(const tree &_t);

			iterator begin() { return (iterator(_begin_node); }
			const_iterator begin() { return (const_iterator(_begin_node)); }

			iterator end() { return (iterator(_en))}
			const_iterator end();

			size_type max_size();

			void clear();
			void swap();
		
			template<class T>
			bool is_left_child(tree_node<T> *x) const
			{ return (x == x->_parent->_left); }

			template<class T>
			bool is_right_child(tree_node<T> *x) const
			{ return (x == x->_parent->_right); }



			template<class T>
			void set_parent(tree_node<T> *x, tree_node<T> *p)
			{ x->_parent = p; }

			// returns pointer to the left-most node under x node
			template<class T>
			tree_node<T>	*tree_min(tree_node<T> *x) const
			{
				while (x->_left != NULL)
					x = x->_left;
				return (x);
			}

			// returns pointer to the right-most node under x node
			template<class T>
			tree_node<T>	*tree_max(tree_node<T> *x) const
			{
				while(x->_right != NULL)
					x = x->_right;
				return (x);
			}

			// returns pointer to the next in-order node after x
			template<class T>
			tree_node<T>	*tree_next(tree_node<T> *x) const
			{
				if (x->_right != NULL)
					return (tree_min(x->_right));
				while (!is_left_child(x))
					x = x->_parent;
				return (x->_parent);
			}

/*
template <class _EndNodePtr, class _NodePtr>
inline _LIBCPP_INLINE_VISIBILITY
_EndNodePtr
__tree_next_iter(_NodePtr __x) _NOEXCEPT
{
    if (__x->__right_ != nullptr)
        return static_cast<_EndNodePtr>(_VSTD::__tree_min(__x->__right_));
    while (!_VSTD::__tree_is_left_child(__x))
        __x = __x->__parent_unsafe();
    return static_cast<_EndNodePtr>(__x->__parent_);
}

// Returns:  pointer to the previous in-order node before __x.
// Precondition:  __x != nullptr.
// Note: __x may be the end node.
template <class _NodePtr, class _EndNodePtr>
inline _LIBCPP_INLINE_VISIBILITY
_NodePtr
__tree_prev_iter(_EndNodePtr __x) _NOEXCEPT
{
    if (__x->__left_ != nullptr)
        return _VSTD::__tree_max(__x->__left_);
    _NodePtr __xx = static_cast<_NodePtr>(__x);
    while (_VSTD::__tree_is_left_child(__xx))
        __xx = __xx->__parent_unsafe();
    return __xx->__parent_unsafe();
}

*/

		// returns pointer to a node which has no children
		template<class T>
		tree_node<T>	*tree_leaf(tree_node<T> x) const
		{
			while (true)
			{
				if (x->_left != NULL)
				{
					x = x->_left;
					continue ;
				}
				if (x->_right != NULL)
				{
					x = x->_right;
					continue ;
				}
				break ;
			}
			return (x);
		}



/* Rotation系のやつ */
	template<class T>
	void	tree_left_rotate(tree_node *x) const
	{
		tree_node *y = x->_right;

		x->_right = y->_left;
		if (x->_right != NULL)
			x->_right -> set_parent(x);
		y->parent = x->_parent;
		if (is_left_child(x))
			x->_parent->_left = y;
		else
			x->_parent->_right = y;
			y->_left = _x;
			x->set_parent(y);
	}

	};
}

#endif