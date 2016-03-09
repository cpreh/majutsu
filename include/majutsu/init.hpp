//          Copyright Carl Philipp Reh 2014 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_INIT_HPP_INCLUDED
#define MAJUTSU_INIT_HPP_INCLUDED

#include <majutsu/role_to_tag.hpp>
#include <fcppt/decltype_sink.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/algorithm/vararg_map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
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
	return
		fcppt::algorithm::vararg_map<
			typename
			Result::all_types
		>(
			[](
				auto &&... _args
			){
				return
					Result{
						std::forward<
							decltype(
								_args
							)
						>(
							_args
						)...
					};
			},
			[
				&_function
			](
				auto const _tag
			)
			{
				typedef
				fcppt::tag_type<
					FCPPT_DECLTYPE_SINK(
						_tag
					)
				>
				role;

				return
					majutsu::role_to_tag<
						role
					>{} =
						_function(
							role{}
						);
			}
		);
}

}

#endif
