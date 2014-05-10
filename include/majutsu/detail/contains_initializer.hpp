#ifndef MAJUTSU_DETAIL_CONTAINS_INITIALIZER_HPP_INCLUDED
#define MAJUTSU_DETAIL_CONTAINS_INITIALIZER_HPP_INCLUDED

#include <majutsu/unwrap_role.hpp>
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
		typename
		majutsu::unwrap_role<
			Element
		>::type,
		boost::mpl::_1
	>
>
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
