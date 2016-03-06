#!/bin/sh
#tests for precedence operators 

echo "-------------------------------"
echo "Test # 1"
echo "-------------------------------"

echo "Testing phrase: ((echo a) && (echo b && echo c))"
((echo a) && (echo b && echo c))

echo "-------------------------------"
echo "Test # 2"
echo "-------------------------------"

echo "Testing phrase: (echo a && (echo b && echo c))"
(echo a && (echo b && echo c))

echo "-------------------------------"
echo "Test # 3"
echo "-------------------------------"

echo "Testing phrase: echo a && (date && cal)"
echo a && (date && cal)

echo "-------------------------------"
echo "Test # 4"
echo "-------------------------------"

echo "Testing phrase: (((date) && (echo b && echo c)) ; cal )"
(((date) && (echo b && echo c)) ; cal )

echo "-------------------------------"
echo "Test # 5"
echo "-------------------------------"

echo "Testing phrase: echo a && echo b && (echo c)"
echo a && echo b && (echo c)

echo "-------------------------------"
echo "Test # 6"
echo "-------------------------------"

echo "Testing phrase: (echo a) && (echo b && echo c)"
(echo a) && (echo b && echo c)

echo "-------------------------------"
echo "Test # 7"
echo "-------------------------------"

echo "Testing phrase: (echo a && (echo b && echo c)"
(echo a && (echo b && echo c))

echo "-------------------------------"
echo "Test # 8"
echo "-------------------------------"

echo "Testing phrase: ((echo a) && (echo b && echo c))))"
((echo a) && (echo b && echo c))

echo "-------------------------------"
echo "Test # 9"
echo "-------------------------------"

echo "Testing phrase: ((echo a) || (echo b || echo c))"
((echo a) || (echo b || echo c))

echo "-------------------------------"
echo "Test # 10"
echo "-------------------------------"

echo "Testing phrase: ((echo a) ; (echo b || echo c))"
((echo a) ; (echo b || echo c))

echo "-------------------------------"
echo "Test # 11"
echo "-------------------------------"

echo "Testing phrase: ((echo a) || (echo b && echo c))"
((echo a) || (echo b && echo c))

echo "-------------------------------"
echo "Test # 12"
echo "-------------------------------"

echo "Testing phrase: ((echo a) ; (echo b ; echo c))"
((echo a) ; (echo b ; echo c))

echo "-------------------------------"
echo "Test # 13"
echo "-------------------------------"

echo "Testing phrase: ((echo a) ; (echo b || echo c))"
((echo a) ; (echo b || echo c))

echo "-------------------------------"
echo "Test # 14"
echo "-------------------------------"

echo "Testing phrase: (echo a || (echo b || echo c))"
(echo a || (echo b || echo c))

echo "-------------------------------"
echo "Test # 15"
echo "-------------------------------"

echo "Testing phrase: (date && (echo b || echo c))"
(date && (echo b || echo c))

echo "-------------------------------"
echo "Test # 16"
echo "-------------------------------"

echo "Testing phrase: ((echo a) && (echo b && echo c))"
((echo a) && (echo b && echo c))

echo "-------------------------------"
echo "Test # 17"
echo "-------------------------------"

echo "Testing phrase: ((echo a) || (echo b ; echo c))"
((echo a) || (echo b ; echo c))
