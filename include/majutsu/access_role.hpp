//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_ACCESS_ROLE_HPP_INCLUDED
#define MAJUTSU_ACCESS_ROLE_HPP_INCLUDED

#include <majutsu/access_role_tpl.hpp>


namespace majutsu
{

template<
	typename Type
>
using
access_role
=
typename
majutsu::access_role_tpl<
	Type
>::type;

}

#endif
