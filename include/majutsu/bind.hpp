//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_BIND_HPP_INCLUDED
#define MAJUTSU_BIND_HPP_INCLUDED

#include <majutsu/bind_fwd.hpp>
#include <majutsu/placeholder.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/transform.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{

template<
	typename Base,
	typename Binders
>
struct bind
{
	typedef typename boost::mpl::transform<
		typename Base::type,
		typename Binders::type,
		boost::mpl::if_<
			std::is_same<
				boost::mpl::_2,
				majutsu::placeholder
			>,
			boost::mpl::_1,
			boost::mpl::_2
		>
	>::type type;
};

}

#endif
