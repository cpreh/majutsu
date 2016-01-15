function(
	add_majutsu_test
	FILENAME
)
	fcppt_utils_add_test(
		${FILENAME}
		${ARGN}
	)
endfunction()

add_majutsu_test(
	fusion
)

add_majutsu_test(
	init
)

add_majutsu_test(
	raw
)

add_majutsu_test(
	raw/combine_static_sizes
	NO_CODE
)

add_majutsu_test(
	raw/nested
)

add_majutsu_test(
	raw/stream
)
