#!/bin/sh
#tests for the test command

echo "Test #1"
test -e /test/file/path

echo "Test #2"
[ -e /test/file/path ]

echo "Test #3"
test -f /test/file/path

echo "Test #4"
[ -f /test/file/path ]

echo "Test #5"
test -d /test/file/path

echo "Test #6"
[ -d /test/file/path ]

echo "Test #7"
test /test/file/path

echo "Test #8"
[ /test/file/path ]
