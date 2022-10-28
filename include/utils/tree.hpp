#ifndef TREE_HPP
# define TREE_HPP

# include "bidirectional_iterator.hpp"
# include "pair.hpp"

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
	// template<class T, class NodePtr, class DiffType>
	// class tree_iterator
	// {
	// 	private:	
	// 		typedef	/*_tree_node_types<NodePtr>*/			node_types;
	// 		typedef	NodePtr									node_pointer;
	// 		typedef typename node_types::iter_pointer		iter_pointer;

	// 		iter_pointer _ptr;

	// 	public:
	// 		typedef bidirectional_iterator_tag						iterator_category;
	// 		typedef T												value_type;
	// 		typedef DiffType										difference_type;
	// 		typedef value_type&										reference;
	// 		typedef typename node_types::node_value_type_pointer	pointer;

	// 		reference operator*() const { return (get_np()->_value); }
	// 		pointer operator->() const { return (pointer_traits<pointer>::pointer_to(get_np()->_value)); }
	// 		tree_iterator &operator++() 
	// 		{
	// 			/* _ptr to next element */
	// 			return (*this);
	// 		}

	// 		tree_iterator operator++(int)
	// 		{
	// 			tree_iterator temp = *this;
	// 			++(*this);
	// 			return (temp);
	// 		}

	// 		tree_iterator &operator--()
	// 		{
	// 			/* _ptr to previous element */
	// 			return (*this);
	// 		}

	// 		tree_iterator operator--(int)
	// 		{
	// 			tree_iterator temp = *this;
	// 			--(*this);
	// 			return (temp);
	// 		}

	// 		bool operator==(const tree_iterator &x, const tree_iterator &y)
	// 		{ return (x._ptr == y._ptr); }

	// 		bool operator!=(const tree_iterator &x, const tree_iterator &y)
	// 		{ return (!(x == y)); }
	// };

/************************** [ TREE CLASS ] **************************/

	template<class T, class Compare, class Alloc>
	class tree
	{
		public:
			typedef	T			value_type;
			typedef Compare		value_compare;
			typedef Alloc		allocator_type;

		private:
			/* iterator pointer */	_begin_node;
			/* compressed_pair<_end_node_type, _node_allocator> ??? */ _pair1;
			/* compressed_pair<size_type, value_compare> */	_pair3;

		public:
			iterator begin() { return (iterator(_begin_node); }
			const_iterator begin() { return (const_iterator(_begin_node)); }
			iterator end() { return (iterator(_en))}
			const_iterator end();
			size_type max_size();

	};
}

#endif