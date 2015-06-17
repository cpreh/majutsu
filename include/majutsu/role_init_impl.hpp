//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_ROLE_INIT_IMPL_HPP_INCLUDED
#define MAJUTSU_ROLE_INIT_IMPL_HPP_INCLUDED

#include <majutsu/role_init_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Tag,
	typename Value
>
majutsu::role_init<
	Tag,
	Value
>::role_init(
	Value _value
)
:
	value_(
		std::forward<
			Value
		>(
			_value
		)
	)
{
}

template<
	typename Tag,
	typename Value
>
Value
majutsu::role_init<
	Tag,
	Value
>::value()
{
	return
		std::forward<
			Value
		>(
			value_
		);
}

#endif
