/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:21:52 by kzennoun          #+#    #+#             */
/*   Updated: 2022/07/26 10:52:16 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include <memory>
#include "utility.hpp"
#include "Tree.hpp"
#include "iterator.hpp"

namespace ft
{

	template < class Key,										// map::key_type
			class T,											// map::mapped_type
			class Compare = std::less<Key>,						// map::key_compare
			class Alloc = std::allocator<pair<const Key,T> >	// map::allocator_type
			>
	class map
	{

		public:

		typedef Key key_type;
		typedef T mapped_type;
		typedef pair<const key_type,mapped_type> value_type;
		typedef Compare key_compare;
		typedef value_compare value_compare;
		typedef Alloc allocator_type;
		typedef allocator_type::reference reference;
		typedef allocator_type::const_reference const_reference;
		typedef allocator_type::pointer pointer;
		typedef allocator_type::const_pointer const_pointer;
		typedef Tree<T, Alloc, Compare>	 tree;
		typedef ft::__tree_iterator<value_type, tree>	 iterator;
		typedef ft::__tree_iterator<const value_type, tree>		const_iterator;	
		typedef	ft::reverse_iterator<iterator>						reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		typedef  iterator_traits<iterator>::difference_type  difference_type;
		typedef  size_t  size_type;

		template <class Key, class T, class Compare, class Alloc>
		class map<Key,T,Compare,Alloc>::value_compare
		{ 
			friend class map;

			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}

			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
		}




		// empty (1)	
		// explicit map (const key_compare& comp = key_compare(),
		//               const allocator_type& alloc = allocator_type());

		explicit map (const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()):
					_compare(comp),
					_allocator(alloc)
					{}




// range (2)	
// template <class InputIterator>
//   map (InputIterator first, InputIterator last,
//        const key_compare& comp = key_compare(),
//        const allocator_type& alloc = allocator_type());

		// copy (3)	
		// map (const map& x);
		map( const map& x )
		{
			*this = x;
		}

		// Destructor
		~map();


		map& operator= (const map& x)
		{
			_compare = x._compare;
			_allocator = x._allocator;
			_tree = x._tree;
			return *this;
		}

		iterator begin()
		{
		return _tree.begin();
		}

		const_iterator begin() const
		{
			return _tree.begin();
		}

		iterator end()
		{
			return NULL;
		}

		const_iterator end() const
		{
			return NULL;
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(_tree.find_highest(_tree.get_root()));
		}

		const_reverse_iterator rbegin() const 
		{
			return const_reverse_iterator(_tree.find_highest(_tree.get_root()));
		}

		reverse_iterator rend()
		{
			return reverse_iterator(NULL);
		}

		const_reverse_iterator rend() const 
		{
			return const_reverse_iterator(NULL);
		}

		bool empty() const
		{
			return (_tree.get_size() == 0);
		}

		size_type size() const
		{
			return (_tree.get_size());
		}

		size_type max_size() const { return _allocator.max_size(); }

// mapped_type& operator[] (const key_type& k)
// {
// 	(*((this->insert(make_pair(k,mapped_type()))).first)).second;
// }


//std::map::insert
// single element (1)	
// pair<iterator,bool> insert (const value_type& val);

// with hint (2)	
// iterator insert (iterator position, const value_type& val);

// range (3)	
// template <class InputIterator>
//   void insert (InputIterator first, InputIterator last);


// std::map::erase
// (1)	
//      void erase (iterator position);

// (2)	
// size_type erase (const key_type& k);

// (3)	
//      void erase (iterator first, iterator last);

//void swap (map& x);

//void clear();

key_compare key_comp() const
{
	return _compare;
}

value_compare value_comp() const
{
	return value_compare();
}

//  iterator find (const key_type& k);

// const_iterator find (const key_type& k) const;


//size_type count (const key_type& k) const;

//       iterator lower_bound (const key_type& k);

// const_iterator lower_bound (const key_type& k) const;

//      iterator upper_bound (const key_type& k);

// const_iterator upper_bound (const key_type& k) const;

// pair<const_iterator,const_iterator> equal_range (const key_type& k) const;

// pair<iterator,iterator>             equal_range (const key_type& k);


		allocator_type get_allocator() const { return _allocator; };

		protected:

		private:
		key_compare		_compare;
		allocator_type	_allocator;
		//pointer			_tree;
		Tree<T, Alloc, Compare>			_tree;
		//size_type		_size;



		// pointer _try_alloc()
		// {
		// 	pointer ptr;

		// 	try 
		// 	{
		// 		ptr = _allocator.allocate(sizeof(node));
		// 	}
		// 	catch (std::bad_alloc& ba)
		// 	{
		// 		std::cerr << "Error allocating node: " << ba.what() << '\n';
		// 		ptr = NULL;
		// 		throw;
		// 		return ptr;
		// 	}
		// 	return ptr;
		// }

	};

}



#endif
