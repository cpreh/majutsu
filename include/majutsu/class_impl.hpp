#ifndef MAJUTSU_CLASS_IMPL_HPP_INCLUDED
#define MAJUTSU_CLASS_IMPL_HPP_INCLUDED

#include <majutsu/class_decl.hpp>
#include <majutsu/role_return_type.hpp>
#include <majutsu/detail/check_empty_class.hpp>
#include <majutsu/memory/init_count.hpp>
#include <fcppt/no_init_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Type,
	template<
		typename
	> class Memory
>
majutsu::class_<
	Type,
	Memory
>::class_()
:
	memory_()
{
	majutsu::detail::check_empty_class<
		memory_type
	>();
}

template<
	typename Type,
	template<
		typename
	> class Memory
>
majutsu::class_<
	Type,
	Memory
>::class_(
	fcppt::no_init const &
)
:
	memory_()
{
}

template<
	typename Type,
	template<
		typename
	> class Memory
>
majutsu::class_<
	Type,
	Memory
>::class_(
	fcppt::no_init &&
)
:
	memory_()
{
}

template<
	typename Type,
	template<
		typename
	> class Memory
>
template<
	typename... Args
>
majutsu::class_<
	Type,
	Memory
>::class_(
	Args && ..._args
)
:
	memory_(
		std::forward<
			Args
		>(
			_args
		)...
	)
{
	static_assert(
		majutsu::memory::init_count<
			memory_type
		>::value
		==
		sizeof...(
			Args
		),
	 	"You have to provide the right amount of parameters for a class_ constructor"
	);
}

template<
	typename Type,
	template<
		typename
	> class Memory
>
majutsu::class_<
	Type,
	Memory
>::class_(
	class_ const &
) = default;

template<
	typename Type,
	template<
		typename
	> class Memory
>
majutsu::class_<
	Type,
	Memory
>::class_(
	class_ &
) = default;

template<
	typename Type,
	template<
		typename
	> class Memory
>
majutsu::class_<
	Type,
	Memory
>::class_(
	class_ &&
) = default;

template<
	typename Type,
	template<
		typename
	> class Memory
>
majutsu::class_<
	Type,
	Memory
> &
majutsu::class_<
	Type,
	Memory
>::operator=(
	class_ const &
) = default;

template<
	typename Type,
	template<
		typename
	> class Memory
>
majutsu::class_<
	Type,
	Memory
> &
majutsu::class_<
	Type,
	Memory
>::operator=(
	class_ &&
) = default;

template<
	typename Type,
	template<
		typename
	> class Memory
>
majutsu::class_<
	Type,
	Memory
>::~class_()
{
}

template<
	typename Type,
	template<
		typename
	> class Memory
>
template<
	typename Role
>
void
majutsu::class_<
	Type,
	Memory
>::set(
	typename
	majutsu::role_return_type<
		typename
		memory_type::types,
		Role
	>::type const &_value
)
{
	memory_. template set<
		Role
	>(
		_value
	);
}

template<
	typename Type,
	template<
		typename
	> class Memory
>
template<
	typename Role
>
typename
majutsu::role_return_type<
	typename
	majutsu::class_<
		Type,
		Memory
	>::memory_type::types,
	Role
>::type
majutsu::class_<
	Type,
	Memory
>::get() const
{
	return
		memory_. template get<
			Role
		>();
}

template<
	typename Type,
	template<
		typename
	> class Memory
>
typename
majutsu::class_<
	Type,
	Memory
>::memory_type &
majutsu::class_<
	Type,
	Memory
>::memory()
{
	return
		memory_;
}

template<
	typename Type,
	template<
		typename
	> class Memory
>
typename
majutsu::class_<
	Type,
	Memory
>::memory_type const &
majutsu::class_<
	Type,
	Memory
>::memory() const
{
	return
		memory_;
}

#endif
