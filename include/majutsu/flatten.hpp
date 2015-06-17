//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_FLATTEN_HPP_INCLUDED
#define MAJUTSU_FLATTEN_HPP_INCLUDED

#include <majutsu/detail/flatten.hpp>


namespace majutsu
{

template<
	typename Type
>
using
flatten
=
typename
majutsu::detail::flatten<
	Type
>::type;

}

#endif
