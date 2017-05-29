#include "Student.h"

#include <string.h>
#include <iostream>

using namespace std;

void Student::getdata()
{
  for(int i=0; i<6; i++)
  {
    int mark;
    cin >> mark;
    marks.push_back(mark);
  }

  cin >> cur_id;
}

void Student::putdata()
{
  int sum = 0;
  for(int i=0; i<marks.size(); i++)
  {
    sum += marks[i];
  }

  this->putdata();
  cout << sum << " " << cur_id << endl;
}
