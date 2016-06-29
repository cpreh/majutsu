include(
	CMakeParseArguments
)

function(
	add_majutsu_test
	FILENAME
)
	set(
		MULTI_ARGS
		LINK_LIBS
	)

	cmake_parse_arguments(
		""
		""
		""
		"${MULTI_ARGS}"
		${ARGN}
	)

	fcppt_utils_add_test(
		${FILENAME}
		LINK_LIBS
			majutsu_interface
			${_LINK_LIBS}
	)
endfunction()

add_majutsu_test(
	init
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_majutsu_test(
	record
	LINK_LIBS
		fcppt_core_interface
)
