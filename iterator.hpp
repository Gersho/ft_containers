/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:40:00 by kzennoun          #+#    #+#             */
/*   Updated: 2022/04/06 12:56:49 by kzennoun         ###   ########lyon.fr   */
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
		typename	ft::random_access_iterator_tag	iterator_category
	};

	template< class T >
	struct iterator_traits<const T*>
	{
		typename	std::ptrdiff_t						difference_type					
		typename	T 									value_type
		typename	const T* 							pointer
		typename	const T& 							reference
		typename	ft::random_access_iterator_tag		iterator_category	
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
	class __generic_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
	{
		private:

		T *it;

		protected:
		
		public:

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
			return p==rhs.p;
		}

		bool operator !=(const __generic_iterator<T> & rhs) const
		{
			return p!=rhs.p;
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
			return p < rhs.p;
		}

		bool operator>( const __generic_iterator<T> & rhs ) const
		{
			return p > rhs.p;
		}

		bool operator<=( const __generic_iterator<T> & rhs ) const
		{
			return p <= rhs.p;
		}

		bool operator>=( const __generic_iterator<T> & rhs) const
		{
			return p >= rhs.p;
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

		__generic_iterator<T> operator-(differenc_type rhs) const 
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

		friend void advance (InputIterator& it, Distance n);
		friend typename iterator_traits<InputIterator>::difference_type distance (InputIterator first, InputIterator last);
	}; // class iterator end

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

	template <class Iterator>
	class __generic_reverse_iterator
	{
		public:

		protected:

		private:

		Iterator iter;
	};
/*
	template <class Iterator>
	class __generic_reverse_iterator
	{

		typename Iterator											iterator_type
		typename iterator_traits<Iterator>::iterator_category		iterator_category
		typename iterator_traits<Iterator>::value_type				value_type
		typename iterator_traits<Iterator>::difference_type			difference_type
		typename iterator_traits<Iterator>::pointer					pointer
		typename iterator_traits<Iterator>::reference				reference


		private:

		iterator_type *rev_it;
		iterator_type *base_it;
		
		protected:
		



		public:

		__generic_reverse_iterator()
		{
			rev_it = NULL;
			base_it = NULL;
		}

		explicit __generic_reverse_iterator (iterator_type it)
		{
			base_it = it;
			rev_it = it - 1; 
		}

	//	template <class Iter>
		__generic_reverse_iterator (const __generic_reverse_iterator<iterator_type>& src)
		{
			rev_it = src.rev_it;
			base_it = src.base_it;
		}

		iterator_type base() const
		{
			return base_it;
		}

		reference operator*() const
		{
			return *rev_it;
		}

		pointer operator->() const
		{
			return rev_it;
		}

		__generic_reverse_iterator<iterator_type>& operator+(const difference_type n) const
		{
			return __generic_reverse_iterator(base_it - n);
		}

		operator++()
		{

		}

		operator+=()
		{

		}

		operator-()
		{

		}

		operator--()
		{

		}

		operator-=()
		{

		}



		operator[]()
		{

		}

  

		protected:
		
		private:




/*
Non-member function overloads

(1)	

template <class Iterator>
  bool operator== (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs);

(2)	

template <class Iterator>
  bool operator!= (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs);

(3)	

template <class Iterator>
  bool operator<  (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs);

(4)	

template <class Iterator>
  bool operator<= (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs);

(5)	

template <class Iterator>
  bool operator>  (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs);

(6)	

template <class Iterator>
  bool operator>= (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs);

Relational operators for reverse_iterator
Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs.

Internally, the function compares directly the base iterators using the reflexively equivalent relational operator:

operator on
reverse iterators	equivalent used on
base iterators
==	==
!=	!=
< 	>
<=	>=
> 	<
>=	<=



	}
*/


} // namespace ft end

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


**********************************************
TODO
**********************************************

//iteratpr class 

Output	Can be dereferenced as an lvalue
(only for mutable iterator types)			*a = t
											*a++ = t


Multi-pass: neither dereferencing nor incrementing affects dereferenceability	{ b=a; *a++; *b; }


reverse iterator


											

*/



	// template< class Iter >
	// struct iterator_traits
	// {
	// 	typename	std::incrementable_traits<Iter>::difference_type  	difference_type
	// 	typename	void 												value_type
	// 	typename	void 												pointer
	// 	typename	void 												reference
	// 	typename	std::output_iterator_tag 							iterator_category
	// };
