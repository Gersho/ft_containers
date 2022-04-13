/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:40:00 by kzennoun          #+#    #+#             */
/*   Updated: 2022/04/13 14:15:56 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITERATOR_HPP
# define ITERATOR_HPP


# include <cstddef>

namespace ft
{
	struct random_access_iterator_tag {};

	template< class Iter >
	struct iterator_traits
	{
		typename			Iter::difference_type  	difference_type;
		typedef	typename	Iter::value_type		value_type;
		typedef	typename	Iter::pointer			pointer;
		typedef	typename	Iter::reference			reference;
		typedef	typename	Iter::iterator_category	iterator_category;
	};

	template< class T >
	struct iterator_traits< T* >
	{
		typedef	std::ptrdiff_t 					difference_type;
		typedef	T								value_type;
		typedef	T* 								pointer;
		typedef	T& 								reference;
		typedef	ft::random_access_iterator_tag	iterator_category;
	};

	template< class T >
	struct iterator_traits< const T* >
	{
		typedef	std::ptrdiff_t					difference_type;			
		typedef	T 								value_type;
		typedef	const T* 						pointer;
		typedef	const T& 						reference;
		typedef	ft::random_access_iterator_tag	iterator_category;
	};

	// template <
	// 			class Category,
	// 			class T,
	// 			class Distance = ptrdiff_t,
	// 			class Pointer = T*,
	// 			class Reference = T&
	// 			>
	// struct __iterator {
	// 	typedef Category  iterator_category;
	// 	typedef T         value_type;
	// 	typedef Distance  difference_type;
	// 	typedef Pointer   pointer;
	// 	typedef Reference reference;
	// };

	template < class T >
	class __generic_iterator// : public ft::__iterator<ft::random_access_iterator_tag, T>
	{
		private:

		T *it;



		protected:
		
		public:


		typedef ft::random_access_iterator_tag 			iterator_category;
		typedef T         								value_type;
		typedef std::ptrdiff_t  						difference_type;
		typedef T*   									pointer;
		typedef T& 										reference;


		__generic_iterator()
			: it(NULL)
		{
		}

		__generic_iterator(T *ptr)
			: it(ptr)
		{
		}

		__generic_iterator(const __generic_iterator<T> & src)
			: it(src.it)
		{
		}
		~__generic_iterator(){}

		__generic_iterator<T> & operator=(const __generic_iterator<T> & rhs)
		{
			it = rhs.it;
			return *this;
		}

		bool operator==( const __generic_iterator<T> & rhs) const
		{
			return it==rhs.it;
		}

		bool operator !=(const __generic_iterator<T> & rhs) const
		{
			return it!=rhs.it;
		}

		__generic_iterator<T>&	operator++( void ) {
			this->it++;
			return *this;
		}

		__generic_iterator<T>	operator++( int ) {
			__generic_iterator<T>	res;

			res = ++*this;
			return res;
		}

		__generic_iterator<T>&	operator--( void ) {
			this->it--;
			return *this;
		}

		__generic_iterator<T>	operator--( int ) {
			__generic_iterator<T>	res;

			res = --*this;
			return res;
		}

		bool operator<( const __generic_iterator<T> & rhs ) const
		{
			return it < rhs.it;
		}

		bool operator>( const __generic_iterator<T> & rhs ) const
		{
			return it > rhs.it;
		}

		bool operator<=( const __generic_iterator<T> & rhs ) const
		{
			return it <= rhs.it;
		}

		bool operator>=( const __generic_iterator<T> & rhs) const
		{
			return it >= rhs.it;
		}

		reference operator*() const
		{
			return *it;
		}

		pointer operator->() const
		{
			return it;
		}

		reference operator[](difference_type index) const
		{
			return *(it + index);
		}


		difference_type operator-(const __generic_iterator<T> & rhs) const 
		{
			return it - rhs.it;
		}

		__generic_iterator<T> operator+(difference_type rhs) const 
		{
			return it + rhs;
		}

		__generic_iterator<T> operator-(difference_type rhs) const 
		{
			return it - rhs;
		}

		__generic_iterator<T>& operator+=(difference_type rhs) const 
		{
			it += rhs;
			return *this;
		}

		__generic_iterator<T>& operator-=(difference_type rhs) const 
		{
			it -= rhs;
			return *this;
		}

		friend void advance (__generic_iterator<T>& it, typename iterator_traits<__generic_iterator<T> >::difference_type n);
	//	friend void advance (__generic_iterator<T>& it, typename iterator_traits<__generic_iterator<T> >::difference_type n);
		friend typename iterator_traits<__generic_iterator<T> >::difference_type distance (__generic_iterator<T> first, __generic_iterator<T> last);
	}; // class iterator end

//TODO const iterator (heritage de l'iterator non const ?)

	template <class InputIterator, class Distance>
	void advance (InputIterator& it, Distance n)
	{
		it.it = it.it + n;
	}

	template<class InputIterator>
	typename iterator_traits<InputIterator>::difference_type distance (InputIterator first, InputIterator last)
	{
		std::ptrdiff_t d;

		d = last.it - first.it;
		if (d < 0)
			d = d * -1;
		return d;
	}

/*
	template <class Iterator>
	class __generic_reverse_iterator
	{
		typename Iterator											iterator_type;
		typename iterator_traits<Iterator>::iterator_category		iterator_category;
		typename iterator_traits<Iterator>::value_type				value_type;
		typename iterator_traits<Iterator>::difference_type			difference_type;
		typename iterator_traits<Iterator>::pointer					pointer;
		typename iterator_traits<Iterator>::reference				reference;

		public:

		protected:



		//default (1)
		__generic_reverse_iterator()
		{

		}

		//initialisation (2)
		__generic_reverse_iterator(iterator_type iter)
		{
		}

		//copy (3)
		template <class Iter>
		__generic_reverse_iterator(const __generic_reverse_iterator<Iter>& rev_it)
		{

		}
		
		private:

		iterator_type base_iterator;
		
	};
*/



} // namespace ft end

#endif



/*


Member functions

(constructor)
    Constructs reverse_iterator object (public member function )

default (1)	 		reverse_iterator();

initialization (2)	 explicit reverse_iterator (iterator_type it);

copy (3)		template <class Iter>
  				reverse_iterator (const reverse_iterator<Iter>& rev_it);

base
    Return base iterator (public member function )

operator*
    Dereference iterator (public member function )

operator+
    Addition operator (public member function )

operator++
    Increment iterator position (public member function )

operator+=
    Advance iterator (public member function )

operator-
    Subtraction operator (public member function )

operator--
    Decrease iterator position (public member function )

operator-=
    Retrocede iterator (public member function )

operator->
    Dereference iterator (public member function )

operator[]
    Dereference iterator with offset (public member function )


Non-member function overloads

relational operators
    Relational operators for reverse_iterator (function template )

operator+
    Addition operator (function template )

operator-
    Subtraction operator (function template )




*/