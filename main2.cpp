/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:37:26 by kzennoun          #+#    #+#             */
/*   Updated: 2022/04/23 21:14:17 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifdef STD //CREATE A REAL STL EXAMPLE
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

template<class T>
void test_print_vec(const ft::vector<T> &vec )
{
	std::size_t vec_size = vec.size();
	
	std::cout << "size(): " << vec.size() << std::endl;
	std::cout << "maxsize(): " << vec.max_size() << std::endl;
	std::cout << "capacity(): " << vec.capacity() << std::endl;
	std::cout << "end() - begin(): " << vec.end() - vec.begin() << std::endl;
//	std::cout << "rbegin() - rend(): " << vec.rbegin() - vec.rend() << std::endl;
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

int main(void)
{
	srand(std::time(NULL));
	{
		ft::vector<int> vec_a;
		ft::vector<int> vec_b(4, 5);
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

		//vec_a.pop_back(); //SEGFAULT test
		fill_vect(vec_a, 50);
		vec_a.pop_back();

		fill_vect(vec_b, 25);
		fill_vect(vec_c, 15);
		fill_vect(vec_d, 10);

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
		vec_a.resize(50);
		test_print_vec(vec_a);
		vec_a.resize(0);
		test_print_vec(vec_a);
		vec_a.resize(20);
		test_print_vec(vec_a);
		fill_vect(vec_a, 15);

		vec_b.reserve(17);

		test_vects(vects);

		std::cout << "Testing Vector::assign() and Vector::swap()" << std::endl;

// 		 vec_c.assign(vec_a.rbegin(), vec_a.rend());
		vec_c.assign(vec_a.begin() + 1, vec_a.end() - 2);
		vec_d.assign(5,12);
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
			std::cout << "vec_a.at(500): " << vec_a.at(500) << std::endl;
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

		//vec_b.insert(vec_b.begin() + 1, vec_a.begin() + 25, vec_a.begin() +24); // SEGFAULT TEST
		vec_b.insert(vec_b.begin() + 1, vec_a.begin() + 12, vec_a.begin() +24);


// std::cout << "PROBLEM HERE" << std::endl;
std::cout << "IN MAIN diff: " << vec_c.end() - (vec_c.begin() + 2) << " start " << (vec_c.begin() + 2) - vec_c.begin() << std::endl;
 		vec_c.insert(vec_c.begin() + 2, 12, 55);

		test_vects(vects);

		std::cout << "Testing Vector::erase()" << std::endl;

		vec_d.erase(vec_d.begin() + 2);
		vec_b.erase(vec_b.begin() + 5, vec_b.begin() + 8);


		std::cout << "Testing Vector::clear()" << std::endl;
		vec_a.clear();
		vec_a.clear();

		test_vects(vects);


	} // end vector<int>
}