#!/bin/bash

# make sure obj subdirectory exists
mkdir -p obj

# First find various files
find src -name \*.c   >  obj/c_files.txt
find src -name \*.cpp >  obj/cpp_files.txt
find src -name \*.s   >  obj/s_files.txt

# now use fgrep to locate them (faster than repeated find)
ALLFILES=""
while [ "x$1" != "x" ] ; do
	EXTENSION="${1##*.}"
	FULLPATH=""
	case ${EXTENSION} in
	cpp)
		FULLPATH=$(fgrep /$1 obj/cpp_files.txt)
		;;
	c)
		FULLPATH=$(fgrep /$1 obj/c_files.txt)
		;;
	s)
		FULLPATH=$(fgrep /$1 obj/s_files.txt)
		;;
	esac
	if [ "x$FULLPATH" = "x" ] ; then
		echo "Cannot find file $1. Aborting." >&2
		exit 2
	fi
	ALLFILES="${ALLFILES}${FULLPATH} "
	shift
done
echo "${ALLFILES}"
