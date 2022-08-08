
#include <iostream>

using namespace std;

#include <unistd.h>

int main(int argc, const char *argv[]) {
    pid_t pid;

    cout << "hello, The main is running..." << endl;

    pid = fork();
    if(pid == 0) {
        cout << "I am fork process: " << getpid() << endl;
        exit(0);
    }
    else {
        cout << "I am " << getpid() << ", subprocess is " << pid << endl;
    }
    
    return 0;
}