#include "bst.h"

int main()
{
    bst object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */
    object.add(14);


    object.Search(object.getRoot(), 14);
    object.display();	//displays again after!
   
    return 0;
}
