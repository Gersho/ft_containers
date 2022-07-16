/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:21:52 by kzennoun          #+#    #+#             */
/*   Updated: 2022/07/16 15:19:16 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include <memory>
#include "utility.hpp"

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
		typedef /* XXX */ value_compare;
		typedef Alloc allocator_type;
		typedef allocator_type::reference reference;
		typedef allocator_type::const_reference const_reference;
		typedef allocator_type::pointer pointer;
		typedef allocator_type::const_pointer const_pointer;
		typedef /*ft::__whatever_iterator<value_type>	*/ iterator;
		typedef /*ft::__generic_iterator<const value_type>	*/		const_iterator;	
		typedef	/*ft::reverse_iterator<iterator>	*/					reverse_iterator;
		typedef	/*ft::reverse_iterator<const_iterator>		*/		const_reverse_iterator;
		typedef /* iterator_traits<iterator>::difference_type */ difference_type;
		typedef /* size_t ? */ size_type;

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



// Constructors

// empty (1)	
// explicit map (const key_compare& comp = key_compare(),
//               const allocator_type& alloc = allocator_type());

// range (2)	
// template <class InputIterator>
//   map (InputIterator first, InputIterator last,
//        const key_compare& comp = key_compare(),
//        const allocator_type& alloc = allocator_type());

// copy (3)	
// map (const map& x);



// Destructor
//~map();


// map& operator= (const map& x);

//       iterator begin();

// const_iterator begin() const;

//       iterator end();

// const_iterator end() const;

//       reverse_iterator rbegin();

// const_reverse_iterator rbegin() const;

//       reverse_iterator rend();

// const_reverse_iterator rend() const;

bool empty() const
{
	return (_size == 0);
}

size_type size() const
{
	return (_size);
}

//size_type max_size() const;

// mapped_type& operator[] (const key_type& k);


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

//key_compare key_comp() const;

//value_compare value_comp() const;

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

		private:
		allocator_type	_allocator;
		pointer			_ptr;
		size_type		_size;

	};


	template <class Key, class T>
	struct node
	{
		struct node left_child;
		struct node right_child;
		size_t left_height;
		size_t right_height;
		struct pair<Key, T> *data;	
	};
	
	
}



#endif
