/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:13:40 by kzennoun          #+#    #+#             */
/*   Updated: 2022/07/18 12:39:58 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#include "utility.hpp"

namespace ft
{

	template <class Key, class Value>
	struct node
	{
		struct node *left;
		struct node *right;
		//struct node parent;
		// size_t left_height;
		// size_t right_height;
		struct pair<Key, Value> *data;
	};

	template <class Key, class Value, class Allocator, class Compare>
	class Tree
	{
		public:

		typedef typename node<Key, Value> node_type;
		typedef Allocator allocator_type;
		typedef Compare key_compare;

//constructors
		Tree(): _root(NULL), _allocator(allocator_type), 
		{
			
		}
//destructor
		~Tree()
		{
			//clear toutes les nodes
		}

		int height(node_type *parent)
		{
			int h = 0;
			if (parent != NULL)
			{
				int l_height = height(parent->left);
				int r_height = height(parent->right);
				int max_height = max(l_height, r_height);
				h = max_height + 1;
			}
			return h;
		}

		int difference(node_type *parent)
		{
			int l_height = height(parent->left);
			int r_height = height(parent->right);
			int diff = l_height - r_height;
			return diff;
		}

		node_type *rr_rotate(node_type *parent)
		{
			node_type *tmp;
			tmp = parent->right;
			parent->right = tmp->left;
			tmp->left = parent;
			return tmp;
		}

		node_type *ll_rotate(node_type *parent)
		{
			node_type *tmp;
			tmp = parent->left;
			parent->left = tmp->right;
			tmp->right = parent;
			return tmp;
		}

		node_type *lr_rotate(node_type *parent)
		{
			node_type *tmp;
			tmp = parent->left;
			parent->left = rr_rotat(tmp);
			return ll_rotat(parent);
		}

		node_type *rl_rotate(node_type *parent)
		{
			node_type *tmp;
			tmp = parent->right;
			parent->right = ll_rotat(tmp);
			return rr_rotat(parent);
		}

		node_type *balance(node_type *root)
		{
			int balance = difference(root);
			if (balance > 1)
			{
				if (difference(root->left) > 0)
					root = ll_rotat(root);
				else
					root = lr_rotat(root);
			}
			else if (balance < -1)
			{
				if (difference(root->right) > 0)
					root = rl_rotat(root);
				else
					root = rr_rotat(root);
			}
			return root;
		}


		node_type *insert(node_type *current_root, struct pair<Key, Value> *data)
		{
			if (current_root == NULL)
			{
				try 
				{
					current_root = _allocator.allocate(sizeof(node_type));
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

				current_root->data = data;
				current_root->left = NULL;
				current_root->right = NULL;
				return current_root;
			}
			else if (&data < current_root->d)
			{
				current_root->left = insert(current_root->left, data);
				//limiter balance pour opti ?
				r = balance(r);
			}
			else if (&data >= current_root->d)
			{
				current_root->r = insert(current_root->r, data);
				//limiter balance pour opti ?
				r = balance(r);
			}
			return r;
		}

		protected:

		private:

		node_type *_root;
		allocator_type	_allocator;
		key_compare		_compare;
		
	};

}








#endif