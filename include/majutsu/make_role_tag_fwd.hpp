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
