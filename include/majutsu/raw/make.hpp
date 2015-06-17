//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_MAKE_HPP_INCLUDED
#define MAJUTSU_RAW_MAKE_HPP_INCLUDED

#include <majutsu/dispatch_value.hpp>
#include <majutsu/raw/const_pointer.hpp>
#include <majutsu/raw/element_type.hpp>


namespace majutsu
{
namespace raw
{

template<
	typename Type
>
inline
majutsu::raw::element_type<
	Type
>
make(
	majutsu::raw::const_pointer const _data
)
{
	return
		make(
			majutsu::dispatch_value<
				Type
			>(),
			_data
		);
}

}
}

#endif
