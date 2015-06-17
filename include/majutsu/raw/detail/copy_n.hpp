//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_DETAIL_COPY_N_HPP_INCLUDED
#define MAJUTSU_RAW_DETAIL_COPY_N_HPP_INCLUDED

#include <majutsu/raw/const_pointer.hpp>
#include <majutsu/raw/pointer.hpp>
#include <majutsu/raw/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstring>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace raw
{
namespace detail
{

inline
void
copy_n(
	majutsu::raw::const_pointer const _src,
	majutsu::raw::size_type const _sz,
	majutsu::raw::pointer const _dest
)
{
	std::memcpy(
		_dest,
		_src,
		_sz
	);
}

}
}
}

#endif
