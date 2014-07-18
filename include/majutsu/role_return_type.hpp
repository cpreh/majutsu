//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_ROLE_RETURN_TYPE_HPP_INCLUDED
#define MAJUTSU_ROLE_RETURN_TYPE_HPP_INCLUDED

#include <majutsu/detail/find_role.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/deref.hpp>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Elements,
	typename Role
>
struct role_return_type
:
boost::mpl::deref<
	typename majutsu::detail::find_role<
		Elements,
		Role
	>::type
>::type
{
};

FCPPT_PP_POP_WARNING

}

#endif
