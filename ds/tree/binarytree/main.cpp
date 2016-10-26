/*
 	Binary Tree
*/
	
#include <iostream>
#include <ctime>
using namespace std;

struct node
{
	int key_value;
	node* left;
	node *right;
};

class btree 
{
  public:
    btree();
    ~btree();

    void insert( int key);
    node *search( int key);
    void destroy_tree();

  private:
    void destroy_tree( node *leaf);
    void insert( int key, node *leaf);
    node *search( int key, node *leaf);

    node *root;
};

btree::btree()
{
  root = NULL;
}

btree::~btree()
{
  destroy_tree( root);
}

void btree::destroy_tree(node *leaf)
{
  if( leaf)
  {
    destroy_tree( leaf->left);
    destroy_tree( leaf->right);
    delete leaf;
  }
}

void btree::insert( int key, node *leaf)
{
  if( key< leaf->key_value) {
    if( leaf->left != NULL)
    {
      insert( key, leaf->left);
    } else {
      leaf->left = new node();
      leaf->left->key_value = key;
      leaf->left->left=NULL; // sets the left child of the child node to null
      leaf->left->right=NULL; // sets the right child of the child node to null
    }
  } else { // key >= leaf->key_value
    if(leaf->right != NULL) {
     insert( key, leaf->right);
    } else {
      leaf->right = new node();
      leaf->right->key_value = key;
      leaf->right->left = NULL; // sets the left child of the child node to null
      leaf->right->right = NULL; // sets the right child of the child node to null
    }
  }
}

// TODO
node *btree::search(int key, node* leaf)
{
  return NULL;
}

int main(int argc, char** argv)
{
	clock_t begin = clock();
	/* starting code */

  // TODO traverse
  // 1) Pre-order
  // 2) In-order
  // 3) Post-order

	/* end of code */
	clock_t end = clock();
	std::cout << "elapsed time=" << double(end - begin) / CLOCKS_PER_SEC << std::endl;
	return 0;
}
