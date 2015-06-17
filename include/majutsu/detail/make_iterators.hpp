//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_DETAIL_MAKE_ITERATORS_HPP_INCLUDED
#define MAJUTSU_DETAIL_MAKE_ITERATORS_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/iter_fold.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace detail
{

template<
	typename Sequence
>
using make_iterators
=
typename
boost::mpl::iter_fold<
	Sequence,
	boost::mpl::vector0<>,
	boost::mpl::push_back<
		boost::mpl::_1,
		boost::mpl::_2
	>
>::type;

}
}

#endif
