//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_NEEDED_SIZE_HPP_INCLUDED
#define MAJUTSU_RAW_NEEDED_SIZE_HPP_INCLUDED

#include <majutsu/dispatch_value.hpp>
#include <majutsu/raw/element_type.hpp>
#include <majutsu/raw/is_static_size.hpp>
#include <majutsu/raw/size_type.hpp>
#include <majutsu/raw/static_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace raw
{

template<
	typename Type
>
inline
typename
boost::enable_if<
	majutsu::raw::is_static_size<
		Type
	>,
	majutsu::raw::size_type
>::type
needed_size(
	majutsu::raw::element_type<
		Type
	> const &
)
{
	return
		majutsu::raw::static_size<
			Type
		>::value;
}

template<
	typename Type
>
inline
typename
boost::disable_if<
	majutsu::raw::is_static_size<
		Type
	>,
	majutsu::raw::size_type
>::type
needed_size(
	majutsu::raw::element_type<
		Type
	> const &_value
)
{
	return
		needed_size(
			majutsu::dispatch_value<
				Type
			>(),
			_value
		);
}

}
}

#endif
