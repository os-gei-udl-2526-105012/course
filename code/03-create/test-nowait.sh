#!/bin/bash
max=100
n_failed=0
n_passed=0
EXPECTED=$(./bin/no-wait2)
for i in `seq 1 $max`
do
    TEST=$(./bin/no-wait2 &)
    if [ "$TEST" != "$EXPECTED" ]
    then
        n_failed=`expr $n_failed + 1`
    else
        n_passed=`expr $n_passed + 1`
    fi
done

echo "passed: $n_passed out of $max."
echo "failed: $n_failed out of $max."

