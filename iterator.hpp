/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:40:00 by kzennoun          #+#    #+#             */
/*   Updated: 2022/08/24 21:57:02 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITERATOR_HPP
# define ITERATOR_HPP


# include <cstddef>
# include "Tree.hpp"


namespace ft
{
	struct random_access_iterator_tag {};
	struct bidirectional_iterator_tag {};

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

	template < class T >
	class __generic_iterator
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

		template <class U>
		__generic_iterator(const __generic_iterator<U> & src)
			: _it(src._get_ptr())
		{
		}

		~__generic_iterator(){}

		const T& base() const{ return *_it; }

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
			return &(operator*());
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

		T* _get_ptr() const{ return _it; }
	}; // class iterator end

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
		typedef typename iterator_traits<Iterator>::iterator_category		iterator_category;
		typedef typename iterator_traits<Iterator>::value_type				value_type;
		typedef typename iterator_traits<Iterator>::difference_type			difference_type;
		typedef typename iterator_traits<Iterator>::pointer					pointer;
		typedef typename iterator_traits<Iterator>::reference				reference;

		reverse_iterator()
		:_it(NULL)
		{	
		};

		explicit reverse_iterator (iterator_type it)
		:_it(it)
		{
		};

		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it)
		:_it(rev_it.base())
		{
			
		};

		iterator_type base() const{ return _it; }

		reference operator*() const
		{
			iterator_type rev_it = _it;
			return *(--rev_it);
		}

		reverse_iterator operator+ (difference_type n) const
		{
			reverse_iterator rev_it = _it - n;
			
 			return rev_it;
		}

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

		reverse_iterator& operator+= (difference_type n)
		{
			_it = _it - n;
			return *this;
		};

		reverse_iterator operator- (difference_type n) const
		{
			reverse_iterator rev_it = _it + n;
			
 			return rev_it;
		}

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

		reverse_iterator& operator-= (difference_type n)
		{
			_it = _it + n;
			return *this;
		};

		pointer operator->() const
		{
			return &(operator*());
		}

		reference operator[] (difference_type n) const 
		{
			return *(_it - 1 - n);
		}

		protected:
		private:

		iterator_type _it;
	}; //fin reverse_iterator

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

	template <class Iterator>
	reverse_iterator<Iterator> operator+ (
	typename reverse_iterator<Iterator>::difference_type n,
	const reverse_iterator<Iterator>& rev_it)
	{
		return rev_it + n;
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (
	const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() - rhs.base();
	}

	template <class T>
	struct node
	{
		struct node<T> *left;
		struct node<T> *right;
		struct node<T> *parent;
		int height;
		T *data;
		bool before_first;
		bool after_last;

		node():
		left(NULL),
		right(NULL),
		parent(NULL),
		height(1),
		data(NULL),
		before_first(false),
		after_last(false)
		{}

		~node(){}
	};

	template < class T, class Treebase >
	class  __tree_iterator
	{

		private:

		struct node<T> *_it;
		Treebase *_tree;

		protected:
		public:

		typedef ft::bidirectional_iterator_tag 			iterator_category;
		typedef T       								value_type;
		typedef T*   									pointer;
		typedef T& 										reference;
		typedef std::ptrdiff_t  						difference_type;
		typedef __tree_iterator<T , Treebase>				iterator;

		__tree_iterator()
			: _it(NULL)
		{
		}

		__tree_iterator(node<T> *ptr, Treebase *tree)
			: _it(ptr), _tree(tree)
		{
		}

		template <class U, class V>
		__tree_iterator(const __tree_iterator<U, V> & src)
		{
			*this = src;
		}

		~__tree_iterator(){}



		struct node<T> *get_it() const{ return _it; }
		Treebase *get_tree() const { return _tree; }

		iterator& operator=( iterator const & rhs )
		{
			_it = rhs._it;
			_tree = rhs._tree;
			return *this;
		}

		bool operator==( iterator & rhs) const
		{
			return (get_it() == rhs.get_it());
		}

		bool operator !=(iterator & rhs) const
		{
			return _it!=rhs._it;
		}

		reference operator*() const
		{
			return *(_it->data);

		}

		pointer operator->() const
		{
			return &(operator*());
		}

		iterator &operator++ ()
		{
			node<T> *tmp;

			if (_it == NULL)
			{
				_it = _tree->get_root();
				if (_it == NULL)
					return *this;

				while (_it->left != NULL)
					_it = _it->left;
			}
			else
			{	
				if(this->_it->before_first)
				{
					tmp = _tree->get_root();
					if(!tmp)
					{
						this->_it =  NULL;
						return *this;
					}
					while(tmp->left != NULL)
						tmp = tmp->left;
					this->_it = tmp;
				}
				else if(this->_it->after_last)
				{
					this->_it =  NULL;
					return *this;
				}		
				else if (_it->right != NULL)
				{
					_it = _it->right;
					while (_it->left != NULL)
						_it = _it->left;
				}
				else
				{
					tmp = _it->parent;
					while (tmp != NULL && _it == tmp->right)
					{
						_it = tmp;
						tmp = tmp->parent;
					}
					_it = tmp;
					if(!_it)
					{
						this->_it = _tree->get_after_last();
					}
				}
			}
			
			return *this;
		}

		iterator operator++( int )
		{
			iterator tmp = *this;
			++( *this );
			return tmp;
		}

		iterator &operator-- ()
		{

			struct node<T> *tmp;

			if (this->_it == NULL)
			{
				this->_it = _tree->get_root();
				if (this->_it == NULL)
				{
					return *this;
				}
				while (this->_it->right != NULL)
					this->_it = this->_it->right;
			}
			else
			{
				if(this->_it->after_last)
				{
					tmp = _tree->get_root();
					if(!tmp)
					{
						this->_it =  NULL;
						return *this;
					}
					while(tmp->right != NULL)
						tmp = tmp->right;
					this->_it = tmp;
				}
				else if(this->_it->before_first)
				{
					this->_it =  NULL;
					return *this;
				}
				else if (this->_it->left != NULL)
				{
					this->_it = this->_it->left;
					while (this->_it->right != NULL)
						this->_it = this->_it->right;
				}
				else
				{
					tmp = this->_it->parent;
					while (tmp != NULL && this->_it == tmp->left)
					{
						this->_it = tmp;
						tmp = tmp->parent;
					}
					this->_it = tmp;
					if(!_it)
					{
						this->_it = _tree->get_before_first();
					}
				}
			}
			
				return *this;

		}

		iterator operator--( int )
		{
			iterator tmp = *this;
			--( *this );
			return tmp;
		}
	};

	template < class T, class Treebase >
	class  __const_tree_iterator
	{

		private:

		struct node<T> *_it;
		const Treebase *_tree;

		protected:
		public:

		typedef ft::bidirectional_iterator_tag 				iterator_category;
		typedef T       									value_type;
		typedef T*   										pointer;
		typedef T& 											reference;
		typedef const T*   									const_pointer;
		typedef const T& 									const_reference;
		typedef std::ptrdiff_t  							difference_type;
		typedef __tree_iterator<T , Treebase>				iterator;
		typedef __const_tree_iterator<T , Treebase>			const_iterator;

		__const_tree_iterator()
			: _it(NULL)
		{
		}

		__const_tree_iterator(node<T> *ptr,const Treebase *tree)
			: _it(ptr), _tree(tree)
		{
		}

		template <class U, class V>
		__const_tree_iterator(const __const_tree_iterator<U, V> & src)
		{
			*this = src;
		}

		template <class U, class V>
		__const_tree_iterator(const __tree_iterator<U, V> & src)
		{
			*this = src;
		}

		~__const_tree_iterator() {}

		struct node<T> *get_it() const{ return _it; }
		const Treebase *get_tree() const { return _tree; }

		const_iterator& operator=( const_iterator const & rhs )
		{
			_it = rhs.get_it();
			_tree = rhs.get_tree();
			return *this;
		}

		const_iterator& operator=( iterator const & rhs )
		{
			_it = rhs.get_it();
			_tree = rhs.get_tree();
			return *this;
		}

		bool operator==( const_iterator & rhs) const
		{
			return (get_it() == rhs.get_it());
		}

		bool operator !=(const_iterator & rhs) const
		{
			return _it!=rhs._it;
		}

		reference operator*() const
		{
			return *(_it->data);
		}

		pointer operator->() const
		{
			return &(operator*());
		}

		const_iterator &operator++ ()
		{
			node<T> *tmp;

			if (_it == NULL)
			{
				_it = _tree->get_root();
				if (_it == NULL)
					return *this;

				while (_it->left != NULL)
					_it = _it->left;
			}
			else
			{	
				if(this->_it->before_first)
				{
					tmp = _tree->get_root();
					if(!tmp)
					{
						this->_it =  NULL;
						return *this;
					}
					while(tmp->left != NULL)
						tmp = tmp->left;
					this->_it = tmp;
				}
				else if(this->_it->after_last)
				{
					this->_it =  NULL;
					return *this;
				}		
				else if (_it->right != NULL)
				{
					_it = _it->right;
					while (_it->left != NULL)
						_it = _it->left;
				}
				else
				{
					tmp = _it->parent;
					while (tmp != NULL && _it == tmp->right)
					{
						_it = tmp;
						tmp = tmp->parent;
					}
					_it = tmp;
					if(!_it)
					{
						this->_it = _tree->get_after_last();
					}
				}
			}
			
				return *this;
		}

		const_iterator operator++( int )
		{
			const_iterator tmp = *this;
			++( *this );
			return tmp;
		}

		const_iterator &operator-- ()
		{
			struct node<T> *tmp;

			if (this->_it == NULL)
			{
				this->_it = _tree->get_root();
				if (this->_it == NULL)
				{
					return *this;
				}
				while (this->_it->right != NULL)
					this->_it = this->_it->right;
			}
			else
			{
				if(this->_it->after_last)
				{
					tmp = _tree->get_root();
					if(!tmp)
					{
						this->_it =  NULL;
						return *this;
					}
					while(tmp->right != NULL)
						tmp = tmp->right;
					this->_it = tmp;
				}
				else if(this->_it->before_first)
				{
					this->_it =  NULL;
					return *this;
				}
				else if (this->_it->left != NULL)
				{
					this->_it = this->_it->left;
					while (this->_it->right != NULL)
						this->_it = this->_it->right;
				}
				else
				{
					tmp = this->_it->parent;
					while (tmp != NULL && this->_it == tmp->left)
					{
						this->_it = tmp;
						tmp = tmp->parent;
					}
					this->_it = tmp;
					if(!_it)
					{
						this->_it = _tree->get_before_first();
					}
				}
			}
			return *this;
		}

		const_iterator operator--( int )
		{
			iterator tmp = *this;
			--( *this );
			return tmp;
		}

	};

	template <class T, class Treebase>
	bool operator==( __tree_iterator<T , Treebase>  const & lhs, __tree_iterator<T , Treebase>  const & rhs )
	{
		return (lhs.get_it() == rhs.get_it());
	}

	template <class T, class Treebase>
	bool operator!=( __tree_iterator<T , Treebase>  const & lhs, __tree_iterator<T , Treebase>  const & rhs )
	{
		return (lhs.get_it() != rhs.get_it());
	}

	template <class T, class Treebase>
	bool operator==( const __const_tree_iterator<T , Treebase>  & lhs, const __const_tree_iterator<T , Treebase> & rhs )
	{
		return (lhs.get_it() == rhs.get_it());
	}

	template <class T, class Treebase>
	bool operator!=( const __const_tree_iterator<T , Treebase>  & lhs, const __const_tree_iterator<T , Treebase>  & rhs )
	{
		return (lhs.get_it() != rhs.get_it());
	}

} // namespace ft end

#endif
