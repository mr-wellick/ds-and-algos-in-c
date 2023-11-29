#include <stdio.h>
#include <stdlib.h>

// create tree node
typedef struct Node {
	int value;
	struct Node* left;
	struct Node* right;
} Node;


// factory method: different types of trees with different root nodes need to be created
typedef struct TreeFactory {
	// function pointer with a return type of Node* with params: int value
	Node* (*createRootNode)(int value); 
} TreeFactory;

Node* createSimpleRootNode(int value){
	Node* rootNode = (Node*)malloc(sizeof(Node)); // type cast pointer return by malloc (void*) to Node*
	rootNode->value = value;
	rootNode->left = NULL;
	rootNode->right = NULL;

	return rootNode;
}

// add nodes to tree
// void addNode()


int main(void){
	// = { createSimpleRootNode }: This is the initializer list, and it's used to initialize the members of the TreeFactory structure.
	TreeFactory simpleTreeFactory = { createSimpleRootNode };
	Node* rootOne = simpleTreeFactory.createRootNode(10);

	// print value of root node
	printf("Simple root %d\n", rootOne->value);
	free(rootOne);

	return 0;
}
