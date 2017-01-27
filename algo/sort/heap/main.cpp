/*
 	Heap sort
*/
	
#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>

using namespace std;

void heapify( vector<int> &v, int idx, int max)
{
  int left = 2*idx + 1;
  int right = 2*idx + 2;

  int largest;
  if (left < max && v[left] > v[idx]) {
    largest = left;  
  } else {
    largest = idx;
  }

  if( right < max && v[right] > v[largest]) {
    largest = right;
  }

  if( largest != idx) {
    int swap = v[idx];
    v[idx] = v[largest];
    v[largest] = swap;
    heapify( v, largest, max);
  }

}

void buildheap( vector<int> &v)
{
  int max = v.size()-1;

  for(int i=int(max/2)-1;i>=0; i--)
  {
    heapify( v, i, max);
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

  // heap sort
  buildheap(v);
  for(int i=v.size()-1; i>=1; i--)
  {
    int swap = v[0];
    v[0] = v[i];
    v[i] = swap;
    heapify( v, 0, i);
  }


  cout << "after sort : ";
  for(int i=0; i<100; i++) cout << v[i] << " ";
  cout << endl;

	/* end of code */
	clock_t end = clock();
	std::cout << "elapsed time=" << double(end - begin) / CLOCKS_PER_SEC << std::endl;
	return 0;
}
