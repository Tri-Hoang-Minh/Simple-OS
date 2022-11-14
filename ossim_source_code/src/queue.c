#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	int size_queue=q->size;
	if(size_queue<MAX_QUEUE_SIZE && size_queue>=0)
	{
		q->proc[size_queue]=proc;
		q->size=size_queue+1;
	}
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	 int size_queue_temp2=q->size;
	 if(size_queue_temp2==1)
	 {
		struct pcb_t* returnproc=q->proc[0];
		q->size=0;
		q->proc[0]=NULL;
		return returnproc;
	 }
	 else if(size_queue_temp2<=MAX_QUEUE_SIZE && size_queue_temp2>1)
	 {
		struct pcb_t* returnproc=q->proc[0];
		uint32_t prioprity_highest=q->proc[0]->priority;
		int position=0;
		int i;
		for(int i=0; i <size_queue_temp2;i++)
		{
			if(prioprity_highest<q->proc[i]->priority)
			{
				prioprity_highest=q->proc[i]->priority;
				position=i;
			}
		}
		returnproc=q->proc[position];
		if(position==(size_queue_temp2-1))
		{
			q->proc[position]=NULL;
			q->size=size_queue_temp2-1;
			return returnproc;
		}
		else
		{
			for(i=position+1;i<size_queue_temp2;i++)
			{
				q->proc[i-1]=q->proc[i];
			}
			q->proc[size_queue_temp2-1]=NULL;
			q->size=size_queue_temp2-1;
			return returnproc;
		}
	 }
	return NULL;
}

