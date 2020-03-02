// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int num;
	std::cin >> num;
	if (num==0)
		return false;
	std::map<std::string, int>mapa;
	std::string nombre, aux;
	for (int i = 0; i < num; ++i)
	{
		std::cin.ignore();
		getline(std::cin, nombre);
		std::cin >> aux;
		if (aux == "INCORRECTO")
			mapa[nombre] -=1;
		else
			mapa[nombre]+=1;
		
	}
	/*for (auto m : mapa)          //?¿?¿?¿?¿?¿?¿?
	{
		if (m.second != 0)
			std::cout << m.first << ", " << m.second<<'\n';
	}*/
	for (auto it = mapa.begin(); it != mapa.end(); ++it)
		if (it->second != 0)
			std::cout << it->first + ", " << it->second << '\n';
	std::cout << "---"<<'\n';
	
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