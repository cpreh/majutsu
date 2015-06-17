//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_FUSION_DETAIL_EXPAND_INITLIST_HPP_INCLUDED
#define MAJUTSU_FUSION_DETAIL_EXPAND_INITLIST_HPP_INCLUDED

#include <majutsu/fusion/detail/init_element.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/fusion/adapted/mpl.hpp>
#include <boost/fusion/algorithm/transformation/transform.hpp>
#include <boost/fusion/container/vector/vector.hpp>
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
			majutsu::fusion::detail::init_element<
				decltype(
					fusion_arguments
				)
			>(
				fusion_arguments
			)
		);
}

}
}
}

#endif
