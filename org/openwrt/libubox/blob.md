BLOB(Binary Large Object)二进制大对象，用于二进制对象序列化。是libubox中提供的疏解结构。


```c
struct blob_attr {
    uint32_t id_len;
	char data[];
};


struct blob_buf {
	struct blob_attr *head;
	bool (*grow)(struct blob_buf *buf, int minlen);
	int buflen;
	void *buf;
};

```


BLOBMSG是基于blob之上的提供一种数据表格与数组的处理能力。