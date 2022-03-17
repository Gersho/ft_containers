/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:40:00 by kzennoun          #+#    #+#             */
/*   Updated: 2022/03/17 16:21:19 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{
	// template< class Iter >
	// struct iterator_traits
	// {
	// 	typename	std::incrementable_traits<Iter>::difference_type  	difference_type
	// 	typename	void 												value_type
	// 	typename	void 												pointer
	// 	typename	void 												reference
	// 	typename	std::output_iterator_tag 							iterator_category
	// };

	template< class Iter >
	struct iterator_traits
	{
		typename	Iter::difference_type  	difference_type
		typename	Iter::value_type		value_type
		typename	Iter::pointer			pointer
		typename	Iter::reference			reference
		typename	Iter::iterator_category	iterator_category
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
		typename	std::ptrdiff_t						difference_type					
		typename	T 									value_type
		typename	const T* 							pointer
		typename	const T& 							reference
		typename	std::random_access_iterator_tag 	iterator_category	
	};

	template <
				class Category,
				class T,
				class Distance = ptrdiff_t,
				class Pointer = T*,
				class Reference = T&
				>
	struct iterator {
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};

	template < class T >
	class random_access_iterator : public ft::iterator<std::random_access_iterator_tag, T>
	{
		private:

		T *it;

		protected:
		
		public:

		random_access_iterator()
		{
			it = NULL;
		}
		random_access_iterator(const random_access_iterator<T> & src)
		{
			it = src.it;
		}
		~random_access_iterator(){}

		random_access_iterator<T> & operator=(const random_access_iterator<T> & rhs)
		{
			if ( this != &rhs )
			{
				it = rhs.it;
			}
			return *this;
		}

		bool operator==( const random_access_iterator<T> & rhs) const
		{
			return p==rhs.p;
		}

		bool operator !=(const random_access_iterator<T> & rhs) const
		{
			return p!=rhs.p;
		}

		random_access_iterator<T>&	operator++( void ) {
			this->it++;
			return *this;
		}

		random_access_iterator<T>	operator++( int n ) {
			( void ) n;
			random_access_iterator	res;

			res = ++*this;
			return res;
		}

		random_access_iterator<T>&	operator--( void ) {
			this->it--;
			return *this;
		}

		random_access_iterator<T>	operator--( int n ) {
			( void ) n;
			random_access_iterator<T>	res;

			res = --*this;
			return res;
		}

		bool operator<( const random_access_iterator<T> & rhs) const
		{
			return p<rhs.p;
		}

		bool operator>( const random_access_iterator<T> & rhs) const
		{
			return p>rhs.p;
		}

		bool operator<=( const random_access_iterator<T> & rhs) const
		{
			return p<=rhs.p;
		}

		bool operator>=( const random_access_iterator<T> & rhs) const
		{
			return p>=rhs.p;
		}

		T& operator*()
		{
			return *it;
		}

		T* operator->()
		{
			return it;
		}

		T & operator[](const unsigned int & index)
		{
			return *(it + index);
		}

		random_access_iterator<T>& operator+(const random_access_iterator<T> & rhs) const 
		{
			return it + rhs.it;
		}

		random_access_iterator<T>& operator-(const random_access_iterator<T> & rhs) const 
		{
			return it - rhs.it;
		}

		random_access_iterator<T>& operator+(const int & rhs) const 
		{
			return it + rhs;
		}

		random_access_iterator<T>& operator-(const int & rhs) const 
		{
			return it - rhs;
		}

		random_access_iterator<T>& operator+=(const random_access_iterator<T>& rhs)
		{

			this->it = this->it + rhs.it;
			return *this;
		}

		random_access_iterator<T>& operator-=(const random_access_iterator<T>& rhs)
		{

			this->it = this->it - rhs.it;
			return *this;
		}

		random_access_iterator<T>& operator+=(const int & rhs) const 
		{
			this->it = this->it + rhs;
			return *this;
		}

		random_access_iterator<T>& operator-=(const int & rhs) const 
		{
			this->it = this->it - rhs;
			return *this;
		}

//friend for non member fonctions
		friend random_access_iterator<T>& operator+(const int & lhs, const random_access_iterator<T>& rhs);
		friend random_access_iterator<T>& operator-(const int & lhs, const random_access_iterator<T>& rhs);
		friend void advance (InputIterator& it, Distance n);
		friend typename iterator_traits<InputIterator>::difference_type distance (InputIterator first, InputIterator last);
	};

//NON MEMBER FUNCTIONS
	template <class T>
	random_access_iterator<T>& operator+(const int & lhs, const random_access_iterator<T>& rhs)
	{
		return lhs + rhs.it;
	}


	template <class T>
	random_access_iterator<T>& operator-(const int & lhs, const random_access_iterator<T>& rhs)
	{
		return lhs - rhs.it;
	}

	template <class InputIterator, class Distance>
	void advance (InputIterator& it, Distance n)
	{
		it.it = it.it + n;
	}

	template<class InputIterator>
	typename iterator_traits<InputIterator>::difference_type distance (InputIterator first, InputIterator last)
	{
		distance d;

		d = last.it - first.it;
		if (d < 0)
			d = d * -1;
		return d;
	}
}

#endif

/*


OK

copy-constructible, copy-assignable and destructible		X b(a);
															b = a;

Can be incremented			++a
							a++

Supports equality/inequality comparisons	a == b
											a != b

Can be dereferenced as an rvalue	*a
									a->m

Supports inequality comparisons (<, >, <= and >=) between iterators	a < b
																	a > b
																	a <= b
																	a >= b

default-constructible	X a;
						X()

	Can be decremented	--a
						a--
						*a--

Supports offset dereference operator ([])		a[n]

	Supports arithmetic operators + and -	a + n
											n + a
											a - n
											a - b

Supports compound assignment operations += and -=	a += n
													a -= n

TODO

Output	Can be dereferenced as an lvalue
(only for mutable iterator types)			*a = t
											*a++ = t


Multi-pass: neither dereferencing nor incrementing affects dereferenceability	{ b=a; *a++; *b; }

											

*/