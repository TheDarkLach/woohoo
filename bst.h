//bst.h
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <time.h>

using namespace std;

struct node
{
    int data;   //some questions use char * data;
    node * left;
    node * right;
};

class bst
{
    public:
    	//These functions are supplied already
    	bst();			//supplied
        void build(); 		//supplied
        void display(); 	//supplied

/* ************** PLACE YOUR PROTOTYPE HERE ***************** */
 
        void add(node* curr_node, int num);
        void Search(node* root, int data);
        node* deletee(node* root, int data);

        node* getRoot()
        {
            return root;
        }
 	private:
 		node * root;
		void display_tree(node*, int);
};
  

