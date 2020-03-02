#! /bin/bash
if [[ $# -lt 2 || $# -gt 4 ]]; then 
    echo "Invocation:  ./add.sh integer integer [integer [integer]] " 
    exit 1 
fi
if [[ $# -eq 2 ]]; then 
    echo "$0 says the sum of $1 and $2 is $(($1 + $2))." 
elif [[ $# -eq 3 ]]; then 
    echo "$0 says the sum of $1, $2 and $3 is $(($1 + $2 + $3))." 
else 
    echo "$0 says the sum of $1, $2, $3 and $4 is $(($1 + $2 + $3 + $4))." 
fi
exit 0
