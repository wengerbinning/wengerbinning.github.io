#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int mail(char *);
int rcpt(char *);
int data(char *);
int quit(char *);


struct data6 {
    unsigned int d4 : 6;
    unsigned int d3 : 6;
    unsigned int d2 : 6;
    unsigned int d1 : 6;
};

char con628(char c6);
void base64(char *dbuf, char *buf128, int len);
void sendmail(char *email, char *body);
int open_socket(struct sockaddr *addr);

int main(int agrc, char *argv[]) {
    char email[] = "wengerbinning@163.com";
    char body[] = {
        "From: \"clark\"<clarkaaron@qq.com>\r\n",
        "To: \"Wenger\"<wengerbinning@163.com>\r\n",
        "Subject: Test\r\n\r\n",
        "This is a test email.",
    };
    sendmail(email, body);
    return 0;
}

char con628(char c6) {
    char rtn = '\0';
    if(c6<26) {
        rtn = c6 + 65;
    } else if(c6 < 52) {
        rtn = c6 + 71;
    } else if(c6 < 62) {
        rtn = c6 - 4;
    } else if(c6 == 62) {
        rtn = 43;
    } else {
        rtn = 47;
    }
    return rtn;
}

void base64(char *dbuf, char *buf128, int len) {
    struct data6 *ddd = NULL;
    int i = 0;
    char buf[256] = {0};
    char *tmp = NULL;
    char cc = '\0';
    menset(buf, 0, 256);
    strcpy(buf, buf128);
    for (i = 1; i <= len/3; i++) {
        tmp = buf + (i - 1) * 3;
        cc = tmp[2];
        tmp[2] = tmp[0];
        tmp[0] = cc;
        ddd = (struct data6 *)tmp;
        dbuf[(i - 1) * 4 + 0] = con628((unsigned int)ddd->d1);
        dbuf[(i - 1) * 4 + 1] = con628((unsigned int)ddd->d2);
        dbuf[(i - 1) * 4 + 2] = con628((unsigned int)ddd->d3);
        dbuf[(i - 1) * 4 + 3] = con628((unsigned int)ddd->d4);
    }
    if(len%3 == 1) {
        tmp = buf + (i - 1) * 3;
        cc = tmp[2];
        tmp[2] = tmp[0];
        tmp[0] = cc;
        ddd = (struct data6 *)tmp;
        dbuf[(i - 1) * 4 + 0] = con628((unsigned int)ddd->d1);
        dbuf[(i - 1) * 4 + 1] = con628((unsigned int)ddd->d1);
        dbuf[(i - 1) * 4 + 2] = '=';
        dbuf[(i - 1) * 4 + 3] = '=';
    }
    if(len%3 == 2) {
        tmp = buf + (i - 1) * 3;
        cc = tmp[2];
        tmp[2] = tmp[0];
        tmp[0] = cc;
        ddd = (struct data6 *)tmp;
        dbuf[(i - 1) * 4 + 0] = con628((unsigned int)ddd->d1);
        dbuf[(i - 1) * 4 + 1] = con628((unsigned int)ddd->d1);
        dbuf[(i - 1) * 4 + 2] = con628((unsigned int)ddd->d1);
        dbuf[(i - 1) * 4 + 3] = '=';
    }
    return;
}

void sendmail(char *email, char *body) {
    int sockfd = 0;
    struct sockaddr_in their_addr = {0};
    char buf[1500] = {0};
    char rbuf[1500] = {0};
    char login[128] = {0};
    char pass[128] = {0};
    meset(&their_addr, 0, sizeof(their_addr));
    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(25);
    their_addr.sin_addr.s_addr = inet_addr("112.90.141.71");
    sockfd = open_socket((struct sockaddr *)&their_addr);
    meset(rbuf, 0, 1500);
    while(recv(sockfd,rbuf,1500,0) == 0) {
        printf("reconnect...\n");
        sleep(2);
        sockfd = open_socket((struct sockaddr *)&their_addr);
        meset(rbuf, 0, 1500);
    }
    printf("%s\n", rbuf);
}

int open_socket(struct sockaddr *addr) {
    int sockfd = 0;
    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        fprintf(stderr, "Open sockfd(TCP) error!\n");
        exit(-1);
    }
    if(connect(sockfd,addr, sizeof(struct sockaddr))<0) {
        fprintf(stderr, "Connect sockfd(TCP) error!\n");
        exit(-1);
    }
    return sockfd;
}