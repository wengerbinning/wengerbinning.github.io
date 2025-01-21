L2TP协议是基于UDP的1701端口实现的.


* 02B - Flags


### Flags

* 01b - Type:
* 01b - Length Bit
* 02b - reserved
* 01b - Senuence Bit
* 01b - reserved
* 01b - Offset Bit
* 01b - Priority Bit
* 04b - Version

### Control Message

* 02B - Length
* 02B - Tunnel ID
* 02B - Session ID
* 02B - Ns
* 02B - Nr
* xxB - AVP options

### AVP option

* 02B - Flags and Length
* 02B - Reserved
* 02B - AVP Type

####

* 0x0000 - Control Message
* 0x0002 - Protocol Version
* 0x0003 - Framing Capabilities
* 0x0004 - Bearer Capabilities
* 0x0006 - Firmware Revision
* 0x0007 - Host Name
* 0x0008 - Vendor Name
* 0x0009 - Asssigned Tunnel ID
* 0x000a - Receive Windows Size

##### Control Message

##### Protocol Version

##### Framing Capabilities

##### Bearer Capabilities

##### Firmware Revision

##### Host Name

##### Vendor Name

##### Asssigned Tunnel ID

##### Receive Windows Size
