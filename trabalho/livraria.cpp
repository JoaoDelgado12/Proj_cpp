#include <iostream>

using namespace std;

bool perm_case(int &op, char ficar, char sair, string frase);

// codigo da sua mulher 

struct aluno{
	unsigned matricula;
	string nome;
	unsigned idade;
	undigned telefone;
};

struct funcionario{
	unsigned codigo;
	string nome;
	unsigned cpf;
};

struct livro{
	unsigned ISBN;
	string descricao;
	int quantidade;
	float valor;
};

struct emprestimo{
	unsigned codigo;
	unsigned data;
	unsigned matricula_aluno;
	unsigned codigo_funcionario;
	unsigned ISBN;
	int quantidade;
	float desconto;
};

//case 0
void menu_principal();



int main() {
	bool perm = 1; // variavel para mandar o programa rodando
	int opcao = 0; // variavel para guardar a escolha do usuario
    
    
	while(perm) {
		switch(opcao) {
			case 0: {
				menu_principal();
				cin >> opcao;
				break;
			}
			case 1:{
			    break;
			}
			case 2:{
				break;
			}
			case 3:{
			    
			    break;
			}
			case 4:{
			    perm = perm_case(opcao, 'n', 's', "Certeza que quer sair ?(s/n)");
			    break;
			}
			default:{
			    cout << "Entrada inválida. \n por favor coloque uma entrada validade de 1 a 4. \n";
				break;
		    }
		}
	}
}

//menus
void menu_principal() { // menu das opcoes
	string array_menu[] = { // as opcoes do menu
		"Cadastros",
        "Empréstimo",
        "Relatórios",
        "Sair"
	};
	//essa parte é só para eu não me preocupar com o tamnanho do array
	cout <<"      Menu Principal" << endl;
	int ind = 1;
	for(string frase  : array_menu){
	    cout << ind << " - " << frase << endl;
	}
}

//tools
bool perm_case(int &op, char ficar, char sair, string frase){ // para perguntar a cada opcao se o usuario quer sair
	char resp = ' ';
	while(resp != ficar && resp != sair) {
		cout << frase;
		cin >> resp;
		if(resp == ficar) {
			system("cls");
			return 1; // permanece na operacao
		} else if(resp == sair) {
			system("cls");
			op = 0; // para ir ao menu
			return 0; // para sair da operacao
		} else {
			cout << "Entrada invalida! \n Escreva (s) ou (n)";
			system("pause");
			system("cls");
		}
	}
	return 0;
}
