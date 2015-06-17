//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_FUNDAMENTAL_DECL_HPP_INCLUDED
#define MAJUTSU_RAW_FUNDAMENTAL_DECL_HPP_INCLUDED

#include <majutsu/raw/fundamental_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace raw
{

template<
	typename Type
>
struct fundamental
{
	typedef
	Type
	element_type;

	static_assert(
		std::is_fundamental<
			Type
		>::value,
		"T must be fundamental"
	);
};

}
}

#endif
