#ifndef MAJUTSU_MEMORY_RAW_HPP_INCLUDED
#define MAJUTSU_MEMORY_RAW_HPP_INCLUDED

#include <majutsu/access_role.hpp>
#include <majutsu/const_raw_pointer.hpp>
#include <majutsu/flatten.hpp>
#include <majutsu/is_constant.hpp>
#include <majutsu/is_role.hpp>
#include <majutsu/make.hpp>
#include <majutsu/needed_size.hpp>
#include <majutsu/place.hpp>
#include <majutsu/raw_data.hpp>
#include <majutsu/raw_pointer.hpp>
#include <majutsu/role_return_type.hpp>
#include <majutsu/detail/find_role.hpp>
#include <majutsu/detail/make_iterators.hpp>
#include <majutsu/detail/wrapped_type.hpp>
#include <majutsu/memory/needs_init.hpp>
#include <majutsu/memory/raw_fwd.hpp>
#include <majutsu/memory/detail/index_of.hpp>
#include <majutsu/memory/detail/init_constants.hpp>
#include <majutsu/memory/detail/init_raw_memory.hpp>
#include <majutsu/memory/detail/store.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/fusion/adapted/mpl.hpp>
#include <boost/fusion/algorithm/iteration/for_each.hpp>
#include <boost/fusion/algorithm/transformation/zip.hpp>
#include <boost/fusion/container/vector.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/remove_if.hpp>
#include <boost/mpl/size.hpp>
#include <algorithm>
#include <array>
#include <numeric>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace memory
{

template<
	typename Type
>
class raw
{
public:
	typedef majutsu::raw_data value_type;
private:
	typedef typename majutsu::flatten<
		Type
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

	raw()
	:
		store_(),
		sizes_()
	{
		this->init();
	}

	template<
		typename Arguments
	>
	raw(
		Arguments const &_arguments
	)
	:
		store_(),
		sizes_()
	{
		this->init();

		typedef typename boost::mpl::remove_if<
			typename majutsu::detail::make_iterators<
				flattened_types
			>::type,
			boost::mpl::not_<
				majutsu::memory::needs_init<
					boost::mpl::deref<
						boost::mpl::_1
					>
				>
			>
		>::type types_to_init;

		boost::fusion::for_each(
			boost::fusion::zip(
				_arguments,
				types_to_init()
			),
			majutsu::memory::detail::init_raw_memory<
				majutsu::memory::raw<
					Type
				>
			>(
				*this
			)
		);
	}

	template<
		typename Role
	>
	void
	set(
		typename majutsu::role_return_type<
			flattened_types,
			Role
		>::type const &_value
	)
	{
		this->set_internal<
			typename majutsu::detail::find_role<
				flattened_types,
				Role
			>::type
		>(
			_value
		);
	}

	template<
		typename Role
	>
	typename majutsu::role_return_type<
		flattened_types,
		Role
	>::type
	get() const
	{
		typedef typename majutsu::detail::find_role<
			flattened_types,
			Role
		>::type role_iter;

		typedef typename boost::mpl::deref<
			role_iter
		>::type found_role;

		typedef typename majutsu::access_role<
			found_role
		>::type elem;

		majutsu::size_type const index(
			majutsu::memory::detail::index_of<
				flattened_types,
				role_iter
			>::value
		);

		return
			majutsu::make<
				elem
			>(
				store_.data()
				+
				std::accumulate(
					sizes_.begin(),
					sizes_.begin() + index,
					0u
				)
			);
	}

	pointer
	data()
	{
		return store_.data();
	}

	const_pointer
	data() const
	{
		return store_.data();
	}

	majutsu::size_type
	size() const
	{
		return store_.size();
	}
private:
	void
	init()
	{
		std::fill(
			sizes_.begin(),
			sizes_.end(),
			0
		);

		boost::mpl::for_each<
			typename majutsu::detail::make_iterators<
				flattened_types
			>::type
		>(
			majutsu::memory::detail::init_constants<
				majutsu::memory::raw<
					Type
				>
			>(
				*this
			)
		);
	}

public:
	template<
		typename Iterator,
		typename Value
	>
	void
	set_internal(
		Value const &_value
	)
	{
		typedef typename boost::mpl::deref<
			Iterator
		>::type deref_elem;

		typedef typename majutsu::detail::wrapped_type<
			deref_elem
		>::type element;

		majutsu::size_type const index(
			majutsu::memory::detail::index_of<
				flattened_types,
				Iterator
			>::value
		);

		majutsu::size_type const needed_size(
			majutsu::needed_size<
				element
			>(
				_value
			)
		);

		majutsu::size_type const offset(
			std::accumulate(
				sizes_.begin(),
				sizes_.begin()
				+ index,
				0u
			)
		);

		storage_type::iterator const place(
			store_.begin() + offset
		);

		majutsu::size_type const cur_size(
			sizes_[
				index
			]
		);

		if(
			needed_size > cur_size
		)
			store_.make_space(
				place,
				needed_size - cur_size
			);
		else
			store_.erase(
				place,
				place + cur_size - needed_size
			);

		majutsu::place<
			element
		>(
			_value,
			store_.begin() + offset
		);

		sizes_[
			index
		] = needed_size;
	}
private:
	storage_type store_;

	size_vector sizes_;
};

}
}

#endif
