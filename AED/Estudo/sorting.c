#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size(x) sizeof(x) / sizeof(x[0])

typedef int T;

//* Ver nos slides/videos para por resumos do que cada algoritmo faz, mais ou menos o que o TOS faz no quadro branco...


void bubble_sort(T* data, int first, int one_after_last) {
    int i, i_low, i_high, i_last;                                                         // iniciar as variáveis, i, i_low, i_high, e i_last

    i_low = first;                                                                        // atribuir ao i_low o first
    i_high = one_after_last - 1;                                                          // atribuir ao i:high o one_after_last - 1  
    while (i_low < i_high) {                                                              // enquanto o low for menor que o high 
        for (i = i_last = i_low; i < i_high; i++){                                        // for itera desde low ate high
            if (data[i] > data[i + 1]) {                                                  // se o elemento[i] for maior que o seguinte [i + 1]
                T tmp = data[i];                                                          // tmp do tipo T igual ao elemento[i]
                data[i] = data[i + 1];                                                    // elemento[i] toma o valor do seguinte
                data[i + 1] = tmp;                                                        // o elemento seguinte toma o valor do seu anterior
                i_last = i;                                                               // last toma o valor de i, em cada iteração, será usado no final no high
            }
        }
        i_high = i_last;                                                                  //! high toma o valor de last, high ficará igual a high - 1 
    }
}

void shaker_sort(T* data, int first, int one_after_last) {
    int i, i_low, i_high, i_last;                                                         // iniciar as variaveis i, i_low, i_high, i_last

    i_low = first;                                                                        // atribuir ao low o first
    i_high = one_after_last - 1;                                                          // atribuir ao high o one_after_last - 1

    while (i_low < i_high) {                                                              // enquanto low menor que high
        //up pass                                                                         // algoritmo da maniera ascendente
        for (i = i_last = i_low; i < i_high; i++){                                        // for itera desde low ate high
            if (data[i] > data[i + 1]) {                                                  // se o elemento[i] for maior que o seguinte [i + 1]
                T tmp = data[i];                                                          // tmp do tipo T igual ao elemento[i]
                data[i] = data[i + 1];                                                    // elemento[i] toma o valor do seguinte
                data[i + 1] = tmp;                                                        // o elemento seguinte toma o valor do seu anterior
                i_last = i;                                                               // last toma o valor de i, em cada iteração, será usado no final no high
            }
        }
        i_high = i_last;

        //down pass                                                                       // algoritmo da maneira descente
        for (i = i_last = i_high; i > i_low; i--){                                        // for itera desde high até low
            if (data[i] < data[i - 1]) {                                                  // se elemento[i] for menor que o elemento anterior [i - 1]
                T tmp = data[i];                                                          // tmp do tipo T, toma o valor do elemento[i]
                data[i] = data[i - 1];                                                    // elemento[i] toma o valor do antetior [i - 1]
                data[i - 1] = tmp;                                                        // elemento[i - 1] toma o valor do tmp, que corresponde elemento[i]
                i_last = i;                                                               // last toma o valor de i, em cada iteração, será usado no final no low
            }
        }   
        i_low = i_last;                                                                   //! low toma o valor de last, low fica igual a low - 1                             
    }
}

void insertion_sort(T* data, int first, int one_after_last) {                   
    int i, j;                                                                             // iniciar as variaveis i e j
    for (i = first + 1; i < one_after_last; i++) {                                        // for itera desde first + 1 até one_after_last, i++
        T tmp = data[i];                                                                  // tmp do tipo T, toma o valor do elemento[i]
        for (j = i; j > first && tmp < data[j - 1]; j--) {                                // for itera desde i até (enquanto j > first e tmp < elemento anterior[j - 1]), j--
            data[j] = data[j - 1];                                                        // elemento atual[i] toma o valor do elemento anterior[j - 1]
        }
        data[j] = tmp;                                                                    // elemento[j], já na posicao certa do array, toma o valor do tmp
    }
}

void shell_sort(T* data, int first, int one_after_last) {
    int i, j, h;                                                                          // iniciar as variaveis i, j, h

    for (h = 1; h < (one_after_last - first) / 3; h = 3 * h + 1)                          // for itera de modo a obter o h, através da expressão apresentada
        ;
    while (h >= 1) {                                                                      // enquanto o h for maior que 1
        for (i = first + h; i < one_after_last; i++) {                                    // for itera desde first + h, ate one_after_last, i++
            T tmp = data[i];                                                              // tmp do tipo T, fica com o elemento atual[i]
            for (j = i; j - h >= first && tmp < data[j - h]; j -= h) {                    //! for itera desde i, até aquilo que para ali está, confuso q fode
                data[j] = data[j - h];                                                    // elemento atual[j] toma o valor do anterior [j - 1]
            }
            data[j] = tmp;                                                                // elemento[j], já na posicao certa do array, toma o valor do tmp
        }
        h /= 3;                                                                           // h = h/3
    }
}

