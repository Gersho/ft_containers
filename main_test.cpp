/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:39:50 by kzennoun          #+#    #+#             */
/*   Updated: 2022/04/19 15:00:45 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "vector.hpp"
#include <vector>
#include <iostream>

//namespace ft = std;

/*

• vector
You don’t have to do the vector<bool> specialization.

• map

• stack
It will use your vector class as default underlying container. But it must still be
compatible with other containers, the STL ones included.


You also have to implement:

• iterators_traits

• reverse_iterator

• enable_if
Yes, it is C++11 but you will be able to implement it in a C++98 manner.
This is asked so you can discover SFINAE.

• is_integral

• equal and/or lexicographical_compare

• std::pair

• std::make_pair

*/

int main()
{	


	ft::vector<int> ft_vec;
	std::cout << "ft size: " << ft_vec.size() << std::endl;
	std::cout << "ft capacity: " << ft_vec.capacity() << std::endl;
	std::cout << "ft max_size: " << ft_vec.max_size() << std::endl;
	ft_vec.push_back(5);
	ft_vec.push_back(15);
	std::cout << "ft size: " << ft_vec.size() << std::endl;
	std::cout << "ft capacity: " << ft_vec.capacity() << std::endl;

	// std::vector<int> std_vec;

	// std::cout << "std size: " << std_vec.size() << std::endl;
	// std::cout << "std capacity: " << std_vec.capacity() << std::endl;
	// std::cout << "std max_size: " << std_vec.max_size() << std::endl;
	// std_vec.push_back(99);
	// std_vec.push_back(99);
	// std_vec.push_back(99);
	// std::cout << "std size: " << std_vec.size() << std::endl;
	// std::cout << "std capacity: " << std_vec.capacity() << std::endl;
	// std::cout << "std max_size: " << std_vec.max_size() << std::endl;

	
	// std_vec.assign(2, 1);
	// std::cout << "std size: " << std_vec.size() << std::endl;
	// std::cout << "std capacity: " << std_vec.capacity() << std::endl;
	// std::cout << "std max_size: " << std_vec.max_size() << std::endl;
	// ft::__generic_iterator<int> it = std_vec.begin();
	// std::cout << "std iterator begin: " << std_vec.begin() << std::endl;
	// std::cout << "std iterator end: " << std_vec.end() << std::endl;
	return 0;
}