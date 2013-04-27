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
	include/majutsu/class.hpp
	include/majutsu/composite.hpp
	include/majutsu/concepts/dynamic_memory/make.hpp
	include/majutsu/concepts/dynamic_memory/needed_size.hpp
	include/majutsu/concepts/dynamic_memory/place.hpp
	include/majutsu/concepts/dynamic_memory/tag.hpp
	include/majutsu/concepts/static_memory/tag.hpp
	include/majutsu/concepts/static_size.hpp
	include/majutsu/const_raw_pointer.hpp
	include/majutsu/constant.hpp
	include/majutsu/constant_fwd.hpp
	include/majutsu/detail/copy_n.hpp
	include/majutsu/detail/find_role.hpp
	include/majutsu/detail/make_iterators.hpp
	include/majutsu/detail/unwrap_role.hpp
	include/majutsu/detail/wrapped_type.hpp
	include/majutsu/extract_constant.hpp
	include/majutsu/flatten.hpp
	include/majutsu/fundamental.hpp
	include/majutsu/integral_size.hpp
	include/majutsu/is_constant.hpp
	include/majutsu/is_role.hpp
	include/majutsu/memory/detail/expand_fusion_initlist.hpp
	include/majutsu/memory/detail/index_of.hpp
	include/majutsu/memory/detail/init_constants.hpp
	include/majutsu/memory/detail/init_fusion_element.hpp
	include/majutsu/memory/detail/init_raw_memory.hpp
	include/majutsu/memory/detail/store.hpp
	include/majutsu/memory/fusion.hpp
	include/majutsu/memory/init_count.hpp
	include/majutsu/memory/needs_init.hpp
	include/majutsu/memory/raw.hpp
	include/majutsu/placeholder.hpp
	include/majutsu/raw_data.hpp
	include/majutsu/raw_pointer.hpp
	include/majutsu/role.hpp
	include/majutsu/role_fwd.hpp
	include/majutsu/role_return_type.hpp
	include/majutsu/simple.hpp
	include/majutsu/size_type.hpp
)

fcppt_utils_add_source_groups(
	"${MAJUTSU_FILES}"
)

fcppt_utils_add_dummy_target(
	majutsu
	"${MAJUTSU_FILES}"
)

set(
	FCPPT_UTILS_NO_TARGETS
	TRUE
)

fcppt_utils_generate_config()

install(
	DIRECTORY
	${CMAKE_SOURCE_DIR}/include/
	DESTINATION
	${INSTALL_INCLUDE_DIR}
)
