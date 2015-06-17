//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_DETAIL_FIND_ROLE_DEREF_HPP_INCLUDED
#define MAJUTSU_DETAIL_FIND_ROLE_DEREF_HPP_INCLUDED

#include <majutsu/detail/find_role.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/deref.hpp>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace detail
{

template<
	typename Elements,
	typename Role
>
using
find_role_deref
=
typename
boost::mpl::deref<
	majutsu::detail::find_role<
		Elements,
		Role
	>
>::type;

}
}

#endif
