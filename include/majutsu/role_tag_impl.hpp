//          Copyright Carl Philipp Reh 2014 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_ROLE_TAG_IMPL_HPP_INCLUDED
#define MAJUTSU_ROLE_TAG_IMPL_HPP_INCLUDED

#include <majutsu/role_init_impl.hpp>
#include <majutsu/role_tag_decl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Tag
>
template<
	typename Arg
>
majutsu::role_init<
	Tag,
	typename
	std::decay<
		Arg
	>::type
>
majutsu::role_tag<
	Tag
>::operator=(
	Arg &&_arg
)
{
	return
		majutsu::role_init<
			Tag,
			typename
			std::decay<
				Arg
			>::type
		>(
			std::forward<
				Arg
			>(
				_arg
			)
		);
}

FCPPT_PP_POP_WARNING

#endif
