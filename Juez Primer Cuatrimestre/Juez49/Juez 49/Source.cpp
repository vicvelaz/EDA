// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol {
	bool existe;
	int indice;
	
};
// función que resuelve el problema
tSol interseccion(std::vector<int> const &creciente, std::vector<int> const &decreciente,int ini,int fin) {
	if (ini + 1 == fin) //Caso base tamaño 1
	{
		if (creciente[ini] == decreciente[ini])
			return { true,ini};
		else if (creciente[ini] > decreciente[ini])
			return { false,ini - 1};
		else
			return{ false,ini};
	}
	else if (ini + 2 == fin) //Caso base tamaño 2
	{
		if (creciente[ini] == decreciente[ini])
			return { true,ini};
		else if (creciente[ini + 1] == decreciente[ini + 1]) 
			return { true,ini + 1}; 
		else if (creciente[ini] > decreciente[ini]) //Se cruzan a la izquierda del intervalo
			return { false,ini - 1};
		else if ((creciente[ini] < decreciente[ini])&& (creciente[ini + 1] > decreciente[ini + 1])) //se cruzan en ese intervalo
			 return { false,ini };
		else //Se cruzan a la derecha del intervalo
			return  { false, fin - 1};
	}
	else {
		int m = (ini + fin - 1) / 2;
		if (creciente[m] == decreciente[m])
			return{ true,m};
		else if (creciente[m] > decreciente[m])
			return interseccion(creciente, decreciente, ini, m+1);
		else
			return interseccion(creciente, decreciente, m, fin);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam;
	std::cin >> tam;
	if (tam==0)
		return false;
	std::vector<int> creciente(tam); //funcion creciente
	for (int i = 0; i < tam; ++i)
		std::cin >> creciente[i];
	std::vector<int> decreciente(tam); //funcion decreciente
	for (int i = 0; i < tam; ++i)
		std::cin >> decreciente[i];
	tSol solucion=interseccion(creciente, decreciente, 0, tam);
	int indice = solucion.indice;
	if (solucion.existe == true)
		std::cout << "SI " << indice << '\n';
	else
		std::cout << "NO " << indice << " " << indice+1 << '\n';

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