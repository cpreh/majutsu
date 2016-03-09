//          Copyright Carl Philipp Reh 2014 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RECORD_OUTPUT_HPP_INCLUDED
#define MAJUTSU_RECORD_OUTPUT_HPP_INCLUDED

#include <majutsu/get.hpp>
#include <majutsu/record_impl.hpp>
#include <majutsu/role_to_tag.hpp>
#include <fcppt/decltype_sink.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/to_std_string.hpp>
#include <fcppt/type_name_from_info.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/algorithm/loop_break_mpl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{

template<
	typename Types
>
std::ostream &
operator<<(
	std::ostream &_stream,
	majutsu::record<
		Types
	> const &_record
)
{
	_stream
		<<
		'{';

	fcppt::algorithm::loop(
		Types{},
		[
			&_stream,
			&_record
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
			role_tag;

			_stream
				<<
				fcppt::to_std_string(
					fcppt::type_name_from_info(
						typeid(
							typename
							role_tag::tag
						)
					)
				)
				<<
				" = "
				<<
				majutsu::get<
					role_tag
				>(
					_record
				)
				<<
				", ";
		}
	);

	return
		_stream
		<<
		'}';
}

}

#endif
