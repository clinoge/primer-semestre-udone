#include <iostream>
/* 
    "Importamos" cout, cin y endl para poder usarlos sin el
    operador de resolucion
*/
using std::cout;
using std::cin; 
using std::endl;

int main(int argc, char *argv[]) {
    char nombre[20];

    cout << "Cual es tu nombre?" << endl;
    cin >> nombre;

    cout << "Hola " << nombre << "!" << endl;

    return 0;
}
