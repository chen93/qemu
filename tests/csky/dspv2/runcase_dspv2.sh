#!/bin/sh

num_total=0
num_fail=0

make
cd case
for file in *.elf
do
    cmd="qemu-system-cskyv2 -machine smartl -kernel $file -nographic"
    $cmd
    if [ $? -ne 0 ]
    then
        num_fail=`expr $num_fail + 1`
    fi
    num_total=`expr $num_total + 1`
done

echo "\n------sumary------"
echo "Total  case: $num_total"
echo "Failed case: $num_fail"
echo "------------------\n"

cd ..
make clean
