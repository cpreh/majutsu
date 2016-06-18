cmake_minimum_required(
	VERSION
	3.0.0
)

project(
	majutsu
)

include(
	FcpptCMakeUtils
)

option(
	ENABLE_TEST
	"Build the tests"
	ON
)

if(
	ENABLE_TEST
)
	list(
		APPEND
		NEEDED_BOOST_LIBS
		"unit_test_framework"
	)
endif()

find_package(
	Boost
	1.47.0
	REQUIRED
	COMPONENTS
	"${NEEDED_BOOST_LIBS}"
)

find_package(
	fcppt
	REQUIRED
)

set(
	MAJUTSU_FILES
	include/majutsu/detail/all_initializers.hpp
	include/majutsu/detail/contains_initializer.hpp
	include/majutsu/detail/find_role.hpp
	include/majutsu/detail/find_role_deref.hpp
	include/majutsu/detail/index_of.hpp
	include/majutsu/detail/tag_is_same.hpp
	include/majutsu/get.hpp
	include/majutsu/init.hpp
	include/majutsu/is_role.hpp
	include/majutsu/is_role_tag.hpp
	include/majutsu/make_role_tag.hpp
	include/majutsu/make_role_tag_arg.hpp
	include/majutsu/make_role_tag_arg_fwd.hpp
	include/majutsu/make_role_tag_fwd.hpp
	include/majutsu/record.hpp
	include/majutsu/record_comparison.hpp
	include/majutsu/record_decl.hpp
	include/majutsu/record_fwd.hpp
	include/majutsu/record_impl.hpp
	include/majutsu/record_output.hpp
	include/majutsu/role.hpp
	include/majutsu/role_fwd.hpp
	include/majutsu/role_init_decl.hpp
	include/majutsu/role_init_fwd.hpp
	include/majutsu/role_init_impl.hpp
	include/majutsu/role_tag.hpp
	include/majutsu/role_tag_decl.hpp
	include/majutsu/role_tag_fwd.hpp
	include/majutsu/role_tag_impl.hpp
	include/majutsu/role_to_tag.hpp
	include/majutsu/role_to_tag_tpl.hpp
	include/majutsu/role_to_type.hpp
	include/majutsu/role_to_type_tpl.hpp
	include/majutsu/role_value_type.hpp
	include/majutsu/set.hpp
)

fcppt_utils_add_source_groups(
	"${MAJUTSU_FILES}"
)

fcppt_utils_add_dummy_target(
	majutsu
	"${MAJUTSU_FILES}"
)

fcppt_utils_set_target_compiler_flags(
	majutsu_dummy
)

if(
	ENABLE_TEST
)
	enable_testing()

	add_subdirectory(
		test
	)
endif()

add_library(
	majutsu_interface
	INTERFACE
)

target_include_directories(
	majutsu_interface
	INTERFACE
	"$<BUILD_INTERFACE:${FCPPT_UTILS_PROJECT_SOURCE_DIR}/include>"
	"$<INSTALL_INTERFACE:${INSTALL_INCLUDE_DIR}>"
)

target_link_libraries(
	majutsu_interface
	INTERFACE
	fcppt_core_interface
)

fcppt_utils_export_install_target(
	majutsu_interface
)

fcppt_utils_generate_config()

install(
	DIRECTORY
	${FCPPT_UTILS_PROJECT_SOURCE_DIR}/include/
	DESTINATION
	${INSTALL_INCLUDE_DIR}
)
