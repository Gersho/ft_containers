/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:21:50 by kzennoun          #+#    #+#             */
/*   Updated: 2022/08/12 15:10:18 by kzennoun         ###   ########lyon.fr   */
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

		//typedef T			value_type;
		typedef Container	container_type;
		typedef typename Container::value_type value_type;
		typedef typename Container::size_type size_type;
		//typedef size_t		size_type;
		
		explicit stack (const container_type& ctnr = container_type())
		:_cont(ctnr)
		{
		}

		//~stack() {}

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



	template <class X, class Y>
	friend bool operator== (const stack<X,Y>& lhs, const stack<X,Y>& rhs);

	template <class X, class Y>
	friend bool operator!= (const stack<X,Y>& lhs, const stack<X,Y>& rhs);

	template <class X, class Y>
	friend bool operator<  (const stack<X,Y>& lhs, const stack<X,Y>& rhs);

	template <class X, class Y>
	friend bool operator<= (const stack<X,Y>& lhs, const stack<X,Y>& rhs);

	template <class X, class Y>
	friend bool operator>  (const stack<X,Y>& lhs, const stack<X,Y>& rhs);

	template <class X, class Y>
	friend bool operator>= (const stack<X,Y>& lhs, const stack<X,Y>& rhs);


		protected:
		
		container_type _cont;
		
		private:


	}; //fin class stack

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		//return lhs._cont.operator==(rhs);
		return lhs._cont == rhs._cont;
	}

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		//return !(lhs._cont.operator==(rhs));
		return !(lhs._cont == rhs._cont);
	}

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		//return lhs._cont.operator<(rhs);
		return lhs._cont < rhs._cont;
	}

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		//return lhs._cont.operator<=(rhs);
		return lhs._cont <= rhs._cont;
	}

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		// return lhs._cont.operator>(rhs);
		return lhs._cont > rhs._cont;
	}

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		//return lhs._cont.operator>=(rhs);
		return lhs._cont >= rhs._cont;
	}

}


#endif

