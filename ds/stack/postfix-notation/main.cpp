/*
 	Postfix notation caculator using Stack
*/
	
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Stack{
  private:
    int top;
    int capacity;
    int *storage;
  public:
    Stack( int capacity)
    {
      if( capacity <= 0) throw string( "Stack capacity must be positive");
      storage = new int[ capacity];
      this->capacity = capacity;
      top = -1;
    }

    void push(int value)
    {
      if( top == capacity) throw string( "Stack overflow!");
      top++;
      storage[top] = value;
    }

    int pop()
    {
      if( top == -1) throw string( "Stack is empty");
      top--;
      return storage[top+1];
    }

    bool isEmpty() { return (top == -1); }
};

int calculate( string expression)
{
  Stack s( 100);

  istringstream iss(expression);
  string token;
  while( getline( iss, token, ' ')) {
    try {
      if( token == "+") {
        int a = s.pop();
        int b = s.pop();
        s.push( a+b);
      } else if( token == "-") {
        int a = s.pop();
        int b = s.pop();
        s.push( a-b);
      } else if( token == "*") {
        int a = s.pop();
        int b = s.pop();
        s.push( a*b);
      } else if( token == "/") {
        int a = s.pop();
        int b = s.pop();
        s.push( a/b);
      } else {
        s.push( stoi(token));
      }
    } catch( exception &e) { continue; }
  }

  return s.pop();
}

int main(int argc, char** argv)
{
	/* starting code */
  string postfix = "3 5 + 4 2 + *";
  cout << "input postfix expression = " << postfix << endl;
  cout << "ret=" << calculate( postfix) << endl;
	/* end of code */
	return 0;
}
