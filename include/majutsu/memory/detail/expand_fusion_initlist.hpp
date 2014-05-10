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


#ifndef MAJUTSU_MEMORY_DETAIL_EXPAND_FUSION_INITLIST_HPP_INCLUDED
#define MAJUTSU_MEMORY_DETAIL_EXPAND_FUSION_INITLIST_HPP_INCLUDED

#include <majutsu/memory/detail/init_fusion_element.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/fusion/adapted/mpl.hpp>
#include <boost/fusion/algorithm/transformation/transform.hpp>
#include <boost/fusion/container/generation/make_vector.hpp>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace memory
{
namespace detail
{

template<
	typename Types,
	typename Tuple,
	typename ...Arguments
>
Tuple
expand_fusion_initlist(
	Arguments && ..._arguments
)
{
	auto fusion_arguments(
		boost::fusion::make_vector(
			std::forward<
				Arguments
			>(
				_arguments
			)...
		)
	);

	return
		boost::fusion::transform(
			Types(),
			majutsu::memory::detail::init_fusion_element<
				Types,
				decltype(
					fusion_arguments
				)
			>(
				fusion_arguments
			)
		);
}

}
}
}

#endif
