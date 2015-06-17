//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_EXTRACT_CONSTANT_HPP_INCLUDED
#define MAJUTSU_RAW_EXTRACT_CONSTANT_HPP_INCLUDED

#include <majutsu/access_role.hpp>
#include <majutsu/flatten.hpp>
#include <majutsu/detail/find_role_deref.hpp>


namespace majutsu
{
namespace raw
{

template<
	typename Types,
	typename Role
>
using extract_constant
=
typename
majutsu::access_role<
	majutsu::detail::find_role_deref<
		majutsu::flatten<
			Types
		>,
		Role
	>
>::constant_value;

}
}

#endif
