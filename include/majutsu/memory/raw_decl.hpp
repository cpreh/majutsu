#ifndef MAJUTSU_MEMORY_RAW_DECL_HPP_INCLUDED
#define MAJUTSU_MEMORY_RAW_DECL_HPP_INCLUDED

#include <majutsu/const_raw_pointer.hpp>
#include <majutsu/flatten.hpp>
#include <majutsu/raw_data.hpp>
#include <majutsu/raw_pointer.hpp>
#include <majutsu/role_return_type.hpp>
#include <majutsu/memory/raw_fwd.hpp>
#include <majutsu/memory/detail/store_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/size.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace memory
{

template<
	typename Types
>
class raw
{
public:
	typedef majutsu::raw_data value_type;
private:
	typedef typename majutsu::flatten<
		Types
	>::type flattened_types;

	typedef std::array<
		majutsu::size_type,
		boost::mpl::size<
			flattened_types
		>::value
	> size_vector;

	typedef majutsu::memory::detail::store<
		value_type
	> storage_type;
public:
	typedef flattened_types types; // TODO

	typedef majutsu::raw_pointer pointer;

	typedef majutsu::const_raw_pointer const_pointer;

	raw();

	template<
		typename... Args
	>
	raw(
		Args && ...
	);

	raw(
		raw const &
	);

	raw(
		raw &
	);

	raw(
		raw &&
	);

	raw &
	operator=(
		raw const &
	);

	raw &
	operator=(
		raw &&
	);

	~raw();

	template<
		typename Role
	>
	void
	set(
		typename majutsu::role_return_type<
			flattened_types,
			Role
		>::type const &
	);

	template<
		typename Role
	>
	typename majutsu::role_return_type<
		flattened_types,
		Role
	>::type
	get() const;

	pointer
	data();

	const_pointer
	data() const;

	majutsu::size_type
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
