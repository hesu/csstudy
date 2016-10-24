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

// TODO
void btree::insert( int key, node *leaf)
{
  if( key< leaf->key_value) {
    if( leaf->left != NULL)
    {
      insert( key, leaf->left);
    } else {
      node newnode;
    }
  } else {
  }
}

int main(int argc, char** argv)
{
	clock_t begin = clock();
	/* starting code */
	/* end of code */
	clock_t end = clock();
	std::cout << "elapsed time=" << double(end - begin) / CLOCKS_PER_SEC << std::endl;
	return 0;
}
