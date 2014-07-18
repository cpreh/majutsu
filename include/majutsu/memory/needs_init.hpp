//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_MEMORY_NEEDS_INIT_HPP_INCLUDED
#define MAJUTSU_MEMORY_NEEDS_INIT_HPP_INCLUDED

#include <majutsu/is_constant.hpp>
#include <majutsu/is_role.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace memory
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Element
>
struct needs_init
:
boost::mpl::and_<
	majutsu::is_role<
		Element
	>,
	boost::mpl::not_<
		majutsu::is_constant<
			Element
		>
	>
>
{};

FCPPT_PP_POP_WARNING

}
}

#endif
