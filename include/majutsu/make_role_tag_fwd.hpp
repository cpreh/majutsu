//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_MAKE_ROLE_TAG_FWD_HPP_INCLUDED
#define MAJUTSU_MAKE_ROLE_TAG_FWD_HPP_INCLUDED

#include <majutsu/role_tag_fwd.hpp>


#define MAJUTSU_MAKE_ROLE_TAG(\
	name\
)\
struct name ## _tag; \
\
typedef \
majutsu::role_tag<\
	name ## _tag\
> \
name

#endif
