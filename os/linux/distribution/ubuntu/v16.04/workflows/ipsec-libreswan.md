

/etc/ipsec.conf
/etc/ipsec.d/







* `/etc/ipsec.conf`

```shell


conn vpn service0
	left=192.168.1.128


	right=192.168.1.100
	type=tunnel

	leftsubnets=192.168.70.0/24
	letfsourceip=192.168.70.1
	rightsubnets=192.168.80.0/24

	metric=60
	ikelifetime="28800"
	authby=secret
	auto=start
	ikev2=no
	rekey=yes
	keyingtries=10

	dpdaction=hold
	dpddelay==30
	dpdtimeout=120

	salifetime="3600"

	ike=aes256-sha2_256; modp2048

	phase2=esp
	phase2alg=aes256-sah2_256
	pfs=no

	leftupdown=/usr/lib/ipsec/_updown
```







