#include <iostream>
#include <vector>
#include <functional>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::function;

template<typename De, typename A>
vector<A> mapear(function<A(De)> f, vector<De> xs) {
  vector<A> ys;
  for (auto x : xs) {
    ys.push_back(f(x));
  }
  return ys;
}

template<typename De, typename A>
function<A(De)> siempre(const A x) {
  return [x](De y) { return x; };
}

template<typename T>
T reducir(function<T(T,T)> f, vector<T> xs, T inicial) {
  T resultado = inicial;
  for (auto x: xs) {
    resultado = f(resultado, x);
  }

  return resultado;
}

template<typename T>
vector<T> voltear(vector<T> xs) {
  vector<T> ys;
  for (auto x : xs) {
    ys.insert(ys.begin(), x);
  }
  return ys;
}

template<typename T>
vector<T> tomar(int n, vector<T> xs) {
  vector<T> ys;
  int contador = 0;
  
  for(auto x : xs) {
    if (contador < n) {
      ys.push_back(x);
      contador++;
    } else {
      break;
    }
  }

  return ys;
}

template <typename T>
vector<T> imprimirVector(vector<T> xs) {
  cout << "[";
  for(auto x: xs) {
    cout << " " << x;
  }
  cout << " ]" << endl;
  return xs;
}

int sumar(int a, int b) {
  return a + b;
}


int main(int argc, char *argv[]) {
  function<bool(int)> siempreVerdad = siempre<int, bool>(false);

  vector<int> numeros = {1,2,3,4,5};
  vector<bool> resultado;
  int resultadoReducir;
  function<int(int,int)> fSumar = sumar;
  vector<int> volteados;
  vector<int> resultadoTomar;
  vector<int> resultadoTomarNada;
  
  resultado = mapear<int,bool>(siempreVerdad, numeros);

  cout << "Resultado de mapear [1,2,3,4,5] con f :: Int -> Bool" << endl;
  imprimirVector<bool>(resultado);
  
  resultadoReducir = reducir<int>(fSumar, numeros, 0);

  cout << "Resultado de reducir [1,2,3,4,5] con f :: Int -> Int -> Int" << endl;
  cout << resultadoReducir << endl;

  cout << "Resultado de voltear [1,2,3,4,5]" << endl;
  volteados = voltear<int>(numeros);
  imprimirVector<int>(volteados);

  cout << "Resultado de tomar 2 [1,2,3,4,5]" << endl;
  resultadoTomar = tomar<int>(2, numeros);
  imprimirVector<int>(resultadoTomar);

  cout << "Resultado de tomar 0 [1,2,3,4,5]" << endl;
  resultadoTomarNada = tomar<int>(0, numeros);
  imprimirVector<int>(resultadoTomarNada);
  
  return 0;
}
