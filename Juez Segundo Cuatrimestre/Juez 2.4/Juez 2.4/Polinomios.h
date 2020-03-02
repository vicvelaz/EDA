#ifndef POLINOMIO
#define POLINOMIO
#include<vector>
class Polinomio {
public:
	Polinomio() {
		//std::vector<monomio>monomios ;
		//indice = 0;
	};
	void setMonomio(int coe, int exp) {
		monomio m;
			m.coeficiente = coe;
			m.exponente = exp;
			monomios.push_back(m);
	}
	int evaluar(int n) {
		int resultado = 0;
		for (int i = 0; i < monomios.size(); ++i)
		{
			int mult = 1;
			for (int j = 0; j < monomios[i].exponente; ++j)
				mult *= n;
			resultado += mult * monomios[i].coeficiente;
		}
		return resultado;
	}

private:
	struct monomio {
		int coeficiente;
		int exponente;
	};
	
	std::vector<monomio>monomios;
};


#endif