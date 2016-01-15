//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_STREAM_MEMORY_HPP_INCLUDED
#define MAJUTSU_RAW_STREAM_MEMORY_HPP_INCLUDED

#include <majutsu/raw/const_pointer.hpp>
#include <majutsu/raw/pointer.hpp>
#include <majutsu/raw/size_type.hpp>
#include <majutsu/raw/detail/copy_n.hpp>
#include <majutsu/raw/stream/memory_fwd.hpp>


namespace majutsu
{
namespace raw
{
namespace stream
{

struct memory
{
	typedef
	majutsu::raw::const_pointer &
	reference;

	static
	inline
	void
	read(
		majutsu::raw::stream::memory::reference _stream,
		majutsu::raw::size_type const _size,
		majutsu::raw::pointer const _result
	)
	{
		majutsu::raw::detail::copy_n(
			_stream,
			_size,
			_result
		);

		_stream +=
			_size;
	}

	static
	constexpr
	bool const
	can_fail = false;
};

}
}
}

#endif
