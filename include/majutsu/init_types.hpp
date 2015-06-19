//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_INIT_TYPES_HPP_INCLUDED
#define MAJUTSU_INIT_TYPES_HPP_INCLUDED


namespace majutsu
{

template<
	typename Record
>
using
init_types
=
typename
Record::init_types;

}

#endif
