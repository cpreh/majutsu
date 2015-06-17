//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_DETAIL_STORE_FWD_HPP_INCLUDED
#define MAJUTSU_RAW_DETAIL_STORE_FWD_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace raw
{
namespace detail
{

template<
	typename T,
	typename Alloc =
		std::allocator<T>
>
class store;

}
}
}

#endif
