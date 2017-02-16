#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;
struct Interval 
{
	int low;
	int high;
};
 
struct Node
{
    int high;
	Interval *interval;
    Node *left;
	Node *right;
};
 
Node *Start(Interval array)              
{
    Node *newnode = new Node;
    newnode->interval = new Interval(array);
    newnode->high = array.high;
    newnode->left = NULL;
	newnode->right = NULL;
};
 
Node *Insert(Node *node, Interval array)  
{
    if (node == NULL)
        return Start(array);
 
    int l = node->interval->low;
    
    if (array.low < l)                             
        node->left = Insert(node->left, array);
 
    else
        node->right = Insert(node->right, array);   
 
    if (node->high < array.high)
        node->high = array.high;
 
    return node;
}

Node *MinNode(Node* node)     
{
    Node* current = node;
    while (current->left != NULL)
    {
		current = current->left;
	}
	return current;
}

Node* Delete(Node* node, Interval array)
{
    if (node == NULL) 
		return node;
 
    if (array.low < node->interval->low)      
        node->left = Delete(node->left, array);
 
    else if (array.low > node->interval->low)     
        node->right = Delete(node->right, array);
 
    else     
    {
        if (node->left == NULL)
        {
            struct Node *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            struct Node *temp = node->left;
            free(node);
            return temp;
        }
 
        Node* temp = MinNode(node->right);
        node->interval = temp->interval;
        node->high= temp->high; 		
        node->right = Delete(node->right, array);
    }
    return node;
}
int check(Interval array, Interval barray )
{
    if (array.low <= barray.high && array.high >= barray.low)
        return 1;
    return 0;
}


Interval *Search(Node *node, Interval searchInterval)
{
    if (node == NULL) 
		return NULL;
 
    if (check(*(node->interval), searchInterval))
        return node->interval;
 
    if (node->left != NULL && node->left->high >= searchInterval.low)
        return Search(node->left, searchInterval);
 
    return Search(node->right, searchInterval);
}

int main()
{
	Interval array[]= {{16, 18}, {8, 4}, {19, 23},{3, 7}, {2, 9}};
	int n=5;
	Node* node=NULL;
	for(int i=0;i<n;i++)
	{
		node=Insert(node,array[i]);
	}
	
	Interval searchInterval = {19,23};   
	Interval *ans = Search(node, searchInterval);
	if (ans == NULL)
    	cout<<"No Overlap found"<<endl;
    else
        cout << " Overlap found, interval " << searchInterval.low <<"," <<searchInterval.high <<" overlaps with " << ans->low << " ," << ans->high <<endl;
        
    Interval deleteInterval = {3,7};    
    node=Delete(node,deleteInterval);
	cout<<"Interval ["<< deleteInterval.low <<","<< deleteInterval.high<<"] is successfully deleted"<<endl;
	ans = Search(node, searchInterval);   
	if (ans == NULL)
    	cout<<"No Overlap found"<<endl;
    else
        cout << "Overlap found, interval " << searchInterval.low <<"," <<searchInterval.high <<" overlaps with " << ans->low << " ," << ans->high <<endl;
    return 0;
}
