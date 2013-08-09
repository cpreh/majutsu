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


#ifndef MAJUTSU_DETAIL_CHECK_EMPTY_CLASS_HPP_INCLUDED
#define MAJUTSU_DETAIL_CHECK_EMPTY_CLASS_HPP_INCLUDED

#include <majutsu/memory/init_count.hpp>


namespace majutsu
{
namespace detail
{

template<
	typename MemoryType
>
void
check_empty_class()
{
	static_assert(
		majutsu::memory::init_count<
			MemoryType
		>::value
		==
		0u,
		"This constructor can only be called with an empty memory type"
	);
}

}
}

#endif
