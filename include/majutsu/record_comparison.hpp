//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RECORD_COMPARISON_HPP_INCLUDED
#define MAJUTSU_RECORD_COMPARISON_HPP_INCLUDED

#include <majutsu/get.hpp>
#include <majutsu/record_impl.hpp>
#include <majutsu/role_to_tag.hpp>
#include <fcppt/decltype_sink.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/algorithm/loop_break_mpl.hpp>


namespace majutsu
{

template<
	typename Types
>
bool
operator==(
	majutsu::record<
		Types
	> const &_record1,
	majutsu::record<
		Types
	> const &_record2
)
{
	return
		fcppt::algorithm::all_of(
			Types{},
			[
				&_record1,
				&_record2
			](
				auto const _role
			)
			{
				typedef
				majutsu::role_to_tag<
					fcppt::tag_type<
						FCPPT_DECLTYPE_SINK(
							_role
						)
					>
				>
				tag;

				return
					majutsu::get<
						tag
					>(
						_record1
					)
					==
					majutsu::get<
						tag
					>(
						_record2
					);
			}
		);
}

template<
	typename Types
>
inline
bool
operator!=(
	majutsu::record<
		Types
	> const &_record1,
	majutsu::record<
		Types
	> const &_record2
)
{
	return
		!(_record1 == _record2);
}

}

#endif
