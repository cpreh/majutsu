#ifndef MAJUTSU_CLASS_DECL_HPP_INCLUDED
#define MAJUTSU_CLASS_DECL_HPP_INCLUDED

#include <majutsu/class_fwd.hpp>
#include <majutsu/role_return_type.hpp>
#include <fcppt/no_init_fwd.hpp>


namespace majutsu
{

template<
	typename Type,
	template<
		typename
	> class Memory
>
struct class_
{
	typedef Type types;

	typedef Memory<
		types
	> memory_type;

	class_();

	explicit
	class_(
		fcppt::no_init const &
	);

	explicit
	class_(
		fcppt::no_init &&
	);

	template<
		typename... Args
	>
	explicit
	class_(
		Args && ...
	);

	class_(
		class_ const &
	);

	class_(
		class_ &
	);

	class_(
		class_ &&
	);

	class_ &
	operator=(
		class_ const &
	);

	class_ &
	operator=(
		class_ &&
	);

	~class_();

	template<
		typename Role
	>
	void
	set(
		typename
		majutsu::role_return_type<
			typename memory_type::types,
			Role
		>::type const &
	);

	template<
		typename Role
	>
	typename
	majutsu::role_return_type<
		typename memory_type::types,
		Role
	>::type
	get() const;

	memory_type &
	memory();

	memory_type const &
	memory() const;
private:
	memory_type memory_;
};

}

#endif
