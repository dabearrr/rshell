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


