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

int main(int argc, char** argv)
{
	clock_t begin = clock();
	/* starting code */
	/* end of code */
	clock_t end = clock();
	std::cout << "elapsed time=" << double(end - begin) / CLOCKS_PER_SEC << std::endl;
	return 0;
}
