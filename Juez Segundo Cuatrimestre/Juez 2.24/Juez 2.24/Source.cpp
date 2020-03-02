// Victor Velazquez Cabrera
// UE68


#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include "bintree_eda.h"
#include "queue_eda.h"

template <typename T>
bintree<T> reconstruir(queue<T> &pre, queue<T> &in) {

	if (pre.empty()) return {};

	T raiz = pre.front(); pre.pop();
	T i = in.front();

	if (pre.empty()) return { raiz };

	queue<T> izq = {};
	queue<T> der = {};

	while (i != raiz) {
		der.push(i); in.pop();
		izq.push(pre.front()); pre.pop();
		i = in.front();
	}
	in.pop();

	return { reconstruir(izq, der), raiz, reconstruir(pre, in) };
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	queue<int> in;
	queue<int> pre;

	std::string line;
	std::getline(std::cin, line);
	std::stringstream ss(line);

	int num;
	while (ss >> num) pre.push(num);

	std::getline(std::cin, line);
	std::stringstream ss2(line);

	int num2;
	while (ss2 >> num2) in.push(num2);

	if (!std::cin)  // fin de la entrada
		return false;

	bintree<int> arbol = reconstruir(pre, in);
	std::vector<int> postorden = arbol.postorder();

	for (unsigned int i = 0; i < postorden.size() - 1; ++i) {
		std::cout << postorden[i] << " ";
	}
	std::cout << postorden[postorden.size() - 1] << std::endl;

	return true;
}



int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar t odo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}