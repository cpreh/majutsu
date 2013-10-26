/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2013 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef MAJUTSU_MEMORY_DETAIL_INIT_RAW_MEMORY_HPP_INCLUDED
#define MAJUTSU_MEMORY_DETAIL_INIT_RAW_MEMORY_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace memory
{
namespace detail
{

template<
	typename TypesToInit,
	typename Memory
>
inline
void
init_raw_memory(
	Memory &
)
{
}

template<
	typename TypesToInit,
	typename Memory,
	typename T,
	typename... Args
>
inline
void
init_raw_memory(
	Memory &_memory,
	T &&_arg,
	Args && ..._args
)
{
	_memory. template set_internal<
		typename
		boost::mpl::front<
			TypesToInit
		>::type
	>(
		std::forward<
			T
		>(
			_arg
		)
	);

	majutsu::memory::detail::init_raw_memory<
		typename
		boost::mpl::pop_front<
			TypesToInit
		>::type
	>(
		_memory,
		std::forward<
			Args
		>(
			_args
		)...
	);
}

}
}
}

#endif
