#include <majutsu/make_role_tag.hpp>
#include <majutsu/record.hpp>
#include <majutsu/role.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	record
)
{
FCPPT_PP_POP_WARNING

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
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

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

	MAJUTSU_MAKE_ROLE_TAG(
		move_only_role
	);

	typedef
	majutsu::record<
		boost::mpl::vector5<
			majutsu::role<
				int,
				int_role
			>,
			majutsu::role<
				bool,
				bool_role
			>,
			majutsu::role<
				nodefault,
				nodefault_role
			>,
			majutsu::role<
				copy_only,
				copy_only_role
			>,
			majutsu::role<
				int_unique_ptr,
				move_only_role
			>
		>
	>
	my_memory;

	int const arg1{
		4
	};

	my_memory test(
		int_role{} =
			arg1,
		bool_role{} =
			true,
		copy_only_role{} =
			copy_only(
				42
			),
		nodefault_role{} =
			nodefault{
				42
			},
		move_only_role{} =
			fcppt::make_unique_ptr<
				int
			>(
				42
			)
	);

	BOOST_CHECK_EQUAL(
		test.get<
			int_role
		>(),
		4
	);

	BOOST_CHECK(
		test.get<
			bool_role
		>()
	);

	BOOST_CHECK_EQUAL(
		test.get<
			nodefault_role
		>().value(),
		42
	);

	BOOST_CHECK_EQUAL(
		test.get<
			copy_only_role
		>().value(),
		42
	);

	BOOST_CHECK_EQUAL(
		*test.get<
			move_only_role
		>(),
		42
	);

	my_memory test2(
		std::move(
			test
		)
	);

	BOOST_CHECK_EQUAL(
		test2.get<
			int_role
		>(),
		4
	);

	BOOST_CHECK(
		test2.get<
			bool_role
		>()
	);

	BOOST_CHECK_EQUAL(
		*test2.get<
			move_only_role
		>(),
		42
	);
}
