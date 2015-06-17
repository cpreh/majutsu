//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_CONSTANT_HPP_INCLUDED
#define MAJUTSU_RAW_CONSTANT_HPP_INCLUDED

#include <majutsu/raw/constant_fwd.hpp>
#include <majutsu/raw/element_type.hpp>
#include <majutsu/raw/static_size.hpp>
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
	typename Type,
	typename Type::element_type Value
>
struct constant
:
Type
{
	typedef
	std::integral_constant<
		majutsu::raw::element_type<
			Type
		>,
		Value
	>
	constant_value;
};

template<
	typename Type,
	typename Type::element_type Value
>
struct static_size<
	majutsu::raw::constant<
		Type,
		Value
	>
>
:
majutsu::raw::static_size<
	Type
>
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
