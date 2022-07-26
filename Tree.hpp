/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:13:40 by kzennoun          #+#    #+#             */
/*   Updated: 2022/07/26 11:02:10 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

//#include "utility.hpp"
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "iterator.hpp"

namespace ft
{

	template <class T>
	struct node
	{
		struct node<T> *left;
		struct node<T> *right;
		struct node<T> *parent;
		int height;
		T *data;

		node():
		left(NULL),
		right(NULL),
		parent(NULL),
		height(1),
		data(NULL)
		{}

		~node(){}
	};

	template <class T, class Allocator, class Compare>
	class Tree
	{
		public:

		typedef node<T> node_type;
		typedef Tree<T, Allocator, Compare> tree_type;
		typedef Allocator allocator_type;
		typedef Compare key_compare;
		typedef ft::__tree_iterator<T, Tree>	 iterator;
		typedef ft::__tree_iterator<const T, Tree>		const_iterator;	
//constructors
		Tree(): _root(NULL), _allocator(allocator_type()), _compare(key_compare()), _size(0)
		{
			
		}
//destructor
		~Tree()
		{
			//clear toutes les nodes
		}

		tree_type &operator= (const tree_type & rhs)
		{
			//clear le tree avec ancien allocator
			//copy allocator/compare
			//deep copy, iter over rhs tree and insert into this
		}

		iterator begin()
		{
			iterator ret;
			ret->_it = tree->get_root();
			if (ret->_it == NULL)
				return NULL;

			while (ret->_it->left != NULL)
				ret->_it = ret->_it->left;
			return *ret;		
		}

		const_iterator begin() const
		{
			iterator ret = begin();
			return const_iterator(*ret, this);
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

		int get_size() const { return _size; } 
		node_type *get_root() const { return _root; }
		void set_root(node_type *root)
		{
			_root = root;
		}

		void set_size(int size)
		{
			_size = size;
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


		node_type *insert(node_type *current_root, T &data)
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
				_allocator.construct(current_root, node_type());

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
				_size++;
				return current_root;
			}
			else if (_compare(*(current_root->data), data))
			{
				current_root->left = insert(current_root->left, data);
				current_root->left->parent = current_root;
				update_height(current_root);
				current_root = balance(current_root);
			}
			else if (_compare(data, *(current_root->data)))
			{
				current_root->right = insert(current_root->right, data);
				current_root->right->parent = current_root;
				
				update_height(current_root);
				current_root = balance(current_root);
			}
			else
			{
				//equals
//std::cout << "cannot add equal value" << std::endl;
			}
			return current_root;
		}



	// node_type *find_lowest(node_type* node)
	// {
	// 	node_type* current = node;
	
	// 	while (current->left != NULL)
	// 		current = current->left;
	
	// 	return current;
	// }

	node_type *find_lowest(node_type* node) const
	{
		node_type* current = node;
	
		while (current->left != NULL)
			current = current->left;
	
		return current;
	}

	// node_type *find_highest(node_type* node)
	// {
	// 	node_type* current = node;
	
	// 	while (current->right != NULL)
	// 		current = current->right;
	
	// 	return current;
	// }

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
			return parent;

		if (_compare(*(parent->data), key))
		{
			parent->left = erase(parent->left, key);
		}
		else if (_compare(key, *(parent->data)))
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
		
	};

}








#endif