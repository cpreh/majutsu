//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_MAKE_HPP_INCLUDED
#define MAJUTSU_MAKE_HPP_INCLUDED

#include <majutsu/const_raw_pointer.hpp>
#include <majutsu/dispatch_value.hpp>


namespace majutsu
{

template<
	typename Type
>
typename Type::type
make(
	majutsu::const_raw_pointer const _data
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

#endif
