//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_MAKE_GENERIC_HPP_INCLUDED
#define MAJUTSU_RAW_MAKE_GENERIC_HPP_INCLUDED

#include <majutsu/dispatch_value.hpp>
#include <majutsu/raw/stream/reference.hpp>
#include <majutsu/raw/stream/result.hpp>


namespace majutsu
{
namespace raw
{

template<
	typename Stream,
	typename Type
>
inline
majutsu::raw::stream::result<
	Stream,
	Type
>
make_generic(
	majutsu::raw::stream::reference<
		Stream
	> _stream
)
{
	return
		make_generic(
			majutsu::dispatch_value<
				Type
			>(),
			majutsu::dispatch_value<
				Stream
			>(),
			_stream
		);
}

}
}

#endif
