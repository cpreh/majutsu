#include <majutsu/access_role.hpp>
#include <majutsu/get.hpp>
#include <majutsu/init.hpp>
#include <majutsu/make_role_tag.hpp>
#include <majutsu/role.hpp>
#include <majutsu/role_value_type.hpp>
#include <majutsu/fusion/record.hpp>
#include <majutsu/raw/constant.hpp>
#include <majutsu/raw/fundamental.hpp>
#include <majutsu/raw/record.hpp>
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

	BOOST_CHECK(
		majutsu::get<
			int_role
		>(
			record
		)
		==
		42
	);
}

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	init_raw
)
{
FCPPT_PP_POP_WARNING

	MAJUTSU_MAKE_ROLE_TAG(
		constant_role
	);

	typedef
	majutsu::raw::fundamental<
		int
	>
	int_;

	typedef
	majutsu::raw::record<
		boost::mpl::vector2<
			majutsu::role<
				majutsu::raw::constant<
					int_,
					10
				>,
				constant_role
			>,
			majutsu::role<
				int_,
				int_role
			>
		>
	>
	my_memory;

	init_test<
		my_memory
	>();
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	init_fusion
)
{
FCPPT_PP_POP_WARNING
	typedef
	majutsu::fusion::record<
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
