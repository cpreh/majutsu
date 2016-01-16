#include <majutsu/get.hpp>
#include <majutsu/make_role_tag.hpp>
#include <majutsu/role.hpp>
#include <majutsu/raw/const_pointer.hpp>
#include <majutsu/raw/fundamental.hpp>
#include <majutsu/raw/make_generic.hpp>
#include <majutsu/raw/record_variadic.hpp>
#include <majutsu/raw/write.hpp>
#include <majutsu/raw/stream/istream.hpp>
#include <majutsu/raw/stream/memory.hpp>
#include <fcppt/optional/object_impl.hpp>
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

MAJUTSU_MAKE_ROLE_TAG(
	record_role
);

typedef
majutsu::raw::record_variadic<
	majutsu::role<
		int_,
		int_role
	>
>
inner_record;

typedef
majutsu::raw::record_variadic<
	majutsu::role<
		int_,
		int_role
	>,
	majutsu::role<
		inner_record,
		record_role
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
		int_role{} = 42,
		record_role{} =
			inner_record{
				int_role{} = 10
			}
	};

	std::stringstream stream;

	majutsu::raw::write(
		stream,
		test
	);

	typedef
	fcppt::optional::object<
		record
	>
	optional_record;

	optional_record const result{
		majutsu::raw::make_generic<
			majutsu::raw::stream::istream,
			record
		>(
			stream
		)
	};

	// TODO: Add record comparison and output
	BOOST_REQUIRE(
		result.has_value()
	);

	BOOST_CHECK_EQUAL(
		majutsu::get<
			int_role
		>(
			result.get_unsafe()
		),
		42
	);

	optional_record const result2{
		majutsu::raw::make_generic<
			majutsu::raw::stream::istream,
			record
		>(
			stream
		)
	};

	BOOST_CHECK(
		!result2.has_value()
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
		int_role{} = 42,
		record_role{} =
			inner_record{
				int_role{} = 10
			}
	};

	majutsu::raw::const_pointer stream(
		test.data()
	);

	record const result{
		majutsu::raw::make_generic<
			majutsu::raw::stream::memory,
			record
		>(
			stream
		)
	};

	BOOST_CHECK_EQUAL(
		majutsu::get<
			int_role
		>(
			result
		),
		42
	);
}
