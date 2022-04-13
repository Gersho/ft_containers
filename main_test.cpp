/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:39:50 by kzennoun          #+#    #+#             */
/*   Updated: 2022/04/13 16:29:16 by kzennoun         ###   ########lyon.fr   */
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

	
	std::vector<int> std_vec;

	std::cout << "std size: " << std_vec.size() << std::endl;
	std::cout << "std capacity: " << std_vec.capacity() << std::endl;
	std::cout << "std max_size: " << std_vec.max_size() << std::endl;

	return 0;
}