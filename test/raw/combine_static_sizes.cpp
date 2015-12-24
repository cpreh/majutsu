#include <majutsu/raw/combine_static_sizes.hpp>
#include <majutsu/raw/fundamental.hpp>
#include <majutsu/raw/is_static_size.hpp>
#include <majutsu/raw/static_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>


int
main()
{
	static_assert(
		majutsu::raw::combine_static_sizes<
			majutsu::raw::static_size<
				majutsu::raw::fundamental<
					std::uint16_t
				>
			>,
			majutsu::raw::static_size<
				majutsu::raw::fundamental<
					std::uint32_t
				>
			>
		>::value
		==
		majutsu::raw::static_size<
			majutsu::raw::fundamental<
				std::uint16_t
			>
		>::value
		+
		majutsu::raw::static_size<
			majutsu::raw::fundamental<
				std::uint32_t
			>
		>::value,
		""
	);

	static_assert(
		!majutsu::raw::is_static_size<
			majutsu::raw::combine_static_sizes<
				majutsu::raw::static_size<
					majutsu::raw::fundamental<
						std::uint16_t
					>
				>,
				majutsu::raw::static_size<
					void
				>
			>
		>::value,
		""
	);
}
