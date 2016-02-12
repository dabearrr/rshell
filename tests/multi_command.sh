#!/bin/sh
#tests commands with ;, &&, or ||

echo "Test #1"
echo "Our command shell is awesome!" ; echo "You know it!" && echo "Drake" ; ls grrr || 
echo "ls should not work and THIS STATEMENT SHOULD PRINT!"

echo "Test #2"
date ; date ; date ; echo "This should print date three times" && echo "This should also print"

echo "Test #3"
date ; date || echo "This should print" || echo "This should also print"

echo "Test #4"
date ; date && date ; echo "This should print" || echo "This should also print"

echo "Test #5"
date && echo "hello world" || echo "hello universe"
