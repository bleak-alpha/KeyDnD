#!/bin/bash

# store the list of current processes in a variable
before=$(ps -e)

# wait for a period of time
sleep 5

# store the list of processes after the wait period
after=$(ps -e)

# compare the two lists and print the new processes
echo "New processes:"
echo "$after" | grep -Fvx "$before"