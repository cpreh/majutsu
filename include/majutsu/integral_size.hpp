//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_INTEGRAL_SIZE_HPP_INCLUDED
#define MAJUTSU_INTEGRAL_SIZE_HPP_INCLUDED

#include <majutsu/size_type.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/integral_c.hpp>
#include <fcppt/config/external_end.hpp>

namespace majutsu

{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	majutsu::size_type Size
>
struct integral_size
:
boost::mpl::integral_c<
	majutsu::size_type,
	Size
>
{
};

FCPPT_PP_POP_WARNING

}

#endif
