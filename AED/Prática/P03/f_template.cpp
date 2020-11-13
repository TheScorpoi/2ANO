//
// Tomás Oliveira e Silva, AED, September 2020
//
// example of a generic function (with a template)
//




//? oK, isto de usar tamanho de arrays em C++, é estupido, para que "dê" temos de fazer isso na main, como tenho nesta main em especifico 
//? e depois sim usar dentro da funcao como argumento de entrada na mesma
//? 
//? Ao usar o size(array), dentro da função aquilo pelos vistos calcula o número de bits, e estraga as contas todas, idk, é estúpido, BRING JAVA BACK AGAIN!!




#include <iostream>
#include <iomanip>

using namespace std;

#define size(x)  (int)(sizeof(x) / sizeof(x[0])) //maneira de definir o tamanho de um array...
                                                 // fucking well, pq que não está definida ja no C...

template <typename T> //i already didnt know who the fuck means template on C ...
//! is this like a function? idk... 
T sum(const T *a,int n)
{
  T s = T(0);
  for(int i = 0;i < n;i++)
    s += a[i];
  return s;
}

//media para arrays em int
double average( int  *array, int sizeArray){
  double sum = 0.0;
  double counter = 0.0;

  for (int i = 0; i < sizeArray; i++)
  {
    sum += array[i];
    counter += 1;
  }
  double res = sum/counter;
  return res;
}

//media para arrays em double
double average( double  *array, int sizeArray){
  double sum = 0.0;
  double counter = 0.0;

  for (int i = 0; i < sizeArray; i++)
  {
    sum += array[i];
    counter += 1;
  }
  double res = sum/counter;
  return res;
}


int main(void)
{
  int ia[] = { 1,2,3,4,5 };
  double da[] = { 1.0,3.0,5.0 };

  cout << "ia[] sum: "
       << std::setw(5)
       << sum<int>(ia,size(ia))
       << endl
       << "da[] sum: "
       << std::fixed << std::setw(10) << std::setprecision(2)
       << sum<double>(da,size(da))
       << endl
       << "Media ia[]: "
       << std::setw(5)
       << average(ia, size(ia))
       << endl
       << "Media da[]: "
       << std::setw(5)
       << average(da, size(da))
       << endl;
  return 0;
}
