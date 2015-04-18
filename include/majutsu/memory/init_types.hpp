//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_MEMORY_INIT_TYPES_HPP_INCLUDED
#define MAJUTSU_MEMORY_INIT_TYPES_HPP_INCLUDED

#include <majutsu/memory/needs_init.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/filter_view.hpp>
#include <boost/mpl/placeholders.hpp>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace memory
{

template<
	typename Memory
>
using init_types
=
boost::mpl::filter_view<
	typename Memory::types,
	majutsu::memory::needs_init<
		boost::mpl::_1
	>
>;

}
}

#endif
