//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_ROLE_INIT_DECL_HPP_INCLUDED
#define MAJUTSU_ROLE_INIT_DECL_HPP_INCLUDED

#include <majutsu/role_init_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


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

	static_assert(
		!std::is_lvalue_reference<
			value_type
		>::value,
		""
	);

	explicit
	role_init(
		Value &&
	);

	explicit
	role_init(
		Value const &
	);

	Value &
	value();
private:
	Value value_;
};

}

#endif
