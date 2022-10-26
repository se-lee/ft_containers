#ifndef TREE_HPP
# define TREE_HPP

# include "bidirectional_iterator.hpp"
# include "pair.hpp"


/*
Nodeクラスを作る：各Nodeの生成、データ型としてTreeで使う



Treeクラス

*/


namespace ft
{
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



	};



}



#endif