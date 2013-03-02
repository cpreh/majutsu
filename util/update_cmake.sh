#!/bin/sh

set -e -u

update_cmake \
	CMakeLists.txt \
	MAJUTSU_FILES \
	include
