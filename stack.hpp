/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:21:50 by kzennoun          #+#    #+#             */
/*   Updated: 2022/07/16 14:40:31 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft 
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{

		public:

		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;
		
		explicit stack (const container_type& ctnr = container_type())
		:_cont(ctnr)
		{
		}

		bool empty() const
		{
			return _cont.empty();
		}

		size_type size() const
		{
			return _cont.size();
		}

		value_type& top()
		{
			return _cont.back();
		}
		const value_type& top() const
		{
			return _cont.back();
		}

		void push (const value_type& val)
		{
			_cont.push_back(val);	
		}

		void pop()
		{
			_cont.pop_back();
		}
		
		protected:
		
		container_type &_cont;
		
		private:


	}; //fin class stack

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs._cont.operator==(rhs);
	}

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(lhs._cont.operator==(rhs));
	}

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs._cont.operator<(rhs);
	}

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs._cont.operator<=(rhs);
	}

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs._cont.operator>(rhs);
	}

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs._cont.operator>=(rhs);
	}

}


#endif

