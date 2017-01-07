/*
 	Heap sort
*/
	
#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	clock_t begin = clock();
	/* starting code */

  // Generate & Suffle
  vector<int> bar;
  for(int i=0; i<100; i++) bar.push_back(i);
  random_shuffle( std::begin( bar ) , std::end( bar ));

  for(int i=0; i<100; i++) cout << bar[i] << " ";
  cout << endl;

  // TODO heap sort;

	/* end of code */
	clock_t end = clock();
	std::cout << "elapsed time=" << double(end - begin) / CLOCKS_PER_SEC << std::endl;
	return 0;
}
