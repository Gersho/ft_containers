/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:39:50 by kzennoun          #+#    #+#             */
/*   Updated: 2022/04/14 16:58:49 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "vector.hpp"
#include <vector>
#include <iostream>

//namespace ft = std;

int main()
{	


	ft::vector<int> ft_vec;
	std::cout << "ft size: " << ft_vec.size() << std::endl;
	std::cout << "ft capacity: " << ft_vec.capacity() << std::endl;
	std::cout << "ft max_size: " << ft_vec.max_size() << std::endl;
	ft_vec.push_back(5);
	ft_vec.push_back(15);
	
	std::vector<int> std_vec;

	std::cout << "std size: " << std_vec.size() << std::endl;
	std::cout << "std capacity: " << std_vec.capacity() << std::endl;
	std::cout << "std max_size: " << std_vec.max_size() << std::endl;
	std_vec.reserve(99);
	std::cout << "std size: " << std_vec.size() << std::endl;
	std::cout << "std capacity: " << std_vec.capacity() << std::endl;
	std::cout << "std max_size: " << std_vec.max_size() << std::endl;

	// ft::__generic_iterator<int> it = std_vec.begin();
	// std::cout << "std iterator begin: " << std_vec.begin() << std::endl;
	// std::cout << "std iterator end: " << std_vec.end() << std::endl;
	return 0;
}