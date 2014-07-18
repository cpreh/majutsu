//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_DETAIL_WRAPPED_TYPE_HPP_INCLUDED
#define MAJUTSU_DETAIL_WRAPPED_TYPE_HPP_INCLUDED

#include <majutsu/access_role.hpp>
#include <majutsu/role_fwd.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


namespace majutsu
{
namespace detail
{

template<
	typename Type
>
struct wrapped_type
{
	typedef Type type;
};

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Type,
	typename Tag
>
struct wrapped_type<
	majutsu::role<
		Type,
		Tag
	>
>
:
majutsu::access_role<
	majutsu::role<
		Type,
		Tag
	>
>
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
