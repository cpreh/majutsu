//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_CONSTANT_HPP_INCLUDED
#define MAJUTSU_CONSTANT_HPP_INCLUDED

#include <majutsu/constant_fwd.hpp>
#include <majutsu/static_size.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


namespace majutsu
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename T,
	typename T::type Value
>
struct constant
:
T
{
	static typename T::type const value = Value;
};

FCPPT_PP_POP_WARNING

template<
	typename T,
	typename T::type Value
>
typename T::type const
majutsu::constant<T, Value>::value;


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename T,
	typename T::type Value
>
struct static_size<
	majutsu::constant<
		T,
		Value
	>
>
:
majutsu::static_size<
	T
>
{
};

FCPPT_PP_POP_WARNING

}

#endif
