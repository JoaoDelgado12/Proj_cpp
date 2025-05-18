#include <iostream>
#include <random>
using namespace std;

struct CLIENTE{
    char nome[100];
    unsigned cpf;
    unsigned idade;
    unsigned telefone;
};
CLIENTE vetor_cliente[100];
int quant_cliente = 0;

struct STUFF{
    char nome[100];
    unsigned matricula;
    unsigned telefone;
};
STUFF vetor_stuff[100];
int quant_stuff = 0;

struct PRODUTO{
	unsigned id;
	char nome[100];
	double valor;
	unsigned quantidade;
};
PRODUTO vetor_produto[100];
int quant_produto = 0; //vale lembrar que isso é o tipo do produto

struct VENDA{
	unsigned id; //código da venda
	unsigned cpf; //cpf do cliente
	unsigned matricula; //matricula do funcionario 
	unsigned descricao[100][3]; //descrição de qual produto, quantidade e total de cada produto
	string data; //data da emissão
	int valor_total; 
};
VENDA vetor_venda[100];
int quant_venda = 0; //vale lembrar que isso é o tipo do produto

//tools
bool perm_case(int &op, char ficar, char sair, string frase);

//case_0
void menu_principal();

//case_1
void case_1();
void menu_cadastro();
void cadastro_cliente(CLIENTE cliente, int &op);
void cadastro_stuff(STUFF stuff, int &op);
void cadastro_produto(PRODUTO produto, int &op);

//case_2
void case_2(VENDA venda, int &op);

