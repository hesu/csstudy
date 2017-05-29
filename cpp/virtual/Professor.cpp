#include "Professor.h"

#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

void Professor::getdata()
{
  cout << "Professor::Getdata()" << endl;
  vector<string> vec;
  string line;
  getline(cin, line);

  istringstream iss(line);
  string token;
  while(getline(iss, token, ' ')) {
    vec.push_back(token);
  }

  this->setname(vec[0].c_str());
  this->setage(stoi(vec[1]));
  this->publications = stoi(vec[2]);
}

void Professor::putdata()
{
  this->putdata();
  cout << " " << this->publications << endl;
}
