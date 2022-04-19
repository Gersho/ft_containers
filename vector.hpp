/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:21:47 by kzennoun          #+#    #+#             */
/*   Updated: 2022/04/19 21:28:20 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <stdexcept>
#include <iostream>
#include "iterator.hpp"

namespace ft 
{

	// enlever _destroy_all() et remplacer par clear()


	template < class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:

		typedef	T													value_type;
		typedef	Allocator											allocator_type;
		typedef	std::size_t											size_type;
		typedef	std::ptrdiff_t										difference_type;
		typedef	value_type&											reference;
		typedef	const value_type&									const_reference;
	 	typedef typename allocator_type::pointer					pointer;
		typedef typename allocator_type::const_pointer 				const_pointer;
		typedef ft::__generic_iterator<value_type>					iterator;
		typedef ft::__generic_iterator<const value_type>			const_iterator;	
		typedef	ft::reverse_iterator<iterator>						reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		

		// (1) Default constructor. Constructs an empty container with a default-constructed allocator.
		vector()
		: _capacity(0), _size(0), _allocator(allocator_type()), _ptr(NULL)
		{
		}
		
		// (2) Constructs an empty container with the given allocator alloc.
		explicit vector( const Allocator& alloc )
		: _capacity(0), _size(0), _allocator(alloc), _ptr(NULL)
		{
		}
		
		// (3) Constructs the container with count cop`ies of elements with value value.
		explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator())
		: _allocator(alloc), _size(0), _capacity(count)
		{
			if (!_try_alloc(&_ptr, count, "bad_alloc caught in explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator()): " ))
			{
				_capacity = 0;
				_ptr = NULL;
				return;
			}
			for (size_type i = 0; i < count; i++)
				push_back(value);
		}
		
		// (5) Constructs the container with the contents of the range [first, last).
		template< class InputIt >
		vector( InputIt first, InputIt last, const Allocator& alloc = Allocator())
		: _size(0), _allocator(alloc)
		{
			size_t	diff = last - first;
			_capacity = diff;
			if (diff > 0)
			{
				if (!_try_alloc(&_ptr, _capacity, "bad_alloc caught in vector( InputIt first, InputIt last, const Allocator& alloc = Allocator()): "))
				{
					_size = 0;
					_capacity = 0;
					_ptr = NULL;
					return;		
				}
				for (size_type i = 0; i < diff; i++)
				{
					_allocator.construct(&_ptr[i], *first);
					first++;
				}
			}
			else
			{
				_capacity = 0;
				_ptr = NULL;
			}
		}
		
	//	(6) Copy constructor. Constructs the container with the copy of the contents of src.
		vector( const vector& src )
		{
			_size = src._size;
			_capacity = src._capacity;
			_allocator = src._allocator;
			if (src._capacity > 0)
			{
				if (!_try_alloc(&_ptr, _capacity, "bad_alloc caught in vector( const vector& src ): "))
				{
					_size = 0;
					_capacity = 0;
					_ptr = NULL;
					return;					
				}
			}
			for (size_type i = 0; i <_size; i++)
				_allocator.construct(&_ptr[i], src._ptr[i]);
		}
		
		~vector()
		{
			_destroy_all();
			_allocator.deallocate(_ptr, _capacity);
		}

		iterator begin()
		{
			iterator it = __generic_iterator<T>(_ptr);
			return it;
		}

		const_iterator begin() const
		{
			const_iterator it = __generic_iterator<const T>(_ptr);
			return it;
		}

		iterator end()
		{
			iterator it = begin() + _size;
			return it;
		}

		const_iterator end() const
		{
			const_iterator it = begin() + _size;
			return it;
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

/*
 Resizes the container so that it contains n elements.

If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).

If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n. If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.

If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.

Notice that this function changes the actual content of the container by inserting or erasing elements from it.
*/
		void resize (size_type n, value_type val = value_type())
		{
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

			pointer tmp;
			if(!_try_alloc(&tmp, n, "bad_alloc caught in void Vector::reserve (size_type n): "))
				return;

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
				throw std::out_of_range("Vector::at out of range");
			return *(begin() + index);
		}

		const_reference at(size_type index) const
		{
			if (index >= _size)
				throw std::out_of_range("Vector::at const out of range");
			return *(begin() + index);
		}

		reference front() { return *begin(); }

		const_reference front() const{ return *begin(); }

		reference back() { return *(end() - 1); }

		const_reference back() const { return *(end() - 1); }


