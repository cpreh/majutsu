#ifndef MAJUTSU_CLASS_HPP_INCLUDED
#define MAJUTSU_CLASS_HPP_INCLUDED

#include <majutsu/class_fwd.hpp>
#include <majutsu/role_return_type.hpp>
#include <majutsu/detail/check_empty_class.hpp>
#include <majutsu/memory/init_count.hpp>
#include <fcppt/no_init_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


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

	class_()
	:
		memory_()
	{
		majutsu::detail::check_empty_class<
			memory_type
		>();
	}

	explicit
	class_(
		fcppt::no_init const &
	)
	:
		memory_()
	{
	}

	explicit
	class_(
		fcppt::no_init &&
	)
	:
		memory_()
	{
	}

	template<
		typename... Args
	>
	explicit
	class_(
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

	class_(
		class_ const &_other
	)
	:
		memory_(
			_other.memory_
		)
	{
	}

	class_(
		class_ &_other
	)
	:
		memory_(
			_other.memory_
		)
	{
	}

	class_(
		class_ &&_other
	)
	:
		memory_(
			std::move(
				_other.memory_
			)
		)
	{
	}

	class_ &
	operator=(
		class_ const &_other
	)
	{
		memory_ =
			_other.memory_;

		return
			*this;
	}

	class_ &
	operator=(
		class_ &&_other
	)
	{
		memory_ =
			std::move(
				_other.memory_
			);

		return
			*this;
	}

	~class_()
	{
	}

	template<
		typename Role,
		typename T
	>
	void
	set(
		T const &_value
	)
	{
		memory_. template set<
			Role
		>(
			_value
		);
	}

	template<
		typename Role
	>
	typename
	majutsu::role_return_type<
		typename memory_type::types,
		Role
	>::type
	get() const
	{
		return
			memory_. template get<
				Role
			>();
	}

	memory_type &
	memory()
	{
		return memory_;
	}

	memory_type const &
	memory() const
	{
		return memory_;
	}
private:
	memory_type memory_;
};

}

#endif
