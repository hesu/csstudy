#include "Person.h"

#include <string.h>
#include <iostream>
using namespace std;

void Person::setname(const char* name)
{
}

void Person::setage(int age)
{
}

void Person::getdata()
{
  /*
  char name[64];
  int age;
  
  cin >> name;
  strcpy(this->name, name);

  cin >> age;
  this->age = age;
  */

  cout << "Person::getdata()" << endl;
}

void Person::putdata()
{
  //cout << name << " " << age << endl;
  cout << "Person::putdata()" << endl;
}
