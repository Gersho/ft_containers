/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:21:47 by kzennoun          #+#    #+#             */
/*   Updated: 2022/09/11 17:22:09 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <stdexcept>
#include "iterator.hpp"
#include "algorithm.hpp"
#include "type_traits.hpp"

// includes for linux errors
// #include <iostream>
// #include <sstream>

namespace ft 
{
	template < class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:

		typedef	T													value_type;
		typedef	Allocator											allocator_type;
		typedef	std::size_t											size_type;
		typedef	std::ptrdiff_t										difference_type;
	 	typedef typename allocator_type::pointer					pointer;
		typedef typename allocator_type::const_pointer 				const_pointer;
		typedef typename allocator_type::reference 					reference;
		typedef typename allocator_type::const_reference 			const_reference;
		typedef ft::__generic_iterator<value_type>					iterator;
		typedef ft::__generic_iterator<const value_type>			const_iterator;	
		typedef	ft::reverse_iterator<iterator>						reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>				const_reverse_iterator;

		// (1) Constructs an empty container, with no elements.
		// explicit vector( const Allocator& alloc = allocator_type())
		// : _capacity(0), _size(0), _allocator(alloc), _ptr(NULL)
		// {
		// }
		explicit vector()
		: _capacity(0), _size(0), _allocator(allocator_type()), _ptr(NULL)
		{
		}

		// (2) Constructs a container with n elements. Each element is a copy of val.
		explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator())
		: _capacity(count), _size(0), _allocator(alloc)
		{
			// if (!_try_alloc(&_ptr, count, "bad_alloc caught in explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator()): " ))
			// {
			// 	_capacity = 0;
			// 	_ptr = NULL;
			// 	return;
			// }
			_ptr = _allocator.allocate(count);
			for (size_type i = 0; i < count; i++)
				push_back(value);
		}

		// (3) Constructs a container with as many elements as the range [first,last),
		// with each element constructed from its corresponding element in that range, in the same order.
	
		template< class InputIt >
		vector(typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type first, InputIt last, const Allocator& alloc = Allocator())
		: _size(0), _allocator(alloc)
		{
			size_t	diff = last - first;
			_capacity = diff;
			if (diff > 0)
			{
				// if (!_try_alloc(&_ptr, _capacity, "bad_alloc caught in vector( InputIt first, InputIt last, const Allocator& alloc = Allocator()): "))
				// {
				// 	_size = 0;
				// 	_capacity = 0;
				// 	_ptr = NULL;
				// 	return;		
				// }

				_ptr = _allocator.allocate(_capacity);
				for (size_type i = 0; i < diff; i++)
				{
					push_back(*first);
					first++;
				}
			}
			else
			{
				_capacity = 0;
				_ptr = NULL;
			}
		}

		//	(4) Constructs a container with a copy of each of the elements in x, in the same order.
		vector( const vector& src )
		{
			if (src._ptr != NULL)
			{
				_size = src._size;
				_capacity = src._capacity;
				_allocator = src._allocator;
				if (src._capacity > 0)
				{
					// if (!_try_alloc(&_ptr, _capacity, "bad_alloc caught in vector( const vector& src ): "))
					// {
					// 	_size = 0;
					// 	_capacity = 0;
					// 	_ptr = NULL;
					// 	return;					
					// }
					_ptr = _allocator.allocate(_capacity);
				}
				for (size_type i = 0; i <_size; i++)
				{
					_allocator.construct(&_ptr[i], src._ptr[i]);
				}
			}
			else
			{
				_size = 0;
				_capacity = 0;
				_allocator = src._allocator;
				_ptr = NULL;		
			}

		}

		~vector()
		{
			clear();
			if (_capacity > 0)
				_allocator.deallocate(_ptr, _capacity);
		}

		vector& operator= (const vector& x)
		{
			clear();
			_allocator = x._allocator;

			assign(x.begin(), x.end());
			return *this;
		}

		iterator begin()
		{
			return iterator(_ptr);
		}

		const_iterator begin() const
		{
			return const_iterator(_ptr);
		}

		iterator end()
		{
			return iterator(_ptr + _size);
		}

		const_iterator end() const
		{
			return const_iterator(_ptr + _size);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin() const 
		{
			return const_reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator rend() const 
		{
			return const_reverse_iterator(begin());
		}

		size_type size() const { return _size; }
		size_type max_size() const { return _allocator.max_size(); }

		void resize (size_type n, value_type val = value_type())
		{
			if (n > max_size())
			{
				throw std::length_error("vector");
				//linux error msg
				//throw std::length_error("vector::_M_fill_insert");
			}
			if (n < _size)
			{
				for (size_type i = n; i < _size; i++)
					_allocator.destroy(&_ptr[i]);
			}
			else if (n < _capacity)
			{
				for (size_type i = _size; i < n; i++)
					_allocator.construct(&_ptr[i], val);
			}
			if (n > _capacity)
			{
				reserve(n);
				for (size_type i = _size; i < n; i++)
					_allocator.construct(&_ptr[i], val);
			}
			_size = n;
		}

		size_type capacity() const { return _capacity; }
		bool empty() const { return _size == 0 ? true : false; };

		void reserve (size_type n)
		{
			if (n <= _capacity)
				return;
			if (n > max_size())
			{
				//linux error msg
				//throw std::length_error("vector::reserve");
				throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
			}
			pointer tmp;
			// if(!_try_alloc(&tmp, n, "bad_alloc caught in void Vector::reserve (size_type n): "))
			// 	return;
			tmp = _allocator.allocate(n);
			for (size_type i = 0; i < _size; i++)
			{
				_allocator.construct(&tmp[i], _ptr[i]);
				_allocator.destroy(&_ptr[i]);
			}
			if (_ptr)
				_allocator.deallocate(_ptr, _capacity);
			_ptr = tmp;
			_capacity = n;
		}

		reference operator[](size_type index)
		{
			return *(begin() + index);
		}

		const_reference operator[] (size_type index) const
		{
			return *(begin() + index);
		}

		reference at(size_type index)
		{
			if (index >= _size)
			{
				// linux error msg
				// std::ostringstream oss;
				// oss 
				// << "vector::_M_range_check: __n (which is "
				// << index
				// << ") >= this->size() (which is "
				// << _size << ")";
				// std::string msg =  oss.str();
				// throw std::out_of_range(msg);

				throw std::out_of_range("vector");
			}
			return *(begin() + index);
		}

		const_reference at(size_type index) const
		{
			if (index >= _size)
			{
				//linux error msg
				// std::ostringstream oss;

				// oss 
				// << "vector::_M_range_check: __n (which is "
				// << index
				// << ") >= this->size() (which is "
				// << _size << ")";
				// std::string msg =  oss.str();

				// throw std::out_of_range(msg);
				throw std::out_of_range("vector");
			}
			return *(begin() + index);
		}

		reference front() { return *begin(); }

		const_reference front() const { return *begin(); }

		reference back() { return *(end() - 1); }

		const_reference back() const { return *(end() - 1); }

		template <class InputIterator>
		void assign (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
		{
			size_type newsize = last - first;

			clear();
			if	(newsize == 0)
				return;
			if (newsize > _capacity)
			{
				reserve(newsize);
				if (!_ptr)
					return;
			}
			for (size_type i = 0; i < newsize; i++)
			{
				_allocator.construct(&_ptr[i], *first);
				first++;
			}
			_size = newsize;
		}

		void assign (size_type n, const value_type& val)
		{
			clear();
			if (n > _capacity)
			{
				reserve(n);
				if (!_ptr)
					return;
			}
			for (size_type i = 0; i < n; i++)
			{
				_allocator.construct(&_ptr[i], val);
			}
			_size = n;		
		}

		void push_back (const value_type& val)
		{
			if(!_upgrade_capacity())
				return;
			_allocator.construct(_ptr + _size, val);
			_size++;
		}

		void	pop_back()
		{
			_allocator.destroy(&_ptr[_size - 1]);
			_size--;
		}

		iterator insert (iterator position, const value_type& val)
		{
			if(!_upgrade_capacity())
				return NULL;
			size_type diff = position - begin();
			for (size_type i = _size; i > diff; i--)
				_allocator.construct(&_ptr[i], _ptr[i - 1]);
			_allocator.construct(&_ptr[diff], val);
			_size++;
			return position;
		}

   		void insert (iterator position, size_type n, const value_type& val)
		{
				size_type diff = position - begin();

	 			// if ( _size + n > _capacity*2)
 				// 	reserve(_size + n);
				// else
				// {
				// 	if(!_upgrade_capacity())
				// 		return;
				// }
	 			if ( _size + n > _capacity)
 					reserve(_size + n);
					
				for (size_type i = _size + n - 1; i > diff + n; i--)
				{
					_allocator.construct(&_ptr[i], _ptr[i - n]);
					_allocator.destroy(&_ptr[i - n]);
				}
				for (size_type i = 0; i < n; i++)
				{
					_allocator.construct(&_ptr[diff + i], val);
					_size++;
				}
				return;
		}

		template <class InputIterator>
		void insert (iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
		{
			while (first != last)
			{
				insert(position, *first);
				position++;
				first++;
			}
		}

		iterator erase (iterator position)
		{
			iterator	first = position;
			iterator	last = end();

			while (first != (last - 1))
			{
				_allocator.destroy(&first[0]);
				_allocator.construct(&first[0], *(first + 1));
				first++;
			}
			_allocator.destroy(&first[0]);	
			_size--;
			return position;
		}

		iterator erase (iterator first, iterator last)
		{
			size_type diff = last - first;
			for (size_type i = 0; i < diff; i++)
			{
				erase(first);
			}
			return first;
		}

		void swap (vector& x)
		{
			size_type		tmp_capacity = _capacity;
			size_type		tmp_size = _size;
			allocator_type	tmp_allocator = _allocator;
			pointer 		tmp_ptr = _ptr;

			_capacity = x._capacity;
			_size = x._size;
			_allocator = x._allocator;
			_ptr = x._ptr;

			x._capacity = tmp_capacity;
			x._size = tmp_size;
			x._allocator = tmp_allocator;
			x._ptr = tmp_ptr;
		}

		void clear()
		{
			iterator	first = begin();
			iterator	last = end();

			while (first != last)
			{
				_allocator.destroy(&first[0]);
				//_allocator.destroy(first);
				first++;
			}
			_size = 0;
		}

		allocator_type get_allocator() const { return _allocator; };

		protected:
		private:

		size_type		_capacity;
		size_type		_size;
		allocator_type	_allocator;
		pointer			_ptr;
	
		// bool _try_alloc(pointer *ptr,size_type count, std::string error)
		// {
		// 	*ptr = _allocator.allocate(count);
		// 	return true;
		// }

		bool _upgrade_capacity()
		{
			if (_size == _capacity)
			{
				if (_capacity == 0)
					reserve(1);
				else
					reserve(_capacity * 2);	
				if (!_ptr)
					return false;
			}
			return true;
		}
	}; //end class vector

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (lhs < rhs) || (lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (lhs > rhs) || (lhs == rhs);
	}

} // end namespace ft

#endif
