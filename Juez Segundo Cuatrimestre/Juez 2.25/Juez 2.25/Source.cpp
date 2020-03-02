// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include"bintree_eda.h"

// función que resuelve el problema
struct tSol {
	bool okey;
	int profundidad;
	int numero;
};

tSol resultado(bintree<int> const & t,std::vector<bool>const &primos) 
{
	if (t.empty())
		return{ false,0,0 };
	else if (primos[t.root()])
		return{ false,0,0 };
	else if (t.root() % 7 == 0)
		return { true,1,t.root() };
	else {
			tSol izq= resultado(t.left(), primos);
			tSol dcha= resultado(t.right(), primos);
			if (izq.okey&&dcha.okey)
			{
				if (izq.profundidad <= dcha.profundidad)
					return { true,1 + izq.profundidad,izq.numero };
				else
					return { true,1 + dcha.profundidad,dcha.numero };
			}
			else if (izq.okey)
				return { true,1 + izq.profundidad,izq.numero };
			else if (dcha.okey)
				return { true,1 + dcha.profundidad,dcha.numero };
			else
				return { false,0,0 };
	}
}



std::vector<bool> criba(){
	int num = 5000;
	std::vector<bool> primos(num);

	for (int i = 0; i < num; ++i) {
		primos[i] = true;                                            
	}
	for (int i = 2; i*i< num; ++i) {
		if (primos[i]) {
			for (int cont = 2*i; cont < num; cont +=i) {
				primos[cont] = false;
			}
		}
	}
	return primos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	std::vector<bool> primos = criba();
	bintree<int> t = leerArbol(-1);
	tSol solucion = resultado(t, primos);
	if (solucion.okey)
		std::cout << solucion.numero << " " << solucion.profundidad << '\n';
	else
		std::cout << "NO HAY" << '\n';
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}