//          Copyright Carl Philipp Reh 2014 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_ROLE_TO_TYPE_HPP_INCLUDED
#define MAJUTSU_ROLE_TO_TYPE_HPP_INCLUDED

#include <majutsu/role_to_type_tpl.hpp>


namespace majutsu
{

template<
	typename Type
>
using
role_to_type
=
typename
majutsu::role_to_type_tpl<
	Type
>::type;

}

#endif
