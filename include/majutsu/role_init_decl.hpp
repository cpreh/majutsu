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
