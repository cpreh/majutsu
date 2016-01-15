#include <majutsu/make_role_tag.hpp>
#include <majutsu/role.hpp>
#include <majutsu/raw/const_pointer.hpp>
#include <majutsu/raw/fundamental.hpp>
#include <majutsu/raw/make_generic.hpp>
#include <majutsu/raw/record_variadic.hpp>
#include <majutsu/raw/write.hpp>
#include <majutsu/raw/stream/istream.hpp>
#include <majutsu/raw/stream/memory.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <sstream>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
majutsu::raw::fundamental<
	int
>
int_;

MAJUTSU_MAKE_ROLE_TAG(
	int_role
);

typedef
majutsu::raw::record_variadic<
	majutsu::role<
		int_,
		int_role
	>
>
record;

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	raw_stream_istream
)
{
FCPPT_PP_POP_WARNING

	record const test{
		int_role{} = 42
	};

	std::stringstream stream;

	majutsu::raw::write(
		stream,
		test
	);

	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	optional_int const result{
		majutsu::raw::make_generic<
			majutsu::raw::stream::istream,
			int_
		>(
			stream
		)
	};

	BOOST_CHECK_EQUAL(
		result,
		optional_int{
			42
		}
	);

	optional_int const result2{
		majutsu::raw::make_generic<
			majutsu::raw::stream::istream,
			int_
		>(
			stream
		)
	};

	BOOST_CHECK_EQUAL(
		result2,
		optional_int()
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	raw_stream_memory
)
{
FCPPT_PP_POP_WARNING

	record const test{
		int_role{} = 42
	};

	majutsu::raw::const_pointer stream(
		test.data()
	);

	int const result{
		majutsu::raw::make_generic<
			majutsu::raw::stream::memory,
			int_
		>(
			stream
		)
	};

	BOOST_CHECK_EQUAL(
		result,
		42
	);
}
