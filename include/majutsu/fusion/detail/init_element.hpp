//	  Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//	  http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_FUSION_DETAIL_INIT_ELEMENT_HPP_INCLUDED
#define MAJUTSU_FUSION_DETAIL_INIT_ELEMENT_HPP_INCLUDED

#include <majutsu/unwrap_role.hpp>
#include <majutsu/detail/tag_is_same.hpp>
#include <fcppt/nonassignable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/fusion/algorithm/query/find_if.hpp>
#include <boost/fusion/iterator/deref.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/find_if.hpp>
#include <boost/mpl/placeholders.hpp>
#include <utility>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace fusion
{
namespace detail
{

template<
	typename Arguments
>
class init_element
{
	FCPPT_NONASSIGNABLE(
		init_element
	);
public:
	explicit
	init_element(
		Arguments &_arguments
	)
	:
		arguments_(
			_arguments
		)
	{
	}

	template<
		typename Role
	>
	auto
	operator()(
		Role const &
	) const
	->
	typename
	boost::mpl::deref<
		typename
		boost::mpl::find_if<
			Arguments,
			majutsu::detail::tag_is_same<
				majutsu::unwrap_role<
					Role
				>,
				boost::mpl::_1
			>
		>::type
	>::type::value_type
	{
		return
			std::forward<
				typename
				boost::mpl::deref<
					typename
					boost::mpl::find_if<
						Arguments,
						majutsu::detail::tag_is_same<
							majutsu::unwrap_role<
								Role
							>,
							boost::mpl::_1
						>
					>::type
				>::type::value_type
			>(
				boost::fusion::deref(
					boost::fusion::find_if<
						majutsu::detail::tag_is_same<
							majutsu::unwrap_role<
								Role
							>,
							boost::mpl::_1
						>
					>(
						arguments_
					)
				).value()
			);
	}
private:
	Arguments &arguments_;
};

}
}
}

#endif
