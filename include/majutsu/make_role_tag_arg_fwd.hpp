#ifndef MAJUTSU_MAKE_ROLE_TAG_ARG_FWD_HPP_INCLUDED
#define MAJUTSU_MAKE_ROLE_TAG_ARG_FWD_HPP_INCLUDED

#include <majutsu/role_tag_fwd.hpp>


#define MAJUTSU_MAKE_ROLE_TAG_ARG(\
	name,\
	arg\
)\
template<\
	arg\
>\
struct name ## _tag; \
\
template<\
	arg arg_name\
> \
using \
name \
= \
majutsu::role_tag<\
	name ## _tag <\
		arg_name\
	>\
> \

#endif
