//          Copyright Carl Philipp Reh 2014 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RECORD_DECL_HPP_INCLUDED
#define MAJUTSU_RECORD_DECL_HPP_INCLUDED

#include <majutsu/record_fwd.hpp>
#include <majutsu/role_to_type_tpl.hpp>
#include <majutsu/role_value_type.hpp>
#include <fcppt/no_init_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/fusion/container/vector.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/transform_view.hpp>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{

template<
	typename Types
>
class record
{
public:
	typedef
	majutsu::record<
		Types
	>
	this_type;

	typedef
	Types
	all_types;

	typedef
	typename
	boost::fusion::result_of::as_vector<
		boost::mpl::transform_view<
			all_types,
			majutsu::role_to_type_tpl<
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
		majutsu::role_value_type<
			this_type,
			Role
		> const &
	);

	template<
		typename Role
	>
	void
	set(
		majutsu::role_value_type<
			this_type,
			Role
		> &&
	);

	template<
		typename Role
	>
	majutsu::role_value_type<
		this_type,
		Role
	> const &
	get() const;

	tuple const &
	impl() const;
private:
	tuple elements_;
};

}

#endif
