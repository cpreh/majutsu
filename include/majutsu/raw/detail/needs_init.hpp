//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_DETAIL_NEEDS_INIT_HPP_INCLUDED
#define MAJUTSU_RAW_DETAIL_NEEDS_INIT_HPP_INCLUDED

#include <majutsu/is_role.hpp>
#include <majutsu/raw/is_constant.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace raw
{
namespace detail
{

template<
	typename Element
>
using needs_init
=
boost::mpl::and_<
	// TODO: Why?
	majutsu::is_role<
		Element
	>,
	boost::mpl::not_<
		majutsu::raw::is_constant<
			Element
		>
	>
>;

}
}
}

#endif
