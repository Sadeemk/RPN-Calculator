// Programmer: Sadeem Khan
// Programmer's ID: 1549921

#ifndef Stack_h
#define Stack_h

#include <algorithm>
using namespace std;

template <typename V>
class Stack
{
  V* values;
  int cap;
  int siz; // use siz instead of size to avoid name collisions
  void capacity(int);

  public:
  Stack(int = 10);
  void pop() {if (siz > 0) --siz;} // inline
  void clear() {siz = 0;} // inline
  void push(const V&);
  V& peek();
  int size() const {return siz;} // inline
  bool empty() const {return siz == 0;} // inline
  ~Stack() {delete [] values;} // inline
  Stack<V>& operator=(const Stack<V>&);
  Stack(const Stack<V>&);
};

template <typename V>
Stack<V>::Stack(int cap)
{
  this->cap = cap;
  values = new V[cap];
  siz = 0;

  for (int index = 0; index < cap; index++)
    values[index] = V();
}

template <typename V>
Stack<V>& Stack<V>::operator=(const Stack<V>& original)
{
  if (this != &original) // if it's not a self copy...
  {
    // do what the destructor does
    delete [] values;

    // do what the copy constructor does
    cap = original.cap; // still just a copy 
    siz = original.siz;
    values = new V[cap]; // not a copy -- new object gets its own array
    for (int i = 0; i < cap; i++) // copy the contents of the array from the original...
      values[i] = original.values[i]; // ...to the copy
  }
  return *this; // return a self reference
}

template <typename V>
Stack<V>::Stack(const Stack<V>& original)
{
  siz = original.siz; 
  cap = original.cap; // still just a copy
  values = new V[cap]; // not a copy -- new object gets its own array
  for (int i = 0; i < cap; i++) // copy the contents of the array from the original...
    values[i] = original.values[i];  // ...to the copy
}

template <typename V>
void Stack<V>::push(const V& value)
{
  if (siz == cap) capacity(2 * cap);
  values[siz] = value;
  ++siz;
}

template <typename V>
V& Stack<V>::peek()
{
  if(siz-1 < 0) return values[0];
  if(siz-1 >= cap) capacity(2 * cap);
  return values[siz-1];
}

template <typename V>
void Stack<V>::capacity(int newCap)
{
  // allocate a new array with the new capacity
  V* temp = new V[newCap];

  // get the lesser of the new and old capacities
  int limit = min(newCap,cap);

  // copy the contents
  for (int i = 0; i < limit; i++)
    temp[i] = values[i];
  
  // set added values to their defaults
  for (int i = limit; i < cap; i++)
    temp[i] = V();

  // deallocate original array
  delete [] values;

  // switch newly allocated array into the object
  values = temp;

  // update the capacity
  cap = newCap;
}
#endif