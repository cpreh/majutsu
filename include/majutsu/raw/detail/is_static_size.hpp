//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_DETAIL_IS_STATIC_SIZE_HPP_INCLUDED
#define MAJUTSU_RAW_DETAIL_IS_STATIC_SIZE_HPP_INCLUDED

#include <majutsu/raw/detail/dynamic_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/not.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace raw
{
namespace detail
{

template<
	typename Size
>
using
is_static_size
=
boost::mpl::not_<
	std::is_base_of<
		majutsu::raw::detail::dynamic_size,
		Size
	>
>;

}
}
}

#endif
