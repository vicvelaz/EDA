// Victor Velazquez Cabrera
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tMatriz = std::vector<std::vector<int>>;

// función que resuelve el problema

void mejorCompra(int n, int m, tMatriz const & precio, int &mejor, int compra, std::vector<int> &comprados, int actual,std::vector<int> const & mejorPrecioAcumulado) //actual es el indice del producto
{
	
		for (int i = 0; i < m; ++i)
		{
			if (comprados[i] < 3)
			{
				++comprados[i];
				if (actual == n - 1)
				{
					if (compra + precio[i][actual] < mejor)
						mejor = compra + precio[i][actual];
				}
				//si me quedan mas productos por comprar
				else if(compra+mejorPrecioAcumulado[actual]<mejor)
					mejorCompra(n, m, precio, mejor, compra + precio[i][actual], comprados, actual + 1,mejorPrecioAcumulado);
				--comprados[i];
			}
		}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int supermercados, productos,mejor=0;
	std::cin >> supermercados >> productos;
	tMatriz matriz(supermercados, std::vector<int>(productos));

	std::vector<int> comprados(supermercados,0),
		mejorPrecio(productos),
		mejorPrecioAcumulado(productos);
	
	for (int i = 0; i < supermercados; ++i) 
	{
		for (int j = 0; j < productos; ++j)
		{
			std::cin >> matriz[i][j]; //Guarda el precio en la matriz
		}
	}
	for(int i=0;i<supermercados;++i)
	{
		
		for (int j = 0; j < productos; ++j)
		{
			if((3*(i+1)>j)&&(j>(3*(i+1)-4)))
				mejor+=matriz[i][j];
		}
	}
	int sumaPrecio = 0;

	for (int j = 0; j < productos; ++j)  //Busca los mejores precios
		for (int i = 0; i < supermercados; ++i)
		{
			if (mejorPrecio[j] == 0)
				mejorPrecio[j] = matriz[i][j];
			else if (mejorPrecio[j] > matriz[i][j])
			{
				mejorPrecio[j] = matriz[i][j];
			}
		}
	
	for (int i = productos - 1; i >= 0; --i) //Realiza la acumulacion de los mejores precios de cada producto
	{
		sumaPrecio += mejorPrecio[i];
		mejorPrecioAcumulado[i] = sumaPrecio;
	}

	
	if (productos > 3 * supermercados)
		std::cout << "Sin solucion factible" << '\n';
	else
	{
		mejorCompra(productos, supermercados, matriz, mejor, 0, comprados, 0,mejorPrecioAcumulado);
		std::cout << mejor << '\n';
	}
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