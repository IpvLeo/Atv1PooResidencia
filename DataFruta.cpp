#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <limits> 

using namespace std;

class Data {
	int dia, mes, ano;
	public:
	

	Data (int _dia, int _mes, int _ano) {
		dia = _dia;
		mes = _mes;
		ano = _ano;
	}
	string toString() const {
		string ret = "";
		ret.append(to_string(dia));
		ret.append("/");
		ret.append(to_string(mes));
		ret.append("/");
		ret.append(to_string(ano));
		return ret;
	}


 static int compara(const Data &d1, const Data &d2) {
        if (d1.ano < d2.ano) {
            return -1;
        } else if (d1.ano > d2.ano) {
            return 1;
        } else {
            if (d1.mes < d2.mes) {
                return -1;
            } else if (d1.mes > d2.mes) {
                return 1;
            } else {
                if (d1.dia < d2.dia) {
                    return -1;
                } else if (d1.dia > d2.dia) {
                    return 1;
                } else {
                    return 0;
                }
            }
        }
    }

    bool operator<(const Data &outra) const {
        return compara(*this, outra) < 0;
	}
};



class Lista {
	public:
	virtual void entradaDeDados() =0;
	virtual void mostraMediana() =0;
	virtual void mostraMenor() =0;
	virtual void mostraMaior() =0;
	virtual void listarEmOrdem() =0;
};

class ListaNomes : public Lista {
	vector<string> lista;
	
	public:
	
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
		void entradaDeDados() override
	{
		int nElementos;
		cout << "Quantos elementos vão existir na sua lista? ";
		cin >> nElementos;

		for (int i = 0; i < nElementos; i++)
		{
			string nome;
			cout << "Digite o nome " << i + 1 << ": ";
			cin >> nome;
			lista.push_back(nome);
		}
		sort(lista.begin(), lista.end());
	}

	void mostraMediana() override
	 {
    int tamanho = lista.size();
    if (tamanho == 0) {
        cout << "A lista está vazia. Não é possível calcular a mediana." << endl;
    } else {
        // Ordene a lista
        sort(lista.begin(), lista.end());

        if (tamanho % 2 == 0) {
            // Tamanho par, calcular a mediana dos dois elementos do meio
            string mediana1 = lista[tamanho / 2 - 1];
            string mediana2 = lista[tamanho / 2];
            cout << "Mediana: " << mediana1 << " e " << mediana2 << endl;
        } else {
            // Tamanho ímpar, exibir o nome no meio da lista
            cout << "Mediana: " << lista[tamanho / 2] << endl;
        }
    }
	}
	
	void mostraMenor() {
    if (lista.empty()) {
        cout << "A lista de nomes está vazia." << endl;
    } else {
        string mNome = lista[0]; // Comece com o primeiro nome
        for (const string &nome : lista) {
            if (nome < mNome) {
                mNome = nome;
            }
        }
        cout << "Menor nome: " << mNome << endl;
    }
}

	void mostraMaior() {
    if (lista.empty()) {
        cout << "A lista de nomes está vazia." << endl;
    } else {
        string maNome = lista[0]; // Comece com o primeiro nome

        for (const string &nome : lista) {
            if (nome > maNome) {
                maNome = nome;
            }
        }

        cout << "Maior nome: " << maNome << endl;
    }
}

	void listarEmOrdem() override {
        if (lista.empty()) {
            cout << "A lista de nomes esta vazia." << endl;
            return;
        }

        sort(lista.begin(), lista.end());
        cout << "Nomes em ordem:" << endl;
        for (const string &nome : lista) {
            cout << nome << endl;
        }
    }
};

class ListaDatas : public Lista {
	vector<Data> lista;
	
	public:
		
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	public:
    void entradaDeDados() override {
        int n;
        cout << "Quantas datas deseja inserir na lista? ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            int dia, mes, ano;
            cout << "Digite a data " << i + 1 << " (DD MM AAAA): ";
            cin >> dia >> mes >> ano;
            Data data(dia, mes, ano);
            lista.push_back(data);
        }
    }

    void mostraMediana() override {
        if (lista.empty()) {
            cout << "A lista de datas esta vazia." << endl;
            return;
        }

        sort(lista.begin(), lista.end(), Data::compara);

        int meio = lista.size() / 2;
        cout << "Mediana das datas: " << lista[meio].toString() << endl;
    }

    void mostraMenor() override {
        if (lista.empty()) {
            cout << "A lista de datas está vazia." << endl;
            return;
        }

        sort(lista.begin(), lista.end(), Data::compara);
        cout << "Primeira data cronologicamente: " << lista[0].toString() << endl;
    }

    void mostraMaior() override {
        if (lista.empty()) {
            cout << "A lista de datas está vazia." << endl;
            return;
        }

        sort(lista.begin(), lista.end(), Data::compara);
        cout << "Ultima data cronologicamente: " << lista.back().toString() << endl;
        cout << "-------------------------------" << endl;
    }

    void listarEmOrdem() override {
        if (lista.empty()) {
            cout << "A lista de datas está vazia." << endl;
            return;
        }

        sort(lista.begin(), lista.end(), Data::compara);
        cout << "Datas em ordem:" << endl;
        for (const Data &data : lista) {
            cout << data.toString() << endl;
        }
    }
};

