//
// Tomás Oliveira e Silva, AED, September 2020
//
// example of function overloading (same function name, different argument numbers and/or data types)
//

#include <iostream>

using std::cout; // make this symbol from the std namespace directly visible

void show(const int i)
{
  cout << "int: "
       << i
       << std::endl;
}

void show(const double d)
{
  cout << "double: "
       << d
       << std::endl;
}

void show(const char *s,const char *h = "string: ") // second argument with default value
{
  cout << h
       << s
       << std::endl;
}

void show(const char c) {
  cout << "char: "
      << c
      << std::endl;    
}


void show(const int *a){
  /*
  cout << "array (ugly): ";
  for (int i = 0; i < 2; i++)
  {
    cout << a[i] << ", ";  
  }
  cout << "]" << std::endl;
  */
  cout << "array: [";
    for (int i = 0; i < 2; i++)
    {
      cout << a[i] << ", ";
    }
    cout << a[2] << "]"
         << std::endl; 
}


int main(void)
{
  int a[3] = {1, 2, 3};

  show(1.0);
  show("hello");
  show(-3);
  show("John","name: ");
  show('a');  
  show(a);
  return 0;
}
