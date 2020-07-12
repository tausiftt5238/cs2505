#! /bin/bash

if [[ $# -ne 2 ]]; then
    echo "invocation: ./add.sh integer integer"
    exit 1
fi 

left=$1
right=$2 

sum=$((left+right))

echo "$0 says the sum of $left and $right is $sum."