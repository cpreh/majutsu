#ifndef MAJUTSU_MEMORY_FUSION_IMPL_HPP_INCLUDED
#define MAJUTSU_MEMORY_FUSION_IMPL_HPP_INCLUDED

#include <majutsu//role_return_type.hpp>
#include <majutsu/detail/find_role.hpp>
#include <majutsu/detail/make_iterators.hpp>
#include <majutsu/memory/fusion_decl.hpp>
#include <majutsu/memory/detail/expand_fusion_initlist.hpp>
#include <majutsu/memory/detail/index_of.hpp>
#include <majutsu/memory/detail/init_constants.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/fusion/adapted/mpl.hpp>
#include <boost/fusion/container/vector.hpp>
#include <boost/fusion/container/generation/make_vector.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/mpl/for_each.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>



template<
	typename Types
>
majutsu::memory::fusion<
	Types
>::fusion()
:
	elements_()
{
	boost::mpl::for_each<
		typename majutsu::detail::make_iterators<
			types
		>::type
	>(
		majutsu::memory::detail::init_constants<
			fusion<
				Types
			>
		>(
			*this
		)
	);
}

template<
	typename Types
>
template<
	typename ...Args
>
majutsu::memory::fusion<
	Types
>::fusion(
	Args && ..._args
)
:
	elements_(
		majutsu::memory::detail::expand_fusion_initlist<
			types,
			tuple
		>(
			boost::fusion::make_vector(
				std::forward<
					Args
				>(
					_args
				)...
			)
		)
	)
{
}

template<
	typename Types
>
majutsu::memory::fusion<
	Types
>::fusion(
	fusion const &
) = default;

template<
	typename Types
>
majutsu::memory::fusion<
	Types
>::fusion(
	fusion &
) = default;

template<
	typename Types
>
majutsu::memory::fusion<
	Types
>::fusion(
	fusion &&
) = default;

template<
	typename Types
>
majutsu::memory::fusion<
	Types
> &
majutsu::memory::fusion<
	Types
>::operator=(
	fusion const &
) = default;

template<
	typename Types
>
majutsu::memory::fusion<
	Types
> &
majutsu::memory::fusion<
	Types
>::operator=(
	fusion &&
) = default;

template<
	typename Types
>
majutsu::memory::fusion<
	Types
>::~fusion()
{
}

template<
	typename Types
>
template<
	typename Role
>
void
majutsu::memory::fusion<
	Types
>::set(
	typename majutsu::role_return_type<
		types,
		Role
	>::type const &_value
)
{
	typedef typename majutsu::detail::find_role<
		types,
		Role
	>::type found_role;

	set_internal<
		found_role
	>(
		_value
	);
}

template<
	typename Types
>
template<
	typename Role
>
typename majutsu::role_return_type<
	typename
	majutsu::memory::fusion<
		Types
	>::types,
	Role
>::type
majutsu::memory::fusion<
	Types
>::get() const
{
	typedef typename majutsu::detail::find_role<
		types,
		Role
	>::type found_role;

	return
		boost::fusion::at<
			detail::index_of<
				types,
				found_role
			>
		>(
			elements_
		);
}

template<
	typename Types
>
template<
	typename Iterator,
	typename Value
>
void
majutsu::memory::fusion<
	Types
>::set_internal(
	Value const &_value
)
{
	boost::fusion::at<
		detail::index_of<
			types,
			Iterator
		>
	>(
		elements_
	) = _value;
}

template<
	typename Types
>
typename
majutsu::memory::fusion<
	Types
>::tuple const &
majutsu::memory::fusion<
	Types
>::impl() const
{
	return
		elements_;
}

#endif
