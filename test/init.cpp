#include <majutsu/get.hpp>
#include <majutsu/init.hpp>
#include <majutsu/make_role_tag.hpp>
#include <majutsu/record.hpp>
#include <majutsu/record_comparison.hpp>
#include <majutsu/record_output.hpp>
#include <majutsu/role.hpp>
#include <majutsu/role_to_type.hpp>
#include <majutsu/role_value_type.hpp>
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

template<
	typename Record
>
struct init_function
{
	template<
		typename Type
	>
	majutsu::role_value_type<
		Record,
		int_role
	>
	operator()(
		majutsu::role<
			Type,
			int_role
		>
	) const
	{
		return
			42;
	}
};

template<
	typename Record
>
void
init_test()
{
	Record const record(
		majutsu::init<
			Record
		>(
			init_function<
				Record
			>{}
		)
	);

	BOOST_CHECK_EQUAL(
		majutsu::get<
			int_role
		>(
			record
		),
		42
	);

	BOOST_CHECK_EQUAL(
		Record{
			int_role{} =
				42
		},
		record
	);
}

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	init_fusion
)
{
FCPPT_PP_POP_WARNING

	typedef
	majutsu::record<
		boost::mpl::vector1<
			majutsu::role<
				int,
				int_role
			>
		>
	>
	my_memory;

	init_test<
		my_memory
	>();
}
