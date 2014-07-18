//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_MEMORY_DETAIL_EXPAND_FUSION_INITLIST_HPP_INCLUDED
#define MAJUTSU_MEMORY_DETAIL_EXPAND_FUSION_INITLIST_HPP_INCLUDED

#include <majutsu/memory/detail/init_fusion_element.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/fusion/adapted/mpl.hpp>
#include <boost/fusion/algorithm/transformation/transform.hpp>
#include <boost/fusion/container/generation/make_vector.hpp>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace memory
{
namespace detail
{

template<
	typename Types,
	typename Tuple,
	typename ...Arguments
>
Tuple
expand_fusion_initlist(
	Arguments && ..._arguments
)
{
	auto fusion_arguments(
		boost::fusion::make_vector(
			std::forward<
				Arguments
			>(
				_arguments
			)...
		)
	);

	return
		boost::fusion::transform(
			Types(),
			majutsu::memory::detail::init_fusion_element<
				Types,
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
