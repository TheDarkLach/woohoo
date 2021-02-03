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

void bst::add(int num)
{
  
}


void bst::Search(node* root, int data)
{
  if(root == NULL){    //If root is Null return false, as there is no element in tree
    cout << "does not contain" << data;
  }
  else if(data = root->data){ // If root data is equal to the searched data, then return true
    cout << "contains " << data;
  }
  else if(data <= root->data){ //If the searched data is less than or equal to root data, recursively search in left tree
    Search(root->left,data);    
  }
  else{
    Search(root->right,data); // If the searched data is greater than root data, recursively search in right tree
  }  
}