#include "Student.h"

#include <string.h>
#include <iostream>

using namespace std;

static int id = 0;

void Student::getdata()
{
  string name;
  cin >> name;

  int age;
  cin >> age;

 // cout << "name=" << name << " age=" << age << endl;

  for(int i=0; i<6; i++)
  {
    int mark;
    cin >> mark;
    marks.push_back(mark);
//    cout << mark << endl;
  }

  this->setname(name.c_str());
  this->setage(age);
  this->cur_id = (++id);
}

void Student::putdata()
{
  int sum = 0;
  for(int i=0; i<marks.size(); i++)
  {
    sum += marks[i];
  }

  cout << this->getname() << " " << this->getage() << " " << sum << " " << cur_id << endl;
}
