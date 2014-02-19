function(
	add_majutsu_test
	PATHNAME
)
	fcppt_utils_add_test(
		${PATHNAME}
		""
		""
	)
endfunction()

add_majutsu_test(
	class
)

add_majutsu_test(
	fusion
)

add_majutsu_test(
	raw
)
