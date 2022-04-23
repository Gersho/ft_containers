/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:40:00 by kzennoun          #+#    #+#             */
/*   Updated: 2022/04/23 02:45:12 by kzennoun         ###   ########lyon.fr   */
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
		typedef typename			Iter::difference_type  	difference_type;
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

		T *_it;

		protected:
		public:

		typedef ft::random_access_iterator_tag 			iterator_category;
		typedef T         								value_type;
		typedef std::ptrdiff_t  						difference_type;
		typedef T*   									pointer;
		typedef T& 										reference;

		__generic_iterator()
			: _it(NULL)
		{
		}

		__generic_iterator(T *ptr)
			: _it(ptr)
		{
		}

		__generic_iterator(const __generic_iterator<T> & src)
			: _it(src._it)
		{
		}
		~__generic_iterator(){}

		__generic_iterator<T> & operator=(const __generic_iterator<T> & rhs)
		{
			_it = rhs._it;
			return *this;
		}

		bool operator==( const __generic_iterator<T> & rhs) const
		{
			return _it==rhs._it;
		}

		bool operator !=(const __generic_iterator<T> & rhs) const
		{
			return _it!=rhs._it;
		}

		__generic_iterator<T>&	operator++( void ) {
			this->_it++;
			return *this;
		}

		__generic_iterator<T>	operator++( int ) {
			__generic_iterator<T>	res;

			res = ++*this;
			return res;
		}

		__generic_iterator<T>&	operator--( void ) {
			this->_it--;
			return *this;
		}

		__generic_iterator<T>	operator--( int ) {
			__generic_iterator<T>	res;

			res = --*this;
			return res;
		}

		bool operator<( const __generic_iterator<T> & rhs ) const
		{
			return _it < rhs._it;
		}

		bool operator>( const __generic_iterator<T> & rhs ) const
		{
			return _it > rhs._it;
		}

		bool operator<=( const __generic_iterator<T> & rhs ) const
		{
			return _it <= rhs._it;
		}

		bool operator>=( const __generic_iterator<T> & rhs) const
		{
			return _it >= rhs._it;
		}

		reference operator*() const
		{
			return *_it;
		}

		pointer operator->() const
		{
			return _it;
		}

		reference operator[](difference_type index) const
		{
			return *(_it + index);
		}

		difference_type operator-(const __generic_iterator<T> & rhs) const 
		{
			return _it - rhs._it;
		}

		__generic_iterator<T> operator+(difference_type rhs) const 
		{
			return _it + rhs;
		}

		__generic_iterator<T> operator-(difference_type rhs) const 
		{
			return _it - rhs;
		}

		__generic_iterator<T>& operator+=(difference_type rhs) const 
		{
			_it += rhs;
			return *this;
		}

		__generic_iterator<T>& operator-=(difference_type rhs) const 
		{
			_it -= rhs;
			return *this;
		}

	//	friend void advance (__generic_iterator<T>& _it, typename iterator_traits<__generic_iterator<T> >::difference_type n);
	//	friend typename iterator_traits<__generic_iterator<T> >::difference_type distance (__generic_iterator<T> first, __generic_iterator<T> last);
	}; // class iterator end

//TODO const iterator (heritage de l'iterator non const ?)

	template <class InputIterator, class Distance>
	void advance (InputIterator& it, Distance n)
	{
		it._it = it._it + n;
	}

	template<class InputIterator>
	typename iterator_traits<InputIterator>::difference_type distance (InputIterator first, InputIterator last)
	{
		std::ptrdiff_t d;

		d = last._it - first._it;
		if (d < 0)
			d = d * -1;
		return d;
	}

	template < class Iterator >
	class reverse_iterator
	{
		public:

		typedef  Iterator											iterator_type;
		typename iterator_traits<Iterator>::iterator_category		iterator_category;
		typename iterator_traits<Iterator>::value_type				value_type;
		typedef typename iterator_traits<Iterator>::difference_type			difference_type;
		typedef typename iterator_traits<Iterator>::pointer					pointer;
		typedef typename iterator_traits<Iterator>::reference				reference;

// Member functions

// (constructor)
//     Constructs reverse_iterator object (public member function )

// default (1)	

// reverse_iterator();
// (1) default constructor
//     Constructs a reverse iterator that points to no object.
//     The internal base iterator is value-initialized.

		reverse_iterator()
		:_it(NULL)
		{
			
		};

// initialization (2)	

// explicit reverse_iterator (iterator_type it);

// (2) initalization constructor
//     Constructs a reverse iterator from some original iterator it. The behavior of the constructed object replicates the original, except that it iterates through its pointed elements in the reverse order.

		explicit reverse_iterator (iterator_type it)
		:_it(it)
		{
			
		};

// copy (3)	

// template <class Iter>
//   reverse_iterator (const reverse_iterator<Iter>& rev_it);
// (3) copy / type-cast constructor
//     Constructs a reverse iterator from some other reverse iterator. The constructed object keeps the same sense of iteration as rev_it.
		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it)
		:_it(rev_it.base())
		{
			
		};

// base
//     Return base iterator (public member function )
		iterator_type base() const{ return _it; }
// operator*
//     Dereference iterator (public member function )
		// (_it - 1) because past the end handling
		reference operator*() const
		{
			iterator_type rev_it = _it - 1;
			
			return *rev_it;
		}
// operator+
//     Addition operator (public member function )
		reverse_iterator operator+ (difference_type n) const
		{
			reverse_iterator rev_it = _it - n;
			
 			return rev_it;
		}

// operator++
//     Increment iterator position (public member function )

		reverse_iterator& operator++()
		{
			_it--;
			return *this;
		};

		reverse_iterator operator++(int)
		{
			reverse_iterator temp = *this;
			++(*this);
			return temp;
		}
// operator+=
//     Advance iterator (public member function )
		reverse_iterator& operator+= (difference_type n)
		{
			_it = _it - n;
			return *this;
		};

// operator-
//     Subtraction operator (public member function )
		reverse_iterator operator- (difference_type n) const
		{
			reverse_iterator rev_it = _it + n;
			
 			return rev_it;
		}
// operator--
//     Decrease iterator position (public member function )
		reverse_iterator& operator--()
		{
			_it++;
			return *this;
		};

		reverse_iterator operator--(int)
		{
			reverse_iterator temp = *this;
			--(*this);
			return temp;
		}

// operator-=
//     Retrocede iterator (public member function )
		reverse_iterator& operator-= (difference_type n)
		{
			_it = _it + n;
			return *this;
		};
// operator->
//     Dereference iterator (public member function )
		pointer operator->() const
		{
			return &(operator*());
		}

// operator[]
//     Dereference iterator with offset (public member function )
		reference operator[] (difference_type n) const 
		{
			return *(_it - 1 - n);
		}

		protected:
		private:

		iterator_type _it;

	}; //fin reverse_iterator

// Non-member function overloads

// relational operators
//     Relational operators for reverse_iterator (function template )

	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

// operator+
//     Addition operator (function template )
	template <class Iterator>
	reverse_iterator<Iterator> operator+ (
	typename reverse_iterator<Iterator>::difference_type n,
	const reverse_iterator<Iterator>& rev_it)
	{
		return rev_it + n;
	}
// operator-
//     Subtraction operator (function template )

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (
	const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() - rhs.base();
	}

} // namespace ft end

#endif
