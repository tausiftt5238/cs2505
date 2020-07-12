#! /bin/bash

sum=0 

if [[ $# -eq 0 ]]; then
    echo "Nothing to add"
    exit 
fi

for x; do # if you don't put "in LIST", it defaults to "in $@", which is the position parameter list
    echo " $x"
    sum=$(($sum + $x));
done 
echo "sum: $sum"

exit 0