// 	- [x] `assign`: Assign vector content
// 		range (1)	

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last)
		{
			size_type newsize = last - first;
			_destroy_all();
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



// 	- [x] `assign`: Assign vector content
// fill (2)	

		void assign (size_type n, const value_type& val)
		{
			_destroy_all();
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


		// - [x] `push_back`: Add element at the end

		
		void push_back (const value_type& val)
		{
			if(!_upgrade_capacity())
				return;
			// std::cout << "coucou" << std::endl;
			// 	std::cout << "ft size: " << size() << std::endl;
			// 	std::cout << "ft capacity: " << capacity() << std::endl;
			// 	std::cout << "ft max_size: " << max_size() << std::endl;
			_allocator.construct(_ptr + _size, val);
		//	std::cout << "coucou2" << std::endl;
			_size++;
		}

		void	pop_back()
		{
			_allocator.destroy(&_ptr[_size - 1]);
			_size--;
		}

		//INSERT single element (1)	


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



		//INSERT fill (2)	

   		void insert (iterator position, size_type n, const value_type& val)
		{
			while (n)
			{
				insert(position, val);
				n--;
			}
		}

		//INSERT range (3)	

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert(position, *first);
				position++;
				first++;
			}
		}

		// - [x] `erase`: Erase elements
		iterator erase (iterator position)
		{
			iterator	first = position;
			iterator	last = end();

			while (first != (last - 1))
			{
				_allocator.destroy(first);
				_allocator.construct(first, *(first + 1));
				first++;
			}
			_allocator.destroy(first);	
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
		
		// - [x] `swap`: Swap content

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


		// - [x] `clear`: Clear content
		void clear()
		{
			_destroy_all();
		}

		// #### Allocator:
		// - [x] `get_allocator`: Get allocator	
		allocator_type get_allocator() const { return _allocator; };
		// ## Non-member function overloads
		// - [x] `relational operators`: Relational operators for vector
		// - [x] `swap`: Exchange contents of vectors

		protected:
		private:

		size_type		_capacity;
		size_type		_size;
		allocator_type	_allocator;
		pointer			_ptr;

		void _destroy_all()
		{
			iterator	first = begin();
			iterator	last = end();

			while (first != last)
			{
				_allocator.destroy(&first[0]);
				first++;
			}
			_size = 0;
		}
		
		bool _try_alloc(pointer *ptr,size_type count, std::string error)
		{
			try 
			{
				*ptr = _allocator.allocate(count);
			}
			catch (std::bad_alloc& ba)
			{
				std::cerr << error << ba.what() << '\n';
				*ptr = NULL;
				throw;
				return false;
			}
			return true;
		}

		bool _upgrade_capacity()
		{
			// if (_ptr)
			// 	return false;
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

		// iterator		_iterator;
		// iterator		_begin;
		//allocator ?



	}; //fin vector class 



		// ## Non-member function overloads
		// - [x] `swap`: Exchange contents of vectors

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}
		
		// - [x] `relational operators`: Relational operators for vector



	

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

	}


	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

	}


	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

	}


	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

	}


	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

	}


	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{

	}




} // fin namespace ft

#endif

/*


try catch list:

allocator allocate()


throw:

vector at() (version normal et const)

*/



/*

# Vector

## Member functions

- [x] `(constructor)`: Construct vector
- [x] `(destructor)`: Vector destructor
- [x] `operator=`: Assign content

#### Iterators:
- [x] `begin`: Return iterator to beginning
- [x] `end`: Return iterator to end
- [x] `rbegin`: Return reverse iterator to reverse beginning
- [x] `rend`: Return reverse iterator to reverse end

#### Capacity:
- [x] `size`: Return size
- [x] `max_size`: Return maximum size
- [x] `resize`: Change size
- [x] `capacity`: Return size of allocated storage capacity
- [x] `empty`: Test whether vector is empty
- [x] `reserve`: Request a change in capacity

#### Element access:
- [x] `operator[]`: Access element
- [x] `at`: Access element
- [x] `front`: Access first element
- [x] `back`: Access last element

#### Modifiers:
- [x] `assign`: Assign vector content
- [x] `push_back`: Add element at the end
- [x] `pop_back`: Delete last element
- [x] `insert`: Insert elements
- [x] `erase`: Erase elements
- [x] `swap`: Swap content
- [x] `clear`: Clear content

#### Allocator:
- [x] `get_allocator`: Get allocator

## Non-member function overloads
- [x] `relational operators`: Relational operators for vector
- [x] `swap`: Exchange contents of vectors

*/


/*
####Member types

Membertype				Definition
value_type				T
allocator_type			Allocator
size_type				Unsigned integer type (usually std::size_t)
difference_type			Signed integer type (usually std::ptrdiff_t)
reference				value_type&
const_reference			const value_type&
iterator				LegacyRandomAccessIterator to value_type
const_iterator			LegacyRandomAccessIterator to const value_type
reverse_iterator		std::reverse_iterator<iterator>
const_reverse_iterator	std::reverse_iterator<const_iterator>


####Member functions

(constructor) 
constructs the vector 

(destructor) 
destructs the vector 

operator=
assigns values to the container 

assign
assigns values to the container 

get_allocator
returns the associated allocator 


####Element access

at
access specified element with bounds checking 

operator[] 
access specified element 

front
access the first element 

back
access the last element 

data
direct access to the underlying array 

####Capacity

empty
checks whether the container is empty 

size 
returns the number of elements 

max_size
returns the maximum possible number of elements 

reserve
reserves storage 

capacity
returns the number of elements that can be held in currently allocated storage 

####Modifiers

clear
clears the contents 

insert
inserts elements 

erase
erases elements 

push_back
adds an element to the end 

pop_back
removes the last element 

resize
changes the number of elements stored 

swap
swaps the contents 

####Non-member functions

operator==
operator!=
operator<
operator<=
operator>
operator>=

std::swap(std::vector)
specializes the std::swap algorithm 
(function template)


####Iterators

begin
returns an iterator to the beginning 

end
returns an iterator to the end 


rbegin
returns a reverse iterator to the beginning 

rend
returns a reverse iterator to the end 

*/