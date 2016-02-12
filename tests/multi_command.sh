#!/bin/sh
#tests commands with ;, &&, or ||

echo "Our command shell is awesome!"; echo "You know it!" && echo "Drake"; ls grrr || echo "ls should not work and THIS STATEMENT SHOULD PRINT!"


