//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RECORD_IMPL_HPP_INCLUDED
#define MAJUTSU_RECORD_IMPL_HPP_INCLUDED

#include <majutsu/record_decl.hpp>
#include <majutsu/role_value_type.hpp>
#include <majutsu/role_to_tag.hpp>
#include <majutsu/detail/all_initializers.hpp>
#include <majutsu/detail/find_role.hpp>
#include <majutsu/detail/index_of.hpp>
#include <majutsu/detail/tag_is_same.hpp>
#include <fcppt/decltype_sink.hpp>
#include <fcppt/no_init_fwd.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/algorithm/vararg_map.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/fusion/adapted/mpl.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/find_if.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/vector.hpp>
#include <type_traits>
#include <tuple>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Types
>
majutsu::record<
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
majutsu::record<
	Types
>::record(
	fcppt::no_init const &
)
{
}

template<
	typename Types
>
majutsu::record<
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
majutsu::record<
	Types
>::record(
	Args && ..._args
)
:
	elements_(
		[
			&_args...
		]{
			std::tuple<
				typename
				std::decay<
					Args
				>::type...
			> arguments(
				std::move(
					_args
				)...
			);

			return
				fcppt::algorithm::vararg_map<
					all_types
				>(
					[](
						auto &&... _args_inner
					)
					{
						return
							tuple{
								std::forward<
									decltype(
										_args_inner
									)
								>(
									_args_inner
								)...
							};
					},
					[
						&arguments
					](
						auto const _tag
					)
					{
						typedef
						fcppt::tag_type<
							FCPPT_DECLTYPE_SINK(
								_tag
							)
						>
						role;

						typedef
						boost::mpl::vector<
							typename
							std::decay<
								Args
							>::type...
						>
						vector_type;

						typedef
						majutsu::detail::index_of<
							vector_type,
							typename
							boost::mpl::find_if<
								vector_type,
								majutsu::detail::tag_is_same<
									majutsu::role_to_tag<
										role
									>,
									boost::mpl::_1
								>
							>::type
						>
						index_type;

						return
							std::move(
								std::get<
									index_type::value
								>(
									arguments
								).value()
							);
					}
				);
		}()
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
majutsu::record<
	Types
>::record(
	record const &
) = default;

template<
	typename Types
>
majutsu::record<
	Types
>::record(
	record &
) = default;

template<
	typename Types
>
majutsu::record<
	Types
>::record(
	record &&
) = default;

template<
	typename Types
>
majutsu::record<
	Types
> &
majutsu::record<
	Types
>::operator=(
	record const &
) = default;

template<
	typename Types
>
majutsu::record<
	Types
> &
majutsu::record<
	Types
>::operator=(
	record &&
) = default;

template<
	typename Types
>
majutsu::record<
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
majutsu::record<
	Types
>::set(
	majutsu::role_value_type<
		this_type,
		Role
	> const &_value
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
void
majutsu::record<
	Types
>::set(
	majutsu::role_value_type<
		this_type,
		Role
	> &&_value
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
		std::move(
			_value
		);
}

template<
	typename Types
>
template<
	typename Role
>
majutsu::role_value_type<
	majutsu::record<
		Types
	>,
	Role
> const &
majutsu::record<
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
majutsu::record<
	Types
>::tuple const &
majutsu::record<
	Types
>::impl() const
{
	return
		elements_;
}

#endif
