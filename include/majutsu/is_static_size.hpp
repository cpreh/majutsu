#ifndef MAJUTSU_IS_STATIC_SIZE_HPP_INCLUDED
#define MAJUTSU_IS_STATIC_SIZE_HPP_INCLUDED

#include <majutsu/static_size.hpp>
#include <majutsu/detail/static_size_base.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/not.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Type
>
struct is_static_size
:
boost::mpl::not_<
	std::is_base_of<
		majutsu::detail::static_size_base,
		majutsu::static_size<
			Type
		>
	>
>
{
};

FCPPT_PP_POP_WARNING

}

#endif
