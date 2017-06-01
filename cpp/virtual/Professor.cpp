#include "Professor.h"

#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

static int id = 0;

void Professor::getdata()
{
  string name;
  string age;
  string publications;
  
  cin >> name;
  cin >> age;
  cin >> publications;

  this->setname(name.c_str());
  this->setage(stoi(age));
  this->publications = stoi(publications);
  this->cur_id = (++id);
//  cout << "name=" << name << " age=" << age << " publications=" << publications << " cur_id=" << cur_id << endl;
}

void Professor::putdata()
{
  cout << this->getname() << " " << this->getage() << " " << this->publications << " " << this->cur_id << endl;
}
