// Victor Velazquez Cabrera
// E68



#include <iostream>
#include <iomanip>
#include <fstream>



// función que resuelve el problema
int becariosPrecarios(int jefes,int contJefes) {
	int num,contBecariosPrecarios=0;
	std::cin >> num;
	if (num == 0)
	{
		if (contJefes >= jefes) return 1;
		else return 0;
	}
	else {
		for (int i = 0; i < num; ++i)
			contBecariosPrecarios+=becariosPrecarios(jefes, contJefes + 1);
		return contBecariosPrecarios;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int jefes;
	std::cin >> jefes;

	if (!std::cin)
		return false;

	int numBecarios = becariosPrecarios(jefes,0);
	std::cout << numBecarios << '\n';

	// escribir sol


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}