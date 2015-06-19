//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_DETAIL_INIT_CONSTANTS_HPP_INCLUDED
#define MAJUTSU_RAW_DETAIL_INIT_CONSTANTS_HPP_INCLUDED

#include <majutsu/access_role.hpp>
#include <majutsu/raw/is_constant.hpp>
#include <fcppt/nonassignable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace raw
{
namespace detail
{

template<
	typename Memory
>
class init_constants
{
	FCPPT_NONASSIGNABLE(
		init_constants
	);
public:
	explicit
	init_constants(
		Memory &_mem
	)
	:
		mem_(
			_mem
		)
	{
	}

	template<
		typename Iterator
	>
	typename
	boost::enable_if<
		majutsu::raw::is_constant<
			majutsu::access_role<
				typename
				boost::mpl::deref<
					Iterator
				>::type
			>
		>,
		void
	>::type
	operator()(
		Iterator &
	) const
	{
		mem_. template set_internal<
			Iterator
		>(
			majutsu::access_role<
				typename
				boost::mpl::deref<
					Iterator
				>::type
			>::constant_value::value
		);
	}

	template<
		typename Iterator
	>
	typename
	boost::disable_if<
		majutsu::raw::is_constant<
			majutsu::access_role<
				typename
				boost::mpl::deref<
					Iterator
				>::type
			>
		>,
		void
	>::type
	operator()(
		Iterator &
	) const
	{
	}
private:
	Memory &mem_;
};

}
}
}

#endif
