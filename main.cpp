#include "bst.h"

int main()
{
    bst object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */
    //object.add(object.getRoot(), 14);
    

    object.Search(object.getRoot(), 20);
    object.deletee(object.getRoot(),20);
    object.display();	//displays again after!
   
    return 0;
}
