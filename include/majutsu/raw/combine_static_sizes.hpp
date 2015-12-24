//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_COMBINE_STATIC_SIZES_HPP_INCLUDED
#define MAJUTSU_RAW_COMBINE_STATIC_SIZES_HPP_INCLUDED

#include <majutsu/raw/detail/dynamic_size.hpp>
#include <majutsu/raw/detail/is_static_size.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/plus.hpp>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace raw
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Size1,
	typename Size2
>
struct combine_static_sizes
:
boost::mpl::eval_if<
	boost::mpl::and_<
		majutsu::raw::detail::is_static_size<
			Size1
		>,
		majutsu::raw::detail::is_static_size<
			Size2
		>
	>,
	boost::mpl::plus<
		Size1,
		Size2
	>,
	boost::mpl::identity<
		majutsu::raw::detail::dynamic_size
	>
>::type
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
