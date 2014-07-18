//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_FUNDAMENTAL_DECL_HPP_INCLUDED
#define MAJUTSU_FUNDAMENTAL_DECL_HPP_INCLUDED

#include <majutsu/fundamental_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{

template<
	typename T
>
struct fundamental
{
	typedef T type;


	static_assert(
		std::is_fundamental<
			T
		>::value,
		"T must be fundamental"
	);
};

}

#endif
