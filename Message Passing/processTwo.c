
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Declaring structure for message queue
struct mesg_buffer
{
	long mesg_type;
	char mesg_text[100];
} message;

int main()
{
	key_t key;
	int message_id;

	// ftok to generate unique key
	key = ftok("progfile", 65);

	// msgget will create a message queue and returns id
	message_id = msgget(key, 0666 | IPC_CREAT);

	// msgrcv to receive message
	msgrcv(message_id, &message, sizeof(message), 1, 0);

	// display the message
	printf("Data Received is : %s \n",
		   message.mesg_text);

	// to destroy the message queue
	msgctl(message_id, IPC_RMID, NULL);

	return 0;
}
