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

void deleteHead(Node** head) {
    if (*head == NULL) {
        printf("Danh sach rong.\n");
        return;
    }

    // Luu lai dia chi phan tu dau 
    Node* temp = *head;

    // Di chuyen head tai phan tu tiep theo
    *head = (*head)->next;

    // Giai phong bo nho
    free(temp);
}

int main(){
	Node* head = NULL;
	int n;
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
	deleteHead(&head);
	printList(head);
	return 0;
}
