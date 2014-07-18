//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_FUNDAMENTAL_HPP_INCLUDED
#define MAJUTSU_FUNDAMENTAL_HPP_INCLUDED

#include <majutsu/const_raw_pointer.hpp>
#include <majutsu/dispatch_type.hpp>
#include <majutsu/fundamental_decl.hpp>
#include <majutsu/integral_size.hpp>
#include <majutsu/raw_pointer.hpp>
#include <majutsu/size_type.hpp>
#include <majutsu/static_size.hpp>
#include <majutsu/detail/copy_n.hpp>
#include <fcppt/cast/to_char_ptr.hpp>
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
struct static_size<
	majutsu::fundamental<
		T
	>
>
:
majutsu::integral_size<
	sizeof(T)
>
{
};

FCPPT_PP_POP_WARNING

template<
	typename Type
>
void
place(
	majutsu::dispatch_type<
		majutsu::fundamental<
			Type
		>
	>,
	Type const &_value,
	majutsu::raw_pointer const _memory
)
{
	majutsu::detail::copy_n(
		fcppt::cast::to_char_ptr<
			majutsu::const_raw_pointer
		>(
			&_value
		),
		majutsu::static_size<
			majutsu::fundamental<
				Type
			>
		>::value,
		_memory
	);
}

template<
	typename Type
>
Type
make(
	majutsu::dispatch_type<
		majutsu::fundamental<
			Type
		>
	>,
	majutsu::const_raw_pointer const _memory
)
{
	Type ret;

	majutsu::detail::copy_n(
		_memory,
		majutsu::static_size<
			majutsu::fundamental<
				Type
			>
		>::value,
		fcppt::cast::to_char_ptr<
			majutsu::raw_pointer
		>(
			&ret
		)
	);

	return
		ret;
}

}

#endif
