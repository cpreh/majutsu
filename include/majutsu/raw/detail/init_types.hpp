//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_DETAIL_INIT_TYPES_HPP_INCLUDED
#define MAJUTSU_RAW_DETAIL_INIT_TYPES_HPP_INCLUDED

#include <majutsu/raw/detail/needs_init.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/filter_view.hpp>
#include <boost/mpl/placeholders.hpp>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace raw
{
namespace detail
{

template<
	typename Types
>
using init_types
=
boost::mpl::filter_view<
	Types,
	majutsu::raw::detail::needs_init<
		boost::mpl::_1
	>
>;

}
}
}

#endif
