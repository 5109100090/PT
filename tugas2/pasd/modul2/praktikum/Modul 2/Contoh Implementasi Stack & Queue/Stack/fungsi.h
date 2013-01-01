struct Stack{
    int data;
    struct Stack *head,
                 *next;  
};

void init(struct Stack *stack){
    stack->head = NULL; //top of stack diset NULL
}

int isEmpty(struct Stack *stack){
    if(stack->head == NULL) return 1;   //mengembalikan nilai 1 bila stack kosong
    else return 0;                      //mengembalikan nilai 0 jika stack memiliki isi
}

/*
fungsi push memiliki konsep kerja yang sama seperti addFirst

Node baru ditambahkan sebagai elemen pertama
push(&stack, 1)
push(&stack, 2)
push(&stack, 3)
push(&stack, 4)

hasilnya menjadi
4
3
2
1
*/
void push(struct Stack *stack, int data){
    struct Stack *newNode = malloc(sizeof(struct Stack));
    newNode->data = data;
    
    if(isEmpty(stack)){
        stack->head = newNode;
        newNode->next = NULL; 
    }
    else{
        newNode->next = stack->head;
        stack->head = newNode;   
    }  
}

/*
    cara kerja fungsi pop sama seperti fungsi removeFirst
    menghapus dan mengembalikan element pertama stack
*/
struct Stack *pop(struct Stack *stack){
    struct Stack *temp = stack->head;
    
    if(isEmpty(stack)){
        printf("Stack is empty");
    }
    else{
        stack->head = stack->head->next;
    }  
    return temp;
}

/*
mengembalikan element pertama dari stack
*/
struct Stack *peek(struct Stack *stack){
    return stack->head;   
}

void print(struct Stack *stack){
    struct Stack *temp = stack->head;
    
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;   
    }   
}
