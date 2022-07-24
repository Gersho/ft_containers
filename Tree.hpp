/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:13:40 by kzennoun          #+#    #+#             */
/*   Updated: 2022/07/24 14:27:19 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

//#include "utility.hpp"
#include <cstdlib>
#include <iostream>
#include <stdexcept>

namespace ft
{

	template <class T>
	struct node
	{
		struct node<T> *left;
		struct node<T> *right;
		struct node<T> *parent;
		unsigned int left_height;
		unsigned int right_height;
		T *data;

		node():
		left(NULL),
		right(NULL),
		parent(NULL),
		left_height(0),
		right_height(0),
		data(NULL)
		{}

		~node(){}
	};

	template <class T, class Allocator, class Compare>
	class Tree
	{
		public:

		typedef node<T> node_type;
		typedef Allocator allocator_type;
		typedef Compare key_compare;

//constructors
		Tree(): _root(NULL), _allocator(allocator_type()) 
		{
			
		}
//destructor
		~Tree()
		{
			//clear toutes les nodes
		}

		// int height(node_type *parent)
		// {
		// 	int h = 0;
		// 	if (parent != NULL)
		// 	{
		// 		int l_height = height(parent->left);
		// 		int r_height = height(parent->right);
		// 		int max_height = max(l_height, r_height);
		// 		h = max_height + 1;
		// 	}
		// 	return h;
		// }

		// void show(node_type *p, int l) {
		// 	int i;
		// 	if (p != NULL) {
		// 	show(p->right, l+ 1);
		// 	std::cout<<" ";
		// 	if (p == _root)
		// 		std::cout << "Root -> ";
		// 	for (i = 0; i < l&& p != _root; i++)
		// 		std::cout << " ";
		// 		std::cout << *(p->data);
		// 		show(p->left, l + 1);
		// 	}
		// }

		int difference(node_type *parent)
		{
			return (parent->left_height - parent->right_height);
		}

		void update_heights(node_type *parent)
		{
			if (!parent)
				return;

			if (parent->left)
			{
				parent->left_height = ((parent->left->left_height < parent->left->right_height) ? parent->left->right_height : parent->left->left_height) + 1;
			}
			else
			{
				parent->left_height = 0;
			}

			if (parent->right)
			{
				parent->right_height = ((parent->right->left_height < parent->right->right_height) ? parent->right->right_height : parent->right->left_height) + 1;
			}
			else
			{
				parent->right_height = 0;
			}
			
		}

		node_type *get_root() const { return _root; }
		void set_root(node_type *root)
		{
			_root = root;
		}

		node_type *left_rotate(node_type *parent)
		{
			node_type *newparent;
			node_type *tmp;
std::cout << "rotating left on node: " << *(parent->data) << std::endl;
			newparent = parent->right; // H = U->right;
			tmp = newparent->left;
			parent->right = newparent->left;  //U->right = I = H->left; 
			newparent->left = parent; // H->left = U; 

			if (tmp != NULL)
				tmp->parent = parent;
			newparent->parent = parent->parent;
			parent->parent = newparent;

			//update heights
			update_heights(parent);
			update_heights(newparent);
			return newparent;
		}

		node_type *right_rotate(node_type *parent)
		{
			node_type *newparent;
			node_type *tmp;
std::cout << "rotating right on node: " << *(parent->data) << std::endl;
			newparent = parent->left;
			tmp = newparent->right;
			parent->left = newparent->right;
			newparent->right = parent;

			if (tmp != NULL)
				tmp->parent = parent;
			newparent->parent = parent->parent;
			parent->parent = newparent;

//update heights parent et newparent
			// parent->left_height;
			// parent->right_height;
			// newparent->left_height;
			// newparent->right_height;	
			update_heights(parent);
			update_heights(newparent);		
			return newparent;
		}


		node_type *double_r_rotate(node_type *parent)
		{
			node_type *tmp;
std::cout << "rotating double r on node: " << *(parent->data) << std::endl;
			tmp = parent->left;
			parent->left = left_rotate(tmp);
			return right_rotate(parent);
		}

		node_type *double_l_rotate(node_type *parent)
		{
			node_type *tmp;
std::cout << "rotating double l on node: " << *(parent->data) << std::endl;
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
					//current_root = _allocator.allocate(sizeof(node_type));
					//current_root = std::allocator<node_type>().allocate(sizeof(node_type));
					current_root = std::allocator<node_type>().allocate(1);
				}
				catch (std::bad_alloc& ba)
				{
					std::cerr << "Error allocating node: " << ba.what() << '\n';
					current_root = NULL;
					throw;
					return current_root;
				}

				//construct la node ?
				//node constructor qui construit la pair ?
				_allocator.construct(current_root, node_type());



				try 
				{
					//current_root->data = _allocator.allocate(sizeof(T));
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
				//current_root->data = data;

				current_root->left = NULL;
				current_root->right = NULL;
				return current_root;
			}
			else if (data < *(current_root->data))
			{
				current_root->left = insert(current_root->left, data);
				current_root->left->parent = current_root;
				//limiter balance pour opti ?
				//r = balance(r);
				current_root = balance(current_root);
			}
			else if (data >= *(current_root->data))
			{
				current_root->right = insert(current_root->right, data);
				current_root->right->parent = current_root;
				//limiter balance pour opti ?
				//r = balance(r);
				current_root = balance(current_root);
			}
			return current_root;
		}

		protected:

		private:

		node_type *_root;
		allocator_type	_allocator;
		key_compare		_compare;
		
	};

}








#endif