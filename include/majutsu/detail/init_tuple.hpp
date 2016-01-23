//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_DETAIL_INIT_TUPLE_HPP_INCLUDED
#define MAJUTSU_DETAIL_INIT_TUPLE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/next.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace detail
{

// TODO: Replace this code by something generic
template<
	typename Result,
	typename Iterator,
	typename EndIterator,
	typename Function,
	typename... Args
>
inline
typename
boost::enable_if<
	std::is_same<
		Iterator,
		EndIterator
	>,
	Result
>::type
init_tuple(
	Function const &,
	Args &&..._args
)
{
	return
		Result(
			std::forward<
				Args
			>(
				_args
			)...
		);
}

template<
	typename Result,
	typename Iterator,
	typename EndIterator,
	typename Function,
	typename... Args
>
inline
typename
boost::disable_if<
	std::is_same<
		Iterator,
		EndIterator
	>,
	Result
>::type
init_tuple(
	Function const &_function,
	Args &&..._args
)
{
	typedef
	typename
	boost::mpl::deref<
		Iterator
	>::type
	role;

	return
		majutsu::detail::init_tuple<
			Result,
			typename
			boost::mpl::next<
				Iterator
			>::type,
			EndIterator
		>(
			_function,
			std::forward<
				Args
			>(
				_args
			)...,
			_function(
				role{}
			)
		);
}


}
}

#endif
