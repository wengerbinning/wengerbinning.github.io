Point-to-Point Tunneling Protocol

TCP:1723


* 02 - Length
* 02 - Message Type


1. 0x0001  Control Message


## Control Message

* 04 - Magic Cookie
* 02 - Control Message Type


0x0001 Start-Control-Connection-Request
0x0002 Start-Control-Connection-Reply
0x0007 Outgoing-Call-Request
0x0008 Outgoing-Call-Reply
0x000f Set-Link-Info


### Start-Control-Connection-Request

* 02 - Reserved
* 02 - Protocol Version
* 02 - Reserved
* 04 - Framing Capabilities
* 04 - Bearer Capabilities
* 02 - Maximum Channels
* 02 - Firmware Version
* 64 - Host Name
* 64 - Vendor Name

###  Start-Control-Connection-Reply

* 02 - Reserved
* 02 - Protocol Version
* 01 - Result Code
* 01 - Error Code
* 04 - Framing Capabilities
* 04 - Bearer Capibilities
* 02 - Maximum Channels
* 02 - Firmware Revision
* 64 - Host Name
* 64 - Vendor Name

### Outgoing-Call-Request

* 02 - Call ID
* 02 - Call Serial
* 04 - Minimum BPS
* 04 - Maximum BPS
* 04 - Bearer Type
* 04 - Framing Type
* 02 - Packet Receive Window Size
* 02 - Packet Processing Delay
* 02 - Phone Number Length
* 02 - Reserved
* 64 - Phone Number
* 64 - Subaddress

### Outgoing-Call-Reply

* 02 - Reserved
* 02 - Call ID
* 02 - Peer Call ID
* 01 - Result Code
* 01 - Error Code
* 02 - Cause Code
* 04 - Connect Speed
* 02 - Package Receive Window Size
* 02 - Package Processing Delay
* 04 - Physical Channel ID

### Set-Link-Info

* 02 - Reserved
* 02 - Peer Call ID
* 02 - Reserved
* 04 - Send ACCM
* 04 - Receive ACCM




