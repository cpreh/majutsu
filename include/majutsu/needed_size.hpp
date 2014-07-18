//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_NEEDED_SIZE_HPP_INCLUDED
#define MAJUTSU_NEEDED_SIZE_HPP_INCLUDED

#include <majutsu/dispatch_value.hpp>
#include <majutsu/is_static_size.hpp>
#include <majutsu/size_type.hpp>
#include <majutsu/static_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{

template<
	typename Type
>
typename
boost::enable_if<
	majutsu::is_static_size<
		Type
	>,
	majutsu::size_type
>::type
needed_size(
	typename Type::type const &
)
{
	return
		majutsu::static_size<
			Type
		>::value;
}

template<
	typename Type
>
typename
boost::disable_if<
	majutsu::is_static_size<
		Type
	>,
	majutsu::size_type
>::type
needed_size(
	typename Type::type const &_value
)
{
	return
		needed_size(
			majutsu::dispatch_value<
				Type
			>(),
			_value
		);
}

}

#endif
