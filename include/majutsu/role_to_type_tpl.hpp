//          Copyright Carl Philipp Reh 2014 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_ROLE_TO_TYPE_TPL_HPP_INCLUDED
#define MAJUTSU_ROLE_TO_TYPE_TPL_HPP_INCLUDED

#include <majutsu/role_fwd.hpp>


namespace majutsu
{

template<
	typename
>
struct role_to_type_tpl;

template<
	typename Type,
	typename Tag
>
struct role_to_type_tpl<
	majutsu::role<
		Type,
		Tag
	>
>
{
	typedef
	Type
	type;
};

}

#endif
