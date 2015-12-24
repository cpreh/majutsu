//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_FUSION_RECORD_DECL_HPP_INCLUDED
#define MAJUTSU_FUSION_RECORD_DECL_HPP_INCLUDED

#include <majutsu/access_role.hpp>
#include <majutsu/access_role_tpl.hpp>
#include <majutsu/flatten.hpp>
#include <majutsu/detail/find_role_deref.hpp>
#include <majutsu/fusion/record_fwd.hpp>
#include <fcppt/no_init_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/fusion/container/vector.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/transform_view.hpp>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace fusion
{

template<
	typename Types
>
class record
{
public:
	typedef
	majutsu::flatten<
		Types
	>
	all_types;
public:
	typedef
	all_types
	init_types;

	template<
		typename Role
	>
	struct role_value_type
	{
		typedef
		majutsu::access_role<
			majutsu::detail::find_role_deref<
				all_types,
				Role
			>
		>
		type;
	};

	template<
		typename Role
	>
	struct role_return_type
	{
		typedef
		typename
		role_value_type<
			Role
		>::type const &
		type;
	};

	typedef
	typename
	boost::fusion::result_of::as_vector<
		boost::mpl::transform_view<
			all_types,
			majutsu::access_role_tpl<
				boost::mpl::_1
			>
		>
	>::type
	tuple;

	record();

	explicit
	record(
		fcppt::no_init const &
	);

	explicit
	record(
		fcppt::no_init &&
	);

	template<
		typename ...Args
	>
	explicit
	record(
		Args && ...
	);

	record(
		record const &
	);

	record(
		record &
	);

	record(
		record &&
	);

	record &
	operator=(
		record const &
	);

	record &
	operator=(
		record &&
	);

	~record();

	template<
		typename Role
	>
	void
	set(
		typename
		role_value_type<
			Role
		>::type
	);

	template<
		typename Role
	>
	typename
	role_return_type<
		Role
	>::type
	get() const;

	tuple const &
	impl() const;
private:
	tuple elements_;
};

}
}

#endif
