//
// Tomás Oliveira e Silva, AED, September 2020
//
// example of a class
//

#include <math.h>
#include <iostream>

using namespace std;

class person
{
private:
  //variáveis
  const static int max_size = 99;
  const static int debug = 0;
  char d_name[max_size + 1];
  char d_address[max_size + 1];
  std::string d_phoneNumber;

public:
  person(const char *name = "", const char *address = "", const std::string phoneNumber = ""); // constructor
  ~person(void);                                                                               // destructor
  //setters
  void set_name(const char *name);
  void set_address(const char *address);
  void set_phoneNumber(const std::string phoneNumber);
  //getters
  const char *get_name(void);
  const char *get_address(void);
  const char *get_phoneNumber(void);
};
person::person(const char *name, const char *address, const std::string phoneNumber)
{ // constructor
  if (debug != 0)
    cout << "person constructor called" << endl;
  this->set_name(name);
  this->set_address(address);
  this->set_phoneNumber(phoneNumber);
}

person::~person(void)
{ // destructor
  if (debug != 0)
    cout << "person destructor called" << endl;
}

void person::set_name(const char *name)
{
  int i;
  /*
  In C and C++, strings are arrays of characters, terminated with a 0 (i.e., '\0')
  so, to copy a string, we need to do it one char at a time
  '\0' has the value 0, but is of type char
  the input name is silently truncated if it is too large (this may cause trouble
  if utf-8 is used to encode the string characters)
  */
  for (i = 0; name[i] != '\0' && i < max_size; i++)
    d_name[i] = name[i];
  d_name[i] = '\0'; // always terminate the string properly
}

void person::set_address(const char *address)
{
  int i;

  for (i = 0; address[i] != '\0' && i < max_size; i++)
    d_address[i] = address[i];
  d_address[i] = '\0';
}

void person::set_phoneNumber(const std::string p)
{
  d_phoneNumber = p;
}

inline const char *person::get_name(void)
{
  return d_name;
}

inline const char *person::get_address(void)
{
  return d_address;
}

inline const char *person::get_phoneNumber(void)
{
  return d_phoneNumber.c_str();
}

//kinda like toString() in Java
std::ostream &operator<<(std::ostream &os, person &p)
{ // make the << operator also work with the person data type
  return os << "[Name]: "
            << p.get_name()
            << "  [Address]: "
            << p.get_address()
            << "  [Phone Number]: "
            << p.get_phoneNumber()
            << endl;
}

int main(void)
{
  person p = person("John Doe", "no address", "12345"); // create a new object and then copy it to p
  person q("no name", "no address", "9999");            // create a new object (no copy needed)

  cout << "Before change of address: " << p.get_name() << ", " << p.get_address() << ", " << p.get_phoneNumber() << endl;
  p.set_address("bench 24, Central Park, New York");
  cout << "After change of address:  " << p.get_name() << ", " << p.get_address() << ", " << p.get_phoneNumber() << endl;

  cout << q; // use the << operator (q is a person!)
  return 0;
}