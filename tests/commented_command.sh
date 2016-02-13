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


