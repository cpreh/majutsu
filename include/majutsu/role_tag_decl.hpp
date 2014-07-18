//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_ROLE_TAG_DECL_HPP_INCLUDED
#define MAJUTSU_ROLE_TAG_DECL_HPP_INCLUDED

#include <majutsu/role_init_fwd.hpp>
#include <majutsu/role_tag_fwd.hpp>


namespace majutsu
{

template<
	typename Tag
>
struct role_tag
{
	template<
		typename Arg
	>
	majutsu::role_init<
		Tag,
		Arg
	>
	operator=(
		Arg &&
	);
};

}

#endif
