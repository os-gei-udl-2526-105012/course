#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

struct message {
    long msg_type;
    char msg_text[100];
};

int main(void) {
    key_t key = ftok("msg_queue_example", 65);
    int msqid = msgget(key, 0666 | IPC_CREAT);
    
    struct message msg;
    
    msgrcv(msqid, &msg, sizeof(msg), 1, 0);
    
    printf("Missatge rebut: %s\n", msg.msg_text);
    
    return 0;
}

