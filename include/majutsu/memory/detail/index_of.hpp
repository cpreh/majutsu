//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_MEMORY_DETAIL_INDEX_OF_HPP_INCLUDED
#define MAJUTSU_MEMORY_DETAIL_INDEX_OF_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/distance.hpp>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace memory
{
namespace detail
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Elements,
	typename Iterator
>
struct index_of
:
boost::mpl::distance<
	typename boost::mpl::begin<
		Elements
	>::type,
	Iterator
>
{
};

FCPPT_PP_POP_WARNING

}
}
}

#endif
