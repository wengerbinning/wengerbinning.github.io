#!/bin/bash

index=1

for param in "$@"; do
    if [ -n "$skip_param" ]; then unset skip_param; continue; fi
    case "$param" in
        --*)
	   echo $index: \"$param\"
	;;
        -*)
		shift
		echo $index: \"$param\"="$1"
		skip_param=1
        ;;
        *)
            echo $index: \"$param\"
        ;;
    esac
    index=$(($index+1)); shift
done
