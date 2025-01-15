基于 GRE 协议

* 01B - Address
* 01B - Control
* 02B - Protocol

### Protocol

* 0xc021 - Link Control Protocols
* 0xc223 - Challenge Handshake Authentication Protocol
* 0x8021 - Internet Protocol Control Protocol
* 0x8057 - IPv6 Control Protocol
* 0x80fd - Compression Control Protocol

## PPP LCP(Link Control Protocol)

* 01B - Code
* 01B - Identifier
* 02B - Length
* xxB - Options

### Code

* 0x01 - Configuration Request
* 0x02 - Configuration Ack
* 0x04 - Configuration Reject
* 0x09 - Echo Request
* 0x0a - Echo Reply

### Option

* 01B - Type
* 02B - Length
* xxB - Value

#### Type

* 0x01 - Maximum Receive Unit: length is 4
* 0x02 - Async Control Character Map: length is 6
* 0x03 - Authentication Protocol: length is 5
* 0x05 - Magic Number: length is 6
* 0x07 - Protocol Field Compression
* 0x08 - Address and Control Field Compression

## PPP CHAP(Challenge Handshake Authetication Protocol)

* 01B - Code
* 01B - Identifier
* 02B - Length
* xxB - Data

### Code

* 0x01 - Challenge
* 0x02 - Response
* 0x03 - Success

## PPP IPCP(Internet Protocol Control Protocol)

* 01B - Code
* 01B - Identifier
* 02B - Length

## PPP IPV6CP(IPv6 Control Protocol)

* 01B - Code
* 01B - Identifier
* 02B - Length

## PPP CCP(Compression COntrol Protocol)

* 01B - Code
* 01B - Identifier
* 02B - Length

### Code

* 0x01 - Configuration Request
* 0x02 - Configuration Ack
