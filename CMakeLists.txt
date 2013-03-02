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

set(
	FCPPT_UTILS_NO_TARGETS
	TRUE
)

fcppt_utils_generate_config()

install(
	DIRECTORY
	${CMAKE_SOURCE_DIR}/include
	DESTINATION
	${INSTALL_INCLUDE_DIR}
)
