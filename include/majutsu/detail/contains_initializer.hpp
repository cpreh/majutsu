//          Copyright Carl Philipp Reh 2014 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_DETAIL_CONTAINS_INITIALIZER_HPP_INCLUDED
#define MAJUTSU_DETAIL_CONTAINS_INITIALIZER_HPP_INCLUDED

#include <majutsu/role_to_tag.hpp>
#include <majutsu/detail/tag_is_same.hpp>
#include <fcppt/mpl/contains_if.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/placeholders.hpp>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace detail
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Args,
	typename Element
>
struct contains_initializer
:
fcppt::mpl::contains_if<
	Args,
	majutsu::detail::tag_is_same<
		majutsu::role_to_tag<
			Element
		>,
		boost::mpl::_1
	>
>
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
