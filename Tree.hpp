/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:13:40 by kzennoun          #+#    #+#             */
/*   Updated: 2022/08/24 22:14:21 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "vector.hpp"
#include "utility.hpp"
#include "iterator.hpp"


namespace ft
{

	template <class T, class Allocator, class Compare>
	class Tree
	{
		public:

		typedef node<T> node_type;
		typedef node<const T> const_node_type;
		typedef Tree<T, Allocator, Compare> tree_type;
		typedef Allocator allocator_type;
		typedef Compare key_compare;
		typedef ft::__tree_iterator<T, Tree>	 iterator;
		typedef ft::__const_tree_iterator<T, Tree>		const_iterator;
		typedef	ft::reverse_iterator<iterator>						reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>				const_reverse_iterator;

		Tree(): _root(NULL), _allocator(allocator_type()), _compare(key_compare()), _size(0)
		{
			_before_first.before_first = true;
			_after_last.after_last = true;
		}

		~Tree()
		{
			clear(_root);
		}

		int get_size() const { return _size; } 
		allocator_type get_allocator() const { return _allocator; }
		key_compare get_compare() const { return _compare; }

		node_type *get_root() const { return _root; }
		node_type *get_after_last() const { return const_cast<node_type*>(&_after_last); }
		node_type *get_before_first() const { return const_cast<node_type*>(&_before_first); }

		bool is_tree_empty() const { return _root ? false :true; } 

		ft::pair<iterator, bool> &get_last_insert()  { return _last_insert; }
		int get_last_erase() const { return _last_erase; } 

		void set_root(node_type *root)
		{
			_root = root;
		}

		void set_size(int size)
		{
			_size = size;
		}

		tree_type &operator= (const tree_type & rhs)
		{
			clear(_root);
			_allocator = rhs.get_allocator();
			_compare = rhs.get_compare();

			if(rhs.get_size() == 0)
			{
				return *this;
			}
			const_iterator it = rhs.begin();
			const_iterator ite = rhs.end();

			while (it != ite)
			{
				set_root(insert(get_root(), *it));
				it++;
			}
			return *this;
		}

		iterator begin() 
		{
			node_type *ptr = get_root();
			
			if(!ptr)
				return iterator(NULL, this);
			while(ptr->left != NULL)
				ptr = ptr->left;
			return iterator(ptr, this);
		}

		const_iterator begin() const
		{

			node_type *ptr = get_root();

			if(!ptr)
				return const_iterator(NULL, this);
			while(ptr->left != NULL)
				ptr = ptr->left;
			return const_iterator(ptr, this);
		}

		iterator end()
		{
			node_type *ptr = get_root();

			if(!ptr)
				return iterator(NULL, this);
			return iterator(get_after_last(), this);
		}

		const_iterator end() const
		{
			node_type *ptr = get_root();

			if(!ptr)
				return const_iterator(NULL, this);
			return const_iterator(get_after_last(), this);
		}

		reverse_iterator rbegin()
		{
			node_type *ptr = get_root();

			if(!ptr)
				return reverse_iterator(iterator(NULL, this));
			return reverse_iterator(iterator(get_after_last(),this));
		}

		const_reverse_iterator rbegin() const 
		{
			node_type *ptr = get_root();

			if(!ptr)
				return const_reverse_iterator(const_iterator(NULL, this));
			return const_reverse_iterator(iterator(get_after_last(),this));
		}

		reverse_iterator rend()
		{
			node_type *ptr = get_root();

			if(!ptr)
				return reverse_iterator(iterator(NULL, this));
			return reverse_iterator(iterator(find_lowest(get_root()),this));
		}

		const_reverse_iterator rend() const 
		{
			node_type *ptr = get_root();

			if(!ptr)
				return const_reverse_iterator(const_iterator(NULL, this));
			return const_reverse_iterator(iterator(find_lowest(get_root()),this));
		}

		iterator find (const T& k)
		{
			node_type *tmp = get_root();

			while(tmp)
			{
				if(_compare(k.first, tmp->data->first))
				{
					tmp = tmp->left;
				}
				else if(_compare(tmp->data->first, k.first))
				{
					tmp = tmp->right;
				}
				else
				{
					return iterator(tmp, this);
				}
			}
			return end();
		}

		const_iterator find (const T& k) const
		{
			node_type *tmp = get_root();

			while(tmp)
			{
				if(_compare(k.first, tmp->data->first))
					tmp = tmp->left;
				else if(_compare(tmp->data->first, k.first))
					tmp = tmp->right;
				else
					return const_iterator(tmp, this);
			}
			return end();		
		}

		size_t count (const T& k) const
		{
			const_iterator it = find(k);

			return it == end() ? 0 : 1;
		}

		template<class X>
		iterator lower_bound(const X& k)
		{
			node_type *ptr = get_root();
			node_type *previous = NULL;

			if (!ptr)
				return end();

			while ( ptr ) {
				if ( !_compare( ptr->data->first, k ) && !_compare( k, ptr->data->first ) )
					return iterator(ptr, this);
				if ( _compare( ptr->data->first, k ) )
					ptr = ptr->right;
				else {
					if ( previous == NULL || _compare( ptr->data->first, previous->data->first ) )
						previous = ptr;
					ptr = ptr->left;
				}
			}
			if ( previous )
				return iterator(previous, this);
			return end();
		}

		template<class X>
		const_iterator lower_bound(const X& k) const
		{
			node_type *ptr = get_root();
			node_type *previous = NULL;

			if (!ptr)
				return end();

			while ( ptr ) {
				if ( !_compare( ptr->data->first, k ) && !_compare( k, ptr->data->first ) )
					return const_iterator(ptr, this);
				if ( _compare( ptr->data->first, k ) )
					ptr = ptr->right;
				else {
					if ( previous == NULL || _compare( ptr->data->first, previous->data->first ) )
						previous = ptr;
					ptr = ptr->left;
				}
			}
			if ( previous )
				return const_iterator(previous, this);
			return end();
		}

		template<class X>
		iterator upper_bound (const X& k)
		{
			iterator low = lower_bound(k);

			if (_compare( k, low.get_it()->data->first ))
				return low;
			low++;
			return low;
		}

		template<class X>
		const_iterator upper_bound (const X& k) const
		{
			const_iterator low = lower_bound(k);

			if (_compare( k, low.get_it()->data->first ))
				return low;
			low++;
			return low;
		}

		void swap(Tree& x)
		{
			std::swap(_root, x._root);
			std::swap(_last_insert, x._last_insert);
			std::swap(_last_erase, x._last_erase);
			std::swap(_before_first, x._before_first);
			std::swap(_after_last, x._after_last);
			std::swap(_size, x._size);
		}

		void clear(node_type *parent)
		{
			if(!parent || parent->after_last || parent->before_first )
				return;
			if (parent->left)
			{
				clear(parent->left);
				parent->left = NULL;
			}
			if (parent->right)
			{
				clear(parent->right);
				parent->right = NULL;
			}
			_allocator.destroy(parent->data);
			_allocator.deallocate(parent->data, 1);
			std::allocator<node_type>().destroy(parent);
			std::allocator<node_type>().deallocate(parent, 1);
			_size = 0;
		}

		int difference(node_type *parent)
		{
			int left_height;
			int right_height;

			if (parent->left)
				left_height = parent->left->height;
			else
				left_height = 0;

			if (parent->right)
				right_height = parent->right->height;
			else
				right_height = 0;
			return (left_height - right_height);
		}

		void update_height(node_type *parent)
		{
			if(!parent)
				return;
			parent->height =  1 + std::max((parent->left != NULL ? parent->left->height : 0), (parent->right != NULL ? parent->right->height : 0));	
		}

		node_type *left_rotate(node_type *parent)
		{
			node_type *newparent;
			node_type *tmp;

			newparent = parent->right;
			tmp = newparent->left;
			parent->right = newparent->left; 
			newparent->left = parent;

			if (tmp != NULL)
				tmp->parent = parent;
			newparent->parent = parent->parent;
			parent->parent = newparent;

			update_height(parent);
			update_height(newparent);
			return newparent;
		}

		node_type *right_rotate(node_type *parent)
		{
			node_type *newparent;
			node_type *tmp;

			newparent = parent->left;
			tmp = newparent->right;
			parent->left = newparent->right;
			newparent->right = parent;

			if (tmp != NULL)
				tmp->parent = parent;
			newparent->parent = parent->parent;
			parent->parent = newparent;

			update_height(parent);
			update_height(newparent);		
			return newparent;
		}

		node_type *double_r_rotate(node_type *parent)
		{
			node_type *tmp;

			tmp = parent->left;
			parent->left = left_rotate(tmp);
			return right_rotate(parent);
		}

		node_type *double_l_rotate(node_type *parent)
		{
			node_type *tmp;

			tmp = parent->right;
			parent->right = right_rotate(tmp);
			return left_rotate(parent);
		}

		node_type *balance(node_type *parent)
		{
			int balance = difference(parent);
			if (balance > 1)
			{
				if (difference(parent->left) > 0)
					parent = right_rotate(parent);
				else
					parent = double_r_rotate(parent);
			}
			else if (balance < -1)
			{
				if (difference(parent->right) > 0)
					parent = double_l_rotate(parent);
				else
					parent = left_rotate(parent);
			}
			return parent;
		}

		node_type *insert(node_type *current_root,const T &data)
		{
			if (current_root == NULL)
			{
				try 
				{
					current_root = std::allocator<node_type>().allocate(1);
				}
				catch (std::bad_alloc& ba)
				{
					std::cerr << "Error allocating node: " << ba.what() << '\n';
					current_root = NULL;
					throw;
					return current_root;
				}
				std::allocator<node_type>().construct(current_root, node_type());

				try 
				{
					current_root->data = _allocator.allocate(1);
				}
				catch (std::bad_alloc& ba)
				{
					std::cerr << "Error allocating T: " << ba.what() << '\n';
					current_root->data = NULL;
					throw;
					return current_root;
				}
				_allocator.construct(current_root->data, data);
 				_last_insert = ft::make_pair(iterator(current_root, this), true);
				_size++;
				return current_root;
			}
			else if (_compare(data.first, current_root->data->first))
			{
				current_root->left = insert(current_root->left, data);
				current_root->left->parent = current_root;
				update_height(current_root);
				current_root = balance(current_root);
			}
			else if (_compare(current_root->data->first, data.first))
			{
				current_root->right = insert(current_root->right, data);
				current_root->right->parent = current_root;
				
				update_height(current_root);
				current_root = balance(current_root);
			}
			else
			{

				_last_insert = ft::make_pair(iterator(current_root, this), false);
			}
			return current_root;
		}

		node_type *find_lowest(node_type* node) const
		{
			node_type* current = node;
		
			while (current->left != NULL)
				current = current->left;
		
			return current;
		}

		node_type *find_highest(node_type* node) const
		{
			node_type* current = node;
		
			while (current->right != NULL)
				current = current->right;
		
			return current;
		}

		node_type* erase(node_type* parent, T key)
		{
			if (parent == NULL)
			{
				_last_erase = 0;
				return parent;
			}

			if (_compare(key.first, parent->data->first))
			{
				parent->left = erase(parent->left, key);
			}
			else if (_compare(parent->data->first, key.first))
			{
				parent->right = erase(parent->right, key);
			}
			else
			{
				if( (parent->left == NULL) ||
					(parent->right == NULL) )
				{
					node_type *temp = parent->left ?
								parent->left :
								parent->right;
		
					if (temp == NULL)
					{
						temp = parent;
						parent = NULL;
					}
					else
					{
						_allocator.destroy(parent->data);
						_allocator.construct(parent->data, *(temp->data));
						parent->left = NULL;
						parent->right = NULL;

					}
					if (temp)
					{
						_allocator.destroy(temp->data);
						_allocator.deallocate(temp->data, 1);
						std::allocator<node_type>().destroy(temp);
						std::allocator<node_type>().deallocate(temp, 1);
						_last_erase = 1;
						_size--;
					}
				}
				else
				{
					node_type* temp = find_lowest(parent->right);
					_allocator.destroy(parent->data);
					_allocator.construct(parent->data, *(temp->data));
					parent->right = erase(parent->right,
											*(temp->data));
				}
			}

			if (parent == NULL)
				return parent;

			update_height(parent);
			parent = balance(parent);	
			return parent;
		}

		protected:

		private:

		node_type *_root;
		allocator_type	_allocator;
		key_compare		_compare;
		int _size;
		ft::pair<iterator, bool> _last_insert;
		int _last_erase;
		node_type _before_first;
		node_type _after_last;
	};

}


#endif