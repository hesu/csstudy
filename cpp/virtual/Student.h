#include "Person.h"
#include <vector>

using namespace std;

class Student : public Person
{
  private:
    vector<int> marks;
    int cur_id;
  public:
    void getdata();
    void putdata();
};
