#include <majutsu/composite.hpp>
#include <majutsu/role.hpp>
#include <majutsu/simple.hpp>
#include <majutsu/memory/fusion.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	fusion
)
{
	typedef
	majutsu::simple<
		int
	>
	int_;

	typedef
	majutsu::simple<
		bool
	>
	bool_;

	typedef
	majutsu::memory::fusion<
		majutsu::composite<
			boost::mpl::vector2<
				majutsu::role<
					int_
				>,
				majutsu::role<
					bool_
				>
			>
		>
	>
	my_memory;

	my_memory test(
		4,
		true
	);

	BOOST_CHECK(
		test.get<
			int_
		>()
		==
		4
	);

	BOOST_CHECK(
		test.get<
			bool_
		>()
	);

	my_memory test2(
		test
	);

	BOOST_CHECK(
		test2.get<
			int_
		>()
		==
		4
	);

	BOOST_CHECK(
		test2.get<
			bool_
		>()
	);
}
