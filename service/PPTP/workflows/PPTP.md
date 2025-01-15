基于TCP协议


* 02B - Length
* 02B - Message Type
* 04B - Magic Cookie
* 02B - Control Message Type
* 02B - Reserved
* 02B - Protocol version
* 02B - Reserved
* 04B - Frame Capabilities
* 04B - Bearer Capabiliites
* 02B - Maximum Channels
* 02B - Firmware Revision
* 64B - Host Name
* 64B - Vendor Name

## Message Type

* 0001 - Control Message

### Control Message Type

* 0x0001 - Start Control Connection Request
* 0x0002 - Start Control Connection Reply
* 0x0007 - Outgoing Call Request
* 0x0008 - Outgoing Call Reply
* 0x000c - Call Clear Request


