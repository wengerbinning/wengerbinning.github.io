TFTP(Trivial File Transfer Protocol)是基于UDP实现的一个简单应用协议,

服务端口: 69



    opcode, filename, 0, mode, 0



opcode: 1(RRQ), 2(WRQ), 3(DATA), 4(ACK), 5(ERROR)


mode: netascii/octet/mail