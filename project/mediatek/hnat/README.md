HNAT





HANT_DESC

```
15  entry
 3  filled
 5  crsn
 3  resv1
 4  sport
 1  resv2
 1  alg
 8  iface
 2  wdmaid
 2  rxid
16  bssid
 8  usr_info
16  tid
 4  fixedrate
 1  prior
 1  sp
 1  hf
 1  amsdu
19  resv3
16  magic_tag_protect
```

```
15  entry
 3  filled
 5  crsn
 3  resv1
 4  sport
 1  resv2
 1  alg
 8  iface
 2  wdmaid
 2  rxid
10  wcid
 6  bssid
20  resv5
16  magic_tag_protect
```

```
14  entry
 5  crsn
 4  sport
 1  alg
 8  iface
 3  filled
 1  resv
16  magic_tag_protect - Magic Tag Protect
 8  wdmaid
 2  rxid
10  wcid
 6  bssid
```


* crsn
    - 0x00
    - 0x01
    - 0x02
    - 0x03
    - 0x07
    - 0x08
    - 0x09
    - 0x0A
    - 0x0B
    - 0x0C
    - 0x0D
    - 0x0E
    - 0x0F
    - 0x10
    - 0x11
    - 0x12
    - 0x13
    - 0x14
    - 0x15
    - 0x16
    - 0x17
    - 0x18
    - 0x19
    - 0x1A
    - 0x1B
    - 0x1C

* Magic Tag Protect

    - 0x5678   HQOS
    - 0x6789   HNAT





```
http://vger.kernel.org/~davem/skb_data.html

```