//priority std::queue<
#include <stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    int priority;
    struct Node * next;
};
struct  Node * create(int data, int priority){
    struct Node * new_node = (struct Node*) malloc (sizeof(struct Node));
    new_node->data = data;
    new_node->priority = priority;
    new_node->next = NULL;
    return new_node;
}
void insert(struct Node** head, int data, int priority){
    struct Node * new_node = create(data,priority);
    
    struct Node * temp = *head;
    
    if (*head == NULL){
        *head = new_node;
    }
    else if((*head )->priority > new_node->priority){
        new_node->next = *head;
        *head = new_node;
    }
    else{
        while(temp->next != NULL && temp->next->priority < new_node->priority){
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    
}
void dequeue(struct Node **head){
    if ( * head == NULL){
        printf("\nQueue is empty");

    }
    printf("\npopped element is : %d", (*head)->data);
    * head = (*head)->next;
}
void peek(struct Node **head){
    if (* head == NULL){
        printf("\nqueue is empty");
    }
    printf("\nTop element is :%d", (*head)->data);
}
void display(struct Node * head){
    struct  Node * temp = head;
    
    while ( temp != NULL){
        printf("%d ->",temp->data);
        temp= temp->next;
    }
    printf("NULL");
}
int main(){
    struct Node * head = NULL;
    
    int n ;
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        int data;
        int priority;
        scanf("%d %d",&data,&priority);
        insert(&head,data,priority);
        
    }
    display(head);
    dequeue(&head);
    peek(&head);￼Enter
