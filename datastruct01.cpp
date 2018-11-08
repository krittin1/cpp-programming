 
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;


struct node{
	string key;
	
	struct node* parent;
	struct node* leftChild;
	struct node* rightSibling;
};
struct node* createNode(string key, struct node* parent){
	// Allocate memory for new node
	struct node* node = (struct node*)malloc(sizeof(struct node));
	// Assign key to this node
	node->key = key;
	// Initialize parent
	node->parent = parent;
	// Initialize left child, and right sibling as NULL
	node->leftChild = NULL;
	node->rightSibling = NULL;
	return(node);
}

int main(){
	/*create root*/
	struct node *root = createNode("Electronics R' US", NULL);
	/* following is the tree after above statement
	Electronics R' US
	/               \
    NULL           NULL
	*/
	root->leftChild = createNode("R&D", root);
	root->leftChild->rightSibling = createNode("Sales", root);
	root->leftChild->rightSibling->rightSibling = createNode("Purchasing", root);
	root->leftChild->rightSibling->rightSibling->rightSibling = createNode("Manufacturing", root);
	/*    R&D ,Sales ,Purchasing, Manufacturing become children of Elactronics R' US
			Electronics R' US
        	/   	 /		\			\
	     R&D 	    Sales	Purchasing	Manufacturing
     	/ \ 	    / \			/  \		/ 	\
     NULL NULL  NULL   NULL   NULL  NUll NULL    NULL
	*/
	root->leftChild->rightSibling->leftChild = createNode("Domestic", root->leftChild->rightSibling);
	root->leftChild->rightSibling->leftChild->rightSibling = createNode("International", root->leftChild -> rightSibling);
	root->leftChild->rightSibling->rightSibling->rightSibling->leftChild = createNode("TV", root->leftChild->rightSibling->rightSibling->rightSibling);
	root->leftChild->rightSibling->rightSibling->rightSibling->leftChild->rightSibling = createNode("CD", root->leftChild->rightSibling->rightSibling->rightSibling);
	root->leftChild->rightSibling->rightSibling->rightSibling->leftChild->rightSibling->rightSibling = createNode("Tuner", root->leftChild->rightSibling->rightSibling->rightSibling);
	/*  Domestic ,International become children of Sales.
	    Tv ,CD, Tuner become children of Manufacturing.
				        Electronics R' US
	          /   	 /						\			\
	       R&D 	      Sales					Purchasing	Manufacturing
	       / \ 	   / 		\					/ 	\		/ \	   \
       NULL NULL Domestic International 	   NULL NUll   TV CD  Tuner
	*/
	root->leftChild->rightSibling->leftChild->rightSibling->leftChild = createNode("Canada",root->leftChild->rightSibling->leftChild->rightSibling);
	root->leftChild->rightSibling->leftChild->rightSibling->leftChild->rightSibling = createNode("S.America",root->leftChild->rightSibling->leftChild->rightSibling);
	root->leftChild->rightSibling->leftChild->rightSibling->leftChild->rightSibling->rightSibling = createNode("Overseas",root->leftChild->rightSibling->leftChild->rightSibling);


	/* Canada, S.America, Overseas become children of International.
				Electronics R' US
	/   	 /						\			\
	R&D 	Sales					Purchasing	Manufacturing
	/ \ 	/ 		\					/ 	\		/ \	   \
NULL NULL Domestic International 	   NULL NUll   TV CD  Tuner
				 /  	\	   \
			Canada S.Amerca  Overseas
	*/
	root->leftChild->rightSibling->leftChild->rightSibling->leftChild->rightSibling->rightSibling->leftChild = createNode("Africa",root->leftChild->rightSibling->leftChild->rightSibling->leftChild->rightSibling->rightSibling);
	root->leftChild->rightSibling->leftChild->rightSibling->leftChild->rightSibling->rightSibling->leftChild->rightSibling = createNode("Europe",root->leftChild->rightSibling->leftChild->rightSibling->leftChild->rightSibling->rightSibling);
	root->leftChild->rightSibling->leftChild->rightSibling->leftChild->rightSibling->rightSibling->leftChild->rightSibling->rightSibling = createNode("Asia",root->leftChild->rightSibling->leftChild->rightSibling->leftChild->rightSibling->rightSibling);
	root->leftChild->rightSibling->leftChild->rightSibling->leftChild->rightSibling->rightSibling->leftChild->rightSibling->rightSibling->rightSibling = createNode("Australia",root->leftChild->rightSibling->leftChild->rightSibling->leftChild->rightSibling->rightSibling);
	/*   Africa, Europe, Asia, Australia become children of Overseas. 
				Electronics R' US
	/   	 /						\			\
	R&D 	Sales					Purchasing	Manufacturing
	/ \ 	/ 		\					/ 	\		/ \	   \
NULL NULL Domestic International 	   NULL NUll   TV CD  Tuner
				   /  	\	    \
			Canada    S.Amerca   Overseas
							   /	|  	  \	    \
						   Africa Europe  Asia   Australia
	*/
	return 0;
}
