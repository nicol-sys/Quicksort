#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

// Función para generar números aleatorios únicos en un rango
std::vector<int> numeroramdom(int min, int max, int count) {
    std::vector<int> numeros;
    
    if (count > (max - min + 1)) {
        std::cerr << "No se pueden generar números únicos suficientes en el rango especificado." << std::endl;
        return numeros;
    }
    
    // Llena un vector con números en orden creciente
    for (int i = min; i <= max; i++) {
        numeros.push_back(i);
    }
    
    // Mezcla los números aleatoriamente
    srand(time(0));
    for (int i = max; i > min; i--) {
        int j = rand() % (i - min + 1) + min;
        std::swap(numeros[i - min], numeros[j - min]);
    }
    
    // Devuelve los primeros "count" números del vector mezclado
    std::vector<int> result(numeros.begin(), numeros.begin() + count);
    return result;
}

// Función para intercambiar dos elementos del arreglo
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Función para encontrar la posición correcta del pivote en el arreglo
int dividir(int arr[], int izq, int derecha) {
    int pivot = arr[derecha]; // Tomamos el último elemento como pivote
    int i = (izq - 1); // El índice del elemento más pequeño

    for (int j = izq; j <= derecha - 1; j++) {
        // Si el elemento actual es menor o igual al pivote, lo intercambiamos con el elemento en la posición i
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Finalmente, intercambiamos el pivote con el elemento en la posición i+1 para colocar el pivote en su posición correcta
    swap(arr[i + 1], arr[derecha]);
    return (i + 1);
}

// Función para ordenar el arreglo utilizando QuickSort
void quickSort(int arr[], int izq, int derecha) {
    if (izq < derecha) {
        int pi = dividir(arr, izq, derecha); // Encuentra la posición del pivote
        quickSort(arr, izq, pi - 1); // Ordena los elementos antes del pivote
        quickSort(arr, pi + 1, derecha); // Ordena los elementos después del pivote
    }
}

int main() {
    // Llama a la función para generar números aleatorios únicos
    const int size = 20;
    std::vector<int> numerosunicos = numeroramdom(1, 100, size);

    if (numerosunicos.empty()) {
        return 1;
    }

    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = numerosunicos[i];
    }

    std::cout << "Arreglo sin ordenar:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    quickSort(arr, 0, size - 1);

    std::cout << "Arreglo ordenado:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

