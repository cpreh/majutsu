//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_WRITE_HPP_INCLUDED
#define MAJUTSU_RAW_WRITE_HPP_INCLUDED

#include <majutsu/raw/record_impl.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_char_ptr.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace raw
{

template<
	typename Types
>
inline
void
write(
	std::ostream &_stream,
	majutsu::raw::record<
		Types
	> const &_record
)
{
	_stream.write(
		fcppt::cast::to_char_ptr<
			std::ostream::char_type const *
		>(
			_record.data()
		),
		fcppt::cast::size<
			std::streamsize
		>(
			fcppt::cast::to_signed(
				_record.size()
			)
		)
	);
}

}
}

#endif
