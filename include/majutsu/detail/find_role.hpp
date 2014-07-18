//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_DETAIL_FIND_ROLE_HPP_INCLUDED
#define MAJUTSU_DETAIL_FIND_ROLE_HPP_INCLUDED

#include <majutsu/unwrap_role.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/find_if.hpp>
#include <boost/mpl/placeholders.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace detail
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Elements,
	typename Role
>
struct find_role
:
boost::mpl::find_if<
	Elements,
	std::is_same<
		majutsu::unwrap_role<
			boost::mpl::_1
		>,
		Role
	>
>
{};

FCPPT_PP_POP_WARNING

}
}

#endif
