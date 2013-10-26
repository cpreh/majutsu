#ifndef MAJUTSU_MEMORY_DETAIL_STORE_FWD_HPP_INCLUDED
#define MAJUTSU_MEMORY_DETAIL_STORE_FWD_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace memory
{
namespace detail
{

template<
	typename T,
	typename Alloc = std::allocator<T>
>
class store;

}
}
}

#endif
