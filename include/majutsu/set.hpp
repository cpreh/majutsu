#ifndef MAJUTSU_SET_HPP_INCLUDED
#define MAJUTSU_SET_HPP_INCLUDED

#include <majutsu/class.hpp>
#include <majutsu/role_return_type.hpp>


namespace majutsu
{

template<
	typename Role,
	typename Types,
	template<
		typename
	> class Memory
>
void
set(
	majutsu::class_<
		Types,
		Memory
	> &_arg,
	typename
	majutsu::role_return_type<
		typename
		majutsu::class_<
			Types,
			Memory
		>::memory_type::types,
		Role
	>::type const &_value
)
{
	_arg. template set<
		Role
	>(
		_value
	);
}

}

#endif