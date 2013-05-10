#ifndef MAJUTSU_STATIC_SIZE_HPP_INCLUDED
#define MAJUTSU_STATIC_SIZE_HPP_INCLUDED

#include <majutsu/detail/static_size_base.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


namespace majutsu
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename T
>
struct static_size
:
majutsu::detail::static_size_base
{
};

FCPPT_PP_POP_WARNING

}

#endif
