#!/bin/bash -e

for fn in `find ../tests -name "*.c"`; do
    CTOEO=$(eval " realpath $1")
    FILE=$(eval " realpath ${fn}")
    NAME="${fn##*/}"
    eval "  mkdir ${FILE%%.c}"
    eval " ${CTOEO} ${FILE} -o ${FILE%%.c}/eo -- > ${FILE%%.c}/${NAME%%.c}.details 2>${FILE%%.c}/${NAME%%.c}.log"
    eval " gcc "
    eval " gcc ${FILE} -o ${FILE%%.c}/${NAME%%.c}.out -w"
    eval " ${FILE%%.c}/${NAME%%.c}.out > ${FILE%%.c}/${NAME%%.c}.res_c"
    # TODO: generate ${FILE%%.c}/pom.xml, ${FILE%%.c}/eo/var.eo, ${FILE%%.c}/eo/operations.eo, ${FILE%%.c}/run.sh
    eval " mvn -f ${FILE%%.c} clean compile"
    eval " ${FILE%%.c}/run > ${FILE%%.c}/${NAME%%.c}.res_eo"
    eval " diff -a ${FILE%%.c}/${NAME%%.c}.res_c ${FILE%%.c}/${NAME%%.c}.res_eo > ${FILE%%.c}/${NAME%%.c}.diff"
done

for diff in `find ../tests -name "*.diff"`; do
    TEST=$(eval " realpath ${diff}")
    if [ -s $diff ]; then
            # The file is not-empty.
            printf "\033[0;31m${TEST}"
    else
            # The file is empty.
            printf "\033[0;32m${TEST}"
    fi
done
