/*
 	<virtual functions>
  
  using virtual functions, constructors and static variables.
*/
	
#include <iostream>
#include <ctime>

using namespace std;

#include "Professor.h"
#include "Student.h"

int main(int argc, char** argv)
{
	clock_t begin = clock();
	/* starting code */

  int n, val;
  cin >> n;

  Person *per[n];

  for(int i=0;i<n;i++)
  {
    cin >> val;
    if( val == 1) {
//      cout << "professor" << endl;
      per[i] = new Professor;
    }
    else {
 //     cout << "student" << endl;
      per[i] = new Student;
    }

    per[i]->getdata();
  }

  for(int i=0; i<n; i++)
    per[i]->putdata();
  

	/* end of code */
	clock_t end = clock();
	std::cout << "elapsed time=" << double(end - begin) / CLOCKS_PER_SEC << std::endl;
	return 0;
}
