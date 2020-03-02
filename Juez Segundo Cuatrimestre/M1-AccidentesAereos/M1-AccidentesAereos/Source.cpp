//Victor Velazquez Cabrera
//E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <string>
using namespace std;

// función que resuelve el problema
string resolver(stack<int> &heridos,stack<string> &fechas,int const &herido,string const & fecha) {
	string sol = "NO HAY";
	int tam = heridos.size();
	if (tam == 0) {
		heridos.push(herido);
		fechas.push(fecha);
	}
	else {
		if (herido < heridos.top())
		{
			sol = fechas.top();
			heridos.push(herido);
			fechas.push(fecha);
		}
		else {
			bool encontrado = false;
			int i = 1;
			heridos.pop();
			fechas.pop();
			while (!encontrado&&i < tam)
			{
				if (herido < heridos.top())
				{
					sol = fechas.top();
					heridos.push(herido);
					fechas.push(fecha);
					encontrado = true;
				}
				else {
					heridos.pop();
					fechas.pop();
					++i;
				}
			}
			heridos.push(herido);
			fechas.push(fecha);
		//	if (!encontrado)
			//	sol = "NO HAY";
		}
	}
		return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int tam;
	cin >> tam;
	if (!std::cin)
		return false;
	stack<int> heridos;
	int herido;
	stack<string> fechas;
	string fecha;

	for (int i = 0; i < tam; ++i)
	{
		cin >> fecha >> herido;
		cout << resolver(heridos, fechas, herido, fecha) << endl;
	}
	cout << "---" << endl;



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