// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>

struct inv {
	long long int inver;
	long long int pot;
};
// función que resuelve el problema
inv inverso(long long int num)
{
	inv solucion;
	if (num < 10)
	{
		solucion.inver = 9 - num;
		solucion.pot = 10;
	}
	else
	{
		solucion = inverso(num / 10);
		solucion.inver += solucion.pot*(9 - (num % 10));
		solucion.pot *= 10;
	}
	return solucion;
}


long long int complementario(long long int num) {
	if (num < 10)
		return (9 - num);
	else
	{
		return complementario(num/10)*10+(9-(num%10));
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	long long int  num;
	std::cin >> num;

	 std::cout<<complementario(num)<<" "<<inverso(num).inver<<'\n';
	// escribir sol


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