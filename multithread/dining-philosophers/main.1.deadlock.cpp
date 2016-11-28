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

void think_and_eat( Chopstick* left, Chopstick *right, int philoId, int leftChopstickId, int rightChopstickId)
{
  while( true) {

    // think
    this_thread::sleep_for(chrono::milliseconds(10));

    if( left == right) 
      throw "left chopstick && right chopstick should not be the same!";

    // eat
    left->m.lock();
    string sl = "  (L)Philosopher " + to_string(philoId) + " picked " + to_string( leftChopstickId) + " chopstick.";
    cout << sl << endl;

    right->m.lock();
    string sr = "  (R)Philosopher " + to_string(philoId) + " picked " + to_string( rightChopstickId) + " chopstick.";
    cout << sr << endl;

    string pe = "Philosopher " + to_string( philoId) + " eats.";
    cout << pe << endl;

    left->m.unlock();
    right->m.unlock();
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

  // 첫번째 철학자만 젓가락이 자기 옆, 맨끝 옆 젓가락이다.
  tasks[0] = thread( think_and_eat,
      //chopsticks[0].get(),
      //chopsticks[nPhilo - 1].get(),
      chopsticks[nPhilo - 1].get(),
      chopsticks[0].get(),
      0,
      nPhilo-1, 
      0);

  // 나머지는 자기 양옆 젓가락을 쓴다.
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
