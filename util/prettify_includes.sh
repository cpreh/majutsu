#!/bin/bash

if [[ $1 == 'run' ]]; then
	shift
	prettify_includes.py --reserved-prefix majutsu --reserved-prefix fcppt "$@" 2>>/tmp/prettify_errors
else
	find include test  \( \( -name '*.hpp' -o -name '*.cpp' \) \) | xargs $0 run
fi
