#include <majutsu/class.hpp>
#include <majutsu/composite.hpp>
#include <majutsu/fundamental.hpp>
#include <majutsu/get.hpp>
#include <majutsu/make_role_tag.hpp>
#include <majutsu/make_role_tag_arg.hpp>
#include <majutsu/role.hpp>
#include <majutsu/set.hpp>
#include <majutsu/memory/fusion.hpp>
#include <majutsu/memory/raw.hpp>
#include <fcppt/no_init.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

MAJUTSU_MAKE_ROLE_TAG(
	int_role
);

MAJUTSU_MAKE_ROLE_TAG_ARG(
	bool_role,
	int
);

template<
	template<
		typename
	>
	class Memory
>
void
test()
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

	typedef
	majutsu::class_<
		majutsu::composite<
			boost::mpl::vector2<
				majutsu::role<
					int_,
					int_role
				>,
				majutsu::role<
					bool_,
					bool_role<
						1
					>
				>
			>
		>,
		Memory
	>
	my_class;

	my_class test(
		int_role{} = 4,
		bool_role<1>{} = true
	);

	BOOST_CHECK(
		majutsu::get<
			int_role
		>(
			test
		)
		==
		4
	);

	BOOST_CHECK(
		majutsu::get<
			bool_role<
				1
			>
		>(
			test
		)
	);

	my_class test2{
		fcppt::no_init()
	};

	test2 = test;

	BOOST_CHECK(
		majutsu::get<
			int_role
		>(
			test2
		)
		==
		4
	);

	BOOST_CHECK(
		majutsu::get<
			bool_role<
				1
			>
		>(
			test2
		)
	);

	majutsu::set<
		bool_role<
			1
		>
	>(
		test2,
		false
	);

	BOOST_CHECK(
		!majutsu::get<
			bool_role<
				1
			>
		>(
			test2
		)
	);
}

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	class_
)
{
	test<
		majutsu::memory::raw
	>();

	test<
		majutsu::memory::fusion
	>();
}
