/*
 	Binary Tree
*/
	
#include <iostream>
#include <ctime>
using namespace std;

struct node
{
	int key_value;
	node *left;
	node *right;
  node *parent;
};

class btree 
{
  public:
    btree();
    ~btree();

    void insert( int key);
    node *search( int key);
    void destroy_tree();
    void pre_traverse( node* leaf);
    void inorder_traverse( node* leaf);
    void post_traverse( node* leaf);
    
    void remove( int key);

    node* getroot() { return root; }

  private:
    void destroy_tree( node *leaf);
    void insert( int key, node *leaf);
    void remove( int key, node *leaf);
    node *search( int key, node *leaf);
    int minvalue( node* leaf);
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

void btree::remove( int key)
{
  remove( key, root);
}

int btree::minvalue( node* leaf)
{
  if( leaf->left == NULL) { return leaf->key_value; }
  else{ 
     return minvalue( leaf->left);
  }
}

void btree::remove( int key, node* leaf)
{
  node* n = search( key, leaf);

  // not exist!
  if( !n) return;

  // removing node has no child!
  if( !(n->left) && !(n->right)) {
    if( n->parent->left == n) { n->parent->left = NULL; }
    else{ n->parent->right = NULL; }
    delete n;
    return;
  }

  // removing node has one child(at left)
  if( n->left && !(n->right)) {
    if( n->parent->left == n) { n->parent->left = n->left; }
    else { n->parent->right = n->left; }
    n->left->parent = n->parent;
    delete n;
    return;
  }
  
  // removing node has one child(at right)
  if( n->right && !(n->left)) {
    if( n->parent->left == n) { n->parent->left = n->right; }
    else { n->parent->right = n->right; }
    delete n; 
    return;
  }

  // removing node has two child! (most complicated case)
  /// find a minimum value in the right subtree;
  /// replace value of the node to be removed with found minimum. Now, right subtree contains a duplicate!
  n->key_value = minvalue(n->right);
  /// apply remove to the right subtree to remove a duplicate.
  remove( n->key_value, n->right);
  return;
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

void btree::destroy_tree()
{
  destroy_tree( root);
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
      leaf->left->parent = leaf;
    }
  } else { // key >= leaf->key_value
    if(leaf->right != NULL) {
     insert( key, leaf->right);
    } else {
      leaf->right = new node();
      leaf->right->key_value = key;
      leaf->right->left = NULL; // sets the left child of the child node to null
      leaf->right->right = NULL; // sets the right child of the child node to null
      leaf->right->parent = leaf;
    }
  }
}

void btree::insert( int key)
{
  if( root) insert( key, root);
  else{
    root = new node();
    root->key_value = key;
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
  }
}

node *btree::search(int key, node* leaf)
{
  if( leaf)
  {
    if( key == leaf->key_value) return leaf;
    if( key < leaf->key_value) return search( key, leaf->left);
    else return search( key, leaf->right);
  }
  return NULL;
}

node *btree::search(int key)
{
  return search(key, root);
}

void btree::pre_traverse( node* leaf)
{
  if (leaf == NULL) { return; }
  cout << leaf->key_value << endl;
  pre_traverse( leaf->left);
  pre_traverse( leaf->right);
}

void btree::inorder_traverse( node* leaf)
{
  if (leaf == NULL) { return; }
  inorder_traverse( leaf->left);
  cout << leaf->key_value << endl;
  inorder_traverse( leaf->right);
}


void btree::post_traverse( node* leaf)
{
  if (leaf == NULL) { return; }
  post_traverse( leaf->left);
  post_traverse( leaf->right);
  cout << leaf->key_value << endl;
}


int main(int argc, char** argv)
{
	clock_t begin = clock();
	/* starting code */
  
  btree *bt = new btree();

  bt->insert(1);
  bt->insert(3);
  bt->insert(5);
  bt->insert(2);
  bt->insert(4);


  // TODO traverse
  // 1) Pre-order
  cout << "pre traverse" << endl;
  bt->pre_traverse( bt->getroot());
  // 2) In-order
  cout << "inorder traverse" << endl;
  bt->inorder_traverse( bt->getroot());
  // 3) Post-order
  cout << "post traverse" << endl;
  bt->post_traverse( bt->getroot());

	/* end of code */
	clock_t end = clock();
	std::cout << "elapsed time=" << double(end - begin) / CLOCKS_PER_SEC << std::endl;
	return 0;
}
