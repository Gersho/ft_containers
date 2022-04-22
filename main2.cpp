/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:37:26 by kzennoun          #+#    #+#             */
/*   Updated: 2022/04/23 01:05:36 by kzennoun         ###   ########lyon.fr   */
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
	ft::vector<int> vec_a;
	ft::vector<int> vec_b(4, 5);
	// ft::vector<int> vec_c;
	
	
	// int	i_a = 4;
	// int i_b = 5;
	// ft::vector<int> vec_b(i_a, i_b);	
	
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
	std::cout << std::boolalpha << "vec_a.empty(): " << vec_a.empty() << std::endl;
	std::cout << std::boolalpha << "vec_b.empty(): " << vec_b.empty() << std::endl;

	test_print_vec(vec_a);
	test_print_vec(vec_b);

	vec_a.push_back(5);
	vec_a.push_back(10);
	vec_a.push_back(15);
	vec_a.push_back(20);

	//vec_a.assign(5,12);
	vec_a.pop_back();

	test_print_vec(vec_a);
	test_print_vec(vec_b);

	std::cout << std::boolalpha << "vec_a == vec_b : " << (vec_a == vec_b) << std::endl;
	std::cout << std::boolalpha << "vec_a != vec_b : " << (vec_a != vec_b) << std::endl;
	std::cout << std::boolalpha << "vec_a < vec_b : " << (vec_a < vec_b) << std::endl;
	std::cout << std::boolalpha << "vec_a > vec_b : " << (vec_a > vec_b) << std::endl;
	std::cout << std::boolalpha << "vec_a <= vec_b : " << (vec_a <= vec_b) << std::endl;
	std::cout << std::boolalpha << "vec_a >= vec_b : " << (vec_a >= vec_b) << std::endl;

	vec_a = vec_b;

	std::cout << std::boolalpha << "vec_a == vec_b : " << (vec_a == vec_b) << std::endl;
	std::cout << std::boolalpha << "vec_a != vec_b : " << (vec_a != vec_b) << std::endl;
	std::cout << std::boolalpha << "vec_a < vec_b : " << (vec_a < vec_b) << std::endl;
	std::cout << std::boolalpha << "vec_a > vec_b : " << (vec_a > vec_b) << std::endl;
	std::cout << std::boolalpha << "vec_a <= vec_b : " << (vec_a <= vec_b) << std::endl;
	std::cout << std::boolalpha << "vec_a >= vec_b : " << (vec_a >= vec_b) << std::endl;

	vec_a.resize(20);
	vec_b.reserve(17);

	test_print_vec(vec_a);
	test_print_vec(vec_b);

	vec_b.swap(vec_a);

	test_print_vec(vec_a);
	test_print_vec(vec_b);
}