//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


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
