//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_ROLE_HPP_INCLUDED
#define MAJUTSU_ROLE_HPP_INCLUDED

#include <majutsu/is_role_tag.hpp>
#include <majutsu/role_fwd.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


namespace majutsu
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Type,
	typename Tag
>
struct role
:
Type
{
	typedef
	Type
	wrapped;

	typedef
	Tag
	tag;

	static_assert(
		majutsu::is_role_tag<
			tag
		>::value,
		"Tag of role<> must be a role_tag"
	);
};

FCPPT_PP_POP_WARNING

}

#endif
