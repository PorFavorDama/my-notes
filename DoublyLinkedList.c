#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int x;
	struct n* next;
	struct n* prev;
}node;

void printList(node* r){
	while(r !=NULL){
		printf("%i\n",r->x);
		r = r->next;
	}
}

void printBackwards(node* r){
	node* iter = r;
	while(iter->next != NULL){
		iter = iter->next;
	}
	while(iter !=NULL){
		printf("%i\n", iter->x);
		iter= iter->prev;
	}
}

void addInOrder(node** r,int x){
	
	if((*r) == NULL){
		*r = malloc(sizeof(node));
		(*r)->next = NULL;
		(*r)->prev = NULL;
		(*r)->x = x;
		return;
	}
	if((*r)->x > x){
		node* toBePrepended = malloc(sizeof(node));
		toBePrepended->x = x;
		toBePrepended->prev = NULL;
		toBePrepended->next = *r;
		(*r)->prev = toBePrepended;
		*r = toBePrepended;
		return;
	}
	
	node* iter = *r;
	while(iter->next != NULL && iter->next->x < x){
		iter = iter->next;
	}
	node* temp = malloc(sizeof(node));
	temp->x = x;
	temp->next = iter->next;
	if(iter->next != NULL){
		iter->next->prev = temp;
	}
	temp->prev = iter;
	iter->next = temp;
	
	

}


		
void delete(node** r,int x){
	int endOfList = 0;
	node* toBeDeleted;
	node* iter = *r;
	node* newRoot = *r;
	while(endOfList != 1){
		if((*r)->x == x){
			toBeDeleted = (*r);
			*r = (*r)->next;
			(*r)->prev = NULL;
			iter = *r;
			newRoot= *r;
			free(toBeDeleted);
			continue;
		}
		
		if(newRoot->next->x == x){
			toBeDeleted = newRoot->next;
			newRoot->next = toBeDeleted->next;
			toBeDeleted->next->prev = toBeDeleted->prev;
			free(toBeDeleted);
			continue;
		}
		   
		newRoot = newRoot->next;
		if(newRoot->next == NULL){
			endOfList = 1;
			continue;
		}
	}
			
		
	
	
}
	
	
	
	
	

		
int main(){
	node* root;
	root = NULL;
	addInOrder(&root,7);
	addInOrder(&root,4);
	addInOrder(&root,2);
	addInOrder(&root,1);
	addInOrder(&root,1);
	addInOrder(&root,3);
	addInOrder(&root,4);
	addInOrder(&root,7);
	addInOrder(&root,6);
	addInOrder(&root,8);
	addInOrder(&root,15);
	addInOrder(&root,10);
	addInOrder(&root,12);
	addInOrder(&root,29);
	addInOrder(&root,0);
	addInOrder(&root,0);
	addInOrder(&root,17);
	

	puts("\n------------Before Deletion------------\n");
	printList(root);
	printf("\n----Backwards----\n");
	printBackwards(root);
	delete(&root,2);
	delete(&root,7);

	puts("\n------------After Deletion------------\n");
	printList(root);
	printf("\n----Backwards----\n");
	printBackwards(root);
	
	
	return 0;
}
	