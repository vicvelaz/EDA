// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void imprimeSol(std::vector<int> sol, int n);
// función que resuelve el problema
void torresColores(std::vector<int> &sol, int n, std::vector<int> &disp, std::vector<int>& coloc, int longi, bool &resul) {
	//probamos azul == 0
	if (disp[0] > coloc[0]) {
		//pongo un azul
		coloc[0] += 1;
		sol[longi] = 0;
		//me faltan piezas por colocar
		if (longi < n) {
			torresColores(sol, n, disp, coloc, longi + 1,resul);
		}
		//he colocado n piezas
		else if (coloc[0] + coloc[2] < coloc[1]) {
			imprimeSol(sol, n);
			resul = true;
		}
		//quito un azul
		coloc[0] -= 1;
	}
	//probamos rojo == 1
	if (disp[1] > coloc[1]) {
		//pongo un rojo
		coloc[1] += 1;
		sol[longi] = 1;
		//me faltan piezas por colocar
		if (longi < n) {
			torresColores(sol, n, disp, coloc, longi + 1,resul);
		}
		//he colocado n piezas
		else if (coloc[0] + coloc[2] < coloc[1]) {
			imprimeSol(sol, n);
			resul = true;
		}
		//quito un rojo
		coloc[1] -= 1;
	}
	//probamos verde == 2
	if (disp[2] > coloc[2] && coloc[2] < coloc[0] && sol[longi - 1] != 2) {
		//pongo un verde
		coloc[2] += 1;
		sol[longi] = 2;
		//me faltan piezas por colocar
		if (longi < n) {
			torresColores(sol, n, disp, coloc, longi + 1,resul);
		}
		//he colocado n piezas
		else if (coloc[0] + coloc[2] < coloc[1]) {
			imprimeSol(sol, n);
			resul = true;
		}
		//quito un verde
		coloc[2] -= 1;
	}
}
void imprimeSol(std::vector<int> sol, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (sol[i] == 0)
			std::cout << "azul ";
		else if(sol[i] == 1)
			std::cout << "rojo ";
		else 
			std::cout << "verde ";
	}
	std::cout << '\n';
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	
	
	int altura,azul,rojo,verde;
	bool resul = false;
	std::cin >> altura;
	if (altura==0)
		return false;
	std::cin >> azul >> rojo >> verde;
	std::vector<int> sol(altura);
	std::vector<int> disp(azul+rojo+verde);
	std::vector<int> coloc(azul + rojo + verde);
	
	torresColores(sol,altura,disp,coloc,0,resul);
	if (!resul)
		std::cout << "SIN SOLUCION \n";
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