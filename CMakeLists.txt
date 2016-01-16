cmake_minimum_required(
	VERSION
	2.8.12
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

include_directories(
	${fcppt_INCLUDE_DIRS}
)

include_directories(
	include
)

set(
	MAJUTSU_FILES
	include/majutsu/access_role.hpp
	include/majutsu/access_role_tpl.hpp
	include/majutsu/detail/all_initializers.hpp
	include/majutsu/detail/contains_initializer.hpp
	include/majutsu/detail/find_role.hpp
	include/majutsu/detail/find_role_deref.hpp
	include/majutsu/detail/flatten.hpp
	include/majutsu/detail/index_of.hpp
	include/majutsu/detail/init.hpp
	include/majutsu/detail/make_iterators.hpp
	include/majutsu/detail/tag_is_same.hpp
	include/majutsu/detail/wrapped_type.hpp
	include/majutsu/dispatch_type.hpp
	include/majutsu/dispatch_value.hpp
	include/majutsu/flatten.hpp
	include/majutsu/fusion/detail/expand_initlist.hpp
	include/majutsu/fusion/record.hpp
	include/majutsu/fusion/record_decl.hpp
	include/majutsu/fusion/record_fwd.hpp
	include/majutsu/fusion/record_impl.hpp
	include/majutsu/get.hpp
	include/majutsu/init.hpp
	include/majutsu/init_types.hpp
	include/majutsu/is_role.hpp
	include/majutsu/is_role_tag.hpp
	include/majutsu/make_role_tag.hpp
	include/majutsu/make_role_tag_arg.hpp
	include/majutsu/make_role_tag_arg_fwd.hpp
	include/majutsu/make_role_tag_fwd.hpp
	include/majutsu/raw/combine_static_sizes.hpp
	include/majutsu/raw/const_pointer.hpp
	include/majutsu/raw/constant.hpp
	include/majutsu/raw/constant_fwd.hpp
	include/majutsu/raw/data.hpp
	include/majutsu/raw/detail/copy_n.hpp
	include/majutsu/raw/detail/dynamic_size.hpp
	include/majutsu/raw/detail/init.hpp
	include/majutsu/raw/detail/init_constants.hpp
	include/majutsu/raw/detail/init_types.hpp
	include/majutsu/raw/detail/is_static_size.hpp
	include/majutsu/raw/detail/needs_init.hpp
	include/majutsu/raw/detail/store_decl.hpp
	include/majutsu/raw/detail/store_fwd.hpp
	include/majutsu/raw/detail/store_impl.hpp
	include/majutsu/raw/element_type.hpp
	include/majutsu/raw/extract_constant.hpp
	include/majutsu/raw/fundamental.hpp
	include/majutsu/raw/fundamental_decl.hpp
	include/majutsu/raw/fundamental_fwd.hpp
	include/majutsu/raw/integral_size.hpp
	include/majutsu/raw/is_constant.hpp
	include/majutsu/raw/is_static_size.hpp
	include/majutsu/raw/make.hpp
	include/majutsu/raw/make_generic.hpp
	include/majutsu/raw/needed_size.hpp
	include/majutsu/raw/needed_size_static.hpp
	include/majutsu/raw/place.hpp
	include/majutsu/raw/pointer.hpp
	include/majutsu/raw/record.hpp
	include/majutsu/raw/record_binding.hpp
	include/majutsu/raw/record_decl.hpp
	include/majutsu/raw/record_fwd.hpp
	include/majutsu/raw/record_impl.hpp
	include/majutsu/raw/record_variadic.hpp
	include/majutsu/raw/record_variadic_fwd.hpp
	include/majutsu/raw/size_type.hpp
	include/majutsu/raw/static_size.hpp
	include/majutsu/raw/stream/bind.hpp
	include/majutsu/raw/stream/istream.hpp
	include/majutsu/raw/stream/istream_fwd.hpp
	include/majutsu/raw/stream/memory.hpp
	include/majutsu/raw/stream/memory_fwd.hpp
	include/majutsu/raw/stream/read.hpp
	include/majutsu/raw/stream/reference.hpp
	include/majutsu/raw/stream/result.hpp
	include/majutsu/raw/stream/return.hpp
	include/majutsu/raw/stream/return_if.hpp
	include/majutsu/raw/write.hpp
	include/majutsu/role.hpp
	include/majutsu/role_fwd.hpp
	include/majutsu/role_init_decl.hpp
	include/majutsu/role_init_fwd.hpp
	include/majutsu/role_init_impl.hpp
	include/majutsu/role_return_type.hpp
	include/majutsu/role_tag.hpp
	include/majutsu/role_tag_decl.hpp
	include/majutsu/role_tag_fwd.hpp
	include/majutsu/role_tag_impl.hpp
	include/majutsu/role_value_type.hpp
	include/majutsu/set.hpp
	include/majutsu/unwrap_role.hpp
	include/majutsu/unwrap_role_tpl.hpp
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

set(
	FCPPT_UTILS_NO_TARGETS
	TRUE
)

fcppt_utils_generate_config(
	FALSE
)

install(
	DIRECTORY
	${FCPPT_UTILS_PROJECT_SOURCE_DIR}/include/
	DESTINATION
	${INSTALL_INCLUDE_DIR}
)
