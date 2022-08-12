#define PID_FILE "/var/run/xxxx.pid"

int lock_file(int fd) {
    struct flock fl;
    fl.l_type = F_WRLCK;
    fl.l_start = 0;
    fl.l_whence = SEEK_SET;
    fl.l_len = 0;

    return (fcntl(fd, F_SETLK, &fl));
}

int alone_runnind(void) {
    int fd;

    char buf[16];

    fd = open(PID_FILE, O_RDWR | O_CREAT, 0666);

    if (fd < 0) {
        perror("open");
        exit(1);
    }

    if (lock_file(fd) < 0) {
        if (errno == EACCESS || errno == EAGAIN) {
            close(fd);
            printf("alone runnind\n");
            return -1;
        }
        printf("can't lock %s: %s\n", PID_FILE, strerror(errno));
    }
 
    ftruncate(fd, 0); //设置文件的大小为0

    sprintf(buf, "%ld", (long)getpid());

    write(fd, buf, strlen(buf) + 1);

    return 0;
}

