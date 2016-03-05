#!/bin/sh
#tests for the test command

echo "Following test cases should result in: NOT FOUND"

echo "Test #1"
if test -e /test/file/path ; then
	   echo "Yes, found!"
else
	   echo "Not found!"
fi

echo "Test #2"
if [ -e /test/file/path ] ; then
	  echo "Yes, found!"
else
	  echo "Not found!"
fi

echo "Test #3"
if test -f /test/file/path ; then
	   echo "Yes, found!"
else
	   echo "Not found!"
fi

echo "Test #4"
if [ -f /test/file/path ] ; then
	  echo "Yes, found!"
else
	  echo "Not found!"
fi

echo "Test #5"
if test -d /test/file/path ; then
	   echo "nope failed test!"
else
	   echo "right result!!!"
fi

echo "Test #6"
if [ -d /test/file/path ] ; then
	  echo "No not correct !"
else
	  echo "Right result!!"
fi

echo "Test #7"
if test -e /hello_world/path ; then
	   echo "Yes, found!"
else
	   echo "Not found!"
fi

echo "Test #8"
if [ -e /Hello_world/file/path ] ; then
	  echo "Yes, found!"
else
	  echo "Not found!"
fi

echo "-------------------------------------------"

echo "Following test cases should result in: YES, FOUND"

echo "Test #9"
if test -e ../tests/test_test.sh ; then
	   echo "Yes, found!"
else
	   echo "Not found!"
fi

echo "Test #10"
if [ -e ../tests/test_test.sh ] ; then
	  echo "Yes, found!"
else
	  echo "Not found!"
fi

echo "Test #11"
if test -f ../tests/test_test.sh ; then
	   echo "Yes, found!"
else
	   echo "Not found!"
fi

echo "Test #12"
if [ -f ../tests/test_test.sh ] ; then
	  echo "Yes, found!"
else
	  echo "Not found!"
fi

echo "Test #13"
if test -d ../tests/test_test.sh ; then
	   echo "Not, Not correct!"
else
	   echo "Yes correct!"
fi

echo "Test #14"
if [ -d ../tests/test_test.sh ] ; then
	  echo "No, not correct!"
else
	  echo "Yes, correct!"
fi

echo "Test #15"
if test ../tests/test_test.sh ; then
	   echo "Yes, found!"
else
	   echo "Not found!"
fi

echo "Test #16"
if [ ../tests/test_test.sh ] ; then
	  echo "Yes, found!"
else
	  echo "Not found!"
fi

echo "-----------------------------------------------"



