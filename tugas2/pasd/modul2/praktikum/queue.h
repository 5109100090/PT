struct Queue{
    char data[20];
    struct Queue *head,
                 *tail,                 
                 *next,
                 *prev;  
};

void initQ(struct Queue *queue){
    queue->head = queue->tail= NULL; 
}

void emptyQ(struct Queue *queue){
    queue->head = queue->tail= NULL; 
}

int isEmptyQ(struct Queue *queue){
    if(queue->head == NULL) return 1;   
    else return 0;                      
}

struct Queue *deQueue(struct Queue *queue){
    struct Queue *temp = queue->head;
    
    if(isEmptyQ(queue)){
        printf("Stack is empty");
    }
    else{
        queue->head = queue->head->next;
    }  
    return temp;
}

struct Queue *seek(struct Queue *queue, int N){
    struct Queue *temp = queue->head;
    
    for(int i=0; i<N-1; i++)
        temp = temp->next;
        
    return temp;
}

void enQueue(struct Queue *queue, char data[20]){
    struct Queue *newNode;
    newNode=(Queue*)malloc(sizeof(Queue));
    strcpy(newNode->data, data);
    
    if(isEmptyQ(queue)){
        queue->head = queue->tail = newNode;
        newNode->next = newNode->prev = NULL; 
    }
    else{
        struct Queue *temp = queue->head;
        int Ndata=0;
        while(temp!=NULL){
          Ndata++;
          temp = temp->next; 
        }
        
        if(Ndata>9)  
          deQueue(queue);
          
        queue->tail->next = newNode;
        queue->tail = newNode;
        newNode->next = NULL;
    }  
}

void printQ(struct Queue *queue){
    int i=0;
    struct Queue *temp = queue->head;
    
    while(temp!=NULL){
        printf("%d. %s\n", i+1, temp->data);
        temp = temp->next; 
        i++;  
    }   
}
