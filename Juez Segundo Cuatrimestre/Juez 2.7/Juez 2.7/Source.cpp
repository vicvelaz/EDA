// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <vector>



// función que resuelve el problema            //pila=
bool resolver(std::vector<int> const & altura) //mediano=
{                                              //alto=
	std::stack<int>pila;                       //alto, bajo, medio -> sin premio
	int mediano = -1, alto = -1;
	bool ganan = true;
	pila.push(altura[altura.size() - 1]);
	for (int i = altura.size()-2; i >= 0; --i)
	{
		if ((altura[i] < mediano) && (altura[i] < alto))
			ganan = false;
		while ((pila.size() > 0) && (pila.top() < altura[i]))
		{
			mediano = pila.top();
			pila.pop();
		}
		alto = altura[i];
		pila.push(altura[i]);
			
	}
	return ganan;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int num;
	std::cin >> num;
	if (!std::cin)
		return false;
	std::vector<int> altura(num);
	//std::stack <int> pila;
	for (int i = 0; i < num; ++i)
	{
		std::cin >> altura[i];

	}

	if (resolver(altura))
		std::cout << "SIEMPRE PREMIO" << '\n';
	else 
		std::cout << "ELEGIR OTRA" << '\n';

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