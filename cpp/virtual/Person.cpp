#include "Person.h"

#include <string.h>
#include <iostream>
using namespace std;

void Person::setname(const char* name)
{
  strcpy( this->name, name);
}

void Person::setage(int age)
{
  this->age = age;
}
    
const char* Person::getname()
{
  return name;
}

const int Person::getage()
{
  return age;
}

void Person::getdata()
{
  cout << "Person::getdata()" << endl;
}

void Person::putdata()
{
  cout << "Person::putdata()" << endl;
}