//case_3
void case_3();
void menu_relatorio();

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
				case_1();
				opcao = 0;
			    break;
			}
			case 2:{
				unsigned matricula;
				bool existe_matricula=0;
				cout << "Matricula:" << endl;
				cin >> matricula;
				for(int ind=0; ind < 100; ind++){
					if(vetor_stuff[ind].matricula == matricula){
						existe_matricula = 1;
					}
				}
				if(!existe_matricula){
					
				}
				
			    VENDA venda;
			    case_2(venda, opcao);
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
				
				cadastro_cliente(cliente, opcao);//cadastrar os clientes
			    break;
			}
			case 2:{
			    STUFF stuff;
				
				cadastro_stuff(stuff, opcao);//cadastrar os stuff
			    break;
			}
			case 3:{
			    PRODUTO produto;
				
				cadastro_produto(produto, opcao);//cadastrar os produto
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

void case_2(VENDA venda, int &opcao){
    bool perm = 1; // variavel para mandar o programa rodando
	
	while(perm) {
		if(vetor_produto[0].id == 0){//para saber se tem algum item registrado
			cout << "Nenhum produto resgistrado!" << endl;
			system("cls");
			opcao = 1;
			return;
		}
		
		int resp;
		int cont_venda = 0;
		for(int ind = 0; ind < 100; ind++){
		cout << ind + 1 << " " << vetor_produto[ind].nome << endl;
		}
		
		cout << "Qual o produto que você quer ?" << endl;
		cin >> resp;
		venda.descricao[cont_venda][0] = vetor_produto[resp].id; //colocou o id do produto na venda
		system("cls");
		cout << "Qual a quantidade do produto ?" << endl;
		cin >> venda.descricao[cont_venda][1]; // a quantidade
		venda.descricao[cont_venda][2] = venda.descricao[cont_venda][1] * vetor_produto[resp].valor; //o valor total de todo item
		if()
		
		cont_venda++; //para apontar para a proxima entrada
		perm = perm_case(opcao, 's' ,'n' , "Quer comprar mais algum produto ?");
	}
}

void case_3(){
    bool perm = 1; // variavel para mandar o programa rodando
	int opcao = 0; // variavel para guardar a escolha do usuario

	while(perm) {
		switch(opcao) {
			case 0: {
				menu_relatorio();
				cin >> opcao;
				break;
			}
			case 1:{
				for(int ind=0; ind < 100; ind++){
					
				}
				
			    break;
			}
			case 2:{
			    break;
			}
			case 3:{
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
	
	if(quant_cliente >= 100){//condigção da número maximo de clientes cadastrados 
	    cout << "Limite de clientes cadastrados";
	    op = 0;
	    system("cls");
	    return;
	}
	
	while(perm_local){	
		// cadastrar cliente
		cout << "Qual o nome do cliente?" << endl;
		cin >> ws;
		cin.getline(cliente.nome, 100);
		cout << "Qual seu CPF " << cliente.nome << " ?" << endl;
		cin >> cliente.cpf;
		cout << "Por favor nos diga sua idade " << cliente.nome << endl;
		cin >> cliente.idade;
		cout << "Qual seu telefone " << cliente.nome << " ?" << endl;
		cin >> cliente.telefone;
		system("cls");
		
		
		for(int ind=0; ind < quant_cliente + 1; ind++){//verifica se já está cadastrado
		    if(cliente.cpf == vetor_cliente[ind].cpf){
		        cout << "Cliente já está cadastrado" << endl;
		        op = 0;
		        return;
		    }
		}
		
		vetor_cliente[quant_cliente] = cliente; //guardando
		quant_cliente++;//apontando para o proximo lugar disponivel do vetor
		
		perm_local = perm_case(op, 's', 'n', "Voce quer adicionar mais um cliente?");
	}
}

void cadastro_stuff(STUFF stuff, int &op){
	bool perm_local = 1;
	
	if(quant_stuff >= 100){//condigção da número maximo de funcionarios cadastrados 
	    cout << "Limite de funcionarios cadastrados";
	    op = 0;
	    system("cls");
	    return;
	}
	
	while(perm_local){	
		// cadastrar cliente
		cout << "Qual o nome do funcionario?" << endl;
		cin >> ws;
		cin.getline(stuff.nome, 100);
		cout << "Qual o telefone do " << stuff.nome << " ?" << endl;
		cin >> stuff.telefone;
		//criando a matricula
		random_device aleatorio;
		mt19937 gen(aleatorio()); // criando a seed de aleatoriadade
		uniform_int_distribution<int> distrib(511111, 999999); //criando o distribuido
		
		stuff.matricula = distrib(gen);
		for(int ind=0; ind < quant_stuff + 1; ind++){//verifica se já está cadastrado
		    if(stuff.matricula == vetor_stuff[ind].matricula){
		        cout << "Funcionario já está cadastrado" << endl;
		        op = 0;
		        return;
		    }
		}
		system("cls");
		
		vetor_stuff[quant_stuff] = stuff; //guardando
		quant_stuff++;//apontando para o proximo lugar disponivel do vetor
		
		perm_local = perm_case(op, 's', 'n', "Voce quer adicionar mais um funcionario?");
	}
}

void cadastro_produto(PRODUTO produto, int &op){
	bool perm_local = 1;
	
	if(quant_produto >= 100){//condigção da número maximo de produtos cadastrados 
	    cout << "Limite de produtos cadastrados";
	    op = 0;
	    system("cls");
	    return;
	}
	
	while(perm_local){	
		// cadastrar cliente
		cout << "Qual o nome do produto?" << endl;
		cin >> ws;
		cin.getline(produto.nome, 100);
		cout << "Qual o seu valor ?"<< endl;
		cin >> produto.valor;
		cout << "Qual a quantidade do produto ?"<< endl;
		cin >> produto.quantidade;
		//criando o ID
		random_device aleatorio;
		mt19937 gen(aleatorio()); // criando a seed de aleatoriadade
		uniform_int_distribution<int> distrib(111111, 999999); //criando o distribuido
		
		produto.id = distrib(gen);
		for(int ind=0; ind < quant_produto + 1; ind++){//verifica se já está cadastrado
		    if(produto.id == vetor_produto[ind].id){
		        cout << "O produto já está cadastrado" << endl;
		        op = 0;
		        return;
		    }
		}
		system("cls");
		
		vetor_produto[quant_produto] = produto; //guardando
		quant_produto++;//apontando para o proximo lugar disponivel do vetor
		
		perm_local = perm_case(op, 's', 'n', "Voce quer adicionar mais um funcionario?");
	}
}

//menus
void menu_principal() { // menu das opcoes
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

void menu_relatorio(){
	string array_menu[] = { // as opcoes do menu
		"Total das Venda",
        "Total por Cliente",
        "Total por Produto",
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


