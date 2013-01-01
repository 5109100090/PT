struct Queue{
    int data;
    struct Queue *head,
                 *tail,                 
                 *next,
                 *prev;  
};

void init(struct Queue *queue){
    queue->head = queue->tail= NULL; //head dan tail diset NULL
}

int isEmpty(struct Queue *queue){
    if(queue->head == NULL) return 1;   //mengembalikan nilai 1 bila queue kosong
    else return 0;                      //mengembalikan nilai 0 jika queue memiliki isi
}

/*
fungsi enQueue memiliki konsep kerja yang sama seperti addLast

Node baru ditambahkan sebagai elemen pertama
push(&stack, 1)
push(&stack, 2)
push(&stack, 3)
push(&stack, 4)

hasilnya menjadi
1
2
3
4
*/
void enQueue(struct Queue *queue, int data){
    struct Queue *newNode = malloc(sizeof(struct Queue));
    newNode->data = data;
    
    if(isEmpty(queue)){
        queue->head = queue->tail = newNode;
        newNode->next = newNode->prev = NULL; 
    }
    else{
        queue->tail->next = newNode;
        queue->tail = newNode;
        newNode->next = NULL;
    }  
}

/*
    cara kerja fungsi deQueue sama seperti fungsi removeFirst
    menghapus dan mengembalikan element pertama stack
*/
struct Queue *deQueue(struct Queue *queue){
    struct Queue *temp = queue->head;
    
    if(isEmpty(queue)){
        printf("Stack is empty");
    }
    else{
        queue->head = queue->head->next;
    }  
    return temp;
}

/*
mengembalikan element pertama dari queue
*/
struct Queue *peek(struct Queue *queue){
    return queue->head;   
}

void print(struct Queue *queue){
    struct Queue *temp = queue->head;
    
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;   
    }   
}
