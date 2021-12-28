#!/bin/bash

while [ "x$1" != "x" ] ; do
	mkdir -p $(dirname $1)
	shift
done
