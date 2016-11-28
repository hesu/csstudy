/*
	Amend your program so that it never reaches a state where philosophers are
	deadlocked, that is, it is never the case that each philosopher holds one chopstick
	and is stuck waiting for another to get the second chopstick.
*/

#include <algorithm> 
#include <chrono> 
#include <iostream> 
#include <memory> 
#include <mutex> 
#include <string> 
#include <thread> 
#include <vector> 
#include <exception> 

using namespace std;

class Chopstick
{
  public:
    Chopstick() {};
    mutex m;
};

void think_and_eat( Chopstick* first, Chopstick *second, int philoId, int firstChopstickId, int secondChopstickId)
{
  while( true) {

    // think
    this_thread::sleep_for(chrono::milliseconds(10));

    if( first == second) 
      throw "first chopstick && second chopstick should not be the same!";

    // eat
    first->m.lock();
    string sl = "  (L)Philosopher " + to_string(philoId) + " picked " + to_string( firstChopstickId) + " chopstick.";
    cout << sl << endl;

    second->m.lock();
    string sr = "  (R)Philosopher " + to_string(philoId) + " picked " + to_string( secondChopstickId) + " chopstick.";
    cout << sr << endl;

    string pe = "Philosopher " + to_string( philoId) + " eats.";
    cout << pe << endl;

    first->m.unlock();
    second->m.unlock();
  }
  return;
}

int main()
{
  // philosopher 수 만큼의 chopstick 을 만들고 준비해둔다.
  static int nPhilo = 5;
  vector<unique_ptr<Chopstick>> chopsticks(nPhilo);
  
  for(int i=0; i<nPhilo; ++i) {
    auto c1 = unique_ptr<Chopstick>(new Chopstick());
    chopsticks[i] = move(c1);
  }

  vector<thread> tasks(nPhilo);

  // 첫번째 철학자는 작은 넘버의 젓가락부터 잡는다.
  tasks[0] = thread( think_and_eat,
      chopsticks[0].get(),
      chopsticks[nPhilo - 1].get(),
      0,
      0,
      nPhilo-1);

  // 나머지는 큰 넘버 젓가락부터 잡는다.
  for(int i=1; i< nPhilo; ++i)
  {
    tasks[i] = thread( think_and_eat,
        chopsticks[i-1].get(),
        chopsticks[i].get(),
        i,
        i-1,
        i
      );
  }

  // Many eat!
  for_each( tasks.begin(), tasks.end(), mem_fn(&thread::join));

  return 0;
}
