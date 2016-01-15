//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_FUNDAMENTAL_HPP_INCLUDED
#define MAJUTSU_RAW_FUNDAMENTAL_HPP_INCLUDED

#include <majutsu/dispatch_type.hpp>
#include <majutsu/raw/const_pointer.hpp>
#include <majutsu/raw/fundamental_decl.hpp>
#include <majutsu/raw/integral_size.hpp>
#include <majutsu/raw/pointer.hpp>
#include <majutsu/raw/size_type.hpp>
#include <majutsu/raw/static_size.hpp>
#include <majutsu/raw/detail/copy_n.hpp>
#include <majutsu/raw/stream/read.hpp>
#include <majutsu/raw/stream/reference.hpp>
#include <majutsu/raw/stream/result.hpp>
#include <majutsu/raw/stream/return_if.hpp>
#include <fcppt/cast/to_char_ptr.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


namespace majutsu
{
namespace raw
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename T
>
struct static_size<
	majutsu::raw::fundamental<
		T
	>
>
:
majutsu::raw::integral_size<
	sizeof(T)
>
{
};

FCPPT_PP_POP_WARNING

template<
	typename Type
>
inline
void
place(
	majutsu::dispatch_type<
		majutsu::raw::fundamental<
			Type
		>
	>,
	Type const &_value,
	majutsu::raw::pointer const _memory
)
{
	majutsu::raw::detail::copy_n(
		fcppt::cast::to_char_ptr<
			majutsu::raw::const_pointer
		>(
			&_value
		),
		majutsu::raw::static_size<
			majutsu::raw::fundamental<
				Type
			>
		>::value,
		_memory
	);
}

template<
	typename Type
>
inline
Type
make(
	majutsu::dispatch_type<
		majutsu::raw::fundamental<
			Type
		>
	>,
	majutsu::raw::const_pointer const _memory
)
{
	Type ret;

	majutsu::raw::detail::copy_n(
		_memory,
		majutsu::raw::static_size<
			majutsu::raw::fundamental<
				Type
			>
		>::value,
		fcppt::cast::to_char_ptr<
			majutsu::raw::pointer
		>(
			&ret
		)
	);

	return
		ret;
}

template<
	typename Type,
	typename Stream
>
inline
majutsu::raw::stream::result<
	Stream,
	majutsu::raw::fundamental<
		Type
	>
>
make_generic(
	majutsu::dispatch_type<
		majutsu::raw::fundamental<
			Type
		>
	>,
	majutsu::dispatch_type<
		Stream
	>,
	majutsu::raw::stream::reference<
		Stream
	> _stream
)
{
	Type ret;

	majutsu::raw::stream::read<
		Stream
	>(
		_stream,
		majutsu::raw::static_size<
			majutsu::raw::fundamental<
				Type
			>
		>::value,
		fcppt::cast::to_char_ptr<
			majutsu::raw::pointer
		>(
			&ret
		)
	);

	return
		majutsu::raw::stream::return_if<
			Stream,
			majutsu::raw::fundamental<
				Type
			>
		>(
			_stream,
			ret
		);
}

}
}

#endif
