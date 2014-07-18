//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_MEMORY_DETAIL_INIT_RAW_MEMORY_HPP_INCLUDED
#define MAJUTSU_MEMORY_DETAIL_INIT_RAW_MEMORY_HPP_INCLUDED

#include <majutsu/role_tag_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace memory
{
namespace detail
{

template<
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
	_memory. template set<
		majutsu::role_tag<
			typename
			T::tag
		>
	>(
		_arg.value()
	);

	majutsu::memory::detail::init_raw_memory(
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
