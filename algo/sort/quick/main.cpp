/*
 	Quick sort
*/
	
#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>

using namespace std;

void quicksort(vector<int>& v)
{
  int len = v.size();
  int ipivot = (len-1)/2;
  
  cout << "ipivot=" << ipivot << " val=" << v[ipivot] << endl;

  // left side (left values < pivot)
  for(int i=0; i<ipivot; i++)
  {

  }

  // right side(right values > pivot)

}

int main(int argc, char** argv)
{
	clock_t begin = clock();
	/* starting code */

  // Generate & Suffle
  vector<int> v;
  for(int i=0; i<100; i++) v.push_back(i);
  random_shuffle( std::begin( v) , std::end( v));

  for(int i=0; i<100; i++) cout << v[i] << " ";
  cout << "\n" << endl;

  // quick sort
  quicksort(v);

  cout << "after sort : ";
  for(int i=0; i<100; i++) cout << v[i] << " ";
  cout << endl;

	/* end of code */
	clock_t end = clock();
	std::cout << "elapsed time=" << double(end - begin) / CLOCKS_PER_SEC << std::endl;
	return 0;
}
