//Programmer: Sadeem Khan
//Programmer ID: 1549921

#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>

#include "Stack.h"

int main()
{
  // Identification
  cout << "Programmer: Sadeem Khan\n";
  cout << "Programmer's ID: 1549921\n";
  cout << "File: " << __FILE__ << endl;

  Stack<double> number;

  while (true)
  {
    string buf;
    cout << "Enter: ";
    if(number.size() != 0)
    {
      Stack<double> c = number;
      while(c.size() != 0)
      {
        cout << c.peek() << " ";
        c.pop();
      }
    }
    cin >> buf;

    if(buf == "q" || buf == "Q") break;
    if((buf == "/" || buf == "*" || buf == "-" || buf == "+") && number.size() >= 2)
    {
      if(buf == "/")
      {
        double a = number.peek();
        number.pop();
        double b = number.peek();
        number.pop();

        number.push(b / a);
      }

      if(buf == "*")
      {
        double a = number.peek();
        number.pop();
        double b = number.peek();
        number.pop();

        number.push(b * a);
      }

      if(buf == "-")
      {
        double a = number.peek();
        number.pop();
        double b = number.peek();
        number.pop();

        number.push(b - a);
      }

      if(buf == "+")
      {
        double a = number.peek();
        number.pop();
        double b = number.peek();
        number.pop();

        number.push(b + a);
      }
    }
    else number.push(atof(buf.c_str()));
  }
  return 0;
}