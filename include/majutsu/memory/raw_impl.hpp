//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_MEMORY_RAW_IMPL_HPP_INCLUDED
#define MAJUTSU_MEMORY_RAW_IMPL_HPP_INCLUDED

#include <majutsu/access_role.hpp>
#include <majutsu/make.hpp>
#include <majutsu/needed_size.hpp>
#include <majutsu/place.hpp>
#include <majutsu/role_return_type.hpp>
#include <majutsu/size_type.hpp>
#include <majutsu/detail/find_role.hpp>
#include <majutsu/detail/make_iterators.hpp>
#include <majutsu/detail/wrapped_type.hpp>
#include <majutsu/memory/raw_decl.hpp>
#include <majutsu/memory/detail/index_of.hpp>
#include <majutsu/memory/detail/init_constants.hpp>
#include <majutsu/memory/detail/init_raw_memory.hpp>
#include <majutsu/memory/detail/store_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/placeholders.hpp>
#include <algorithm>
#include <numeric>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Types
>
majutsu::memory::raw<
	Types
>::raw()
:
	store_(),
	sizes_()
{
	this->init();
}

template<
	typename Types
>
template<
	typename... Args
>
majutsu::memory::raw<
	Types
>::raw(
	Args && ..._args
)
:
	store_(),
	sizes_()
{
	this->init();

	majutsu::memory::detail::init_raw_memory(
		*this,
		std::forward<
			Args
		>(
			_args
		)...
	);
}

template<
	typename Types
>
majutsu::memory::raw<
	Types
>::raw(
	raw const &
) = default;

template<
	typename Types
>
majutsu::memory::raw<
	Types
>::raw(
	raw &
) = default;

template<
	typename Types
>
majutsu::memory::raw<
	Types
>::raw(
	raw &&
) = default;

template<
	typename Types
>
majutsu::memory::raw<
	Types
> &
majutsu::memory::raw<
	Types
>::operator=(
	raw const &
) = default;

template<
	typename Types
>
majutsu::memory::raw<
	Types
> &
majutsu::memory::raw<
	Types
>::operator=(
	raw &&
) = default;

template<
	typename Types
>
majutsu::memory::raw<
	Types
>::~raw()
{
}

template<
	typename Types
>
template<
	typename Role
>
void
majutsu::memory::raw<
	Types
>::set(
	typename majutsu::role_return_type<
		flattened_types,
		Role
	>::type const &_value
)
{
	this->set_internal<
		typename majutsu::detail::find_role<
			flattened_types,
			Role
		>::type
	>(
		_value
	);
}

template<
	typename Types
>
template<
	typename Role
>
typename majutsu::role_return_type<
	typename
	majutsu::memory::raw<
		Types
	>::flattened_types,
	Role
>::type
majutsu::memory::raw<
	Types
>::get() const
{
	typedef typename majutsu::detail::find_role<
		flattened_types,
		Role
	>::type role_iter;

	typedef typename boost::mpl::deref<
		role_iter
	>::type found_role;

	typedef typename majutsu::access_role<
		found_role
	>::type elem;

	majutsu::size_type const index(
		majutsu::memory::detail::index_of<
			flattened_types,
			role_iter
		>::value
	);

	return
		majutsu::make<
			elem
		>(
			store_.data()
			+
			std::accumulate(
				sizes_.begin(),
				sizes_.begin() + index,
				0u
			)
		);
}

template<
	typename Types
>
typename
majutsu::memory::raw<
	Types
>::pointer
majutsu::memory::raw<
	Types
>::data()
{
	return store_.data();
}

template<
	typename Types
>
typename
majutsu::memory::raw<
	Types
>::const_pointer
majutsu::memory::raw<
	Types
>::data() const
{
	return store_.data();
}

template<
	typename Types
>
majutsu::size_type
majutsu::memory::raw<
	Types
>::size() const
{
	return store_.size();
}

template<
	typename Types
>
void
majutsu::memory::raw<
	Types
>::init()
{
	std::fill(
		sizes_.begin(),
		sizes_.end(),
		0
	);

	boost::mpl::for_each<
		typename majutsu::detail::make_iterators<
			flattened_types
		>::type
	>(
		majutsu::memory::detail::init_constants<
			majutsu::memory::raw<
				Types
			>
		>(
			*this
		)
	);
}

template<
	typename Types
>
template<
	typename Iterator,
	typename Value
>
void
majutsu::memory::raw<
	Types
>::set_internal(
	Value const &_value
)
{
	typedef typename boost::mpl::deref<
		Iterator
	>::type deref_elem;

	typedef typename majutsu::detail::wrapped_type<
		deref_elem
	>::type element;

	majutsu::size_type const index(
		majutsu::memory::detail::index_of<
			flattened_types,
			Iterator
		>::value
	);

	majutsu::size_type const needed_size(
		majutsu::needed_size<
			element
		>(
			_value
		)
	);

	majutsu::size_type const offset(
		std::accumulate(
			sizes_.begin(),
			sizes_.begin()
			+ index,
			0u
		)
	);

	storage_type::iterator const place(
		store_.begin() + offset
	);

	majutsu::size_type const cur_size(
		sizes_[
			index
		]
	);

	if(
		needed_size > cur_size
	)
		store_.make_space(
			place,
			needed_size - cur_size
		);
	else
		store_.erase(
			place,
			place + cur_size - needed_size
		);

	majutsu::place<
		element
	>(
		_value,
		store_.begin() + offset
	);

	sizes_[
		index
	] = needed_size;
}

#endif
