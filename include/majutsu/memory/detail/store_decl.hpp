//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_MEMORY_DETAIL_STORE_DECL_HPP_INCLUDED
#define MAJUTSU_MEMORY_DETAIL_STORE_DECL_HPP_INCLUDED

#include <majutsu/memory/detail/store_fwd.hpp>


namespace majutsu
{
namespace memory
{
namespace detail
{

template<
	typename T,
	typename Alloc
>
class store
{
public:
	typedef T value_type;

	typedef Alloc allocator_type;

	typedef typename allocator_type::size_type size_type;

	typedef typename allocator_type::reference reference;

	typedef typename allocator_type::const_reference const_reference;

	typedef typename allocator_type::pointer pointer;

	typedef typename allocator_type::const_pointer const_pointer;

	typedef pointer iterator;

	typedef const_pointer const_iterator;

	explicit
	store(
		allocator_type const & = allocator_type()
	);

	explicit
	store(
		size_type,
		allocator_type const & = allocator_type()
	);

	store(
		store const &
	);

	store(
		store &&_other
	);

	store &
	operator=(
		store const &_other
	);

	store &
	operator=(
		store &&_other
	);

	~store();

	size_type
	size() const;

	size_type
	capacity() const;

	pointer
	data();

	const_pointer
	data() const;

	pointer
	data_end();

	const_pointer
	data_end() const;

	iterator
	begin();

	const_iterator
	begin() const;

	iterator
	end();

	const_iterator
	end() const;

	void
	make_space(
		iterator,
		size_type
	);

	void
	erase(
		iterator,
		iterator
	);
private:
	void
	deallocate();

	allocator_type alloc_;

	pointer
		data_,
		data_end_,
		cap_;
};

}
}
}

#endif
