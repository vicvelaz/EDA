// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stack>


// función que resuelve el problema
bool resolver(std::string linea) {

	const char *cadena = linea.c_str();
	std::stack<char> pila;
	for (; *cadena; cadena++)
	{
		if (*cadena == '(')
			pila.push(')');
		else if (*cadena == '[')
			pila.push(']');
		else if (*cadena == '{')
			pila.push('}');
	
		else if (*cadena == ')')
		{
			if (pila.empty())
				return false;
			else if(pila.top() == ')')
				pila.pop();
			else
				return false;
		}
		else if (*cadena == ']')
		{
			if (pila.empty())
				return false;
			else if (pila.top() == ']')
				pila.pop();
			else
				return false;
		}
		else if (*cadena == '}')
		{
			if (pila.empty())
				return false;
			else if (pila.top() == '}')
				pila.pop();
			else
				return false;
		}
	}
	if (pila.empty())
		return true;
	else
		return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::string linea;
	std::getline(std::cin, linea);

	if (!std::cin)
		return false;

	if (resolver(linea))
		std::cout << "SI" << '\n';
	else
		std::cout << "NO" << '\n';

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