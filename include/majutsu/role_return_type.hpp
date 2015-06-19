//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_ROLE_RETURN_TYPE_HPP_INCLUDED
#define MAJUTSU_ROLE_RETURN_TYPE_HPP_INCLUDED


namespace majutsu
{

template<
	typename Memory,
	typename Role
>
using role_return_type
=
typename
Memory:: template role_return_type<
	Role
>::type;

}

#endif
