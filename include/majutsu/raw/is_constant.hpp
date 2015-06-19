//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_IS_CONSTANT_HPP_INCLUDED
#define MAJUTSU_RAW_IS_CONSTANT_HPP_INCLUDED

#include <majutsu/raw/constant_fwd.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace raw
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Type
>
struct is_constant
:
std::false_type
{
};

template<
	typename Type,
	typename Type::element_type Value
>
struct is_constant<
	majutsu::raw::constant<
		Type,
		Value
	>
>
:
std::true_type
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
