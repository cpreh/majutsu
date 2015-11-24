//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_FUSION_DETAIL_EXPAND_INITLIST_HPP_INCLUDED
#define MAJUTSU_FUSION_DETAIL_EXPAND_INITLIST_HPP_INCLUDED

#include <majutsu/unwrap_role.hpp>
#include <majutsu/detail/tag_is_same.hpp>
#include <fcppt/decltype_sink.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/fusion/adapted/mpl.hpp>
#include <boost/fusion/algorithm/query/find_if.hpp>
#include <boost/fusion/algorithm/transformation/transform.hpp>
#include <boost/fusion/container/vector/vector.hpp>
#include <boost/fusion/iterator/deref.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/find_if.hpp>
#include <boost/mpl/placeholders.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace fusion
{
namespace detail
{

template<
	typename Tuple,
	typename Types,
	typename ...Arguments
>
inline
Tuple
expand_initlist(
	Arguments && ..._arguments
)
{
	boost::fusion::vector<
		Arguments...
	> fusion_arguments(
		std::forward<
			Arguments
		>(
			_arguments
		)...
	);

	return
		boost::fusion::transform(
			Types(),
			[
				&fusion_arguments
			](
				auto const &_role
			)
			{
				typedef
				FCPPT_DECLTYPE_SINK(
					_role
				)
				role_type;

				return
					std::forward<
						typename
						boost::mpl::deref<
							typename
							boost::mpl::find_if<
								decltype(
									fusion_arguments
								),
								majutsu::detail::tag_is_same<
									majutsu::unwrap_role<
										role_type
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
										role_type
									>,
									boost::mpl::_1
								>
							>(
								fusion_arguments
							)
						).value()
					);
			}
		);
}

}
}
}

#endif
