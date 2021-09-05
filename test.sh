for fn in `find ./tests -name "*.c"`; do
    eval " $1 $fn > ${fn%%.c}.eo 2> ${fn%%.c}.log"
done
