


#### json_object_from_file

```c
/* json_util.c */

struct json_object *json_object_from_file (const char *filename)
{
  struct printbuf *pb;
  struct json_object *obj;
  char buf[JSON_FILE_BUF_SIZE];
  int fd, ret;

  if ((fd = open(filename, O_RDONLY)) < 0) {
    MC_ERROR("json_object_from_file: error opening file %s: %s\n", filename, strerror(errno));
    return NULL;
  }
  if (!(pb = printbuf_new())) {
    close(fd);
    MC_ERROR("json_object_from_file: printbuf_new failed\n");
    return NULL;
  }

  while((ret = read(fd, buf, JSON_FILE_BUF_SIZE)) > 0) {
    printbuf_memappend(pb, buf, ret);
  }
  
  close(fd);
  if(ret < 0) {
    MC_ERROR("json_object_from_file: error reading file %s: %s\n", filename, strerror(errno));
    printbuf_free(pb);
    return NULL;
  }
  
  obj = json_tokener_parse(pb->buf);
  printbuf_free(pb);

  return obj;
}
```