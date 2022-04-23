#!/bin/bash
make -s fclean
make -s all
make -s clean
make -s std
make -s clean
echo "Begin testing"
./containers > ft.out
./containers_std > std.out
diff ft.out std.out > diff.out
echo "End testing"
qt=$(($(wc -l < diff.out)))
echo "Number of differences (only 0 is acceptable): $qt"