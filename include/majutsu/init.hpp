//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_INIT_HPP_INCLUDED
#define MAJUTSU_INIT_HPP_INCLUDED

#include <majutsu/detail/init.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/end.hpp>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{

template<
	typename Result,
	typename Function
>
inline
Result
init(
	Function const &_function
)
{
	typedef
	typename
	Result::all_types
	types;

	return
		majutsu::detail::init<
			Result,
			typename
			boost::mpl::begin<
				types
			>::type,
			typename
			boost::mpl::end<
				types
			>::type
		>(
			_function
		);
}

}

#endif
