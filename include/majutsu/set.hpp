//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_SET_HPP_INCLUDED
#define MAJUTSU_SET_HPP_INCLUDED

#include <majutsu/role_value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{

template<
	typename Role,
	typename Record
>
inline
void
set(
	Record &_arg,
	majutsu::role_value_type<
		Record,
		Role
	> const &_value
)
{
	_arg. template set<
		Role
	>(
		_value
	);
}

template<
	typename Role,
	typename Record
>
inline
void
set(
	Record &_arg,
	majutsu::role_value_type<
		Record,
		Role
	> &&_value
)
{
	_arg. template set<
		Role
	>(
		std::move(
			_value
		)
	);
}

}

#endif
