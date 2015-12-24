//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_DETAIL_MAKE_RECORD_HPP_INCLUDED
#define MAJUTSU_RAW_DETAIL_MAKE_RECORD_HPP_INCLUDED

#include <majutsu/access_role.hpp>
#include <majutsu/unwrap_role.hpp>
#include <majutsu/raw/const_pointer.hpp>
#include <majutsu/raw/needed_size.hpp>
#include <majutsu/raw/record_impl.hpp>
#include <majutsu/raw/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/next.hpp>
#include <boost/utility/enable_if.hpp>
#include <utility>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace raw
{

namespace detail
{

template<
	typename Types,
	typename Iterator,
	typename LastIterator,
	typename... Args
>
inline
typename
boost::enable_if<
	std::is_same<
		Iterator,
		LastIterator
	>,
	majutsu::raw::record<
		Types
	>
>::type
make_record(
	majutsu::raw::const_pointer,
	Args &&... _args
)
{
	return
		majutsu::raw::record<
			Types
		>(
			std::forward<
				Args
			>(
				_args
			)...
		);
}

template<
	typename Types,
	typename Iterator,
	typename LastIterator,
	typename... Args
>
inline
typename
boost::disable_if<
	std::is_same<
		Iterator,
		LastIterator
	>,
	majutsu::raw::record<
		Types
	>
>::type
make_record(
	majutsu::raw::const_pointer const _memory,
	Args &&... _args
)
{
	typedef
	typename
	boost::mpl::deref<
		Iterator
	>::type
	role;

	typedef
	majutsu::access_role<
		role
	>
	element;

	majutsu::raw::element_type<
		element
	> value(
		majutsu::raw::make<
			element
		>(
			_memory
		)
	);

	majutsu::raw::size_type const size(
		majutsu::raw::needed_size<
			element
		>(
			value
		)
	);

	return
		majutsu::raw::detail::make_record<
			Types,
			typename
			boost::mpl::next<
				Iterator
			>::type,
			LastIterator
		>(
			_memory
			+
			size,
			std::forward<
				Args
			>(
				_args
			)...,
			majutsu::unwrap_role<
				role
			>{} =
				std::move(
					value
				)
		);
}

}
}
}

#endif
