//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_FUSION_RECORD_IMPL_HPP_INCLUDED
#define MAJUTSU_FUSION_RECORD_IMPL_HPP_INCLUDED

#include <majutsu/detail/all_initializers.hpp>
#include <majutsu/detail/find_role.hpp>
#include <majutsu/detail/index_of.hpp>
#include <majutsu/fusion/record_decl.hpp>
#include <majutsu/fusion/detail/expand_initlist.hpp>
#include <fcppt/no_init_fwd.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/fusion/adapted/mpl.hpp>
#include <boost/fusion/container/vector.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/vector.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>



template<
	typename Types
>
majutsu::fusion::record<
	Types
>::record()
:
	elements_()
{
	static_assert(
		boost::mpl::empty<
			all_types
		>::value,
		"record not empty"
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Types
>
majutsu::fusion::record<
	Types
>::record(
	fcppt::no_init const &
)
{
}

template<
	typename Types
>
majutsu::fusion::record<
	Types
>::record(
	fcppt::no_init &&
)
{
}

FCPPT_PP_POP_WARNING

template<
	typename Types
>
template<
	typename ...Args
>
majutsu::fusion::record<
	Types
>::record(
	Args && ..._args
)
:
	elements_(
		majutsu::fusion::detail::expand_initlist<
			tuple,
			all_types
		>(
			std::forward<
				Args
			>(
				_args
			)...
		)
	)
{
	static_assert(
		boost::mpl::size<
			all_types
		>::value
		==
		sizeof...(
			Args
		),
	 	"You have to provide the right amount of parameters"
	);

	static_assert(
		majutsu::detail::all_initializers<
			all_types,
			boost::mpl::vector<
				Args...
			>
		>::value,
		"You have to initialize every element"
	);
}

template<
	typename Types
>
majutsu::fusion::record<
	Types
>::record(
	record const &
) = default;

template<
	typename Types
>
majutsu::fusion::record<
	Types
>::record(
	record &
) = default;

template<
	typename Types
>
majutsu::fusion::record<
	Types
>::record(
	record &&
) = default;

template<
	typename Types
>
majutsu::fusion::record<
	Types
> &
majutsu::fusion::record<
	Types
>::operator=(
	record const &
) = default;

template<
	typename Types
>
majutsu::fusion::record<
	Types
> &
majutsu::fusion::record<
	Types
>::operator=(
	record &&
) = default;

template<
	typename Types
>
majutsu::fusion::record<
	Types
>::~record()
{
}

template<
	typename Types
>
template<
	typename Role
>
void
majutsu::fusion::record<
	Types
>::set(
	typename
	role_return_type<
		Role
	>::type _value
)
{
	boost::fusion::at<
		majutsu::detail::index_of<
			all_types,
			majutsu::detail::find_role<
				all_types,
				Role
			>
		>
	>(
		elements_
	) =
		_value;
}

template<
	typename Types
>
template<
	typename Role
>
typename
majutsu::fusion::record<
	Types
>:: template role_return_type<
	Role
>::type
majutsu::fusion::record<
	Types
>::get() const
{
	return
		boost::fusion::at<
			majutsu::detail::index_of<
				all_types,
				majutsu::detail::find_role<
					all_types,
					Role
				>
			>
		>(
			elements_
		);
}

template<
	typename Types
>
typename
majutsu::fusion::record<
	Types
>::tuple const &
majutsu::fusion::record<
	Types
>::impl() const
{
	return
		elements_;
}

#endif
