function(
	add_majutsu_test
	PATHNAME
)
	string(
		REPLACE
		"/"
		"_"
		TESTNAME
		${PATHNAME}
	)

	set(
		MAJUTSU_TEST_NAME
		test_${TESTNAME}
	)

	add_executable(
		${MAJUTSU_TEST_NAME}
		${PATHNAME}.cpp
	)

	fcppt_utils_set_target_compiler_flags(
		${MAJUTSU_TEST_NAME}
	)

	target_compile_definitions(
		${MAJUTSU_TEST_NAME}
		PRIVATE
		BOOST_TEST_MODULE=${TESTNAME}
		${ADDITIONAL_DEFINES}
	)

	if(
		Boost_USE_STATIC_LIBS
	)
		target_compile_definitions(
			${MAJUTSU_TEST_NAME}
			PRIVATE
			BOOST_TEST_NO_LIB
		)
	else()
		target_compile_definitions(
			${MAJUTSU_TEST_NAME}
			PRIVATE
			BOOST_TEST_DYN_LINK
		)
	endif()

	target_link_libraries(
		${MAJUTSU_TEST_NAME}
		${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
	)

	add_test(
		NAME
		${MAJUTSU_TEST_NAME}
		COMMAND
		${MAJUTSU_TEST_NAME}
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
