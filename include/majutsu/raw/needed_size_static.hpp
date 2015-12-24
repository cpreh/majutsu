//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_NEEDED_SIZE_STATIC_HPP_INCLUDED
#define MAJUTSU_RAW_NEEDED_SIZE_STATIC_HPP_INCLUDED

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
constexpr
typename
boost::enable_if<
	majutsu::raw::is_static_size<
		Type
	>,
	majutsu::raw::size_type
>::type
needed_size_static()
{
	return
		majutsu::raw::static_size<
			Type
		>::value;
}

}
}

#endif
