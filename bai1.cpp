#include<stdio.h>
#include<stdlib.h> 

// dinh nghia nut
typedef struct Node{
	int data;
	struct Node* next; 
}; 

// tao 1 nut moi
Node* createNode(int value){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
} 

void insertHead(Node** head, int data){
	Node* newNode = createNode(data);
	newNode->next = *head; 
	*head = newNode; 
}

void printList(Node* head){
	Node* temp = head;
	while(temp != NULL){
		printf("%d--->", temp->data);
		temp = temp->next; 
	} 
	printf("NULL\n"); 
} 

int main(){
	Node* head = NULL;
	int n;
	int value[n];
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	if(n<=0){
		printf("Danh sach rong!");
		return 0; 
	} 
	for(int i=0; i<n; i++){
		printf("Phan tu thu %d = ", i);
		scanf("%d", &value[i]);
	} 
	for(int i=n-1; i>=0; i--){
		insertHead(&head, value[i]);
	} 
	printList(head);
	return 0;
}

