#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <limits> 

using namespace std;

class Data {
	int dia, mes, ano;
	public:
	
	/*
	O m�todo abaixo retornar� -1 se d1 � anterior a d2
	Retornar� 0 se d1 = d2
	Retornar� +1 se d1 � posterior a d2
	*/
		static int compara(const Data &d1, const Data &d2)
		{
			if (d1.ano < d2.ano)
			{
				return -1; // d1 é menor que d2
			}
			else if (d1.ano > d2.ano)
			{
				return 1; // d1 é maior que d2
			}
			else
			{ // Os anos são iguais
				if (d1.mes < d2.mes)
				{
					return -1; // o mes de d1 é menor q d2
				}
				else if (d1.mes > d2.mes)
				{
					return 1; // d1 é maior que d2
				}
				else
				{ // Os anos e meses são iguais
					if (d1.dia < d2.dia)
					{
						return -1; // o dia de d1 é menor que o d2
					}
					else if (d1.dia > d2.dia)
					{
						return 1; // o dia de d1 é maior que o d2
					}
					else
					{ // As datas são iguais
						return 0;
					}
				}
			}
		}

	Data (int _dia, int _mes, int _ano) {
		dia = _dia;
		mes = _mes;
		ano = _ano;
	}
	string toString() {
		string ret = "";
		ret.append(to_string(dia));
		ret.append("/");
		ret.append(to_string(mes));
		ret.append("/");
		ret.append(to_string(ano));
		return ret;
	}
};

class Lista {
	public:
	virtual void entradaDeDados() =0;
	virtual void mostraMediana() =0;
	virtual void mostraMenor() =0;
	virtual void mostraMaior() =0;
};

class ListaNomes {
	vector<string> lista;
	
	public:
	
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() {
		lista.push_back("Teste");
	}
		
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de strings" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar o primeiro nome alfabeticamente" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar o ultimo nome alfabeticamente" << endl;
	}
};

class ListaDatas  {
	vector<Data> lista;
	
	public:
		
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() {
		
	}
	
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de datas" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar a primeira data cronologicamente" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar a ultima data cronologicamente" << endl;
	}
};

class ListaSalarios  {
	vector<double> lista;
	
	public:
	//funsao para ver quantidade de salario da lista
	void entradaDeDados() {
        int ElementosSalario;
        cout << "Quantos salários existirão na lista? ";
        cin >> ElementosSalario;

        for (int i = 0; i < ElementosSalario; i++) {
            double salario;
            cout << "Digite o salário " << i + 1 << ": ";
            cin >> salario;
            lista.push_back(salario);
        }
    }
//funsao para mostrar a mediana da lista de salarios
    void mostraMediana() {

        //funsao para ordenar salarios.
        sort(lista.begin(), lista.end());

        int tamanho = lista.size();

        if (tamanho % 2 == 0) {
        // Se a quantidade de salários for par, média das duas do meio.
            double mediana = (lista[tamanho / 2 - 1] + lista[tamanho / 2]) / 2.0;
            std::cout << "Mediana dos salários: " << mediana << endl;
        } else {
        // Se a quantidade de salários for ímpar, pegue o do meio.
            double mediana = lista[tamanho / 2];
            std::cout << "Mediana dos salários: " << mediana << endl;
        }
    }
	
//funsao para mostrar o menor salario	
	void mostraMenor() {
		 if (lista.empty()) {
            cout << "A lista de salários está vazia." << endl;
        } else {
            // funsao para inicializar com o maior valor possível 
            double menorSalario = numeric_limits<float>::max(); 

            // funsao para encontre o menor salário na lista
            for (double salario : lista) {
                if (salario < menorSalario) {
                    menorSalario = salario;
                }
            }

            cout << "Menor salário: " << menorSalario << endl;
        }
    }
    //funsao para mostrar o maior salario
	void mostraMaior() {
		 if (lista.empty()) {
            cout << "A lista de salários está vazia." << endl;
        } else {
            // funsao para encontra o maior salário .
            double maiorSalario = *max_element(lista.begin(), lista.end());
            cout << "Maior salário: " << maiorSalario << endl;
        }
    }
};


class ListaIdades  {
	vector<int> lista;
	
	public:
		
		/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() {
		
	}
	
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de idades" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar a menor das idades" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar a maior das idades" << endl;
	}
};
 
int main () {
	vector<Lista*> listaDeListas;
	
	ListaNomes listaNomes;
	listaNomes.entradaDeDados();
	listaDeListas.push_back(&listaNomes);
	
	ListaDatas listaDatas;
	listaDatas.entradaDeDados();
	listaDeListas.push_back(&listaDatas);
	
	ListaSalarios listaSalarios;
	listaSalarios.entradaDeDados();
	listaDeListas.push_back(&listaSalarios);
	
	ListaIdades listaIdades;
	listaIdades.entradaDeDados();
	listaDeListas.push_back(&listaIdades);
	
	for (Lista* l : listaDeListas) {
		l->mostraMediana();
		l->mostraMenor();
		l->mostraMaior();
	}
	
}
    

