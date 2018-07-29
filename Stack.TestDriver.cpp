// Programmer: Sadeem Khan
// Programmer's ID: 1549921

#include <iostream>
using namespace std;

#include<cassert>

#include "Stack.h"
#include "Stack.h"

int main()
{
  // Identification
  cout << "Programmer: Sadeem Khan\n";
  cout << "Programmer's ID: 1549921\n";
  cout << "File: " << __FILE__ << endl;

  // Test using ints
  Stack<int> a;
  for (int i = 0; i < a.size(); i++)
  {
    assert(a.peek() == 0);
    a.pop();
  }

  cout << "\nTesting push, peek, pop, empty and clear\n";
  a.push(3131);
  a.push(2121);
  cout << "EXPECTED: 2121\n";
  cout << "ACTUAL: " << a.peek() << endl;
  a.pop();
  cout << "Expected: 3131" << endl;
  cout << "Actual result: " << a.peek() << endl;
  a.push(1111);
  a.push(4141);
  cout << "Expected: 3" << endl;
  cout << "Actual result: " << a.size() << endl;
  a.clear();
  cout << "Expected: 1" << endl;
  cout << "Actual result: " << a.empty() << endl;

  // Const object test
  cout << "\nConst object test" << endl;
  const Stack<int> c;
  assert(c.size() == 0);
  assert(c.empty());

  a.push(3200);
  a.push(4200);
  // object copy test
  cout << "\nObject copy test\n";
  Stack<int> d = a; // making a copy
  assert(a.size() == d.size());
  for (int i = 0; i < a.size(); i++)
  {
    assert(a.peek() == d.peek());
    a.pop();
    d.pop();
  }

  a.push(5200);
  a.push(6200);
  // object assignment test
  cout << "\nObject assignment test\n";
  Stack<int> e; e = a;
  assert(a.size() == e.size());
  for (int i = 0; i < 10; i++) 
  {
    assert(a.size() == e.size());
    a.pop();
    e.pop();
  }
}