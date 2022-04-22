make -s fclean
make -s all
make -s clean
make -s std
make -s clean
echo "Begin testing"
./containers > ft.out
./containers_std > std.out
diff ft.out std.out > diff.out
cat diff.out
echo "End testing"
#echo -n "Number of differences: "
#wc -l $(`cat diff.out | grep "<"`)
# wc -l diff.out