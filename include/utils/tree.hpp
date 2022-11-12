#ifndef TREE_HPP
# define TREE_HPP

# include <memory>
# include <functional>
# include "pair.hpp"
# include "../iterators/bidirectional_iterator.hpp"
# include "../iterators/tree_iterator.hpp"

namespace ft
{
// template<class Key, class T, class Compare = std::less<ft::pair<Key, T> >, class Allocator = std::allocator<ft::tree_node<ft::pair<const Key, T> > > > ;


template<class Type, class Compare, class Allocator = std::allocator<ft::tree_node<Type> > >
class tree
{
	public:
		typedef Type				value_type;
		typedef Compare			value_compare;
		typedef Allocator				allocator_type;
		typedef std::size_t				size_type;

		typedef tree_iterator<value_type>						iterator;
		typedef const_tree_iterator<value_type> 				const_iterator; 

	private:
		tree_node<value_type>	*_root_node;
		tree_node<value_type>	*_begin_node;
		tree_node<value_type>	*_end_node;
		allocator_type			_allocator;
		value_compare			_value_compare;
		size_t					_size;

	public:
		tree() : _root_node(NULL), _begin_node(NULL), _end_node(NULL) {}
		explicit tree(const value_compare &comp) : _root_node(NULL), _begin_node(NULL), _end_node(NULL), _allocator(NULL), _value_compare(comp) {}
		explicit tree(const allocator_type &a) : _root_node(NULL), _begin_node(NULL), _end_node(NULL), _allocator(a), _value_compare(NULL) {}
		tree(const value_compare &comp, const allocator_type &a) : _root_node(NULL), _begin_node(NULL), _end_node(NULL), _allocator(a), _value_compare(comp) {}

		template<class InputIterator>
		tree (InputIterator first, InputIterator last, const Compare &comp = Compare(), const Allocator &alloc = Allocator())
		{
			_allocator = alloc;
			_value_compare = comp;
			insert(first, last);
		}

		tree(const tree &other )
		{
			*this = other;
			return (*this);
		}

		~tree() 
		{
			clear();
		}

		tree &operator=(const tree &other)
		{
			_root_node = other._root_node;
			_begin_node = other._begin_node;
			_end_node = other._end_node;
			_allocator = other._allocator;
			_value_compare = other._value_compare;
		
			return (*this);
		}

		size_t	size()
		{ return (_size); }

		bool empty() const { return (!_size); }

		iterator begin() 
		{ return (iterator(_begin_node)); }

		const_iterator begin() const 
		{ return (const_iterator(_begin_node)); }

		iterator end() 
		{ return (iterator(_end_node)); }
		
		const_iterator end() const 
		{ return (const_itertor(_end_node)); }

		iterator root() 
		{ return (iterator(_root_node)); }
		
		const_iterator root() const 
		{ return (iterator(_root_node)); }

		size_type max_size();

		void clear()
		{
			_allocator.destroy(_root_node);
			_size = 0;
			_begin_node = _end_node;
			_end_node->_left = NULL;
		}


		void swap();

		template<class value_type>
		bool is_left_child(tree_node<value_type> *x) const
		{ return (x == x->_parent->_left); }

		template<class value_type>
		bool is_right_child(tree_node<value_type> *x) const
		{ return (x == x->_parent->_right); }

		template<class value_type>
		void set_parent(tree_node<value_type> *x, tree_node<value_type> *p)
		{ x->_parent = p; }


		template<class value_type>
		void	tree_left_rotate(tree_node<value_type> *x) const
		{
			tree_node<value_type> *y = x->_right;

			x->_right = y->_left;
			if (x->_right != NULL)
				x->_right -> set_parent(x);
			y->parent = x->_parent;
			if (is_left_child(x))
				x->_parent->_left = y;
			else
				x->_parent->_right = y;
				y->_left = x;
				x->set_parent(y);
		}

		// tree_node<value_type>	*find_insert_place(tree_node<value_type> *parent, const value_type &value)
		// {
		// 	tree_node<value_type> *sub_root = parent;
		// 	if (sub_root != NULL) {
		// 		while (true){
		// 			if (value_compare() (value, sub_root->_pair_value)) { // to the left
		// 				if (sub_root->left != NULL)
		// 					sub_root = sub_root->left;
		// 				else {
		// 					parent = sub_root;
		// 					return (parent._left);
		// 				}
		// 			}
		// 			else if (value_compare() (sub_root->pair_value, value)) { // to the right
		// 				if (sub_root->right != NULL)
		// 					sub_root = sub_root->right;
		// 				else {
		// 					parent = sub_root;
		// 					return (sub_root->right);
		// 				}
		// 			}
		// 			else { 
		// 				parent = sub_root;
		// 				return (parent);
		// 			}
		// 		}
		// 	}
		// 	parent = _end_node;
		// 	return (parent->_left);
		// }

		tree_node<value_type>	*find_insert_place(tree_node<value_type> *root/*root*/, const value_type &value)
		{
			while (true) { //std::less<int>()(2, 3)
				if (_value_compare(value.first, root->_pair_value.first)) {
					if (root->_left != NULL)
						root = root->_left;
					else // if root has no left child
						return (root->_left); //null
				}
				else if (_value_compare(root->_pair_value, value)) {
					if (root->_right != NULL)
						root = root->_right;
					else
						return (root->_right); //null
				}
				else {
					return (root);
				}
			}
		}

	/*
		挿入された場合には、first に挿入された要素へのイテレータ、 second に true が設定される。
		挿入されなかった場合には、 first に x と等価のキーを持つ要素へのイテレータ、 second に false が設定される。
	*/
		ft::pair<iterator, bool>	insert(const value_type &value)
		{
			tree_node<value_type> *new_node;
			new_node = _allocator.allocate(1);
			_allocator.construct(new_node, value);
			if (_root_node == NULL) { // first node insertion
				_root_node = new_node;
				_begin_node = _root_node;
				_end_node = _root_node;
				_size++;
				return (ft::pair<iterator, bool>(iterator(new_node), true));
			}
			new_node = find_insert_place(_root_node, value);
			
		

// new_node にInsert placeのポインター代入。NULLでなければ重複あり、Nullであれば重複なし

			// if key doesnt exist, create a new node
			// if there is no root node, set new node as the root;
			// else, search for the place to insert new_node;

			return (ft::pair<iterator, bool>(iterator(new_node), true));
		}


		iterator insert(const_iterator it, const value_type &x);

		template<class InputIterator>
		void insert(InputIterator first, InputIterator last);

// erase
		iterator erase( iterator pos );
		iterator erase( iterator first, iterator last );
		// size_type erase( const Key &key );

		allocator_type get_allocator() const { return (_allocator); }

// rotate


};

}

#endif