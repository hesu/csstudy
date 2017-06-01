#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Person.h"

class Professor : public Person
{
  private:
    int publications;
    int cur_id;
  public:
    void getdata();
    void putdata();
};

#endif
