SCRIPT_NAME=${0##*/}
SCRIPT_PATH=${0%/*}
BACK_SUFFIX=".back"

SOURCERC="${SCRIPT_PATH}/.sourcerc"

if [ -n "$1" ]; then
    USER=$1
    if [ -f "${SOURCERC}" ]; then
        sed -i${BACK_SUFFIX} "s/USER=.*$/USER=${USER}/g" $SOURCERC
    else
        echo "USER=${USER}" > $SOURCERC
else
    if [ -f $SOURCE ]; then
        sed -n '0,/USER=.*$/p' $SOURCERC
    else
        echo "no user."
    fi
fi

if [ -n "$2" ]; then
    EMAIL=$2
    echo "EMAIL=$EMAIL" >> $SOURCERC
else
    if [ -f $SOURCERC ]; then
        source $SOURCERC
    else
        echo "no email"
    fi
fi

echo $USER $EMAIL
