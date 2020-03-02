// Victor Velázquez Cabrera
// E68


#include <iostream>
#include <fstream>
#include <string>
// Solucion recursiva lineal no final
std::string decimalBinario(int n) {
	if (n == 0) return "0";
	else if (n == 1) return "1";
	else return decimalBinario(n / 2) + char('0' + n % 2);
}
bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (!std::cin) return false;
	std::cout << decimalBinario(n) << '\n';
	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();
#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}