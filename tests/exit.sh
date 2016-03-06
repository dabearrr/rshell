#!/bin/sh
#tests exit and commands with exit

echo "Testing exit command"
echo "Now exiting......GOODBYE!"
exit

./rshell

echo "Testing ls ; exit"
ls ; exit 
./rshell
echo "Testing date ; ls && exit"
date ; ls && exit 
./rshell
echo "Testing date ; ls && date || ls -lR ; exit "
date ; ls && date || ls -lR ; exit
./rshell
echo "Testing date ; ls && cal ; date || ls -lR #exit"
date ; ls && cal ; date || ls -lR #exit

echo "Testing exit ; ls ; date ; cal"
exit ; ls ; date ; cal
./rshell
echo "testing exit ; exit"
exit exit
./rshell
echo "-------------------------------------------------"
echo "Test #8"
echo "Testing: test -e /test/file/path ; exit"
test -e /test/file/path ; exit
echo "-------------------------------------------------"
./rshell
echo "Test #9"
echo "Testing: test -e /test/file/path && exit"
test -e /test/file/path && exit
echo "-------------------------------------------------"
./rshell
echo "Test #10"
echo "Testing: exit test -e /test/file/path # ls"
exit test -e /test/file/path # ls
echo "-------------------------------------------------"
./rshell
echo "Test #11"
echo "Testing: exit [ -e /test/file/path ] # ls "
exit [ -e /test/file/path ] # ls 
echo "-------------------------------------------------"
./rshell
echo "Test #12"
echo "Testing: [ -e /test/file/path ] ; exit"
[ -e /test/file/path ] ; exit
echo "-------------------------------------------------"
./rshell
echo "Test #13"
echo "Testing: echo a && (echo B && echo c) ; exit"
echo a && (echo B && echo c) ; exit
echo "----------------------------------------------"
./rshell
echo "Test #14"
echo "Testing: echo a && (echo B && echo c) ; exit"
echo a && (echo B && echo c) ; exit
echo "----------------------------------------------"
./rshell
echo "Test #15"
echo "Testing: exit ; echo a && (echo B && echo c) #ls"
exit ; echo a && (echo B && echo c) #ls
echo "----------------------------------------------"
./rshell
echo "Test #16"
echo "Testing: echo a && exit && (echo B && echo c) #date "
echo a && exit && (echo B && echo c) #date
echo "----------------------------------------------"
./rshell
echo "Test #17"
echo "Testing: echo a && (echo B) #ls && echo c) #date ; exit"
echo a && (echo B) #ls && echo c) #date ; exit
echo "----------------------------------------------"
echo "Test #18"
echo "Testing: # exit ; clear echo a && (echo B && echo c) #date "
# exit ; clear echo a && (echo B && echo c) #date
echo "----------------------------------------------"
echo "Test #12"
echo "Testing: echo a && (echo B && echo c) || exit"
echo a && (echo B && echo c) || exit
echo "----------------------------------------------"
./rshell

