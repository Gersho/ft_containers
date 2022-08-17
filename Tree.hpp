/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:13:40 by kzennoun          #+#    #+#             */
/*   Updated: 2022/08/17 17:23:45 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

//#include "utility.hpp"
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "vector.hpp"
#include "utility.hpp"
#include "iterator.hpp"


namespace ft
{

	// template <class T>
	// struct node
	// {
	// 	struct node<T> *left;
	// 	struct node<T> *right;
	// 	struct node<T> *parent;
	// 	int height;
	// 	T *data;

	// 	node():
	// 	left(NULL),
	// 	right(NULL),
	// 	parent(NULL),
	// 	height(1),
	// 	data(NULL)
	// 	{}

	// 	~node(){}
	// };

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
		typedef ft::__const_tree_iterator<const T, Tree>		const_iterator;
		typedef	ft::reverse_iterator<iterator>						reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>				const_reverse_iterator;
//constructors
		Tree(): _root(NULL), _allocator(allocator_type()), _compare(key_compare()), _size(0)
		{
			_before_first.before_first = true;
			_after_last.after_last = true;
		}
//destructor
		~Tree()
		{
			//clear toutes les nodes
			clear(_root);
		}

		int get_size() const { return _size; } 
		allocator_type get_allocator() const { return _allocator; }
		key_compare get_compare() const { return _compare; }

		node_type *get_root() const { return _root; }
		// node_type *get_root() { return _root; }
		// const_node_type *get_root() const { return _root; }
		node_type *get_after_last() { return &_after_last; }
		node_type *get_before_first() { return &_before_first; }


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
			//_root = rhs.get_root();
			_allocator = rhs.get_allocator();
			_compare = rhs.get_compare();

			const_iterator it = rhs.begin();
			const_iterator ite = rhs.end();

			// iterator it = rhs.begin();
			// iterator ite = rhs.end();

			while (it != ite)
			{
				set_root(insert(get_root(), *it));
				it++;
			}

			//set_root(insert(rhs.begin(), rhs.end()));

			return *this;
		}

		iterator begin() 
		{
//std::cout << "coucou" << std::endl;
//std::cout << "coucou2 ptr" << ptr << std::endl;
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



			// iterator ret = begin();
			// return const_iterator(*ret, this);

			//return const_iterator(begin());
		}

		iterator end()
		{
// 			node_type ptr;
// 			ptr.after_last = true;	
// //std::cout << "###########################prout" << std::endl;
// 			return iterator(&ptr, this);
// 			//return iterator(NULL, this);
			node_type *ptr = get_root();
//std::cout << "coucou2 ptr" << ptr << std::endl;
			if(!ptr)
				return iterator(NULL, this);

			return iterator(get_after_last(), this);
		}


		const_iterator end() const
		{
//std::cout << "########################### CONST prout" << std::endl;
			node_type *ptr = get_root();
//std::cout << "coucou2 ptr" << ptr << std::endl;
			if(!ptr)
				return const_iterator(NULL, this);

			return const_iterator(get_after_last(), this);

		// 	node_type ptr;
		// 	ptr.after_last = true;	
		// 	return const_iterator(&ptr, this);
		// //	return const_iterator(NULL, this);
		}




		reverse_iterator rbegin()
		{
			node_type *ptr = get_root();
			if(!ptr)
				return reverse_iterator(iterator(NULL, this));
			return reverse_iterator(iterator(get_after_last(),this));
			// node_type ptr;
			// ptr.after_last = true;	
			// return reverse_iterator(iterator(&ptr, this));
			//return reverse_iterator(_tree.find_highest(_tree.get_root()));
			//return reverse_iterator(iterator(_tree.find_highest(_tree.get_root()), &_tree));
			//return reverse_iterator(iterator(NULL, &_tree));
		}

		const_reverse_iterator rbegin() const 
		{
			node_type *ptr = get_root();
			if(!ptr)
				return const_reverse_iterator(const_iterator(NULL, this));
			return const_reverse_iterator(iterator(get_after_last(),this));

			// node_type ptr;
			// ptr.after_last = true;	
			// return const_reverse_iterator(const_iterator(&ptr, this));
			//return const_reverse_iterator(_tree.find_highest(_tree.get_root()));
			//return const_reverse_iterator(const_iterator(_tree.find_highest(_tree.get_root()), &_tree));
			//return const_reverse_iterator(const_iterator(NULL, &_tree));
		}

		reverse_iterator rend()
		{

			node_type *ptr = get_root();
			if(!ptr)
				return reverse_iterator(iterator(NULL, this));
		//	return reverse_iterator(iterator(get_before_first(),this));
			return reverse_iterator(iterator(find_lowest(get_root()),this));
			// //before first
			// node_type ptr;
			// ptr.before_first = true;	
			//return reverse_iterator(iterator(&ptr, this));
			//return reverse_iterator(NULL);
			//return reverse_iterator(iterator(NULL, &_tree));
		}

		const_reverse_iterator rend() const 
		{

			node_type *ptr = get_root();
			if(!ptr)
				return const_reverse_iterator(const_iterator(NULL, this));
			//return const_reverse_iterator(iterator(get_before_first(),this));
			return const_reverse_iterator(iterator(find_lowest(get_root()),this));
			// node_type ptr;
			// ptr.before_first = true;	
			// return const_reverse_iterator(const_iterator(&ptr, this));
			// return const_reverse_iterator(NULL);
			//return const_reverse_iterator(const_iterator(NULL, &_tree));
		}




	template<class X>
	iterator find (const X& k)
	{
		node_type *tmp = get_root();
// std::cout << "coucou" <<std::endl;
		while(tmp)
		{
			if(_compare(k, tmp->data->first))
			{
// std::cout << "tmp first: " << tmp->data->first << " going left" << std::endl;
				tmp = tmp->left;
			}
			else if(_compare(tmp->data->first, k))
			{
// std::cout << "tmp first: " << tmp->data->first << " going right" << std::endl;
				tmp = tmp->right;
			}
			else
			{
// std::cout << "tmp first: " << tmp->data->first << " returning" << std::endl;
				return iterator(tmp, this);
			}
		}
		//return end();
		return end();
	}

	template<class X>
	const_iterator find (const X& k) const
	{
		//const node<value_type> *tmp = _tree.get_root();
		node_type *tmp = get_root();
		//node<const pair<const int, int> > *
		//node<ft::pair<const int, int> > *
		//std::cout << "coucou" <<std::endl;
		while(tmp)
		{
			if(_compare(k, tmp->data->first))
				tmp = tmp->left;
			else if(_compare(tmp->data->first, k))
				tmp = tmp->right;
			else
				return const_iterator(tmp, this);
				//node<pair<const int, int> > *
				//node<const ft::pair<const int, int> > *
				
		}
		return end();		
	}






	template<class X>
	size_t count (const X& k) const
	{
		const_iterator it = find(k);
		//iterator it = find(k);
		return it == end() ? 0 : 1;
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
//std::cout << " test parent " << parent << "" << std::endl;
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
		{
			_last_erase = 0;
			return parent;
		}

		//if (_compare(parent->data->first, key))
		if (_compare(key.first, parent->data->first))
		{
			parent->left = erase(parent->left, key);
		}
		// else if (_compare(key, parent->data->first))
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