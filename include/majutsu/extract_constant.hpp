//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_EXTRACT_CONSTANT_HPP_INCLUDED
#define MAJUTSU_EXTRACT_CONSTANT_HPP_INCLUDED

#include <majutsu/flatten.hpp>
#include <majutsu/detail/find_role.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/integral_c.hpp>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{

template<
	typename Types,
	typename Role
>
struct extract_constant
{
private:
	typedef typename majutsu::flatten<
		Types
	>::type flattened_types;

	typedef typename boost::mpl::deref<
		typename majutsu::detail::find_role<
			flattened_types,
			Role
		>::type
	>::type found_role;
public:
	typedef boost::mpl::integral_c<
		typename found_role::type,
		found_role::value
	> type;
};

}

#endif
