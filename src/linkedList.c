#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void traversal(struct node *ptr){
	while(ptr!=NULL){
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
}

struct node *insertAtFist(struct node *head,int Data){
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	ptr->next=head;
	ptr->data=Data;
	head=ptr;
	
	return ptr;
}

void insertAtLast(struct node *p,int Data){
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=ptr;
	ptr->next=NULL;
	ptr->data=Data;
}

struct node *deleteFirst(struct node *head){
	struct node *ptr=head;
	head=head->next;
	free(ptr);
	return head; 
}

struct node *deleteLast(struct node *head){
	struct node *p=head;
	struct node *q=head->next;
	while(q->next!=NULL){
		p=p->next;
		q=q->next;
	}
	p->next=NULL;
	free(q);

	return head; 
}

int main(){
	struct node *head;
	struct node *second;
	struct node *third;
	head=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	third=(struct node*)malloc(sizeof(struct node));

	head->data=1;
	head->next=second;
	second->data=2;
	second->next=third;
	third->data=3;
	third->next=NULL;

	head=insertAtFist(head,5);
	insertAtLast(head,7);
	printf("\n");
	traversal(head);

	return 0;
}

