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

// xoa vi tri bat ki
void deleteAtPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("Danh sach rong.\n");
        return;
    }

    // neu la xoa dau  
    if (position == 0) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node* temp = *head;
    // duyet den vi tri can xoa 
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Vi tri xoa khong hop le.\n");
        return;
    }

    // xoa 
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

int main(){
	Node* head = NULL;
	int n, position;
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
	
	printf("Vi tri can xoa = ");
	scanf("%d", &position);
	
	deleteAtPosition(&head, position);
	printf("Danh sach sau khi xoa: ");
	printList(head);
	return 0;
}
