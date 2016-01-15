//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_STREAM_READ_HPP_INCLUDED
#define MAJUTSU_RAW_STREAM_READ_HPP_INCLUDED

#include <majutsu/raw/pointer.hpp>
#include <majutsu/raw/size_type.hpp>
#include <majutsu/raw/stream/reference.hpp>


namespace majutsu
{
namespace raw
{
namespace stream
{

template<
	typename Stream
>
inline
void
read(
	majutsu::raw::stream::reference<
		Stream
	> _stream,
	majutsu::raw::size_type const _size,
	majutsu::raw::pointer const _result
)
{
	Stream::read(
		_stream,
		_size,
		_result
	);
}

}
}
}

#endif
