#include <iostream>

using namespace std;

struct CLIENTE{
    char nome[100];
    unsigned cpf;
    unsigned idade;
    unsigned telefone;
};

struct STUFF{
    char nome[100];
    unsigned cpf;
    unsigned idade;
    unsigned telefone;
};

void meu();
bool perm_case(opcao, frase);

int main() {
	bool perm = 1; // variavel para mandar o programa rodando
	int opcao = 0; // variavel para guardar a escolha do usuario
    
    CLIENTE vetor_cliente[100]; //vetores com os cliente
    unsigned quant_cliente = 0; //quantidade de clientes atual
    
	while(perm) {
		switch(opcao) {
			case 0: {
				menu();
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
			    
			    break;
			}
			default:{
			    cout << "Entrada inválida. \n por favor coloque uma entrada validade de 1 a 4. \n";
				break;
		    }
		}
	}
}

void case_1(){
    bool perm = 1; // variavel para mandar o programa rodando
	int opcao = 0; // variavel para guardar a escolha do usuario

	while(perm) {
		switch(opcao) {
			case 0: {
				menu_cadastro();
				cin >> opcao;
				break;
			}
			case 1:{
			    CLIENTE cliente;
			    
			    cadastro_cliente(cliente, opcao);
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
			    opcao = 0; //para retorna ao menu
			    system("cls");
				break;
		    }
		}
	}
}

//funções de cadastro

void cadastro_cliente(CLIENTE cliente, int &op){
	bool perm_local = 1;
	if(quant_cliente < 100){
	    cout << "Limete de usuarios cadastrados";
	    op = 0;
	    return;
	}
	
	while(perm_local){	
		// cadastrar cliente
		cout << "Qual o nome do cliente?" << endl;
		cin >> ws;
		cin.getline(cliente.nome, 100);
		cout << "Qual o CPF do cliente?" << endl;
		cin >> cliente.cpf;
		cout << "Qual a idade do cliente" << endl;
		cin >> cliente.idade;
		cout << "Qual o telefone do cliente" << endl;
		cin >> cliente.telefone;
		system("cls");
		
		//verifica se já está cadastrado
		for(int ind=0; ind < 100; ind++){
		    if(cliente.cpf == vetor_cliente[ind].cpf){
		        cout << "Cliente já cadastrado" << endl;
		        op = 0;
		        return;
		    }
		}
		
		vetor_cliente[quant_cliente] = cliente; //guardando
		quant_cliente++;//apontando para o proximo lugar disponivel do vetor
		
		perm_local = perm_case(op, 's', 'n', "Voce quer adicionar mais um cliente?");
	}
}

//menu
void menu() { // menu das opcoes
	string array_menu[] = { // as opcoes do menu
		"Cadastros",
         "Venda",
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

void menu_cadastro(){
    string array_menu[] = { // as opcoes do menu
		"Cadastrar Cliente",
         "Cadastrar Funcionário",
        "Cadastrar Produto",
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
int perm_case(int &op, char pos, char neg, string frase) { // para perguntar a cada opcao se o usuario quer sair
	char resp = ' ';
	while(resp != pos && resp != neg) {
		cout << frase;
		cin >> resp;
		if(resp == pos) {
			system("cls");
			return 1; // permanece na operacao
		} else if(resp == neg) {
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
