//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_UNWRAP_ROLE_HPP_INCLUDED
#define MAJUTSU_UNWRAP_ROLE_HPP_INCLUDED

#include <majutsu/role_fwd.hpp>


namespace majutsu
{

template<
	typename Type
>
struct unwrap_role;

template<
	typename Type,
	typename Tag
>
struct unwrap_role<
	majutsu::role<
		Type,
		Tag
	>
>
{
	typedef Tag type;
};

}

#endif
