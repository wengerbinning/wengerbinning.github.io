基于TCP协议的1723端口


固定字段(12B)

* 02B - Length
* 02B - Message Type
* 04B - Magic Cookie
* 02B - Control Message Type
* 02B - Reserved

### Message Type

* 0001 - Control Message

#### Control Message Type

* 0x0001 - Start Control Connection Request
* 0x0002 - Start Control Connection Reply
* 0x0005 - Echo Request
* 0x0006 - Echo Reply
* 0x0007 - Outgoing Call Request
* 0x0008 - Outgoing Call Reply
* 0x000c - Call Clear Request

##### Start Control Connection Request

* 02B - Protocol version
* 02B - Reserved
* 04B - Frame Capabilities
* 04B - Bearer Capabiliites
* 02B - Maximum Channels
* 02B - Firmware Revision
* 64B - Host Name
* 64B - Vendor Name


##### Start Control Connection Reply

* 02B - Protocol version
* 01B - Result Code
* 01B - Error Code
* 04B - Frame Capabilities
* 04B - Bearer Capabiliites
* 02B - Maximum Channels
* 02B - Firmware Revision
* 64B - Host Name
* 64B - Vendor Name

#### Echo Request

* 04B - Identifier

#### Echo Reply

* 04B - Identifier
* 01B - Result Code
* 01B - Error Code
* 02B - Reserved

##### Outgoing Call Request

* 02B - Call ID
* 02B - Call Serial Number
* 04B - Minumum BPS
* 04B - Maximum BPS
* 04B - Bearer Type
* 04B - Framing Type
* 02B - Packet Receive Windows Size
* 02B - Packet Processing Delay
* 02B - Phone Number Length
* 02B - Reserved
* 64B - Phone Number
* 64B - Subaddress

##### Outgoing Call Reply

* 02B - Call ID
* 02B - Peer Call ID
* 01B - Result Code
* 01B - Error Code
* 02B - Cause Code
* 04B - Connect Speed
* 02B - Packet Receive Windows Size
* 02B - Packet Packet Processing Delay
* 04B - Phsical Channel ID