void quick_sort(T* data, int first, int one_after_last) {                                 //! Isto está grande que fode
    //TOS's function, for god sake, it's giant...                                         //! Depois ir à net ver uma cena disto mais simples e pequena
    int i, j, one_after_small, first_equal, n_smaller, n_larger, n_equal;
    T pivot, tmp;

    if (one_after_last - first < 20)
        insertion_sort(data, first, one_after_last);
    else {                                                                                // select pivot (median of three, the pivot's position will be one_after_last-1)
#define POS1 (first)
#define POS2 (one_after_last - 1)
#define POS3 ((first + one_after_last) / 2)
#define TEST(pos1, pos2)               \
    do                                 \
        if (data[pos1] > data[pos2]) { \
            tmp = data[pos1];          \
            data[pos1] = data[pos2];   \
            data[pos2] = tmp;          \
        }                              \
    while (0)
        TEST(POS1, POS2);  // bitonic
        TEST(POS1, POS3);  // sort of
        TEST(POS2, POS3);  // 3 items
#undef POS1
#undef POS2
#undef POS3
#undef TEST                                                                               
                                                                                          // 3-way partition. At the end of the while loop the items will be partitioned as follows:
                                                                                          // |first  "smaller part"|one_after_small  "larger part"|first_equal  "equal part"|one_after_last
        one_after_small = first;
        first_equal = one_after_last - 1;
        pivot = data[first_equal];
        i = first;
        while (i < first_equal)
            if (data[i] < pivot) {                                                        // place data[i] in the "smaller than the pivot" part of the array
                tmp = data[i];
                data[i] = data[one_after_small];                                          // tricky! this does the right thing when
                data[one_after_small] = tmp;                                              // i == one_after_small and when i > one_after_small
                i++;
                one_after_small++;
            } else if (data[i] == pivot) {                                                // place data[i] in the "equal to the pivot" part of the array
                first_equal--;
                tmp = data[i];                                                            // this is known to be the pivot, but we do it in this way
                data[i] = data[first_equal];                                              // to make life easier to those that need to adapt this
                data[first_equal] = tmp;                                                  // code so that it deals with more complex data items
            } else {                                                                      // data[i] becomes automatically part of the "larger than the pivot" part of the array
                i++;
            }
        n_smaller = one_after_small - first;
        n_larger = first_equal - one_after_small;
        n_equal = one_after_last - first_equal;
        j = (n_equal < n_larger) ? n_equal : n_larger;
        for (i = 0; i < j; i++) {                                                         // move the "equal to the pivot" part of the array to the middle
            tmp = data[one_after_small + i];
            data[one_after_small + i] = data[one_after_last - 1 - i];
            data[one_after_last - 1 - i] = tmp;
        }
        // recurse
        quick_sort(data, first, first + n_smaller);
        quick_sort(data, first + n_smaller + n_equal, one_after_last);
    }
}

//! merge_sort dont work, it says "segmentation fault"
// Utiliza um array temporáro para ordenar
void merge_sort(T* data, int first, int one_after_last) {                                 
    int i, j, k, middle;                                                                  // iniciar as variaveis i, j, k, middle     
    T* buffer;                                                                            // iniciar a variavel buffer, ponteiro do tipo do array 

    middle = (first + one_after_last) / 2;                                                // calcular o meio: first + one_after_last / 2

    merge_sort(data, first, middle);                                                      // recursividade: no intervalo [first, middle[  
    merge_sort(data, middle, one_after_last);                                             // recursividade: no intervalo [middle, one_after_last[

    buffer = (T*)malloc((size_t)(one_after_last - first) * sizeof(T)) - first;            //! alocar memoria para o buffer, não entendi o '- first' no final

    i = first, j = middle, k = first;                                                     // atribuir valores à variáveis i, k = first e j = middle

    while (k < one_after_last) {                                                          // enquanto k (first) menor que o one_after_last
                                                                                          // buffer[k++] dependendo da validacao da condicao, toma o valor elemento[i++] ou elemento[j++]
        buffer[k++] = (j == one_after_last || (i < middle && data[i] <= data[j])) ? data[i++] : data[j++];
    }

    for (i = first; i < one_after_last; i++) {                                            // for itera desde first ate one_after_last
        data[i] = buffer[i];                                                              // copiar elementos dos buffer para o array original
    }
    free(buffer + first);                                                                 // libertar o buffer //! + first 
}

