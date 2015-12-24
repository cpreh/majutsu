//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_RECORD_IMPL_HPP_INCLUDED
#define MAJUTSU_RAW_RECORD_IMPL_HPP_INCLUDED

#include <majutsu/access_role.hpp>
#include <majutsu/detail/all_initializers.hpp>
#include <majutsu/detail/find_role.hpp>
#include <majutsu/detail/index_of.hpp>
#include <majutsu/detail/make_iterators.hpp>
#include <majutsu/detail/wrapped_type.hpp>
#include <majutsu/raw/make.hpp>
#include <majutsu/raw/needed_size.hpp>
#include <majutsu/raw/place.hpp>
#include <majutsu/raw/record_decl.hpp>
#include <majutsu/raw/size_type.hpp>
#include <majutsu/raw/detail/init.hpp>
#include <majutsu/raw/detail/init_constants.hpp>
#include <majutsu/raw/detail/init_types.hpp>
#include <majutsu/raw/detail/store_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/vector.hpp>
#include <algorithm>
#include <numeric>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Types
>
majutsu::raw::record<
	Types
>::record()
:
	store_(),
	sizes_()
{
	static_assert(
		boost::mpl::empty<
			majutsu::raw::detail::init_types<
				all_types
			>
		>::value,
		"record not empty"
	);

	this->init();
}

template<
	typename Types
>
template<
	typename... Args
>
majutsu::raw::record<
	Types
>::record(
	Args && ..._args
)
:
	store_(),
	sizes_()
{
	static_assert(
		boost::mpl::size<
			majutsu::raw::detail::init_types<
				all_types
			>
		>::value
		==
		sizeof...(
			Args
		),
	 	"You have to provide the right amount of parameters"
	);

	static_assert(
		majutsu::detail::all_initializers<
			majutsu::raw::detail::init_types<
				all_types
			>,
			boost::mpl::vector<
				Args...
			>
		>::value,
		"You have to initialize every element"
	);

	this->init();

	majutsu::raw::detail::init(
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
majutsu::raw::record<
	Types
>::record(
	record const &
) = default;

template<
	typename Types
>
majutsu::raw::record<
	Types
>::record(
	record &
) = default;

template<
	typename Types
>
majutsu::raw::record<
	Types
>::record(
	record &&
) = default;

template<
	typename Types
>
majutsu::raw::record<
	Types
> &
majutsu::raw::record<
	Types
>::operator=(
	record const &
) = default;

template<
	typename Types
>
majutsu::raw::record<
	Types
> &
majutsu::raw::record<
	Types
>::operator=(
	record &&
) = default;

template<
	typename Types
>
majutsu::raw::record<
	Types
>::~record()
{
}

template<
	typename Types
>
template<
	typename Role
>
void
majutsu::raw::record<
	Types
>::set(
	typename
	role_return_type<
		Role
	>::type const &_value
)
{
	this->set_internal<
		majutsu::detail::find_role<
			all_types,
			Role
		>
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
typename
majutsu::raw::record<
	Types
>:: template role_return_type<
	Role
>::type
majutsu::raw::record<
	Types
>::get() const
{
	typedef
	majutsu::detail::find_role<
		all_types,
		Role
	>
	role_iter;

	typedef
	typename
	boost::mpl::deref<
		role_iter
	>::type
	found_role;

	typedef
	majutsu::access_role<
		found_role
	>
	elem;

	majutsu::raw::size_type const index(
		majutsu::detail::index_of<
			all_types,
			role_iter
		>::value
	);

	return
		majutsu::raw::make<
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
majutsu::raw::record<
	Types
>::pointer
majutsu::raw::record<
	Types
>::data()
{
	return
		store_.data();
}

template<
	typename Types
>
typename
majutsu::raw::record<
	Types
>::const_pointer
majutsu::raw::record<
	Types
>::data() const
{
	return
		store_.data();
}

template<
	typename Types
>
majutsu::raw::size_type
majutsu::raw::record<
	Types
>::size() const
{
	return
		store_.size();
}

template<
	typename Types
>
void
majutsu::raw::record<
	Types
>::init()
{
	// TODO: Initialize this directly!
	std::fill(
		sizes_.begin(),
		sizes_.end(),
		0
	);

	boost::mpl::for_each<
		typename majutsu::detail::make_iterators<
			all_types
		>::type
	>(
		majutsu::raw::detail::init_constants<
			majutsu::raw::record<
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
majutsu::raw::record<
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

	majutsu::raw::size_type const index(
		majutsu::detail::index_of<
			all_types,
			Iterator
		>::value
	);

	majutsu::raw::size_type const needed_size(
		majutsu::raw::needed_size<
			element
		>(
			_value
		)
	);

	majutsu::raw::size_type const offset(
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

	majutsu::raw::size_type const cur_size(
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

	majutsu::raw::place<
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
