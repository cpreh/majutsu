#include <majutsu/class.hpp>
#include <majutsu/composite.hpp>
#include <majutsu/fundamental.hpp>
#include <majutsu/get.hpp>
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
					int_
				>,
				majutsu::role<
					bool_
				>
			>
		>,
		Memory
	>
	my_class;

	my_class test(
		4,
		true
	);

	BOOST_CHECK(
		majutsu::get<
			int_
		>(
			test
		)
		==
		4
	);

	BOOST_CHECK(
		majutsu::get<
			bool_
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
			int_
		>(
			test2
		)
		==
		4
	);

	BOOST_CHECK(
		majutsu::get<
			bool_
		>(
			test2
		)
	);

	majutsu::set<
		bool_
	>(
		test2,
		false
	);

	BOOST_CHECK(
		!majutsu::get<
			bool_
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
