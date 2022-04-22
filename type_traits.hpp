/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:24:51 by kzennoun          #+#    #+#             */
/*   Updated: 2022/04/23 00:07:51 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

//# include <uchar.h>

namespace ft
{
	template<bool Cond, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//faire plus de recherches sur constexpr
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	template<class T>
	struct is_integral
	{
		const static bool value = false;
		// constexpr operator bool(){ return value; }
	};

	template<>
	struct is_integral<bool>
	{
		const static bool value = true;
		// constexpr operator bool(){ return value; }		
	};

	template<>
	struct is_integral<char>
	{
		const static bool value = true;
		// constexpr operator bool(){ return value; }		
	};

	// template<>
	// struct is_integral<char16_t>
	// {
	// 	const static bool value = true;
	// 	// constexpr operator bool(){ return value; }		
	// };

	// template<>
	// struct is_integral<char32_t>
	// {
	// 	const static bool value = true;
	// 	// constexpr operator bool(){ return value; }		
	// };

	template<>
	struct is_integral<wchar_t>
	{
		const static bool value = true;
		// constexpr operator bool(){ return value; }		
	};

	template<>
	struct is_integral<signed char>
	{
		const static bool value = true;
		// constexpr operator bool(){ return value; }		
	};

	template<>
	struct is_integral<short int>
	{
		const static bool value = true;
		// constexpr operator bool(){ return value; }		
	};

	template<>
	struct is_integral<int>
	{
		const static bool value = true;
		// constexpr operator bool(){ return value; }		
	};

	template<>
	struct is_integral<long int>
	{
		const static bool value = true;
		// constexpr operator bool(){ return value; }		
	};

	template<>
	struct is_integral<long long int>
	{
		const static bool value = true;
		// constexpr operator bool(){ return value; }		
	};

	template<>
	struct is_integral<unsigned char>
	{
		const static bool value = true;
		// constexpr operator bool(){ return value; }		
	};

	template<>
	struct is_integral<unsigned short int>
	{
		const static bool value = true;
		// constexpr operator bool(){ return value; }		
	};

	template<>
	struct is_integral<unsigned int>
	{
		const static bool value = true;
		// constexpr operator bool(){ return value; }		
	};

	template<>
	struct is_integral<unsigned long int>
	{
		const static bool value = true;
		// constexpr operator bool(){ return value; }		
	};

	template<>
	struct is_integral<unsigned long long int>
	{
		const static bool value = true;
		// constexpr operator bool(){ return value; }		
	};

}

#endif
