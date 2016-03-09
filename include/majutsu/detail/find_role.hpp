//          Copyright Carl Philipp Reh 2014 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_DETAIL_FIND_ROLE_HPP_INCLUDED
#define MAJUTSU_DETAIL_FIND_ROLE_HPP_INCLUDED

#include <majutsu/role_to_tag_tpl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/find_if.hpp>
#include <boost/mpl/placeholders.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace detail
{

template<
	typename Elements,
	typename Role
>
using find_role
=
typename
boost::mpl::find_if<
	Elements,
	std::is_same<
		majutsu::role_to_tag_tpl<
			boost::mpl::_1
		>,
		Role
	>
>::type;

}
}

#endif
