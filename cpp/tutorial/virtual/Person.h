#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <sstream>

class Person
{
  private:
    char name[64];
    int age;
  public:
    void setname(const char* name);
    void setage(int age);
    
    const char* getname();
    const int getage();

    virtual void getdata();
    virtual void putdata();
};

#endif //PERSON_H
