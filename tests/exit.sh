#!/bin/sh
#tests exit and commands with exit

echo "Testing exit command"
echo "Now exiting......GOODBYE!"
exit

echo "Testing ls ; exit"
ls ; exit 

echo "Testing date ; ls && exit"
date ; ls && exit 

echo "Testing date ; ls && date || ls -lR"
date ; ls && date || ls -lR


