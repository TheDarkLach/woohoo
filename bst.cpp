#include "bst.h"

bst::bst(){root = NULL;}

void bst::build() {
  srand((unsigned)time(0));
  int arrayLength = rand()%5+10;
  int values[arrayLength];
  for (int a = 0; a < arrayLength; a++){values[a] = -1;}
  for (int a = 0; a < arrayLength; a++) {
    bool duplicate = false;
    do {
      duplicate = false;
      values[a] = rand()%30+1;
      for (int b = 0; b < arrayLength; b++) {
        if ((a != b) && (values[a] == values[b])) {duplicate = true;}
      }
    } while (duplicate == true);
  }
  for (int a = 0; a < arrayLength; a++) {
    node* newnode = new node();
    newnode->data = values[a];
    node* current = root;
    if (root == NULL) {
      root = newnode;
    }
    else {
      while(current != NULL) {
        if (newnode->data < current->data) {
          if (current->left == NULL) {
            current->left = newnode;
	    break;
	  }
	  else {
            current = current->left;
	  }
	}
	else {
          if (current->right == NULL) {
            current->right = newnode;
	    break;
	  }
	  else {
            current = current->right;
	  }
	}
      }
    }
  }
}

void bst::display_tree(node* current, int level) {
  if (current->right != NULL) {display_tree(current->right, level+1);}
  for (int a = 0; a < level; a++) {cout << "\t";}
  cout << current->data << " (";
  if (current->left != NULL) cout << current->left->data << ",";
  else cout << ",";
  if (current->right != NULL) cout << current->right->data << ")" << endl;
  else cout << ")" << endl;
  if (current->left != NULL) {display_tree(current->left, level+1);}
}

void bst::display() {
  cout << "---------Tree Printout----------" << endl;
  display_tree(root, 0);
  cout << "--------------------------------" << endl;
}

  node* FindMin(node *root) {
   if (root == NULL) {
      return 0; // or undefined.
   }
   if (root->left != NULL) {
      return FindMin(root->left); // left tree is smaller
   }
   return root;//->data;
}

node* bst::deletee(node* root, int data)
{
   if (root == NULL) {
     return root;
  }
  if (data < root->data) {  // data is in the left sub tree.
      root->left = deletee(root->left, data);
  } else if (data > root->data) { // data is in the right sub tree.
      root->right = deletee(root->right, data);
  } else {
     // case 1: no children
     if (root->left == NULL && root->right == NULL) {
        delete(root); // wipe out the memory, in C, use free function
        root = NULL;
     }
     // case 2: one child (right)
     else if (root->left == NULL) {
        node *temp = root; // save current node as a backup
        root = root->right;
        delete temp;
     }
     // case 3: one child (left)
     else if (root->right == NULL) {
        node *temp = root; // save current node as a backup
        root = root->left;
        delete temp;
     }
     // case 4: two children
     else {
        node *temp = FindMin(root->right); // find minimal value of right sub tree
        root->data = temp->data; // duplicate the node
        root->right = deletee(root->right, temp->data); // delete the duplicate node
     }
  }
  return root; 

}

void bst::add(node* curr_node, int num)
{
	if(num > curr_node->data)
	{
		if(curr_node->right == NULL) //Check if avaliable to insert
		{
			node* temp = new node();
			temp->data = num;

			curr_node->right = temp;

			return; //Inserted
		}
		else //If not avaliable to insert, go to the right node
		{
			add(curr_node->right, num);
		}
	}
	else
	{
		if(curr_node->left == NULL) //Check if avaliable to insert
		{
			node* temp = new node();
			temp->data = num;

			curr_node->left = temp;

			return; //Inserted
		}
		else //If not avaliable to insert, go to the right node
		{
			add(curr_node->left, num);
		}
	}
}

void bst::Search(node* root, int data)
{
  if(root == NULL){    //If root is Null return false, as there is no element in tree
    cout << "does not contain" << data << endl;
  }
  else if(data == root->data){ // If root data is equal to the searched data, then return true
    cout << "contains " << data << endl;
  }
  else if(data <= root->data){ //If the searched data is less than or equal to root data, recursively search in left tree
    Search(root->left,data);    
  }
  else{
    Search(root->right,data); // If the searched data is greater than root data, recursively search in right tree
  }  
}
