#!/bin/sh
#tests commands with comments

echo "Test #1"
echo "Testing ls -a with ls before # -a"
ls # -a
echo "successfully outputted ls without -a flag"

echo"Test #2"
echo"testing ls -lR with the ls before # -lR"
ls # -lR
echo "Successfully outputted ls without -lR flag"

echo "Test #3"
echo "testing ls # clear, should not clear!"
ls #clear

echo "Test #4"
echo "testing #ls , should do nothing!"
#ls
echo "Ls not displayed successful!"

echo "Test #5"
echo "Testing ls; date #cal : this should output ls and date and no cal"
ls; date #cal

echo "Test #6"
echo "testing #ls #ls ; date"
# ls # ls ; date

echo "-------------------------------------------------"
echo "Test #7"
echo "Testing: test -e /test/file/path # ls"
test -e /test/file/path # ls
echo "-------------------------------------------------"

echo "Test #8"
echo "Testing: # test -e /test/file/path # ls"
# test -e /test/file/path # ls
echo "-------------------------------------------------"

echo "Test #9"
echo "Testing: test -e /test/file/path # ls"
test -e /test/file/path # ls
echo "-------------------------------------------------"

echo "Test #10"
echo "Testing: [ -e /test/file/path ] # ls "
[ -e /test/file/path ] # ls 
echo "-------------------------------------------------"

echo "Test #11"
echo "Testing: # [ -e /test/file/path ] # ls"
# [ -e /test/file/path ] # ls
echo "-------------------------------------------------"

echo "Test #12"
echo "Testing: echo a && (echo B && echo c) #date"
echo a && (echo B && echo c) #date

echo "Test #13"
echo "Testing: # echo a && (echo B && echo c) #date "
# echo a && (echo B && echo c) #date

echo "Test #14"
echo "Testing: echo a #ls && (echo B && echo c) #date"
echo a #ls && (echo B && echo c) #date

echo "Test #15"
echo "Testing: echo a && (echo B && echo c) #ls"
echo a && (echo B && echo c) #ls

echo "Test #16"
echo "Testing: echo a && (echo B && echo c) #date "
echo a && (echo B && echo c) #date

echo "Test #17"
echo "Testing: echo a && (echo B) #ls && echo c) #date"
echo a && (echo B) #ls && echo c) #date

echo "Test #18"
echo "Testing: #clear echo a && (echo B && echo c) #date "
#clear echo a && (echo B && echo c) #date
