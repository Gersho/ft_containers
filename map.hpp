/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:21:52 by kzennoun          #+#    #+#             */
/*   Updated: 2022/08/18 13:24:56 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include <memory>
#include "Tree.hpp"
#include "utility.hpp"
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


//  const Tree
//  	<
// 	ft::map<int, int, std::less<int>, std::allocator<ft::pair<const int, int> > >::value_type,
// 	  std::allocator<ft::pair<const int, int> >, ft::map<int, int, std::less<int>,
// 	    std::allocator<ft::pair<const int, int> > >::key_compare
// 	> *'
//  // (aka 'const Tree
//  	<
// 	pair<const int, int>,
// 	 std::allocator<ft::pair<const int, int> >
// 	 , std::less<int> > *')) would lose const qualifier
                

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
		typedef Tree<value_type, Alloc, Compare>	 tree;
		typedef ft::__tree_iterator<value_type, tree>	 iterator;
		//typedef typename tree::const_iterator		const_iterator;	
		typedef ft::__const_tree_iterator<value_type, tree>		const_iterator;	
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

	
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()):
			_compare(comp),
			_allocator(alloc)
			{
//  std::cout << "map iterator constructor P1" << std::endl;
				insert(first, last);
//  std::cout << "map iterator constructor P2" << std::endl;
			}


		// map( const map& x )
		// {
		// 	*this = x;
		// }

		//map( const map& x ): _compare(x._compare), _allocator(x.get_allocator()), _tree(x._tree) {}

		map( const map& x ): _compare(x._compare), _allocator(x.get_allocator())
		{
			clear();
			const_iterator it = x.begin();
			const_iterator ite = x.end();
			insert(it, ite);
		}


		// Destructor
		~map()
		{
//std::cout << "destructing map" << std::endl;
		}


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
			
			//return iterator(NULL, &_tree);
			return _tree.end();
		}

		const_iterator end() const
		{
			//return const_iterator(NULL, &_tree);
			return _tree.end();
		}

		reverse_iterator rbegin()
		{
			//return reverse_iterator(_tree.find_highest(_tree.get_root()));
			//return reverse_iterator(iterator(_tree.find_highest(_tree.get_root()), &_tree));
			//return reverse_iterator(iterator(NULL, &_tree));
			return _tree.rbegin();
		}

		const_reverse_iterator rbegin() const 
		{
			//return const_reverse_iterator(_tree.find_highest(_tree.get_root()));
			//return const_reverse_iterator(const_iterator(_tree.find_highest(_tree.get_root()), &_tree));
			//	return const_reverse_iterator(const_iterator(NULL, &_tree));
			return _tree.rbegin();
		}

		reverse_iterator rend()
		{
			//return reverse_iterator(NULL);
			///return reverse_iterator(iterator(NULL, &_tree));
			return _tree.rend();
		}

		const_reverse_iterator rend() const 
		{
			// return const_reverse_iterator(NULL);
			//return const_reverse_iterator(const_iterator(NULL, &_tree));
			return _tree.rend();
		}

		bool empty() const
		{
			return (_tree.get_size() == 0);
		}

		size_type size() const
		{
			return (_tree.get_size());
		}

		size_type max_size() const 
		{
//WTF ?
			//return std::allocator<pair<const Key,T> >().max_size();
			 return _allocator.max_size();
		}

		mapped_type& operator[] (const key_type& k)
		{
			//return (*((this->insert(make_pair(k,mapped_type()))).first)).second;
			return insert(ft::make_pair(k, mapped_type())).first->second;
		}



		// void insert (const value_type& val)
		ft::pair<iterator,bool> insert (const value_type& val)
		{
			_tree.set_root(_tree.insert(_tree.get_root(), val));
//std::cout << "coucou " << std::endl;
			// ft::pair<iterator,bool> ret = _tree.get_last_insert();
		//	ft::pair<iterator,bool> ret = ft::make_pair(begin(), true);
			//ft::pair<iterator,bool> ret = ft::make_pair(iterator(_tree.get_last_insert().first), _tree.get_last_insert().second);
			//return ret;
			return _tree.get_last_insert();
		}

		// with hint (2)	
		iterator insert (iterator position, const value_type& val)
		{
			(void)position;
			_tree.set_root(_tree.insert(_tree.get_root(), val));
			return find(val.first);
		}


		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
// std::cout << "coucou first: " << first.get_it() << " last:" << last.get_it() << std::endl;
// std::cout << "test1 " << std::boolalpha << (first != last) << std::endl;
//std::cout << "test " << first->second << std::endl;
			while (first != last)
			{
// std::cout << "in loop first != last: " << std::boolalpha << (first != last) << std::endl;
// std::cout << "new first " << first.get_it() << std::endl;
				_tree.set_root(_tree.insert(_tree.get_root(), *first));
				first++;
// std::cout << "new first2 " << first.get_it() << std::endl;
			}
		}


		void erase (iterator position)
		{
//			(void) position;
// 			Key target = position->first;
// std::cout << "target " << target << std::endl;
			
			_tree.set_root(_tree.erase(_tree.get_root(),  *position));
// 			_tree.set_root(_tree.erase(_tree.get_root(),  target));
		}

	
		size_type erase (const key_type& k)
		{
			pair<const key_type, mapped_type> tmp = ft::make_pair(k, mapped_type());
			_tree.set_root(_tree.erase(_tree.get_root(), tmp));
			return _tree.get_last_erase();
		}


		void erase (iterator first, iterator last)
		{
			ft::vector<Key> values;

			while (first != last)
			{
				values.push_back(first->first);
				first++;
			}

			ft::vector<int>::iterator it = values.begin();
			ft::vector<int>::iterator ite = values.end();
			while (it != ite)
			{
				_tree.set_root(_tree.erase(_tree.get_root(), make_pair(*it, mapped_type())));
				it++;
			}
		}

		void swap (map& x)
		{
			_tree.swap(x._tree);
		}

		void clear()
		{
			_tree.clear(_tree.get_root());			
		}

		key_compare key_comp() const
		{
			return _compare;
		}

		value_compare value_comp() const
		{
			return value_compare();
		}


	iterator find (const key_type& k)
	{
		return _tree.find(k);
	}

	const_iterator find (const key_type& k) const
	{
		return _tree.find(k);
	}


	size_type count (const key_type& k) const
	{
		return _tree.count(k);
	}

	iterator lower_bound (const key_type& k)
	{
		// The function uses its internal comparison object (key_comp)
		//  to determine this, returning an iterator to the first element
		//   for which key_comp(element_key,k) would return false.
		// typename ft::map<Key, T>::iterator it = begin();
		// typename ft::map<Key, T>::iterator ite = end();

		// while (it != ite)
		// {
		// 	if (!_compare(it->first,k))
		// 		return it;
		// 	it++;
		// }
		// return end();
		return _tree.lower_bound(k);
	}

	const_iterator lower_bound (const key_type& k) const
	{
		// typename ft::map<Key, T>::const_iterator it = begin();
		// typename ft::map<Key, T>::const_iterator ite = end();

		// while (it != ite)
		// {
		// 	if (!_compare(it->first,k))
		// 		return it;
		// 	it++;
		// }
		// return end();
		return _tree.lower_bound(k);
	}

	iterator upper_bound (const key_type& k)
	{
		// typename ft::map<Key, T>::iterator it = begin();
		// typename ft::map<Key, T>::iterator ite = end();

		// while (it != ite)
		// {
		// 	if (_compare(k, it->first))
		// 		return it;
		// 	it++;
		// }
		// return end();
		return _tree.upper_bound(k);	
	}

	const_iterator upper_bound (const key_type& k) const
	{
		// typename ft::map<Key, T>::const_iterator it = begin();
		// typename ft::map<Key, T>::const_iterator ite = end();

		// while (it != ite)
		// {
		// 	if (_compare(k, it->first))
		// 		return it;
		// 	it++;
		// }
		// return end();	
		return _tree.upper_bound(k);
	}


	pair<iterator,iterator> equal_range (const key_type& k)
	{
		// The function returns a pair, whose member
		//  pair::first is the lower bound of the range (the same as lower_bound),
		//   and pair::second is the upper bound (the same as upper_bound).
		return ft::make_pair(lower_bound(k), upper_bound(k));
	}


	pair<const_iterator,const_iterator> equal_range (const key_type& k) const
	{
		return ft::make_pair(lower_bound(k), upper_bound(k));
	}



		allocator_type get_allocator() const { return _allocator; };

		protected:

		private:
		key_compare		_compare;
		allocator_type	_allocator;
		Tree<value_type, Alloc, key_compare>			_tree;


		template <class X, class Y, class C, class A>
		friend bool operator== ( const map<X,Y,C,A>& lhs,
							const map<X,Y,C,A>& rhs );


		template <class X, class Y, class C, class A>
		friend bool operator<  ( const map<X,Y,C,A>& lhs,
							const map<X,Y,C,A>& rhs );

	};

	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
	{
		x.swap(y);
	}


	template <class Key, class T, class Compare, class Alloc>
	bool operator== ( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!= ( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs == rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<  ( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<= ( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return !(rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>  ( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return rhs < lhs;
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>= ( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs < rhs);
	}

}



#endif
