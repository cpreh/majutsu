#ifndef MAJUTSU_ROLE_INIT_IMPL_HPP_INCLUDED
#define MAJUTSU_ROLE_INIT_IMPL_HPP_INCLUDED

#include <majutsu/role_init_decl.hpp>


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
		_value
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
>::value() const
{
	return
		value_;
}

#endif
