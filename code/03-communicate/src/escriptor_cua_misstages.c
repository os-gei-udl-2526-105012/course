#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>

struct message {
    long msg_type;
    char msg_text[100];
};

int main(void) {
    key_t key = ftok("msg_queue_example", 65);
    int msqid = msgget(key, 0666 | IPC_CREAT);
    
    struct message msg;
    msg.msg_type = 1;
    strcpy(msg.msg_text, "Aquest és un missatge de prova!");
    
    msgsnd(msqid, &msg, sizeof(msg), 0);
    
    printf("Missatge enviat: %s\n", msg.msg_text);
    
    return 0;
}

