#ifndef MAJUTSU_MAKE_HPP_INCLUDED
#define MAJUTSU_MAKE_HPP_INCLUDED

#include <majutsu/const_raw_pointer.hpp>
#include <majutsu/dispatch_value.hpp>


namespace majutsu
{

template<
	typename Type
>
typename Type::type
make(
	majutsu::const_raw_pointer const _data
)
{
	return
		make(
			majutsu::dispatch_value<
				Type
			>(),
			_data
		);
}

}

#endif
