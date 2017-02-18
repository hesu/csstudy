/*
 	Quick sort
*/
	
#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>

using namespace std;

int partition(vector<int>&v, int left, int right)
{
  int ipivot = (left+right)/2;

  int swap = v[ipivot];
  v[ipivot] = v[right];
  v[right] = swap;

  int store = left;

  for(int i=left;i<right; i++) {
    if (v[i] <= v[right]) {
      swap = v[i];
      v[i] = v[store];
      v[store] = swap;

      store++;
    }
  }

  swap = v[right];
  v[right] = v[store];
  v[store] = swap;

  return store;
}

void quicksort(vector<int>& v, int left, int right)
{
  if (left<right) {
    int pi = partition(v, left, right);
    quicksort( v, left, pi-1);
    quicksort( v, pi+1, right);
  }
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
  quicksort(v, 0, 99);

  cout << "after sort : ";
  for(int i=0; i<100; i++) cout << v[i] << " ";
  cout << endl;

	/* end of code */
	clock_t end = clock();
	std::cout << "elapsed time=" << double(end - begin) / CLOCKS_PER_SEC << std::endl;
	return 0;
}
