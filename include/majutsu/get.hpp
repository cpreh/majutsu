//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_GET_HPP_INCLUDED
#define MAJUTSU_GET_HPP_INCLUDED

#include <majutsu/role_return_type.hpp>


namespace majutsu
{

template<
	typename Role,
	typename Record
>
inline
majutsu::role_return_type<
	Record,
	Role
>
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
