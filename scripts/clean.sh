for fn in `find ../tests -name "*.eo"`; do
    eval " rm -v $fn"
done

for fn in `find ../tests -name "*.log"`; do
    eval " rm -v $fn"
done
