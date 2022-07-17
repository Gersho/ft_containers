/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:13:40 by kzennoun          #+#    #+#             */
/*   Updated: 2022/07/17 21:10:03 by kzennoun         ###   ########lyon.fr   */
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
		struct node left;
		struct node right;
		//struct node parent;
		// size_t left_height;
		// size_t right_height;
		struct pair<Key, Value> *data;
	};

	template <class Key, class Value>
	class Tree
	{
		public:

		typedef typename node<Key, Value> node_type; 

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


		// node_type *insert(node_type *root, struct pair<Key, Value> *data)
		// {
		// 	if (root == NULL) {
		// 		root = new avl;
		// 		root->data = data;
		// 		root->left = NULL;
		// 		root->right = NULL;
		// 		return root;
		// 	}
		// 	else if (v< root->d)
		// 	{
		// 		root->left = insert(root->left, v);
		// 		r = balance(r);
		// 	}
		// 	else if (v >= root->d)
		// 	{
		// 		root->r = insert(root->r, v);
		// 		r = balance(r);
		// 	}
		// 	return r;
		// }

		protected:

		private:

		struct node_type _root;
	};

}








#endif