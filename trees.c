#include <stdio.h>
#include <stdlib.h>

// factory method: different types of trees with different root nodes need to be created
//typedef struct TreeFactory {
//	// function pointer with a return type of Node* with params: int value
//	Node* (*createRootNode)(int value); 
//} TreeFactory;

// Example on how to use this typedef
// = { createSimpleRootNode }: This is the initializer list, and it's used to initialize the members of the TreeFactory structure.
//TreeFactory simpleTreeFactory = { createSimpleRootNode };
//Node* root = simpleTreeFactory.createRootNode(10);

typedef struct Node {
	int value;
	struct Node* left;
	struct Node* right;
} Node;

Node* createSimpleRootNode(int value){
	Node* rootNode = (Node*)malloc(sizeof(Node)); // type cast pointer return by malloc (void*) to Node*
	rootNode->value = value;
	rootNode->left = NULL;
	rootNode->right = NULL;

	return rootNode;
}

Node* addNode(Node* curr,  int value){
	if(curr == NULL){
		curr = createSimpleRootNode(value);
	} else if(value < curr->value) {
		curr->left = addNode(curr->left, value);
	} else if(value > curr->value) {
		curr->right = addNode(curr->right, value);
	}	

	return curr;
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

void printTree(Node* curr){
	if(curr == NULL){
		return;
	}

	// pre-order traversal
	printf("pre-order traversal: %d\n", curr->value);
	printTree(curr->left);
	printTree(curr->right);
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
