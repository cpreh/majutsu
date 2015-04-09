//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_ROLE_INIT_DECL_HPP_INCLUDED
#define MAJUTSU_ROLE_INIT_DECL_HPP_INCLUDED

#include <majutsu/role_init_fwd.hpp>


namespace majutsu
{

template<
	typename Tag,
	typename Value
>
class role_init
{
public:
	typedef
	Tag
	tag;

	typedef
	Value
	value_type;

	explicit
	role_init(
		Value
	);

	Value
	value() const;
private:
	Value value_;
};

}

#endif
