if [ -z $STR ]; then
    echo STR not exist!
fi
export STR=demo
if [ -n $STR ]; then
    echo $STR
fi
unset STR
if [ -n $STR ]; then
    echo STR not delete!
fi
