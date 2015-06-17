//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_RECORD_DECL_HPP_INCLUDED
#define MAJUTSU_RAW_RECORD_DECL_HPP_INCLUDED

#include <majutsu/access_role.hpp>
#include <majutsu/flatten.hpp>
#include <majutsu/detail/find_role_deref.hpp>
#include <majutsu/raw/const_pointer.hpp>
#include <majutsu/raw/data.hpp>
#include <majutsu/raw/element_type.hpp>
#include <majutsu/raw/pointer.hpp>
#include <majutsu/raw/record_fwd.hpp>
#include <majutsu/raw/size_type.hpp>
#include <majutsu/raw/detail/store_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/size.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace raw
{

template<
	typename Types
>
class record
{
public:
	typedef
	majutsu::raw::data
	value_type;
private:
	typedef
	majutsu::flatten<
		Types
	>
	flattened_types;

	typedef
	std::array<
		majutsu::raw::size_type,
		boost::mpl::size<
			flattened_types
		>::value
	>
	size_vector;

	typedef
	majutsu::raw::detail::store<
		value_type
	>
	storage_type;
public:
	typedef
	Types
	types;

	template<
		typename Role
	>
	struct role_return_type
	{
		typedef
		majutsu::raw::element_type<
			majutsu::access_role<
				majutsu::detail::find_role_deref<
					flattened_types,
					Role
				>
			>
		>
		type;
	};

	typedef
	majutsu::raw::pointer
	pointer;

	typedef
	majutsu::raw::const_pointer
	const_pointer;

	record();

	template<
		typename... Args
	>
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
		role_return_type<
			Role
		>::type const &
	);

	template<
		typename Role
	>
	typename
	role_return_type<
		Role
	>::type
	get() const;

	pointer
	data();

	const_pointer
	data() const;

	majutsu::raw::size_type
	size() const;
private:
	void
	init();
public:
	template<
		typename Iterator,
		typename Value
	>
	void
	set_internal(
		Value const &
	);
private:
	storage_type store_;

	size_vector sizes_;
};

}
}

#endif
