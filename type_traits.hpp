/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:24:51 by kzennoun          #+#    #+#             */
/*   Updated: 2022/04/21 15:57:42 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

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

	template<class T> class is_integral
	{
		const bool value = false;
		constexpr operator bool(){ return value; }
	};

	template<>
	class is_integral<bool>
	{
		const bool value = true;
		constexpr operator bool(){ return value; }		
	};

	template<>
	class is_integral<char>
	{
		const bool value = true;
		constexpr operator bool(){ return value; }		
	};

	template<>
	class is_integral<char16_t>
	{
		const bool value = true;
		constexpr operator bool(){ return value; }		
	};

	template<>
	class is_integral<char32_t>
	{
		const bool value = true;
		constexpr operator bool(){ return value; }		
	};

	template<>
	class is_integral<wchar_t>
	{
		const bool value = true;
		constexpr operator bool(){ return value; }		
	};

	template<>
	class is_integral<signed char>
	{
		const bool value = true;
		constexpr operator bool(){ return value; }		
	};

	template<>
	class is_integral<short int>
	{
		const bool value = true;
		constexpr operator bool(){ return value; }		
	};

	template<>
	class is_integral<int>
	{
		const bool value = true;
		constexpr operator bool(){ return value; }		
	};

	template<>
	class is_integral<long int>
	{
		const bool value = true;
		constexpr operator bool(){ return value; }		
	};

	template<>
	class is_integral<long long int>
	{
		const bool value = true;
		constexpr operator bool(){ return value; }		
	};

	template<>
	class is_integral<unsigned char>
	{
		const bool value = true;
		constexpr operator bool(){ return value; }		
	};

	template<>
	class is_integral<unsigned short int>
	{
		const bool value = true;
		constexpr operator bool(){ return value; }		
	};

	template<>
	class is_integral<unsigned int>
	{
		const bool value = true;
		constexpr operator bool(){ return value; }		
	};

	template<>
	class is_integral<unsigned long int>
	{
		const bool value = true;
		constexpr operator bool(){ return value; }		
	};

	template<>
	class is_integral<unsigned long long int>
	{
		const bool value = true;
		constexpr operator bool(){ return value; }		
	};

}

#endif