class ListaSalarios : public Lista {
	vector<double> lista;
	
	public:
	//funsao para ver quantidade de salario da lista
	void entradaDeDados() override {
        int ElementosSalario;
        cout << "Quantos salários existirao na lista? ";
        cin >> ElementosSalario;

        for (int i = 0; i < ElementosSalario; i++) {
            double salario;
            cout << "Digite o salario " << i + 1 << ": ";
            cin >> salario;
            lista.push_back(salario);
        }
    }
//funsao para mostrar a mediana da lista de salarios
    void mostraMediana() override {

        //funsao para ordenar salarios.
        sort(lista.begin(), lista.end());

        int tamanho = lista.size();

        if (tamanho % 2 == 0) {
        // Se a quantidade de salários for par, média das duas do meio.
            double mediana = (lista[tamanho / 2 - 1] + lista[tamanho / 2]) / 2.0;
            cout <<endl<< "Mediana dos salarios: " << mediana << endl;
        } else {
        // Se a quantidade de salários for ímpar, pegue o do meio.
            double mediana = lista[tamanho / 2];
            cout <<endl<< "Mediana dos salarios: " << mediana <<endl;
        }
    }
	
//funsao para mostrar o menor salario	
	void mostraMenor() override {
		 if (lista.empty()) {
            cout << "A lista de salarios esta vazia." << endl;
        } else {
            // funsao para inicializar com o maior valor possível 
            double menorSalario = numeric_limits<double>::max(); 

            // funsao para encontre o menor salário na lista
            for (double salario : lista) {
                if (salario < menorSalario) {
                    menorSalario = salario;
                }
            }

            cout << "Menor salario: " << menorSalario << endl;
        }
    }
    //funsao para mostrar o maior salario
	void mostraMaior() override {
		 if (lista.empty()) {
            cout << "A lista de salarios esta vazia." << endl;
        } else {
            // funsao para encontra o maior salário .
            double maiorSalario = *max_element(lista.begin(), lista.end());
            cout << "Maior salario: " << maiorSalario << endl;
			cout<<"-------------------------------"<<endl;
        }
    }
	void listarEmOrdem() override {
        if (lista.empty()) {
            cout << "A lista de salários está vazia." << endl;
            return;
        }

        sort(lista.begin(), lista.end());
        cout << "Salários em ordem:" << endl;
        for (double salario : lista) {
            cout << salario << endl;
        }
    }
};


class ListaIdades : public Lista{ 
	vector<double> lista;
	
	public:
	//funsao para ver quantidade de idades da lista
	void entradaDeDados() override {
        int ElementosIdade;
        cout << "Quantas idades existirao na lista? ";
        cin >> ElementosIdade;

        for (int i = 0; i < ElementosIdade; i++) {
            double idade;
            cout << "Digite a idade " << i + 1 << ": ";
            cin >> idade;
            lista.push_back(idade);
        }
    }
//funsao para mostrar a mediana da lista de idades
    void mostraMediana() override {

        //funsao para ordenar idades.
        sort(lista.begin(), lista.end());

        int tamanho = lista.size();

        if (tamanho % 2 == 0) {
        // Se a quantidade de idades for par, média das duas do meio.
            double mediana = (lista[tamanho / 2 - 1] + lista[tamanho / 2]) / 2.0;
            cout << "Mediana das idades: " << mediana << endl;
        } else {
        // Se a quantidade de idades for ímpar, pegue o do meio.
            double mediana = lista[tamanho / 2];
            cout << "Mediana das idades: " << mediana << endl;
        }
    }
	
//funsao para mostrar o menor idade	
	void mostraMenor() override {
		 if (lista.empty()) {
            cout << "A lista de idades esta vazia." << endl;
        } else {
            // funsao para inicializar com o maior valor possível 
            double menorIdade = numeric_limits<double>::max(); 

            // funsao para encontre a menor idade na lista
            for (double idade : lista) {
                if (idade < menorIdade) {
                    menorIdade = idade;
                }
            }

            cout << "Menor idade: " << menorIdade << endl;
        }
    }
    //funsao para mostrar a maior idade
	void mostraMaior() override {
		 if (lista.empty()) {
            cout << "A lista de idades esta vazia." << endl;
        } else {
            // funsao para encontra a maior idade .
            double maiorIdade = *max_element(lista.begin(), lista.end());
            cout << "Maior idade: " << maiorIdade << endl;
			cout<<"-------------------------------"<<endl;
        }
    }

	void listarEmOrdem() override {
        if (lista.empty()) {
            cout << "A lista de idades está vazia." << endl;
            return;
        }

        sort(lista.begin(), lista.end());
        cout << "Idades em ordem:" << endl;
        for (double idade : lista) {
            cout << idade << endl;
        }
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
	 // Limpando memória
    for (Lista* l : listaDeListas) {
        delete l;
    }
}