#ifndef MAJUTSU_GET_HPP_INCLUDED
#define MAJUTSU_GET_HPP_INCLUDED

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
typename
majutsu::role_return_type<
	typename
	majutsu::class_<
		Types,
		Memory
	>::memory_type::types,
	Role
>::type
get(
	majutsu::class_<
		Types,
		Memory
	> const &_arg
)
{
	return
		_arg. template get<
			Role
		>();
}

}

#endif
