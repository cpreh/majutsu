//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_PLACE_HPP_INCLUDED
#define MAJUTSU_RAW_PLACE_HPP_INCLUDED

#include <majutsu/dispatch_value.hpp>
#include <majutsu/raw/element_type.hpp>
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
place(
	majutsu::raw::element_type<
		Type
	> const &_value,
	majutsu::raw::pointer const _data
)
{
	return
		place(
			majutsu::dispatch_value<
				Type
			>(),
			_value,
			_data
		);
}

}
}

#endif
