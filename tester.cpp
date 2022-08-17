/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:37:26 by kzennoun          #+#    #+#             */
/*   Updated: 2022/08/17 17:52:02 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifdef STD
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
#endif

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <signal.h>

//for stack tests
#include <vector>
#include <list>



void abort_proc(int)
{
	throw std::runtime_error("ABORT");
}

void stack_tests()
{
	{ 	
		ft::stack<int> s_a;
		ft::stack<int> s_b;

		std::cout << std::boolalpha << "s_a.empty() " << s_a.empty() << std::endl;
		std::cout << "s_a.size() " << s_a.size() << std::endl;
		
		std::cout << std::boolalpha << "s_a == s_b : " << (s_a == s_b) << std::endl;
		std::cout << std::boolalpha << "s_a != s_b : " << (s_a != s_b) << std::endl;
		std::cout << std::boolalpha << "s_a < s_b : " << (s_a < s_b) << std::endl;
		std::cout << std::boolalpha << "s_a > s_b : " << (s_a > s_b) << std::endl;
		std::cout << std::boolalpha << "s_a <= s_b : " << (s_a <= s_b) << std::endl;
		std::cout << std::boolalpha << "s_a >= s_b : " << (s_a >= s_b) << std::endl;

		std::cout << "s_a.push(10)" <<std::endl;
		s_a.push(10);
		std::cout << std::boolalpha << "s_a.empty() " << s_a.empty() << std::endl;
		std::cout << "s_a.size() " << s_a.size() << std::endl;
		
		std::cout << std::boolalpha << "s_a == s_b : " << (s_a == s_b) << std::endl;
		std::cout << std::boolalpha << "s_a != s_b : " << (s_a != s_b) << std::endl;
		std::cout << std::boolalpha << "s_a < s_b : " << (s_a < s_b) << std::endl;
		std::cout << std::boolalpha << "s_a > s_b : " << (s_a > s_b) << std::endl;
		std::cout << std::boolalpha << "s_a <= s_b : " << (s_a <= s_b) << std::endl;
		std::cout << std::boolalpha << "s_a >= s_b : " << (s_a >= s_b) << std::endl;

		s_b.push(10);

		std::cout << std::boolalpha << "s_a == s_b : " << (s_a == s_b) << std::endl;
		std::cout << std::boolalpha << "s_a != s_b : " << (s_a != s_b) << std::endl;
		std::cout << std::boolalpha << "s_a < s_b : " << (s_a < s_b) << std::endl;
		std::cout << std::boolalpha << "s_a > s_b : " << (s_a > s_b) << std::endl;
		std::cout << std::boolalpha << "s_a <= s_b : " << (s_a <= s_b) << std::endl;
		std::cout << std::boolalpha << "s_a >= s_b : " << (s_a >= s_b) << std::endl;

		std::cout << "s_a.top() " << s_a.top() << std::endl;
		std::cout << "s_b.top() " << s_b.top() << std::endl;

		s_a.push(10);
		s_a.push(15);
		s_a.push(12);
		s_a.push(17);

		std::cout << std::boolalpha << "s_a == s_b : " << (s_a == s_b) << std::endl;
		std::cout << std::boolalpha << "s_a != s_b : " << (s_a != s_b) << std::endl;
		std::cout << std::boolalpha << "s_a < s_b : " << (s_a < s_b) << std::endl;
		std::cout << std::boolalpha << "s_a > s_b : " << (s_a > s_b) << std::endl;
		std::cout << std::boolalpha << "s_a <= s_b : " << (s_a <= s_b) << std::endl;
		std::cout << std::boolalpha << "s_a >= s_b : " << (s_a >= s_b) << std::endl;

		while (!s_a.empty())
		{
			std::cout << "top: " << s_a.top() << std::endl;
			s_a.pop();
		}
		s_a.pop();
		s_a.pop();
		s_a.pop();
		
	}



	{
		std::cout << "tests with std vector as underlying container" << std::endl;
		ft::stack<int, std::vector<int> > s_a;
		ft::stack<int, std::vector<int> > s_b;

		std::cout << std::boolalpha << "s_a.empty() " << s_a.empty() << std::endl;
		std::cout << "s_a.size() " << s_a.size() << std::endl;
		
		std::cout << std::boolalpha << "s_a == s_b : " << (s_a == s_b) << std::endl;
		std::cout << std::boolalpha << "s_a != s_b : " << (s_a != s_b) << std::endl;
		std::cout << std::boolalpha << "s_a < s_b : " << (s_a < s_b) << std::endl;
		std::cout << std::boolalpha << "s_a > s_b : " << (s_a > s_b) << std::endl;
		std::cout << std::boolalpha << "s_a <= s_b : " << (s_a <= s_b) << std::endl;
		std::cout << std::boolalpha << "s_a >= s_b : " << (s_a >= s_b) << std::endl;

		std::cout << "s_a.push(10)" <<std::endl;
		s_a.push(10);
		std::cout << std::boolalpha << "s_a.empty() " << s_a.empty() << std::endl;
		std::cout << "s_a.size() " << s_a.size() << std::endl;
		
		std::cout << std::boolalpha << "s_a == s_b : " << (s_a == s_b) << std::endl;
		std::cout << std::boolalpha << "s_a != s_b : " << (s_a != s_b) << std::endl;
		std::cout << std::boolalpha << "s_a < s_b : " << (s_a < s_b) << std::endl;
		std::cout << std::boolalpha << "s_a > s_b : " << (s_a > s_b) << std::endl;
		std::cout << std::boolalpha << "s_a <= s_b : " << (s_a <= s_b) << std::endl;
		std::cout << std::boolalpha << "s_a >= s_b : " << (s_a >= s_b) << std::endl;

		s_b.push(10);

		std::cout << std::boolalpha << "s_a == s_b : " << (s_a == s_b) << std::endl;
		std::cout << std::boolalpha << "s_a != s_b : " << (s_a != s_b) << std::endl;
		std::cout << std::boolalpha << "s_a < s_b : " << (s_a < s_b) << std::endl;
		std::cout << std::boolalpha << "s_a > s_b : " << (s_a > s_b) << std::endl;
		std::cout << std::boolalpha << "s_a <= s_b : " << (s_a <= s_b) << std::endl;
		std::cout << std::boolalpha << "s_a >= s_b : " << (s_a >= s_b) << std::endl;

		std::cout << "s_a.top() " << s_a.top() << std::endl;
		std::cout << "s_b.top() " << s_b.top() << std::endl;

		s_a.push(10);
		s_a.push(15);
		s_a.push(12);
		s_a.push(17);

		std::cout << std::boolalpha << "s_a == s_b : " << (s_a == s_b) << std::endl;
		std::cout << std::boolalpha << "s_a != s_b : " << (s_a != s_b) << std::endl;
		std::cout << std::boolalpha << "s_a < s_b : " << (s_a < s_b) << std::endl;
		std::cout << std::boolalpha << "s_a > s_b : " << (s_a > s_b) << std::endl;
		std::cout << std::boolalpha << "s_a <= s_b : " << (s_a <= s_b) << std::endl;
		std::cout << std::boolalpha << "s_a >= s_b : " << (s_a >= s_b) << std::endl;

		while (!s_a.empty())
		{
			std::cout << "top: " << s_a.top() << std::endl;
			s_a.pop();
		}
		s_a.pop();
		s_a.pop();
		s_a.pop();
	}


	{
		std::cout << "tests with std list as underlying container" << std::endl;
		ft::stack<int, std::list<int> > s_a;
		ft::stack<int, std::list<int> > s_b;

		std::cout << std::boolalpha << "s_a.empty() " << s_a.empty() << std::endl;
		std::cout << "s_a.size() " << s_a.size() << std::endl;
		
		std::cout << std::boolalpha << "s_a == s_b : " << (s_a == s_b) << std::endl;
		std::cout << std::boolalpha << "s_a != s_b : " << (s_a != s_b) << std::endl;
		std::cout << std::boolalpha << "s_a < s_b : " << (s_a < s_b) << std::endl;
		std::cout << std::boolalpha << "s_a > s_b : " << (s_a > s_b) << std::endl;
		std::cout << std::boolalpha << "s_a <= s_b : " << (s_a <= s_b) << std::endl;
		std::cout << std::boolalpha << "s_a >= s_b : " << (s_a >= s_b) << std::endl;

		std::cout << "s_a.push(10)" <<std::endl;
		s_a.push(10);
		std::cout << std::boolalpha << "s_a.empty() " << s_a.empty() << std::endl;
		std::cout << "s_a.size() " << s_a.size() << std::endl;
		
		std::cout << std::boolalpha << "s_a == s_b : " << (s_a == s_b) << std::endl;
		std::cout << std::boolalpha << "s_a != s_b : " << (s_a != s_b) << std::endl;
		std::cout << std::boolalpha << "s_a < s_b : " << (s_a < s_b) << std::endl;
		std::cout << std::boolalpha << "s_a > s_b : " << (s_a > s_b) << std::endl;
		std::cout << std::boolalpha << "s_a <= s_b : " << (s_a <= s_b) << std::endl;
		std::cout << std::boolalpha << "s_a >= s_b : " << (s_a >= s_b) << std::endl;

		s_b.push(10);

		std::cout << std::boolalpha << "s_a == s_b : " << (s_a == s_b) << std::endl;
		std::cout << std::boolalpha << "s_a != s_b : " << (s_a != s_b) << std::endl;
		std::cout << std::boolalpha << "s_a < s_b : " << (s_a < s_b) << std::endl;
		std::cout << std::boolalpha << "s_a > s_b : " << (s_a > s_b) << std::endl;
		std::cout << std::boolalpha << "s_a <= s_b : " << (s_a <= s_b) << std::endl;
		std::cout << std::boolalpha << "s_a >= s_b : " << (s_a >= s_b) << std::endl;

		std::cout << "s_a.top() " << s_a.top() << std::endl;
		std::cout << "s_b.top() " << s_b.top() << std::endl;

		s_a.push(10);
		s_a.push(15);
		s_a.push(12);
		s_a.push(17);

		std::cout << std::boolalpha << "s_a == s_b : " << (s_a == s_b) << std::endl;
		std::cout << std::boolalpha << "s_a != s_b : " << (s_a != s_b) << std::endl;
		std::cout << std::boolalpha << "s_a < s_b : " << (s_a < s_b) << std::endl;
		std::cout << std::boolalpha << "s_a > s_b : " << (s_a > s_b) << std::endl;
		std::cout << std::boolalpha << "s_a <= s_b : " << (s_a <= s_b) << std::endl;
		std::cout << std::boolalpha << "s_a >= s_b : " << (s_a >= s_b) << std::endl;

		while (!s_a.empty())
		{
			std::cout << "top: " << s_a.top() << std::endl;
			s_a.pop();
		}

		try 
		{
			s_a.pop();
		}
		catch(std::exception& e)
		{
			std::cout << "abort test ok: " << e.what() << std::endl;
		}
	}
}

template<class T>
void test_print_vec(ft::vector<T> &vec )
{
	std::size_t vec_size = vec.size();
	
	std::cout << "size(): " << vec.size() << std::endl;
	std::cout << "maxsize(): " << vec.max_size() << std::endl;
	std::cout << "capacity(): " << vec.capacity() << std::endl;

	ft::vector<int>::reverse_iterator it = vec.rbegin();
	ft::vector<int>::reverse_iterator ite = vec.rend();
	int j = 0;
	while (it != ite)
	{
		std::cout << "j: " << j << " *it: " << *it << std::endl;
		it++;
		j++;
	} 

	for (std::size_t i = 0; i < vec_size; i++)
	{
		std::cout << "vec[" << i << "]: " << vec[i] << std::endl;
	}
}

template<class T>
struct s_vect 
{
	ft::vector<T> *vec_a;
	ft::vector<T> *vec_b;
	ft::vector<T> *vec_c;
	ft::vector<T> *vec_d;
};

template<class T>
void test_vects(struct s_vect<T> vects)
{
	std::cout << "Printing vector A" << std::endl;
	test_print_vec(*(vects.vec_a));
	std::cout << "Printing vector B" << std::endl;
	test_print_vec(*(vects.vec_b));
	std::cout << "Printing vector C" << std::endl;
	test_print_vec(*(vects.vec_c));
	std::cout << "Printing vector D" << std::endl;
	test_print_vec(*(vects.vec_d));
}

template<class T>
void fill_vect(ft::vector<T> &vec, size_t qt)
{
	while (qt)
	{
		vec.push_back(rand());
		qt--;
	}
}

template<class Key, class T>
void show_map(ft::map<Key, T> &map)
{
	std::cout << "size: " << map.size() << std::endl;

	typename ft::map<Key, T>::iterator it = map.begin();
	typename ft::map<Key, T>::iterator ite = map.end();

	std::cout << "normal order" << std::endl;
	while(it != ite)
	{
		std::cout << "key: " << it->first<< " value: " << it->second << std::endl;
		it++;
	}

	typename ft::map<Key, T>::reverse_iterator rit = map.rbegin();
	typename ft::map<Key, T>::reverse_iterator rite = map.rend();
 
	std::cout << "reverse order" << std::endl;
	while(rit != rite)
	{ 
		std::cout << "reverse key: " << rit->first<< " value: " << rit->second << std::endl;
		rit++;
	}
}

void map_tests_normal()
{
	ft::map<int, int> a;
	ft::map<int, int> b;


	a.insert( ft::make_pair<int, int>( 50, 5000 ) );
	a.insert( ft::make_pair<int, int>( 80, 8000 ) );
	a.insert( ft::make_pair<int, int>( 30, 3000 ) );
	a.insert( ft::make_pair<int, int>( 20, 2000 ) );

	ft::map<int, int> c(a.begin(), a.end());
	// ft::map<int, int> d(a);
	// std::cout << "printing map d" << std::endl;
	// show_map(d);

	// std::cout << "Testing map relational operators" << std::endl;
	// std::cout << std::boolalpha << "a == c : " << (a == c) << std::endl;
	// std::cout << std::boolalpha << "a != c : " << (a != c) << std::endl;
	// std::cout << std::boolalpha << "a < c : " << (a < c) << std::endl;
	// std::cout << std::boolalpha << "a > c : " << (a > c) << std::endl;
	// std::cout << std::boolalpha << "a <= c : " << (a <= c) << std::endl;
	// std::cout << std::boolalpha << "a >= c : " << (a >= c) << std::endl;

	std::cout << "printing map c" << std::endl;
	show_map(c);

	a.insert( ft::make_pair<int, int>( 70, 7000 ) );
	a.insert(a.begin(), ft::make_pair<int, int>( 60, 6000 ));
	// std::cout << "Testing map relational operators" << std::endl;
	// std::cout << std::boolalpha << "a == c : " << (a == c) << std::endl;
	// std::cout << std::boolalpha << "a != c : " << (a != c) << std::endl;
	// std::cout << std::boolalpha << "a < c : " << (a < c) << std::endl;
	// std::cout << std::boolalpha << "a > c : " << (a > c) << std::endl;
	// std::cout << std::boolalpha << "a <= c : " << (a <= c) << std::endl;
	// std::cout << std::boolalpha << "a >= c : " << (a >= c) << std::endl;

	// std::cout << "max size a: " << a.max_size() << std::endl;
	// std::cout << "max size b: " << b.max_size() << std::endl;

	std::cout << "printing map a" << std::endl;
	show_map(a);
	b.insert(a.begin(), a.end());
	std::cout << "printing map b" << std::endl;
	show_map(b);
	b.erase(b.begin());

	std::cout << "printing map b" << std::endl;
	show_map(b);

	b.erase(8);

	std::cout << "printing map b" << std::endl;
	show_map(b);

	b.erase(b.begin(), b.end());
	std::cout << "printing map b" << std::endl;
	show_map(b);

	std::cout << a.empty() << std::endl;
	std::cout << b.empty() << std::endl;
	std::cout << a.size() << std::endl;
	std::cout << b.size() << std::endl;

	ft::map<int, int >::iterator it = a.find(50);
	std::cout << "find key: " << it->first<< " value: " << it->second << std::endl;
	it = a.find(30);
	std::cout << "find key: " << it->first<< " value: " << it->second << std::endl;
	it = a.find(0);

	if (it == a.end())
	{
		std::cout << "not found" << std::endl;
	}

	std::cout << "print a[2] " << a[2] << std::endl;
	std::cout << "print a[2] " << a[80] << std::endl;

	
	// it = a.lower_bound(30);
	// std::cout << "lower_bound key: " << it->first<< " value: " << it->second << std::endl;
	// it = a.lower_bound(20);
	// std::cout << "lower_bound key: " << it->first<< " value: " << it->second << std::endl;
	// it = a.lower_bound(50);
	// std::cout << "lower_bound key: " << it->first<< " value: " << it->second << std::endl;
	// it = a.lower_bound(0);
	// std::cout << "lower_bound key: " << it->first<< " value: " << it->second << std::endl;

	// it = a.upper_bound(30);
	// std::cout << "upper_bound key: " << it->first<< " value: " << it->second << std::endl;
	// it = a.upper_bound(80);
	// std::cout << "upper_bound key: " << it->first<< " value: " << it->second << std::endl;
	// it = a.upper_bound(20);
	// std::cout << "upper_bound key: " << it->first<< " value: " << it->second << std::endl;
	// it = a.upper_bound(0);
	// std::cout << "upper_bound key: " << it->first<< " value: " << it->second << std::endl;

	// ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator>  pair_A =  a.equal_range(50);
	// std::cout << "keyA: " << pair_A.first->first << " valueA: " << pair_A.first->second 
	// 		<<  " keyB: " << pair_A.second->first << " valueB: " << pair_A.second->second << std::endl;
	
	// pair_A =  a.equal_range(30);
	// std::cout << "keyA: " << pair_A.first->first << " valueA: " << pair_A.first->second 
	// 		<<  " keyB: " << pair_A.second->first << " valueB: " << pair_A.second->second << std::endl;

	// pair_A =  a.equal_range(70);
	// std::cout << "keyA: " << pair_A.first->first << " valueA: " << pair_A.first->second 
	// 		<<  " keyB: " << pair_A.second->first << " valueB: " << pair_A.second->second << std::endl;

	// pair_A =  a.equal_range(0);
	// std::cout << "keyA: " << pair_A.first->first << " valueA: " << pair_A.first->second 
	// 		<<  " keyB: " << pair_A.second->first << " valueB: " << pair_A.second->second << std::endl;


std::cout << "############################still alive" << std::endl;

	std::cout << "Testing const stuff" << std::endl;


	// ft::map<int, int >::const_iterator cit = a.find(50);
	// std::cout << "find key: " << cit->first<< " value: " << cit->second << std::endl;
	// cit = a.find(30);
	// std::cout << "find key: " << cit->first<< " value: " << cit->second << std::endl;
	// cit = a.find(0);

	// if (cit == a.end())
	// {
	// 	std::cout << "not found" << std::endl;
	// }

	// cit = a.lower_bound(30);
	// std::cout << "lower_bound key: " << cit->first<< " value: " << cit->second << std::endl;
	// cit = a.lower_bound(20);
	// std::cout << "lower_bound key: " << cit->first<< " value: " << cit->second << std::endl;
	// cit = a.lower_bound(50);
	// std::cout << "lower_bound key: " << cit->first<< " value: " << cit->second << std::endl;
	// cit = a.lower_bound(0);
	// std::cout << "lower_bound key: " << cit->first<< " value: " << cit->second << std::endl;


	// cit = a.upper_bound(30);
	// std::cout << "upper_bound key: " << cit->first<< " value: " << cit->second << std::endl;
	// cit = a.upper_bound(80);
	// std::cout << "upper_bound key: " << cit->first<< " value: " << cit->second << std::endl;
	// cit = a.upper_bound(20);
	// std::cout << "upper_bound key: " << cit->first<< " value: " << cit->second << std::endl;
	// cit = a.upper_bound(0);
	// std::cout << "upper_bound key: " << cit->first<< " value: " << cit->second << std::endl;


	// ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::const_iterator>  cpair_A =  a.equal_range(50);
	// std::cout << "keyA: " << cpair_A.first->first << " valueA: " << cpair_A.first->second 
	// 		<<  " keyB: " << cpair_A.second->first << " valueB: " << cpair_A.second->second << std::endl;
	
	// cpair_A =  a.equal_range(30);
	// std::cout << "keyA: " << cpair_A.first->first << " valueA: " << cpair_A.first->second 
	// 		<<  " keyB: " << cpair_A.second->first << " valueB: " << cpair_A.second->second << std::endl;

	// cpair_A =  a.equal_range(70);
	// std::cout << "keyA: " << cpair_A.first->first << " valueA: " << cpair_A.first->second 
	// 		<<  " keyB: " << cpair_A.second->first << " valueB: " << cpair_A.second->second << std::endl;

	// cpair_A =  a.equal_range(0);
	// std::cout << "keyA: " << cpair_A.first->first << " valueA: " << cpair_A.first->second 
	// 		<<  " keyB: " << cpair_A.second->first << " valueB: " << cpair_A.second->second << std::endl;


	//std::cout << a.count(80) << std::endl;
	//std::cout << a.count(0) << std::endl;


	std::cout << "testing swap" << std::endl;

	a.swap(b);
	ft::swap(b, c);

	std::cout << "reprint all maps" << std::endl;
	std::cout << "printing map a" << std::endl;
	show_map(a);
	std::cout << "printing map b" << std::endl;
	show_map(b);
	std::cout << "printing map c" << std::endl;
	show_map(c);
	// std::cout << "printing map d" << std::endl;
	// show_map(d);

std::cout << "############################still alive END" << std::endl;

}

void vector_tests()
{
	ft::vector<int> vec_a;
	ft::vector<int> vec_b(400, 72);
	ft::vector<int> vec_c(vec_b.begin()+2, vec_b.end());
	ft::vector<int> vec_d(vec_c);

	struct s_vect<int> vects;
	vects.vec_a = &vec_a;
	vects.vec_b = &vec_b;
	vects.vec_c = &vec_c;
	vects.vec_d = &vec_d;

	std::cout << "Testing Vector::empty()" << std::endl;
	std::cout << std::boolalpha << "vec_a.empty(): " << vec_a.empty() << std::endl;
	std::cout << std::boolalpha << "vec_b.empty(): " << vec_b.empty() << std::endl;
	std::cout << std::boolalpha << "vec_c.empty(): " << vec_c.empty() << std::endl;
	std::cout << std::boolalpha << "vec_d.empty(): " << vec_d.empty() << std::endl;

	test_vects(vects);

	std::cout << "Testing Vector::push_back() and Vector::pop_back()" << std::endl;

	fill_vect(vec_a, 5000);
	vec_a.pop_back();

	fill_vect(vec_b, 2000);
	fill_vect(vec_c, 1002);
	fill_vect(vec_d, 1005);

	test_vects(vects);

	std::cout << "Testing Vector relational operators" << std::endl;
	std::cout << std::boolalpha << "vec_a == vec_b : " << (vec_a == vec_b) << std::endl;
	std::cout << std::boolalpha << "vec_a != vec_b : " << (vec_a != vec_b) << std::endl;
	std::cout << std::boolalpha << "vec_a < vec_b : " << (vec_a < vec_b) << std::endl;
	std::cout << std::boolalpha << "vec_a > vec_b : " << (vec_a > vec_b) << std::endl;
	std::cout << std::boolalpha << "vec_a <= vec_b : " << (vec_a <= vec_b) << std::endl;
	std::cout << std::boolalpha << "vec_a >= vec_b : " << (vec_a >= vec_b) << std::endl;

	vec_d = vec_b;

	std::cout << std::boolalpha << "vec_d == vec_b : " << (vec_d == vec_b) << std::endl;
	std::cout << std::boolalpha << "vec_d != vec_b : " << (vec_d != vec_b) << std::endl;
	std::cout << std::boolalpha << "vec_d < vec_b : " << (vec_d < vec_b) << std::endl;
	std::cout << std::boolalpha << "vec_d > vec_b : " << (vec_d > vec_b) << std::endl;
	std::cout << std::boolalpha << "vec_d <= vec_b : " << (vec_d <= vec_b) << std::endl;
	std::cout << std::boolalpha << "vec_d >= vec_b : " << (vec_d >= vec_b) << std::endl;

	test_vects(vects);

	std::cout << "Testing Vector::resize() ans Vector::reserve()" << std::endl;
	vec_a.resize(20);
	test_print_vec(vec_a);
	vec_a.resize(5000);
	test_print_vec(vec_a);
	vec_a.resize(0);
	test_print_vec(vec_a);
	vec_a.resize(20);
	test_print_vec(vec_a);
	fill_vect(vec_a, 12425);

	vec_b.reserve(1700);
	vec_b.reserve(17000);

	test_vects(vects);

	std::cout << "Testing Vector::assign() and Vector::swap()" << std::endl;

	vec_c.assign(vec_a.begin() + 1, vec_a.end() - 2);
	vec_d.assign(5,12);

	test_vects(vects);

	vec_a.swap(vec_b);
	ft::swap(vec_c, vec_d);

	test_vects(vects);

	std::cout << "Testing Vector access operators" << std::endl;

	std::cout << "vec_a[0]: " << vec_a[0] << std::endl;
	std::cout << "vec_a[1]: " << vec_a[1] << std::endl;
	std::cout << "vec_a[2]: " << vec_a[2] << std::endl;

	std::cout << "vec_a.at(0): " << vec_a.at(0) << std::endl;

	std::cout << "Testing exeptions thrown" << std::endl;

	try
	{
		std::cout << "vec_a.at(vec_a.size() + 10): " << vec_a.at(vec_a.size() + 10) << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Out of Range error: " << e.what() << '\n';
	}

	try
	{
		vec_a.resize(vec_a.max_size() + 10);
	}
	catch (const std::length_error& e) {
		std::cerr << "Length error: " << e.what() << '\n';
	}

	try
	{
		vec_a.reserve(vec_a.max_size() + 10);
	}
	catch (const std::length_error& e) {
		std::cerr << "Length error: " << e.what() << '\n';
	}


	std::cout << "Testing Vector::front() and Vector::back()" << std::endl;
	std::cout << "vec_a.front():" << vec_a.front() << std::endl;
	std::cout << "vec_a.back():" << vec_a.back() << std::endl;
	std::cout << "vec_b.front():" << vec_b.front() << std::endl;
	std::cout << "vec_b.back():" << vec_b.back() << std::endl;
	std::cout << "vec_c.front():" << vec_c.front() << std::endl;
	std::cout << "vec_c.back():" << vec_c.back() << std::endl;
	std::cout << "vec_d.front():" << vec_d.front() << std::endl;
	std::cout << "vec_d.back():" << vec_d.back() << std::endl;

	test_vects(vects);

	std::cout << "Testing Vector::insert()" << std::endl;

	//(1) single elem
	vec_b.insert(vec_b.begin() + 5, 75);
	vec_b.insert(vec_b.begin() + 2, 22);
	vec_b.insert(vec_b.begin() + 11, 875);

	//(2) fill
	vec_a.insert(vec_a.begin() + 2, 41, 5175);

	//(3) range
	vec_b.insert(vec_b.begin() + 1, vec_a.begin() + 12, vec_a.begin() +24);

	test_vects(vects);

	std::cout << "Testing Vector::erase()" << std::endl;

	vec_d.erase(vec_d.begin() + 2);
	vec_b.erase(vec_b.begin() + 5, vec_b.begin() + 8);

	std::cout << "Testing Vector::clear()" << std::endl;
	vec_a.clear();
	vec_a.clear();

	test_vects(vects);

	std::cout << "Testing const versions" << std::endl;
	ft::vector<int>::const_iterator const_it = vec_c.begin();
	ft::vector<int>::const_iterator const_ite = vec_c.end();
	int j = 0;
	while (const_it != const_ite)
	{
		std::cout << "j: " << j << " *it: " << *const_it << std::endl;
		const_it++;
		j++;
	}

	ft::vector<int>::const_reverse_iterator const_rit = vec_c.rbegin();
	ft::vector<int>::const_reverse_iterator const_rite = vec_c.rend();
	j = 0;
	while (const_rit != const_rite)
	{
		std::cout << "j: " << j << " *it: " << *const_rit << std::endl;
		const_rit++;
		j++;
	}

	ft::vector<int>::const_reference const_ref_a = vec_c[2];
	std::cout << const_ref_a << std::endl;

	ft::vector<int>::const_reference const_ref_b = vec_c.at(2);
	std::cout << const_ref_b << std::endl;

	ft::vector<int>::const_reference const_ref_c = vec_c.front();
	std::cout << const_ref_c << std::endl;

	ft::vector<int>::const_reference const_ref_d = vec_c.back();
	std::cout << const_ref_d << std::endl;

	test_vects(vects);
}

void map_tests()
{
	map_tests_normal();
	//map_tests_big();
}

int main(void)
{
	clock_t start_test;
	clock_t time_vect;
	clock_t time_stack;
	clock_t time_map;

	signal(SIGABRT, &abort_proc);
	srand(0);
	start_test = clock();

//	vector_tests();

	time_vect = clock() - start_test;
	start_test = clock();
	
//	stack_tests();

	time_stack = clock() - start_test;
	start_test = clock();

	map_tests();

	time_map = clock() - start_test;


	std::ofstream	outfile;
	#ifdef STD
		outfile.open ("./logs/std.time");
		if (!outfile.is_open())
		{
			std::cout << "TESTER ERROR: Cannot open output file" << std::endl;
			return (-1);
		}
		outfile << "STD" << std::endl;
	#else
		outfile.open ("./logs/ft.time");
		if (!outfile.is_open())
		{
			std::cout << "TESTER ERROR: Cannot open output file" << std::endl;
			return (-1);
		}
		outfile << "FT" << std::endl;
	#endif

	float time_f;
	time_f = ((float)time_vect)/CLOCKS_PER_SEC;
  	outfile << "Vector: " << time_f << " sec (" << time_vect << " CT.)" << std::endl;
	time_f = ((float)time_stack)/CLOCKS_PER_SEC;
  	outfile << " Stack: " << time_f << " sec (" << time_stack << " CT.)" << std::endl;
	time_f = ((float)time_map)/CLOCKS_PER_SEC;
  	outfile << "   Map: " << time_f << " sec (" << time_map << " CT.)" << std::endl;
  	outfile.close();
}