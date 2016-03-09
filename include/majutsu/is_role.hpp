//          Copyright Carl Philipp Reh 2014 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_IS_ROLE_HPP_INCLUDED
#define MAJUTSU_IS_ROLE_HPP_INCLUDED

#include <majutsu/role_fwd.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename T
>
struct is_role
:
std::false_type
{
};

template<
	typename Type,
	typename Tag
>
struct is_role<
	majutsu::role<
		Type,
		Tag
	>
>
:
std::true_type
{
};

FCPPT_PP_POP_WARNING

}

#endif
