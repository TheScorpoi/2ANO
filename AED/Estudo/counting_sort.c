//
// Counting Sort
// Adapatado do site: (24/12/2020)
// https://www.programiz.com/dsa/counting-sort
//
// I've noticed that this algorithms is very bad for large numbers, 
// so, it wont work particulary well...
//

void counting_sort(int *data, int first, int one_after_last) {
    int output[one_after_last];
    int max = data[0];
    int count[one_after_last];

    // Encontrar o maior elemento do array
    for (int i = 1; i < one_after_last; i++) {
        if (data[i] > max)
            max = data[i];
    }
    
    // Inicializar count tudo com zeros
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // guardar a informação de cada elemento
    for (int i = 0; i < one_after_last; i++) {
        count[data[i]]++;
    }

    // Guardar a comulative sum de cada array
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Encontrar o indice de cada elememto no array original (data) no count 
    // e colocar os elementos no array ordenado (output)
    for (int i = one_after_last - 1; i >= 0; i--) {
        output[count[data[i]] - 1] = data[i];
        count[data[i]]--;
    }

    // Copia de output para data
    for (int i = 0; i < one_after_last; i++) {
        data[i] = output[i];
    }
}