// utiliza um heap para ordenar
void heap_sort(T* data, int first, int one_after_last) {
    int i, j, k, n;                                                                       // criar as variaveis i, j, k, n

    data += first - 1;                                                                    //! array ???? 
    n = one_after_last - first;                                                           // n toma o valor de elementos a ordenar

    // phase 1: heap construction
    for (i = n / 2; i >= 1; i--) {                                                        // for itera desde metade no n, ate um, com i--
        for (j = i; 2 * j <= n; j = k) {                                                  // for itera desde i, ate ao dobro do i menor que o n, com j = k em cada ciclo
            k = (2 * j + 1 <= n && data[2 * j + 1] > data[2 * j]) ? 2 * j + 1 : 2 * j;    // operador ternario para determinar valor de k
            if (data[j] >= data[k]) {                                                     // se o elemento[j] for maior ou igual ao elemento[k], quebra o ciclo
                break;
            }
            T tmp = data[j];                                                              // tmp conserva o elemento[j]
            data[j] = data[k];                                                            // elemento[j] toma o valor do elemento[k]
            data[k] = tmp;                                                                // elemento[k] toma o valor de tmp
        }
    }

    // phase 2: sort
    while (n > 1) {                                                                       // enquanto n > 1
        T tmp = data[1];                                                                  // tmp toma o valor do elemento[1]
        data[1] = data[n];                                                                // elemento[1] toma o valor do elemento[n]
        data[n--] = tmp;                                                                  // elemento[n--] = toma o valor do tmp
        for (j = 1; 2 * j <= n; j = k) {                                                  // for itera desde 1 ate (dobro de j menor ou igual que n), com j = k em cada ciclo
            k = (2 * j + 1 <= n && data[2 * j + 1] > data[2 * j]) ? 2 * j + 1 : 2 * j;    // operador ternario para determinar valor de k
            if (data[j] >= data[k]) {                                                     // se o elemento[j] for maior ou igual ao elemento[k], quebra o ciclo
                break;
            }
            T tmp = data[j];                                                              // tmp conserva o elemento[j]
            data[j] = data[k];                                                            // elemento[j] toma o valor do elemento[k]
            data[k] = tmp;                                                                // elemento[k] toma o valor de tmp
        }
    }
    
}

//* Won't be evaluated
void rank_sort(T* data, int first, int one_after_last) {
    int i, j, *rank;
    T* buffer;

    rank = (int*)malloc((size_t)(one_after_last - first) * sizeof(int)) - first;
    for (i = first; i < one_after_last; i++) {
        rank[i] = first;
    }
    for (i = first + 1; i < one_after_last; i++) {
        for (j = first; j < i; j++) {
            rank[(data[i] < data[j]) ? j : i]++;
        }
    }
    buffer = (T*)malloc((size_t)(one_after_last - first) * sizeof(T)) - first;  // no error check!
    for (i = first; i < one_after_last; i++) {
        buffer[i] = data[i];
    }
    for (i = first; i < one_after_last; i++) {
        data[rank[i]] = buffer[i];
    }
    free(buffer + first);
    free(rank + first);
}

//* Won't be evaluated
void selection_sort(T *data,int first,int one_after_last)
{
  int i,j,k;

  for(i = one_after_last - 1;i > first;i--)
  {
    for(j = first,k = 1;k <= i;k++)
      if(data[k] > data[j])
        j = k;
    if(j < i)
    {
      T tmp = data[i];
      data[i] = data[j];
      data[j] = tmp;
    }
  }
}

void merge_sort2(T *data,int first,int one_after_last)
{
  int i,j,k,middle;
  T *buffer;

  if(one_after_last - first < 30) // do not allocate less than 40 bytes
    insertion_sort(data,first,one_after_last);
  else
  {
    middle = (first + one_after_last) / 2;
    merge_sort2(data,first,middle);
    merge_sort2(data,middle,one_after_last);
    buffer = (T *)malloc((size_t)(one_after_last - first) * sizeof(T)) - first; // no error check!
    i = first;  // first input (first half)
    j = middle; // second input (second half)
    k = first;  // merged output
    while(k < one_after_last)
      if(j == one_after_last || (i < middle && data[i] <= data[j]))
        buffer[k++] = data[i++];
      else
        buffer[k++] = data[j++];
    for(i = first;i < one_after_last;i++)
      data[i] = buffer[i];
    free(buffer + first);
  }
}
int main(int argc, char const* argv[]) {
    int array[35] = {7, 6, 3, 4, 8, 9, 2, 3, 4, 5,5,4,6,7,8,33,44,55,66,77,3,2,1,2,3,4,5,6,5,4,3,2,1,2,3};

    //bubble_sort(array, 0, 10);
    //shaker_sort(array, 0, 10);
    //insertion_sort(array, 0, 10);
    //shell_sort(array, 0, 10);
    //quick_sort(array, 0, 10);
    //!merge_sort(array, 0, 10);  DIDNT WORK!
    //heap_sort(array, 0, 10);
    merge_sort2(array, 0, 35);

    //* The following algorithms won't be evaluated
    //rank_sort(array, 0, 10);
    //selection_sort(array, 0, 10);

    for (int i = 0; i < size(array); i++) {
        printf("%d  ", array[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}