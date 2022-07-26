/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:21:52 by kzennoun          #+#    #+#             */
/*   Updated: 2022/07/26 20:13:17 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include <memory>
#include "utility.hpp"
#include "Tree.hpp"
#include "iterator.hpp"
#include "vector.hpp"

namespace ft
{

	template < class Key,										// map::key_type
			class T,											// map::mapped_type
			class Compare = std::less<Key>,						// map::key_compare
			class Alloc = std::allocator<pair<const Key,T> >	// map::allocator_type
			>
	class map
	{
		private:
		
		class value_comp;


		public:

		typedef Key key_type;
		typedef T mapped_type;
		typedef pair<const key_type,mapped_type> value_type;
		typedef Compare key_compare;
		typedef value_comp value_compare;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef Tree<T, Alloc, Compare>	 tree;
		typedef ft::__tree_iterator<value_type, tree>	 iterator;
		typedef ft::__tree_iterator<const value_type, tree>		const_iterator;	
		typedef	ft::reverse_iterator<iterator>						reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type  difference_type;
		typedef  size_t  size_type;

		// template <class X, class Y, class C, class A>
		// class map<X,Y,C,A>::value_comp
		// { 
		// 	friend class map;

		// 	protected:
		// 		C comp;
		// 		value_compare (C c) : comp(c) {}

		// 	public:
		// 		typedef bool result_type;
		// 		typedef value_type first_argument_type;
		// 		typedef value_type second_argument_type;
		// 		bool operator() (const value_type& x, const value_type& y) const
		// 		{
		// 			return comp(x.first, y.first);
		// 		}
		// }
		private:

		class value_comp
		{
			protected:
				Compare comp;
				value_comp( key_compare c ) : comp( c ) {}
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
		};

		public:

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


		map( const map& x )
		{
			*this = x;
		}

		// Destructor
		~map(){}


		map& operator= (const map& x)
		{
			_compare = x._compare;
			_allocator = x._allocator;
			_tree = x._tree;
//TODO OPERATOR= TREE WITH DEEP COPY
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



		ft::pair<iterator,bool> insert (const value_type& val)
		{
			_tree.set_root(_tree.insert(_tree.get_root(), val));
std::cout << "coucou " << std::endl;
			ft::pair<iterator,bool> ret = _tree.get_last_insert();
			//ft::pair<iterator,bool> ret = ft::make_pair(iterator(_tree.get_last_insert().first), _tree.get_last_insert().second);
			return ret;
		}

// with hint (2)	
// iterator insert (iterator position, const value_type& val);


		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{	
			while (first != last)
			{
				_tree.set_root(_tree.insert(_tree.get_root(), *first));
				first++;
			}
		}


		void erase (iterator position)
		{
			_tree.set_root(_tree.erase(_tree.get_root(), *(position).first));
		}

	
		size_type erase (const key_type& k)
		{
			_tree.set_root(_tree.erase(_tree.get_root(), k));
			return _tree.get_last_erase();
		}


		void erase (iterator first, iterator last)
		{
			ft::vector<Key> values;

			while (first != last)
			{
				values.push_back(*(first).first);
				first++;
			}

			ft::vector<int>::iterator it = values.begin();
			ft::vector<int>::iterator ite = values.end();
			while (it != ite)
			{
				_tree.set_root(_tree.erase(_tree.get_root(), *it));
				it++;
			}
		}

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
		Tree<value_type, Alloc, key_compare>			_tree;



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
