//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_DETAIL_FLATTEN_HPP_INCLUDED
#define MAJUTSU_DETAIL_FLATTEN_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/back_inserter.hpp>
#include <boost/mpl/copy.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace detail
{

template<
	typename Type,
	typename Enable = void
>
struct flatten;

template<
	typename Type
>
struct flatten<
	Type,
	typename boost::enable_if<
		boost::mpl::is_sequence<
			Type
		>
	>::type
>
{
	typedef
	typename
	boost::mpl::fold<
		Type,
		boost::mpl::vector0<>,
		boost::mpl::copy<
			majutsu::detail::flatten<
				boost::mpl::_2
			>,
			boost::mpl::back_inserter<
				boost::mpl::_1
			>
		>
	>::type
	type;
};

template<
	typename Type
>
struct flatten<
	Type,
	typename boost::disable_if<
		boost::mpl::is_sequence<
			Type
		>
	>::type
>
{
	typedef boost::mpl::vector1<
		Type
	> type;
};

}
}

#endif
