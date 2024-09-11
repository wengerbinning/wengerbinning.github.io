
openssl genrsa -out private.pem 2048

openssl genpkey -algorithm RSA -out private.pem
openssl rsa -in private.pem -pubout -out public.pem
openssl rsa -in private.key -pubout > public.key


openssl -sign -inkey private.pem -in message.txt -out message.sig
openssl dgst -verify public.pem -signature message.sig message.txt





openssl dgst -hex -sign private.pem message.txt
openssl dgst -sign private.pem -out message.sig message.txt

openssl base64 -in message.sig -out message.base64
cat message.base64 | base64 -d > message.sig

openssl dgst -verify public.pem -signature message.sig message.txt



openssl genrsa -out gwn_firmware_private 2048
openssl rsa -in gwn_firmware_private -pubout -out gwn_firmware_public


openssl dgst -sign gwn_firmware_private -sha1 -hex boot.img
openssl dgst -sign gwn_firmware_private -sha1 -out boot.sig boot.img
openssl dgst -verify gwn_firmware_public -sha1 -signature boot.sig boot.img

openssl dgst -sign gwn_firmware_private -sha1 -hex base.img
openssl dgst -sign gwn_firmware_private -sha1 -out base.sig base.img
openssl dgst -verify gwn_firmware_public -sha1 -signature base.sig base.img

openssl dgst -sign gwn_firmware_private -sha1 -hex core.img
openssl dgst -sign gwn_firmware_private -sha1 -out base.sig core.img
openssl dgst -verify gwn_firmware_public -sha1 -signature core.sig core.img

# SHA256
openssl dgst -sign gwn_firmware_private -sha1 -hex boot.img
openssl dgst -sign gwn_firmware_private -sha1 -out boot.sig boot.img
openssl dgst -verify gwn_firmware_public -sha1 -signature boot.sig boot.img

    openssl dgst -sign gwn_firmware_private -hex base.img
openssl dgst -sign gwn_firmware_private -out base.sig base.img
openssl dgst -verify gwn_firmware_public -signature base.sig base.img


openssl dgst -sign gwn_firmware_private -hex core.img
openssl dgst -sign gwn_firmware_private -out base.sig core.img
openssl dgst -verify gwn_firmware_public -signature core.sig core.img