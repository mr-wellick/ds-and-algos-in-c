#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node* left;
	struct Node* right;
} Node;

Node* createNode(int value){
	Node* rootNode = (Node*)malloc(sizeof(Node)); // type cast pointer return by malloc (void*) to Node*
	rootNode->value = value;
	rootNode->left = NULL;
	rootNode->right = NULL;

	return rootNode;
}

Node* addNode(Node* curr,  int value){
	if(curr == NULL){
		curr = createNode(value);
	} else if(value < curr->value) {
		curr->left = addNode(curr->left, value);
	} else if(value > curr->value) {
		curr->right = addNode(curr->right, value);
	}	

	return curr;
}

void printTree(Node* curr){
	if(curr == NULL){
		return;
	}

	// pre-order traversal
	printf("pre-order traversal: %d\n", curr->value);
	printTree(curr->left);
	printTree(curr->right);
}

void demolish(Node* curr){
	if(curr == NULL) {
		return;
	}

	demolish(curr->left);
	demolish(curr->right);
	// post-order traversal
	printf("post-order traversal: %d\n", curr->value);
	free(curr);
}

int main(void){
	Node *root = NULL;
	//       10
	//     /    \
	//    5      15
	//   / \     / \
	//  N  N    N   N
	root = addNode(root, 10);
	root = addNode(root, 5);
	root = addNode(root, 15);

	printTree(root);
	printf("\n");
	demolish(root);

	return 0;
}

