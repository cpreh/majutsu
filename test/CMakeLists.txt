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
	init
)

add_majutsu_test(
	record
)
