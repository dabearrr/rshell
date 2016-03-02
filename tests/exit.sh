#!/bin/sh
#tests exit and commands with exit

echo "Testing exit command"
echo "Now exiting......GOODBYE!"
exit

echo "Testing ls ; exit"
ls ; exit 

echo "Testing date ; ls && exit"
date ; ls && exit 

echo "Testing date ; ls && date || ls -lR ; exit "
date ; ls && date || ls -lR ; exit

echo "Testing date ; ls && cal ; date || ls -lR #exit"
date ; ls && cal ; date || ls -lR #exit

echo "Testing exit ; ls ; date ; cal"
exit ; ls ; date ; cal

echo "testing exit ; exit"
exit exit

echo "-------------------------------------------------"
echo "Test #8"
echo "Testing: test -e /test/file/path ; exit"
test -e /test/file/path ; exit
echo "-------------------------------------------------"

echo "Test #9"
echo "Testing: test -e /test/file/path && exit"
test -e /test/file/path && exit
echo "-------------------------------------------------"

echo "Test #10"
echo "Testing: exit test -e /test/file/path # ls"
exit test -e /test/file/path # ls
echo "-------------------------------------------------"

echo "Test #11"
echo "Testing: exit [ -e /test/file/path ] # ls "
exit [ -e /test/file/path ] # ls 
echo "-------------------------------------------------"

echo "Test #12"
echo "Testing: [ -e /test/file/path ] ; exit"
[ -e /test/file/path ] ; exit
echo "-------------------------------------------------"
