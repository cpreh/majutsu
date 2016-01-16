//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_PLACE_AND_UPDATE_HPP_INCLUDED
#define MAJUTSU_RAW_PLACE_AND_UPDATE_HPP_INCLUDED

#include <majutsu/raw/element_type.hpp>
#include <majutsu/raw/needed_size.hpp>
#include <majutsu/raw/place.hpp>
#include <majutsu/raw/pointer.hpp>


namespace majutsu
{
namespace raw
{

template<
	typename Type
>
inline
void
place_and_update(
	majutsu::raw::element_type<
		Type
	> const &_value,
	majutsu::raw::pointer &_data
)
{
	majutsu::raw::place<
		Type
	>(
		_value,
		_data
	);

	_data +=
		majutsu::raw::needed_size<
			Type
		>(
			_value
		);
}

}
}

#endif
