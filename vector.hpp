/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:21:47 by kzennoun          #+#    #+#             */
/*   Updated: 2022/04/13 17:16:12 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <stdexcept>
#include "iterator.hpp"

namespace ft 
{

	//template < class T, class Alloc = std::allocator<T> > class vector; // generic template

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
		typedef ft::__generic_iterator<T>							iterator;
		typedef ft::__generic_iterator<const T>						const_iterator;	
		// typedef	ft::__generic_reverse_iterator<iterator>			reverse_iterator;
		// typedef	ft::__generic_reverse_iterator<const_iterator>		const_reverse_iterator;
		

		// (1) Default constructor. Constructs an empty container with a default-constructed allocator.
		vector()
		: _capacity(0), _size(0), _ptr(NULL)//, _allocator(allocator_type)
		{
		}
		
		// (2) Constructs an empty container with the given allocator alloc.
		explicit vector( const Allocator& alloc )
		: _capacity(0), _size(0), _ptr(NULL), _allocator(alloc)
		{

		}
		
		// (3) Constructs the container with count cop`ies of elements with value value.
		// explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator())
		// : _allocator(alloc), _size(count), _capacity(count)
		// {
		// 	//try catch
		// 	//allocate quel taille ? quel capacity ?
		// 	_ptr = _allocator.allocate(sizeof(T) * count);
		// }
		
		// (5) Constructs the container with the contents of the range [first, last).
		template< class InputIt >
		vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() )
		: _allocator(alloc)
		{
			size_t	diff = last - first;
			_capacity = diff;
			_size = diff;
			_ptr = _allocator.allocate(_capacity);
		}
		
		// (6) Copy constructor. Constructs the container with the copy of the contents of other.
		// vector( const vector& other )
		// {

		// }
		
		~vector()
		{
			//free stuff or whatever
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


		//rbegin
		//rend

		size_type size() const { return _size; }

		size_type max_size() const
		{
			return _allocator.max_size();
		}

		//resize
		void resize (size_type n, value_type val = value_type())
		{

		}

/*
 Resizes the container so that it contains n elements.

If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).

If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n. If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.

If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.

Notice that this function changes the actual content of the container by inserting or erasing elements from it.
*/

		size_type capacity() const { return _capacity; }
		bool empty() const { return _size == 0 ? true : false; };

		//reserve

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
			if (index > _size)
				throw std::out_of_range("out of range");
			return *(begin() + index);
		}

		const_reference at(size_type index) const
		{
			if (index > _size)
				throw std::out_of_range("out of range");
			return *(begin() + index);
		}


		//front

		//back

		// 	- [x] `assign`: Assign vector content
		// - [x] `push_back`: Add element at the end
		// - [x] `pop_back`: Delete last element
		// - [x] `insert`: Insert elements
		// - [x] `erase`: Erase elements
		// - [x] `swap`: Swap content
		// - [x] `clear`: Clear content

		// #### Allocator:
		// - [x] `get_allocator`: Get allocator	

		// ## Non-member function overloads
		// - [x] `relational operators`: Relational operators for vector
		// - [x] `swap`: Exchange contents of vectors

		protected:
		private:

		size_type		_capacity;
		size_type		_size;
		allocator_type	_allocator;
		pointer			_ptr;

		
		// iterator		_iterator;
		// iterator		_begin;
		//allocator ?



	};

}

#endif

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