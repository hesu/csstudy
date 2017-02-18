/*
 	Quick sort
*/
	
#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>

using namespace std;

void quicksort(vector<int>& v, int left, int right)
{
  int i=left, j=right;
  int pivot = v[(left+right)/2];
  int tmp;

  // partition
  while (i<=j) {
    while (v[i] < pivot) {
      i++;
    }
    while (v[j] > pivot) {
      j--;
    }

    if (i<=j) {
      tmp = v[i];
      v[i] = v[j];
      v[j] = tmp;
      i++;
      j--;
    }
  }

  // recursion
  if (left<j) {
    quicksort(v, left, j);
  }

  if (i<right) {
    quicksort(v, i, right);
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
