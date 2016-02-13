#!/bin/sh
#tests commands with ;, &&, or ||

echo "Test #1"
echo "Our command shell is awesome!" ; echo "You know it!" && echo "Drake" ; ls grrr || 
echo "ls should not work and THIS STATEMENT SHOULD PRINT!"

echo "Test #2"
date ; date ; date ; echo "This should print date three times" && echo "This should also print"

echo "Test #3"
date ; date || echo "This shouldn't print" || echo "This shouldn't also print"

echo "Test #4"
date ; date && date ; echo "This should print" || echo "This should also print"

echo "Test #5"
date && echo "hello world" || echo "hello universe"

echo "Test #6"
date ; echo "hello man whats up" ; echo "yo" && cal || date ; cal
echo "This should print date, echo, echo, cal, cal"

echo "Test #7"
date || echo "hello man whats up" && echo "yo" && cal && date ; cal
echo "This should print date, echo, cal, cal"

echo "Test #8"
date && echo "hello man whats up" || echo "yo" || cal || date ; cal
echo "This should print date, echo, cal"

echo "Test #9"
date && echo "hello man whats up" && echo "yo" && cal && date && cal
echo "This should print date, echo, echo, cal, date, cal"

echo "Test #10"
date || echo "hello man whats up" || echo "yo" || cal || date || cal
echo "This should print date"

echo "Test #11"
date ; echo "hello man whats up" ; echo "yo" ; cal || date ; cal
echo "This should print date, echo, echo, cal, cal"

echo "Test #12"
date ; echo "hello man whats up" ; echo "yo" && cal ; date ; cal
echo "This should print date, echo, echo, cal, date cal"
