//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_GET_HPP_INCLUDED
#define MAJUTSU_GET_HPP_INCLUDED

#include <majutsu/role_value_type.hpp>


namespace majutsu
{

template<
	typename Role,
	typename Record
>
inline
majutsu::role_value_type<
	Record,
	Role
> const &
get(
	Record const &_arg
)
{
	return
		_arg. template get<
			Role
		>();
}

}

#endif
