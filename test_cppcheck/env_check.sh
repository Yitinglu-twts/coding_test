#!/bin/bash

CPPCHECK_OPTS="-I. --enable=all --error-exitcode=1 --suppress=missingIncludeSystem ."
CPPCHECK=$(which cppcheck)
if [ $? -ne 0 ]; then
    echo "[!] cppcheck not installed. Unable to perform static analysis." >&2
    exit 1
fi


# static analysis #>/dev/null
$CPPCHECK $CPPCHECK_OPTS
if [ $? -ne 0 ]; then
    echo "" >&2
    echo "Fail to pass static analysis." >&2
    echo
    exit 1
fi
exit 0
