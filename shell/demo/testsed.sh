SCRIPT_NAME=${0##*/}
SCRIPT_PATH=${0%/*}

FILE=${SCRIPT_PATH}/.info

info_update() {
    if [ -n "$1" ]; then
        local FILE=$1
    else
        echo 'no file.'
        exit
    fi

    if [ -n "$2" ]; then
        local KEY=$2
    else
        echo 'no key.'
        exit
    fi

    if [ -n "$3" ]; then
        local VALUE=$3
    else
        echo 'no value.'
        exit
    fi

    if [ -f "${FILE}" ]; then
        RESULT=$(sed -n "/${KEY}=.*$/p" ${FILE})
        if [ -n "$RESULT" ]; then
            sed -i.back "s/${RESULT}/${KEY}=${VALUE}/g" ${FILE}
        else
            cp "${FILE}" "${FILE}.back"
            echo "${KEY}=${VALUE}" >> ${FILE}
        fi
    else
        echo "${KEY}=${VALUE}" > ${FILE}
    fi
}

info_update $FILE "USER" "CLA4K"
