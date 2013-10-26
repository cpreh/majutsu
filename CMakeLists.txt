cmake_minimum_required(
	VERSION 2.6
)

project(
	majutsu
)

include(
	FcpptCMakeUtils
)

fcppt_utils_prepare_config()

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
	Boost 1.47.0 REQUIRED COMPONENTS
	"${NEEDED_BOOST_LIBS}"
)

find_package(
	fcppt
	REQUIRED
)

include_directories(
	${fcppt_INCLUDE_DIRS}
)

add_definitions(
	${fcppt_DEFINITIONS}
)

include_directories(
	include
)

set(
	MAJUTSU_FILES
	include/majutsu/access_role.hpp
	include/majutsu/bind.hpp
	include/majutsu/bind_fwd.hpp
	include/majutsu/class.hpp
	include/majutsu/class_decl.hpp
	include/majutsu/class_fwd.hpp
	include/majutsu/class_impl.hpp
	include/majutsu/composite.hpp
	include/majutsu/composite_fwd.hpp
	include/majutsu/const_raw_pointer.hpp
	include/majutsu/constant.hpp
	include/majutsu/constant_fwd.hpp
	include/majutsu/detail/check_empty_class.hpp
	include/majutsu/detail/copy_n.hpp
	include/majutsu/detail/find_role.hpp
	include/majutsu/detail/make_iterators.hpp
	include/majutsu/detail/static_size_base.hpp
	include/majutsu/detail/unwrap_role.hpp
	include/majutsu/detail/wrapped_type.hpp
	include/majutsu/dispatch_value.hpp
	include/majutsu/extract_constant.hpp
	include/majutsu/flatten.hpp
	include/majutsu/fundamental.hpp
	include/majutsu/fundamental_decl.hpp
	include/majutsu/fundamental_fwd.hpp
	include/majutsu/get.hpp
	include/majutsu/integral_size.hpp
	include/majutsu/is_constant.hpp
	include/majutsu/is_role.hpp
	include/majutsu/is_static_size.hpp
	include/majutsu/make.hpp
	include/majutsu/memory/detail/expand_fusion_initlist.hpp
	include/majutsu/memory/detail/index_of.hpp
	include/majutsu/memory/detail/init_constants.hpp
	include/majutsu/memory/detail/init_fusion_element.hpp
	include/majutsu/memory/detail/init_raw_memory.hpp
	include/majutsu/memory/detail/store_decl.hpp
	include/majutsu/memory/detail/store_fwd.hpp
	include/majutsu/memory/detail/store_impl.hpp
	include/majutsu/memory/fusion.hpp
	include/majutsu/memory/fusion_decl.hpp
	include/majutsu/memory/fusion_fwd.hpp
	include/majutsu/memory/fusion_impl.hpp
	include/majutsu/memory/init_count.hpp
	include/majutsu/memory/needs_init.hpp
	include/majutsu/memory/raw.hpp
	include/majutsu/memory/raw_decl.hpp
	include/majutsu/memory/raw_fwd.hpp
	include/majutsu/memory/raw_impl.hpp
	include/majutsu/needed_size.hpp
	include/majutsu/place.hpp
	include/majutsu/placeholder.hpp
	include/majutsu/placeholder_fwd.hpp
	include/majutsu/raw_data.hpp
	include/majutsu/raw_pointer.hpp
	include/majutsu/role.hpp
	include/majutsu/role_fwd.hpp
	include/majutsu/role_return_type.hpp
	include/majutsu/set.hpp
	include/majutsu/simple.hpp
	include/majutsu/simple_fwd.hpp
	include/majutsu/size_type.hpp
	include/majutsu/static_size.hpp
)

fcppt_utils_add_source_groups(
	"${MAJUTSU_FILES}"
)

fcppt_utils_add_dummy_target(
	majutsu
	"${MAJUTSU_FILES}"
)

if(
	ENABLE_TEST
)
	enable_testing()

	add_subdirectory(
		test
	)
endif()

set(
	FCPPT_UTILS_NO_TARGETS
	TRUE
)

fcppt_utils_generate_config()

install(
	DIRECTORY
	${FCPPT_UTILS_PROJECT_SOURCE_DIR}/include/
	DESTINATION
	${INSTALL_INCLUDE_DIR}
)
