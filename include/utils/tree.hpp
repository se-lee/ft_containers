#ifndef TREE_HPP
# define TREE_HPP

# include <memory>
# include <functional>
# include "pair.hpp"
# include "../iterators/bidirectional_iterator.hpp"
# include "../iterators/tree_iterator.hpp"

namespace ft
{

template<class Type, class Compare = std::less<Type>, class Allocator = std::allocator<tree_node<Type> > >
class tree
{
	public:
		typedef Type												value_type;
		typedef Compare												value_compare;
		typedef Allocator											allocator_type;
		typedef typename Allocator::template rebind<tree_node<Type> >::other node_allocator;
		typedef std::size_t											size_type;
		typedef ft::tree_node<value_type>*							pointer;
		typedef	const ft::tree_node<value_type>*					const_pointer;
		typedef tree_iterator<ft::tree_node<value_type> >			iterator;
		typedef const_tree_iterator<ft::tree_node<value_type> > 	const_iterator; 

	private:
		pointer					_root;
		pointer					_begin;
		pointer					_end;
		size_t					_size;
		value_compare			_value_compare;
		allocator_type			_allocator;

	public:
		tree() : _root(NULL), _begin(NULL), _end(NULL), _size(0) {}
		tree(const value_compare &comp, const allocator_type &a) : _root(NULL), _begin(NULL), _end(NULL), _size(0) 
		{ 
			_value_compare = comp; 
			_allocator = a;
		}
	
		template<class InputIterator>
		tree (InputIterator first, InputIterator last, const Compare &comp, const Allocator &alloc)
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
			clear_all_elements();
		}

		tree &operator=(const tree &other)
		{
			_root = other._root;
			_begin = other._begin;
			_end = other._end;
			_allocator = other._allocator;
			_value_compare = other._value_compare;
		
			return (*this);
		}

		size_t	size()
		{ return (_size); }

		bool empty() const { return (!_size); }

		iterator begin() 
		{ return (iterator(_begin)); }

		const_iterator begin() const 
		{ return (const_iterator(_begin)); }

		iterator end() 
		{ return (iterator(_end)); }
		
		const_iterator end() const 
		{ return (const_itertor(_end)); }

		iterator root() 
		{ return (iterator(_root)); }
		
		const_iterator root() const 
		{ return (iterator(_root)); }

		size_type max_size();

		void clear()
		{
			_allocator.destroy(_root);
			_size = 0;
			_begin = _end;
			_end->_left = NULL;
		}

		void clear_all_elements()
		{
			for (pointer ptr = _begin; ptr != _end; ptr++)
				_allocator.destroy(ptr);
			_size = 0;
		}

		void swap();




		template<class value_type>
		bool is_left_child(pointer x) const
		{ return (x == x->_parent->_left); }

		template<class value_type>
		bool is_right_child(pointer x) const
		{ return (x == x->_parent->_right); }

		template<class value_type>
		void set_parent(pointer x, pointer p)
		{ x->_parent = p; }


		template<class value_type>
		void	tree_left_rotate(pointer x) const
		{
			pointer y = x->_right;

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

		pointer find_insert_place(pointer root, const value_type &value)
		{
			while (true) {
				if (value_compare() (value.first, root->_pair_value.first)) {
					if (root->_left != NULL)
						root = root->_left;
					else
						return (root->_left);
				}
				else if (value_compare() (root->_pair_value, value)) {
					if (root->_right != NULL)
						root = root->_right;
					else
						return (root->_right);
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
			pointer new_node;
			new_node = _allocator.allocate(1);
			_allocator.construct(new_node, value);
			if (_root == NULL) { // first node insertion
				_root = new_node;
				_begin = _root;
				_end = _root;
				_size++;
				return (ft::pair<iterator, bool>(new_node, true));
			}
			new_node = find_insert_place(_root, value);
			
		

// new_node にInsert placeのポインター代入。NULLでなければ重複あり、Nullであれば重複なし

			// if key doesnt exist, create a new node
			// if there is no root node, set new node as the root;
			// else, search for the place to insert new_node;

			return (ft::pair<iterator, bool>(new_node, true));
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