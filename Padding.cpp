// Padding.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cstddef>
#include <chrono>
#include <vector>

class Prueba1 {
public:
    char a; // 1 byte
    int b; //4 bytes
    short c; //2 bytes
    double d; //8 bytes
};

class Prueba2 {
public:
    double d; // 8
    int b; // 4
    short c; // 2
    char a; // 1
};

int main()
{ /*
    std::cout << "Inicio del dato 1: " << offsetof(Prueba1, a) << std::endl;
    std::cout << "Inicio del dato 2: " << offsetof(Prueba1, b) << std::endl;
    std::cout << "Inicio del dato 3: " << offsetof(Prueba1, c) << std::endl;
    std::cout << "Inicio del dato 4: " << offsetof(Prueba1, d) << std::endl;

    std::cout << sizeof(Prueba1) << std::endl;


    std::cout << "Inicio del dato 1: " << offsetof(Prueba2, d) << std::endl;
    std::cout << "Inicio del dato 2: " << offsetof(Prueba2, b) << std::endl;
    std::cout << "Inicio del dato 3: " << offsetof(Prueba2, c) << std::endl;
    std::cout << "Inicio del dato 4: " << offsetof(Prueba2, a) << std::endl;

    std::cout << sizeof(Prueba2) << std::endl;
    std::cout << alignof(Prueba2) << std::endl;
    */
    std::cout << "Tamaño de la clase Mal organizada" << sizeof(Prueba1) << std::endl;
    std::cout << "Tamaño de la clase mejor organizada" << sizeof(Prueba2) << std::endl;

    const size_t N = 200'000'000;
    std::vector<Prueba1> vMalo(N); //4.9GB
    std::vector<Prueba2> vBueno(N);
    for (size_t i = 0; i < N;i++) {
        //vMalo[i].d = i;
        vBueno[i].d = i;
    }
    auto start1 = std::chrono::high_resolution_clock::now();
    double sum1 = 0;
    for (size_t i = 0; i < N; i++) {
       sum1 += vMalo[i].d;
    }
    auto end1 = std::chrono::high_resolution_clock::now();

    auto Temp1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count();
    
    auto start2 = std::chrono::high_resolution_clock::now();
    double sum2 = 0;
    for (size_t i = 0; i < N; i++) {
        sum2 += vBueno[i].d;
    }
    auto end2 = std::chrono::high_resolution_clock::now();

    auto Temp2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count();


    std::cout << "Tiempo de la estructura mala: " << Temp1 << "ms" << std::endl;
    std::cout << "Tiempo de la estructura Buena: " << Temp2 << "ms" << std::endl;

}

