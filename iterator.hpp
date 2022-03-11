/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:40:00 by kzennoun          #+#    #+#             */
/*   Updated: 2022/03/11 15:51:26 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{

	template< class Iter >
	struct iterator_traits
	{
		typename std::incrementable_traits<Iter>::difference_type  	difference_type
		typename void 												value_type
		typename void 												pointer
		typename void 												reference
		typename std::output_iterator_tag 							iterator_category
	};

	template< class T >
	struct iterator_traits<T*>
	{

		typename	std::ptrdiff_t 					difference_type
		typename	T								value_type
		typename	T* 								pointer
		typename	T& 								reference
		typename	std::random_access_iterator_tag iterator_category

	};

	template< class T >
	struct iterator_traits<const T*>
	{
		typename difference_type					std::ptrdiff_t
		typename T 									value_type
		typename const T* 							pointer
		typename const T& 							reference
		typename std::random_access_iterator_tag 	iterator_category	

	};

}