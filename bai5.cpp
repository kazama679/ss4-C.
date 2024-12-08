#include<stdio.h>
#include<stdlib.h> 

typedef struct Node{
	int data;
	struct Node* next; 
}; 

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

// them vao vi tri bat ki
void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    
    // neu la vi tri dau tien 
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    Node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Vi tri chen khong hop le.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
} 

int main(){
	Node* head = NULL;
	int n, data, position;
	int value[n];
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	if(n<0||n>1000){
		printf("Vui long nhap n trong khoang tu 0 - 1000!");
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
	
	printf("Gia tri can chen = ");
	scanf("%d", &data);
	printf("Vi tri can chen = ");
	scanf("%d", &position);
	
	insertAtPosition(&head, data, position);
	printf("Danh sach sau khi chen: ");
	printList(head);
	return 0;
}
