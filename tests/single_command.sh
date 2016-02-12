#!/bin/bash
#tests single commands

if ! ls '/var/aaaaaaa' &> /dev/null; then 
  echo 'failed'
fi

if ls ~/rshell/tests > /dev/null 2>&1
then
    echo "There is at least one match (maybe more)!"
else
    echo "No files found"
fi
