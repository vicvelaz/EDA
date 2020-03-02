// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <deque>
#include <fstream>
using namespace std;


bool resuelveCaso()
{
	int longSubintervalo, numSobres;
	deque<int> intervalo, candidatosMax;
	int maximo = 0, aux;

	cin >> numSobres >> longSubintervalo;

	if (numSobres != 0 || longSubintervalo != 0)
	{
		if (longSubintervalo != 1)
		{
			maximo = 0;
			intervalo.clear();
			candidatosMax.clear();

			// LEEMOS LOS DATOS PRIMER SUBINTERVALO
			for (int i = 0; i < longSubintervalo; i++)
			{
				cin >> aux;
				intervalo.push_back(aux);

				if (aux > maximo)
				{
					maximo = aux;
					candidatosMax.clear();
				}
				else
				{
					while (candidatosMax.size() > 0 && candidatosMax.back() < aux)
						candidatosMax.pop_back();

					candidatosMax.push_back(aux);
				}
			}
			// AVANZAMOS
			for (int i = longSubintervalo; i < numSobres; i++)
			{
				cout << maximo << " ";

				if (intervalo.front() == maximo)
				{
					maximo = candidatosMax.front();
					candidatosMax.pop_front();
				}

				cin >> aux;
				intervalo.pop_front();
				intervalo.push_back(aux);

				if (aux > maximo)
				{
					maximo = aux;
					candidatosMax.clear();
				}
				else
				{
					while (candidatosMax.size() > 0 && candidatosMax.back() < aux)
						candidatosMax.pop_back();

					candidatosMax.push_back(aux);
				}
			}

			cout << maximo << '\n';
		}
		else
		{
			cin >> aux;

			for (int i = 0; i < numSobres - 1; i++)
			{
				cout << aux << " ";
				cin >> aux;
			}
			cout << aux << '\n';
		}
		return true;
	}
	else
		return false;
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