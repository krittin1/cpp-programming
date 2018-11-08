 
//   KRITTIN    KANOKWILAIRAT   5910450026
#include <iostream> 
#include <stdlib.h> 
#include<string>
#include <stack> 
using namespace std; 
  

struct node 
{ 
    int size ; 
    string key ;
    struct node* left, *right , *rightRight ;
} ; 
struct node* newnode(string key, int size)
{
	struct node* node = new struct node ;
	node -> key= key ;
	node -> size = size ;
	node -> left = NULL ;
	node -> right = NULL ;
	node -> rightRight = NULL ;
	return(node);
	
};
void Preorder(node *root)
{
	
	int value = 0;
	
	if (root == NULL)
	{
		return ;
	}
	stack<node *> nodeStack ;
	nodeStack.push(root) ;
	
	while (nodeStack.empty() == false)
	{
		struct node *node = nodeStack.top();
		value = value + node -> size;
		nodeStack.pop();
		if (node -> right)
		{
			nodeStack.push(node->right) ;
		}
		if (node -> rightRight)
		{
			nodeStack.push(node -> rightRight);
		}
		if (node -> left)
		{
			nodeStack.push(node -> left);
		}
	}
	
	cout << " ";
	cout << value;
	cout << "K";
	
	
}
int main()
{
	
	struct node *root = newnode("/user/rt/courses",1); 
	/*                      /user/rt/courses/                                    */
	root -> left = newnode("cs016/",2); 
	/*                     /user/rt/courses/ 
	                      /
	                   cs016/                            
		                                                                         */
	root -> right = newnode("cs252/",1); 
	/*                    /user/rt/courses/ 
	                    /                 \
		               cs016/            cs252/                  
		                                                                           */
	root -> left -> left = newnode("grades/",8);
		/*                    /user/rt/courses/ 
	                    /                 \
		               cs016/            cs252/                  
		               /
					   grades                                                           
					                                                                */
	root -> left -> right =  newnode("homeworks/",1); 
		/*                    /user/rt/courses/ 
	                    /                 \
		               cs016/            cs252/                  
		            /       \
				grades       homeworks                                                    
					                                                                */
	
	root -> left -> rightRight = newnode("programs/",1);
		/*                    /user/rt/courses/ 
	                    /                 \
		               cs016/            cs252/                  
		            /    |       \
				grades  homeworks  programs                                                  
					                                                                */
	
	root -> right -> left = newnode("projects/",1); 
		/*                    /user/rt/courses/ 
	                    /                           \
		               cs016/                        cs252/                  
		            /    |       \                   /
				grades  homeworks  programs          projects                                        
					                                                                */
	root -> right -> right = newnode("grades2",3); 
		/*                    /user/rt/courses/ 
	                    /                           \
		               cs016/                        cs252/                  
		            /    |       \                   /        \
				grades  homeworks  programs          projects   grades2                                     
					                                                                */
	
	root -> left -> right -> left = newnode("hw1",3);   
		/*                    /user/rt/courses/ 
	                    /                           \
		               cs016/                        cs252/                  
		            /    |       \                   /        \
				grades  homeworks  programs          projects   grades2                                     
					    /
						hw1                                                            
						                                                               */
	root -> left -> right -> right = newnode("hw2",2); 
		/*                    /user/rt/courses/ 
	                    /                           \
		               cs016/                        cs252/                  
		            /    |       \                   /        \
				grades  homeworks  programs          projects   grades2                                     
					    /      \
						hw1     hw2                                                       
						                                                               */
	root -> left -> right -> rightRight = newnode("hw3",4); 
		/*                    /user/rt/courses/ 
	                    /                           \
		               cs016/                        cs252/                  
		            /    |       \                   /        \
				grades  homeworks  programs          projects   grades2                                     
					    /    |  \
						hw1  hw2 hw3                                                       
						                                                               */
	root -> left -> rightRight -> left = newnode("pr1",57); 
		/*                            /user/rt/courses/ 
	                            /                                \
		                   cs016/                                cs252/                  
		            /    |           \                        /            \
				grades  homeworks      programs               projects       grades2                                     
					    /    |  \      /
						hw1  hw2 hw3   pr1                                                    
						                                                               */
	root -> left -> rightRight-> right = newnode("pr2",97); 
		/*                            /user/rt/courses/ 
	                            /                                \
		                   cs016/                                cs252/                  
		            /    |           \                        /            \
				grades  homeworks      programs               projects       grades2                                     
					    /    |  \      /      \
						hw1  hw2 hw3   pr1     pr2                                               
						                                                               */
	root -> left -> rightRight -> rightRight = newnode("pr3",74); 
	/*                            /user/rt/courses/ 
	                            /                                \
		                   cs016/                                cs252/                  
		            /    |           \                        /            \
				grades  homeworks      programs               projects       grades2                                     
					    /    |  \      /   |   \
						hw1  hw2 hw3   pr1 pr2  pr3                                               
						                                                               */
	root -> right -> left -> left = newnode("papers/",1);  
	/*                            /user/rt/courses/ 
	                            /                                \
		                   cs016/                                cs252/                  
		            /    |           \                        /            \
				grades  homeworks      programs               projects       grades2                                     
					    /    |  \      /   |   \             /
						hw1  hw2 hw3   pr1 pr2  pr3          papers                                     
						                                                               */
	root -> right -> left -> right = newnode("demos/",1); 
	/*                            /user/rt/courses/ 
	                            /                                \
		                   cs016/                                cs252/                  
		            /    |           \                        /            \
				grades  homeworks      programs               projects       grades2                                     
					    /    |  \      /   |   \             /       \
						hw1  hw2 hw3   pr1 pr2  pr3          papers   demos                                  
						                                                               */
	root -> right -> left->left -> left = newnode("buylow",26); 
		/*                            /user/rt/courses/ 
	                            /                                \
		                   cs016/                                cs252/                  
		            /    |           \                        /            \
				grades  homeworks      programs               projects       grades2                                     
					    /    |  \      /   |   \             /       \
						hw1  hw2 hw3   pr1 pr2  pr3          papers   demos                                  
						                                     /
															buylow                          
															                              */
	root -> right -> left -> left -> right= newnode("sellhigh",55);
		/*                            /user/rt/courses/ 
	                            /                                \
		                   cs016/                                cs252/                  
		            /    |           \                        /            \
				grades  homeworks      programs               projects       grades2                                     
					    /    |  \      /   |   \             /         \
						hw1  hw2 hw3   pr1 pr2  pr3          papers      demos                                  
						                                     /     \
															buylow  sellhigh                        
															                              */
	
	root -> right -> left -> right -> left = newnode("market",4786); 
		/*                            /user/rt/courses/ 
	                            /                                \
		                   cs016/                                cs252/                  
		            /    |           \                        /            \
				grades  homeworks      programs               projects       grades2                                     
					    /    |  \      /   |   \             /         \
						hw1  hw2 hw3   pr1 pr2  pr3          papers      demos                                  
						                                     /     \           \
															buylow  sellhigh    markets                    
															                              */
	
	Preorder(root);


}
