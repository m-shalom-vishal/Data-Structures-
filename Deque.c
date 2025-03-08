#include<stdio.h>

#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node * front = NULL;
struct Node * rear = NULL;

void insertfront(int data){
    struct Node * new_node = ( struct Node *) malloc (sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    
    if (front == NULL){
        new_node->next = NULL;
        front = rear = new_node;
    }
    front->prev = new_node;
    new_node->next = front;
    front = new_node;
}
void insertend(int data){
    struct Node * new_node = ( struct Node *) malloc (sizeof(struct Node));
    new_node->data = data;
    new_node->next= NULL;
    
    if (front == NULL){
        new_node->prev = NULL;
        front = rear = new_node;
    }
    rear->next = new_node;
    new_node->prev = rear;
    rear = new_node;
}
void deletefront(){
    if(front == NULL){
        printf("Deque is Empty");
    }
    printf("Popped element at front  :%d ", front -> data);
    front = front->next;
    front->prev = NULL;
    
}
void deleteend (){
    if(rear == NULL){
        printf("Deque is Empty");
    }
    printf("Popped element at end :%d ", rear -> data);
    rear = rear->prev;
    rear->next = NULL;
    
}
void display(){
    struct Node * temp = front;
    
    while (temp!= NULL  ){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i =0;i<n;i++){
        int data;
        scanf("%d",&data);
        insertfront(data);
    }
    int k;
    scanf("%d",&k);
    for (int i= 0;i<k;i++){
        int data;
        scanf("%d",&data);
        insertend(data);
    }
    printf("Deque : ");
    display();
    printf("\n");
    deletefront();
    printf("\n");
    deleteend();
    printf("\nfinal : ");
    display();
}
