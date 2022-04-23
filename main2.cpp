/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:37:26 by kzennoun          #+#    #+#             */
/*   Updated: 2022/04/23 04:26:37 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//#if 0
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

// template<class T>
// struct is_vector
// {
// 	const static bool value = false;
// };

// template<class U>
// struct is_vector<ft::vector<U> >
// {
// 	const static bool value = true;		
// };


template<class T>
void test_print_vec(const ft::vector<T> &vec )
{
	std::size_t vec_size = vec.size();
	
	std::cout << "size(): " << vec.size() << std::endl;
	std::cout << "maxsize(): " << vec.max_size() << std::endl;
	std::cout << "capacity(): " << vec.capacity() << std::endl;

	for (std::size_t i = 0; i < vec_size; i++)
	{
		std::cout << "vec[" << i << "]: " << vec[i] << std::endl;
	}
}


int main(void)
{
	{
		ft::vector<int> vec_a;
		ft::vector<int> vec_b(4, 5);
		ft::vector<int> vec_c(vec_b.begin()+2, vec_b.end());
		ft::vector<int> vec_d(vec_c);
		
		std::cout << "Testing Vector::empty()" << std::endl;
		std::cout << std::boolalpha << "vec_a.empty(): " << vec_a.empty() << std::endl;
		std::cout << std::boolalpha << "vec_b.empty(): " << vec_b.empty() << std::endl;
		std::cout << std::boolalpha << "vec_c.empty(): " << vec_c.empty() << std::endl;
		std::cout << std::boolalpha << "vec_d.empty(): " << vec_d.empty() << std::endl;

		std::cout << "Printing vector A" << std::endl;
		test_print_vec(vec_a);
		std::cout << "Printing vector B" << std::endl;
		test_print_vec(vec_b);
		std::cout << "Printing vector C" << std::endl;
		test_print_vec(vec_c);
		std::cout << "Printing vector D" << std::endl;
		test_print_vec(vec_d);

		std::cout << "Testing Vector::push_back() and Vector::pop_back()" << std::endl;
		vec_a.push_back(5);
		vec_a.push_back(10);
		vec_a.pop_back();
		vec_a.push_back(105);
		vec_a.push_back(115);
		vec_a.push_back(125);
		vec_a.pop_back();
		vec_a.push_back(15);
		vec_a.push_back(20);


		vec_b.push_back(45455);
		vec_b.push_back(15415);
		vec_b.push_back(1245);
		vec_b.push_back(1221125);
		vec_b.push_back(525);
		vec_b.push_back(1575);
		vec_b.push_back(1275725);
		vec_b.push_back(12444125);
		vec_b.push_back(111125);
		vec_b.push_back(1225);
		vec_b.push_back(0);
		vec_b.push_back(45);

		std::cout << "Printing vector A" << std::endl;
		test_print_vec(vec_a);
		std::cout << "Printing vector B" << std::endl;
		test_print_vec(vec_b);
		std::cout << "Printing vector C" << std::endl;
		test_print_vec(vec_c);
		std::cout << "Printing vector D" << std::endl;
		test_print_vec(vec_d);

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


		std::cout << "Testing Vector::resize()" << std::endl;
		vec_a.resize(20);
		test_print_vec(vec_a);
		vec_a.resize(50);
		test_print_vec(vec_a);
		vec_a.resize(0);
		test_print_vec(vec_a);
		vec_a.resize(20);
		test_print_vec(vec_a);
		vec_a.push_back(5);
		vec_a.push_back(10);
		vec_a.pop_back();
		vec_a.push_back(105);
		vec_a.push_back(115);
		vec_a.push_back(105);
		vec_a.push_back(115);
		vec_a.push_back(105);
//std::cout << "STILL ALIVE" << std::endl;
		vec_a.push_back(115);
		vec_a.push_back(105);
		vec_a.push_back(115);
		vec_a.push_back(105);
		vec_a.push_back(115);
		vec_a.push_back(105);
		vec_a.push_back(115);
		vec_a.push_back(105);
		vec_a.push_back(115);
		vec_a.push_back(105);
		vec_a.push_back(115);
		vec_a.push_back(105);
		vec_a.push_back(115);
		vec_a.push_back(125);
		vec_a.pop_back();
		vec_a.push_back(15);
		vec_a.push_back(20);

		vec_b.reserve(17);

		std::cout << "Printing vector A" << std::endl;
		test_print_vec(vec_a);
		std::cout << "Printing vector B" << std::endl;
		test_print_vec(vec_b);
		std::cout << "Printing vector C" << std::endl;
		test_print_vec(vec_c);
		std::cout << "Printing vector D" << std::endl;
		test_print_vec(vec_d);

		std::cout << "Testing Vector::assign()" << std::endl;
// std::cout << vec_c.rend() - vec_c.rbegin() << std::endl;
// std::cout << vec_c.rbegin() - vec_c.rend() << std::endl;
// 		 vec_c.assign(vec_a.rbegin(), vec_a.rend());
		vec_c.assign(vec_a.begin(), vec_a.end());
std::cout << "STILL ALIVE" << std::endl;
		vec_d.assign(5,12);
		vec_b.swap(vec_a);

		std::cout << "Printing vector A" << std::endl;
		test_print_vec(vec_a);
		std::cout << "Printing vector B" << std::endl;
		test_print_vec(vec_b);
		std::cout << "Printing vector C" << std::endl;
		test_print_vec(vec_c);
		std::cout << "Printing vector D" << std::endl;
		test_print_vec(vec_d);

		std::cout << "Testing Vector access operators" << std::endl;

		std::cout << "vec_a[0]: " << vec_a[0] << std::endl;
		std::cout << "vec_a[1]: " << vec_a[1] << std::endl;
		std::cout << "vec_a[2]: " << vec_a[2] << std::endl;

		std::cout << "vec_a.at(0): " << vec_a.at(0) << std::endl;

		try
		{
			std::cout << "vec_a.at(500): " << vec_a.at(500) << std::endl;
		}
		catch (const std::out_of_range& e) {
			std::cerr << "Out of Range error: " << e.what() << '\n';
		}

		std::cout << "Testing Vector::front() and Vector::back()" << std::endl;
		std::cout << "vec_a.front():" << vec_a.front() << std::endl;
		std::cout << "vec_a.back():" << vec_a.back() << std::endl;
		std::cout << "vec_b.front():" << vec_b.front() << std::endl;
		std::cout << "vec_b.back():" << vec_a.back() << std::endl;
		std::cout << "vec_c.front():" << vec_c.front() << std::endl;
		std::cout << "vec_c.back():" << vec_c.back() << std::endl;
		std::cout << "vec_d.front():" << vec_d.front() << std::endl;
		std::cout << "vec_d.back():" << vec_d.back() << std::endl;

		std::cout << "Printing vector A" << std::endl;
		test_print_vec(vec_a);
		std::cout << "Printing vector B" << std::endl;
		test_print_vec(vec_b);
		std::cout << "Printing vector C" << std::endl;
		test_print_vec(vec_c);
		std::cout << "Printing vector D" << std::endl;
		test_print_vec(vec_d);

		std::cout << "Testing Vector::insert()" << std::endl;



		vec_b.insert(vec_b.begin() + 5, 75);
		vec_b.insert(vec_b.begin() + 2, 22);
		vec_b.insert(vec_b.begin() + 11, 875);

		vec_b.insert(vec_b.begin() + 1, vec_a.begin() + 2, vec_a.end() - 3);

// std::cout << "juste avant le insert relou" << std::endl;
// 		vec_c.insert(vec_c.begin() + 2, 5, 55);

		std::cout << "Printing vector A" << std::endl;
		test_print_vec(vec_a);
		std::cout << "Printing vector B" << std::endl;
		test_print_vec(vec_b);
		std::cout << "Printing vector C" << std::endl;
		test_print_vec(vec_c);
		std::cout << "Printing vector D" << std::endl;
		test_print_vec(vec_d);

		std::cout << "Testing Vector::erase()" << std::endl;

		vec_d.erase(vec_d.begin() + 2);
		vec_b.erase(vec_b.begin() + 5, vec_b.begin() + 8);


		std::cout << "Testing Vector::clear()" << std::endl;
		vec_a.clear();
		vec_a.clear();

		std::cout << "Printing vector A" << std::endl;
		test_print_vec(vec_a);
		std::cout << "Printing vector B" << std::endl;
		test_print_vec(vec_b);
		std::cout << "Printing vector C" << std::endl;
		test_print_vec(vec_c);
		std::cout << "Printing vector D" << std::endl;
		test_print_vec(vec_d);

	} // end vector<int>
}