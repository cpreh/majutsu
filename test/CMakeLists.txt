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

	set_target_properties(
		${MAJUTSU_TEST_NAME}
		PROPERTIES
		COMPILE_FLAGS
		"${ADDITIONAL_DEFINES}"
	)

	if(
		Boost_USE_STATIC_LIBS
	)
		set_property(
			TARGET
			${MAJUTSU_TEST_NAME}
			PROPERTY COMPILE_DEFINITIONS
			"BOOST_TEST_NO_LIB;BOOST_TEST_MODULE=${TESTNAME}"
		)
	else()
		set_property(
			TARGET
			${MAJUTSU_TEST_NAME}
			PROPERTY COMPILE_DEFINITIONS
			"BOOST_TEST_DYN_LINK;BOOST_TEST_MODULE=${TESTNAME}"
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
