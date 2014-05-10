#ifndef MAJUTSU_DETAIL_TAG_IS_SAME_HPP_INCLUDED
#define MAJUTSU_DETAIL_TAG_IS_SAME_HPP_INCLUDED

#include <majutsu/role_init_fwd.hpp>
#include <majutsu/role_tag_fwd.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace detail
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Tag,
	typename Type
>
struct tag_is_same;

template<
	typename Tag1,
	typename Tag2,
	typename Type
>
struct tag_is_same<
	majutsu::role_tag<
		Tag1
	>,
	majutsu::role_init<
		Tag2,
		Type
	>
>
:
std::is_same<
	Tag1,
	Tag2
>
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
