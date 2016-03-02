#!/bin/sh
#tests for precedence operators

echo "-----------------------------"
echo "Test #1"
echo "-----------------------------"

echo "Without precedence for this phrase: echo A && echo B || echo C && echo D"
echo A && echo B || echo C && echo D

echo "With precedence operators for this phrase: (echo A && echo B) || echo (C && echo D)"
(echo A && echo B) || (echo C && echo D)

echo "------------------------------"
echo "Test #2"
echo "------------------------------"

echo "Without precedence for this phrase: echo A && echo B || echo C && echo D"
echo A && echo B || echo C && echo D

echo "With precedence operators for this phrase: (echo A) && echo B || (echo C) && echo D"
(echo A) && echo B || (echo C) && echo D

echo "------------------------------"
echo "Test #3"
echo "------------------------------"

echo "With precedence for this phrase: date ; ((cal && echo C) || (echo D))"
date ; ((cal && echo C) || (echo D))

echo "Without precedence operators for this phrase: date ; cal && echo C || echo D"
date ; cal && echo C || echo D
