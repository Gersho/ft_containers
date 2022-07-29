/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:37:26 by kzennoun          #+#    #+#             */
/*   Updated: 2022/07/29 14:01:51 by kzennoun         ###   ########lyon.fr   */
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

template<class T>
void test_print_vec(ft::vector<T> &vec )
{
	std::size_t vec_size = vec.size();
	
	std::cout << "size(): " << vec.size() << std::endl;
	std::cout << "maxsize(): " << vec.max_size() << std::endl;
	std::cout << "capacity(): " << vec.capacity() << std::endl;
	std::cout << "end() - begin(): " << vec.end() - vec.begin() << std::endl;

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

void fill_vect(ft::vector<int> &vec, size_t qt)
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
	typename ft::map<Key, T>::iterator it = map.begin();
	typename ft::map<Key, T>::iterator ite = map.end();
// std::cout << "in show map it: " << it.get_it() << " ite: " << ite.get_it() << std::endl; 
	std::cout << "normal order" << std::endl;
	while(it != ite)
	{
// std::cout << "in the loop" << " it: " << it.get_it() << " ite: " << ite.get_it() << std::endl;
		std::cout << "key: " << it->first<< " value: " << it->second << std::endl;
		it++;
	}

	// typename ft::map<Key, T>::reverse_iterator rit = map.rbegin();
	// typename ft::map<Key, T>::reverse_iterator rite = map.rend();

	// std::cout << "reverse order" << std::cout;
	// while(rit != rite)
	// {
	// 	std::cout << "key: " << rit->first<< " value: " << rit->second << std::endl;
	// 	rit++;
	// }
}

void map_tests_basics()
{

	ft::map<int, int> a;
	ft::map<int, int> b;

	a.insert( ft::make_pair<int, int>( 5, 5 ) );
	a.insert( ft::make_pair<int, int>( 8, 1 ) );
	a.insert( ft::make_pair<int, int>( 0, 2 ) );
	a.insert( ft::make_pair<int, int>( 2, 3 ) );

	ft::map<int, int> c(a.begin(), a.end());
	//ft::map<int, int> d(c);

	std::cout << "printing map c" << std::endl;
	show_map(c);
	// std::cout << "printing map d" << std::endl;
	// show_map(d);

	a.insert( ft::make_pair<int, int>( 2, 3 ) );
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
	// show_map(a);
	std::cout << "printing map b" << std::endl;
	show_map(b);

	std::cout << a.empty() << std::endl;
	std::cout << b.empty() << std::endl;
	std::cout << a.size() << std::endl;
	std::cout << b.size() << std::endl;
	std::cout << a.max_size() << std::endl;
	std::cout << b.max_size() << std::endl;
//	std::cout << "print a[2]" << a[2] << std::endl;
}

void map_tests()
{
	map_tests_basics();
	//map_tests_big();
}

void vector_tests()
{
	ft::vector<int> vec_a;
	ft::vector<int> vec_b(400, 5);
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

	test_vects(vects);

	std::cout << "Testing Vector::assign() and Vector::swap()" << std::endl;

	vec_c.assign(vec_a.begin() + 1, vec_a.end() - 2);
	vec_d.assign(5,12);

	test_vects(vects);

	vec_b.swap(vec_a);

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

	vec_b.insert(vec_b.begin() + 5, 75);
	vec_b.insert(vec_b.begin() + 2, 22);
	vec_b.insert(vec_b.begin() + 11, 875);

	vec_b.insert(vec_b.begin() + 1, vec_a.begin() + 12, vec_a.begin() +24);

	vec_c.insert(vec_c.begin() + 2, 12, 55);
	vec_a.insert(vec_a.begin() + 2, 41, 5175);

	test_vects(vects);

	std::cout << "Testing Vector::erase()" << std::endl;

	vec_d.erase(vec_d.begin() + 2);
	vec_b.erase(vec_b.begin() + 5, vec_b.begin() + 8);


	std::cout << "Testing Vector::clear()" << std::endl;
	vec_a.clear();
	vec_a.clear();

	 test_vects(vects);
}

int main(void)
{
	clock_t start_test;
	clock_t time_vect;
	clock_t time_stack;
	clock_t time_map;

	//srand(std::time(NULL));
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