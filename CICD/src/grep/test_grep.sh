SUCCESS=0
FAIL=0
DIFF_RES=""
echo "" > log.txt

declare -a tests=(
"bsn test.txt VAR"
"VAR qwe test.txt"
"qwe VAR test.txt patterns.txt"
"VAR -e 123 -e qwe test.txt patterns.txt"
"VAR -f patterns.txt test.txt"
"-f patterns.txt VAR test.txt test2.txt"
)

declare -a plus_tests=(
"-lc qwe test.txt patterns.txt"
"-e 'sd\|e' test.txt"
"test.txt -e qwe -f patterns.txt"
"test.txt -e qwe -iv"
"test.txt -e qwe -in"
)

testing()
{
    t=$(echo $@ | sed "s/VAR/$var/")
    ./s21_grep $t > test_s21_grep.txt 2>&1
    grep $t > test_grep.txt 2>&1

    if [ -z "$(diff -q test_s21_grep.txt test_grep.txt)" ]
    then
        (( SUCCESS++ ))
        #echo "$t"
    else
        (( FAIL++ ))
        echo "$t" >> log.txt
    fi
    rm test_s21_grep.txt test_grep.txt
}



for var1 in i v c l n h o
do
    for i in "${tests[@]}"
    do
        var="-$var1"
        testing $i
    done
done


for var1 in i v c l n h o
do
    for var2 in i v c l n h o
    do
        if [ $var1 != $var2 ]
        then
            for i in "${tests[@]}"
            do
                var="-$var1 -$var2"
                testing $i
            done
        fi
    done
done

# for var1 in i v c l n h o
# do
#     for var2 in i v c l n h o
#     do
#         for var3 in i v c l n h o
#         do
#             if [ $var1 != $var2 ] && [ $var2 != $var3 ] && [ $var1 != $var3 ]
#             then
#                 for i in "${tests[@]}"
#                 do
#                     var="-$var1 -$var2 -$var3"
#                     testing $i
#                 done
#             fi
#         done
#     done
# done

# for i in "${plus_tests[@]}"
# do
#     var="-"
#     testing $i
# done

echo "FAIL: $FAIL"
echo "SUCCESS: $SUCCESS"

