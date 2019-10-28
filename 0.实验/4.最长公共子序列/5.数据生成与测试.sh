#!/bin/bash

op=7

m=10
n=10
mul=5

touch input

for (( i=1; i<=op; i++ )) do
    echo $i
    echo $m $n > input
    data=$[$m*$n]

    echo M: $m N: $n M*N: $data
    g++ ./0.生成.cpp
    ./a.out < input > $data
    run $1 < $data

    m=$[$m*$mul]
    printf "\n"
done






