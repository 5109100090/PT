struct Stack{
    char data[20];
    struct Stack *head,
                 *next;  
};

void initS(struct Stack *stack){
    stack->head = NULL; 
}

void emptyS(struct Stack *stack){
    stack->head = NULL; 
}

int isEmptyS(struct Stack *stack){
    if(stack->head == NULL) return 1;   
    else return 0;                      
}

void pushS(struct Stack *stack, char data[20]){
    struct Stack *newNode;
    newNode=(Stack *)malloc(sizeof(Stack));

    strcpy(newNode->data, data);
    
    if(isEmptyS(stack)){
        stack->head = newNode;
        newNode->next = NULL; 
    }
    else{
        newNode->next = stack->head;
        stack->head = newNode;   
    }  
}

struct Stack *popS(struct Stack *stack){
    struct Stack *temp = stack->head;
    
    if(isEmptyS(stack)){
        printf("Stack is empty\n");
        return 0;
    }
    else{
        stack->head = stack->head->next;
    }
    printf("===POP '%s' from stack===\n", temp);  
    return temp;
}

struct Stack *peekS(struct Stack *stack){
    return stack->head;   
}

void printS(struct Stack *stack){
    struct Stack *temp = stack->head;
    
    while(temp!=NULL){
        printf("%s\n", temp->data);
        temp = temp->next;   
    }   
    
    printf("\n");
}
