#include <majutsu/composite.hpp>
#include <majutsu/integral_size.hpp>
#include <majutsu/make_role_tag.hpp>
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
	class nodefault
	{
	public:
		explicit
		nodefault(
			int const _value
		)
		:
			value_(
				_value
			)
		{
		}

		int
		value() const
		{
			return
				value_;
		}
	private:
		int value_;
	};

	class copy_only
	{
	public:
		explicit
		copy_only(
			int const _value
		)
		:
			value_(
				_value
			)
		{
		}

		copy_only(
			copy_only const &
		) = default;

		int
		value() const
		{
			return
				value_;
		}
	private:
		int value_;
	};

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
	majutsu::simple<
		nodefault
	>
	nodefault_;

	typedef
	majutsu::simple<
		copy_only
	>
	copy_only_;

	MAJUTSU_MAKE_ROLE_TAG(
		int_role
	);

	MAJUTSU_MAKE_ROLE_TAG(
		bool_role
	);

	MAJUTSU_MAKE_ROLE_TAG(
		nodefault_role
	);

	MAJUTSU_MAKE_ROLE_TAG(
		copy_only_role
	);

	typedef
	majutsu::memory::fusion<
		majutsu::composite<
			boost::mpl::vector4<
				majutsu::role<
					int_,
					int_role
				>,
				majutsu::role<
					bool_,
					bool_role
				>,
				majutsu::role<
					nodefault_,
					nodefault_role
				>,
				majutsu::role<
					copy_only_,
					copy_only_role
				>
			>
		>
	>
	my_memory;

	my_memory test(
		int_role{} = 4,
		bool_role{} = true,
		nodefault_role{} = nodefault{42},
		copy_only_role{} = copy_only(42)
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

	BOOST_CHECK(
		test.get<
			nodefault_role
		>().value()
		==
		42
	);

	BOOST_CHECK(
		test.get<
			copy_only_role
		>().value()
		==
		42
	);

	my_memory test2(
		test
	);

	BOOST_CHECK(
		test2.get<
			int_role
		>()
		==
		4
	);

	BOOST_CHECK(
		test2.get<
			bool_role
		>()
	);
}
