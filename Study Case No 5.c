#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node{
	long long nim;
	char name[100];
	char time[100];
	struct node *left;
	struct node *right;
};

struct node *new_node(long long nimi, char *namei, char *timei){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->nim = nimi;
	strcpy(temp->name, namei);
	strcpy(temp->time, timei);
	temp->left = NULL;
	temp->right= NULL;
	
	return temp;
}

struct node *insert(struct node *node, long long nimi, char *namei, char *timei){
	if (node == NULL)
	return new_node(nimi, namei, timei);
	
	if (nimi < node->nim)
	node->left = insert(node->left, nimi, namei, timei);
	
	else if (nimi > node->nim)
	node->right = insert(node->right, nimi, namei, timei);
	
	return node;
}

struct node *insertMenu(struct node *node){
	long long nimi;
	char namei[50], timei[50];
	printf("Insert data!\n");
	printf("NIM\t: "); scanf("%lld", &nimi); getchar();
	printf("Name\t: "); scanf("%[^\n]", namei); getchar();
	printf("Time\t: "); scanf("%[^\n]", timei); getchar();
	node = insert(node, nimi, namei, timei);
	confirm();
	
	return node;
}

void inOrder(struct node *root){
	if (root == NULL){
		return;
	}
	else{
		inOrder(root->left);
		printf("NIM\t: %lld\n", root->nim);
		printf("Name\t: %s\n", root->name);
		printf("Time\t: %s\n\n", root->time);
		inOrder(root->right);
	}
}

void search(struct node *root, long long searchi){
	if (root == NULL){
		return;
	}
	else{
		if(searchi < root->nim){
			search(root->left, searchi);
		}
		if(searchi > root->nim){
			search(root->right, searchi);
		}
		if(searchi == root->nim){
			printf("NIM\t: %lld\n", root->nim);
			printf("Name\t: %s\n", root->name);
			printf("Time\t: %s\n\n", root->time);
		}
	}
}

void menusearch(struct node *root){
	long long searchi;
	printf("Search Student!\n");
	printf("===============================\n");
	printf("Input Student NIM : "); scanf("%lld", &searchi); getchar();
	system("cls");
	search(root, searchi);
	confirm();
}

void confirm(){
	printf("Press enter to go back to the main menu!\n");
	getchar();
	system("cls");
}

int main(){
	struct node *root = NULL;
	int opt;
	while(opt != 4){
		printf("BINUS STUDENT ATTENDANCE MENU!\n");
		printf("===============================\n");
		printf("1. Input Student Attendance\n");
		printf("2. Show Student Attendance\n");
		printf("3. Search Student\n");
		printf("4. Exit\n");
		printf("Choose a menu : "); scanf("%d", &opt); getchar();
		system("cls");
		
		switch(opt){
			case 1 : root = insertMenu(root); break;
			case 2 : inOrder(root); confirm(); break;
			case 3 : menusearch(root); break;
		}
	}
	printf("Thankyou for using this program!\n");
	
	return 0;
}
