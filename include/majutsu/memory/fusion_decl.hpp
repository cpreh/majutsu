//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_MEMORY_FUSION_DECL_HPP_INCLUDED
#define MAJUTSU_MEMORY_FUSION_DECL_HPP_INCLUDED

#include <majutsu/flatten.hpp>
#include <majutsu//role_return_type.hpp>
#include <majutsu/memory/fusion_fwd.hpp>
#include <fcppt/mpl/inner.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/fusion/container/vector.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/transform.hpp>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace memory
{

template<
	typename Type
>
class fusion
{
public:
	typedef
	typename
	majutsu::flatten<
		Type
	>::type
	types; // TODO

	// use transform instead of transform_view for now
	// otherwise VC++ 2010 SP1 breaks
	typedef typename boost::fusion::result_of::as_vector<
		typename boost::mpl::transform<
		//boost::mpl::transform_view<
			types,
			fcppt::mpl::inner<
				boost::mpl::_1
			>
		>::type
	>::type tuple;

	fusion();

	template<
		typename ...Args
	>
	explicit
	fusion(
		Args && ..._args
	);

	fusion(
		fusion const &
	);

	fusion(
		fusion &
	);

	fusion(
		fusion &&
	);

	fusion &
	operator=(
		fusion const &
	);

	fusion &
	operator=(
		fusion &&
	);

	~fusion();

	template<
		typename Role
	>
	void
	set(
		typename
		majutsu::role_return_type<
			types,
			Role
		>::type const &
	);

	template<
		typename Role
	>
	typename
	majutsu::role_return_type<
		types,
		Role
	>::type
	get() const;

	template<
		typename Iterator,
		typename Value
	>
	void
	set_internal(
		Value const &
	);

	tuple const &
	impl() const;
private:
	tuple elements_;
};

}
}

#endif
