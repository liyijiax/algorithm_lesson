#!/bin/bash

op=1

m=10
n=100
mul=5

touch input

for (( i=1; i<=op; i++ )) do
    echo $i
    echo $m $n > input
    data=$[$m*$n]
    touch $data
    echo $m $n  > $data
    echo M: $m N: $n M*N: $data
    g++ ./0.生成.cpp
    ./a.out < input >> $data
    run $1 < $data
    run $2 < $data
    run $3 < $data
    run $4 < $data

    m=$[$m*$mul]
    n=$[$n*$mul]
    printf "\n"
done






