//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_DETAIL_INIT_HPP_INCLUDED
#define MAJUTSU_RAW_DETAIL_INIT_HPP_INCLUDED

#include <majutsu/role_return_type.hpp>
#include <majutsu/role_tag_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace raw
{
namespace detail
{

template<
	typename Memory
>
inline
void
init(
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
init(
	Memory &_memory,
	T &&_arg,
	Args && ..._args
)
{
	typedef
	majutsu::role_tag<
		typename
		T::tag
	>
	role_tag_type;

	static_assert(
		std::is_same<
			typename
			std::remove_const<
				typename
				std::remove_reference<
					typename
					T::value_type
				>::type
			>::type,
			majutsu::role_return_type<
				Memory,
				role_tag_type
			>
		>::value,
		"Invalid init type"
	);

	_memory. template set<
		majutsu::role_tag<
			typename
			T::tag
		>
	>(
		_arg.value()
	);

	majutsu::raw::detail::init(
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
