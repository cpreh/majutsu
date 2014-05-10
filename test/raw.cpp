#include <majutsu/composite.hpp>
#include <majutsu/fundamental.hpp>
#include <majutsu/make_role_tag.hpp>
#include <majutsu/role.hpp>
#include <majutsu/memory/raw.hpp>
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
	raw
)
{
	typedef
	majutsu::fundamental<
		int
	>
	int_;

	typedef
	majutsu::fundamental<
		bool
	>
	bool_;

	MAJUTSU_MAKE_ROLE_TAG(
		int_role
	);

	MAJUTSU_MAKE_ROLE_TAG(
		bool_role
	);

	typedef
	majutsu::memory::raw<
		majutsu::composite<
			boost::mpl::vector2<
				majutsu::role<
					int_,
					int_role
				>,
				majutsu::role<
					bool_,
					bool_role
				>
			>
		>
	>
	my_memory;

	my_memory test(
		int_role{} = 4,
		bool_role{} = true
	);

	BOOST_CHECK(
		test.get<
			int_role
		>()
		==
		4
	);

	BOOST_CHECK(
		test.get<
			bool_role
		>()
	);
}
