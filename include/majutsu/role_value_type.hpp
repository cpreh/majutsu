//          Copyright Carl Philipp Reh 2014 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_ROLE_VALUE_TYPE_HPP_INCLUDED
#define MAJUTSU_ROLE_VALUE_TYPE_HPP_INCLUDED

#include <majutsu/role_to_type.hpp>
#include <majutsu/detail/find_role_deref.hpp>


namespace majutsu
{

template<
	typename Record,
	typename Role
>
using role_value_type
=
majutsu::role_to_type<
	majutsu::detail::find_role_deref<
		typename
		Record::all_types,
		Role
	>
>;

}

#endif
