#include <iostream>

using namespace std;

bool perm_case(int &op, char ficar, char sair, string frase);

//contadores/variaveis globais
int qtd_alunos = 0;
int qtd_funcionarios = 0;
int qtd_livros = 0;
int qtd_emprestimo = 0;

// codigo da sua mulher

struct alunos {
	unsigned matricula;
	string nome;
	unsigned idade;
	unsigned telefone;
};

struct emprestimos {
	unsigned codigo;
	unsigned data;
	unsigned matricula_aluno;
	unsigned codigo_funcionario;
	unsigned ISBN;
	int quantidade;
	float desconto;
};

struct funcionarios {
	unsigned codigo;
	string nome;
	unsigned cpf;
};

struct livros {
	unsigned ISBN;
	string descricao;
	int quantidade;
	float valor;
};

//Variaveis/vetores:

alunos aluno[100];
funcionarios funcionario[100];
livros livro[100];
emprestimos emprestimo[100];

//case 0
void menu_principal();

//case 2
void cadastrar_aluno();
void cadastrar_funcionario();
void verificar_funcionario(int &opcao);
void verificar_aluno(int &opcao);


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
			case 1: {
				break;
			}
			case 2: {
				bool perm = 1;
				while(perm) {
					unsigned codigo_teste;// codigo do funcionario
					cout << "Qual seu codigo?";//pergunta o codigo
					cin >> codigo_teste;

					bool teste_cadastro = 0;// faz o teste se tem o codigo
					for(int i=0; i < 100; i++) {
						if(funcionario[i].codigo == codigo_teste) {
							teste_cadastro = 1;
						}
					}
					if(!teste_cadastro) { //se não tiver, então faça o cadastro e retone para fazer o emprestimo
						cout << "Voce ainda nao tem cadastro. Por favor realize o cadastro para exercer essa funcao.";
						system("cls");
						cadastrar_funcionario();
						opcao = 2;
					}

					emprestimo[qtd_emprestimo].codigo_funcionario = codigo_teste;

					unsigned matricula_teste;// matricula do aluno
					cout << "Qual a sua matricula?";//pergunta a matricula
					cin >> codigo_teste;

					teste_cadastro = 0;// faz o teste se tem a matricula
					for(int i=0; i < 100; i++) {
						if(aluno[i].matricula == matricula_teste) {
							teste_cadastro = 1;
						}
					}
					if(!teste_cadastro) { //se não tiver, então faça o cadastro e retone para fazer o emprestimo
						cout << "Voce ainda nao tem cadastro. Por favor realize o cadastro para fazer o emprestimo.";
						system("cls");
						cadastrar_funcionario();
						opcao = 2;
					}

					emprestimo[qtd_emprestimo].matricula_aluno = matricula_teste;
					
					emprestimo[qtd_emprestimo].codigo = qtd_emprestimo;
					
					cout << "Qual o codigo do livro";
					cin >> emprestimo[qtd_emprestimo].ISBN;
					
					cout << "Quantos livros ?";
					cin >> emprestimo[qtd_emprestimo].quantidade;
					
					cout << "Qual e a data";
					cin >> emprestimo[qtd_emprestimo].data;
					
					char resp;
					cout << "Tem desconto ? (s/n)";
					cin >> resp;
					if(resp == 's'){
						cout << "Qual e a data";
						cin >> emprestimo[qtd_emprestimo].desconto;
					}

					perm = perm_case(opcao, 's', 'n', "Mais algum emprestimo? (s/n)");
				}
				break;
			}
			case 3: {

				break;
			}
			case 4: {
				perm = perm_case(opcao, 'n', 's', "Certeza que quer sair ?(s/n)");
				break;
			}
			default: {
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
	for(string frase  : array_menu) {
		cout << ind << " - " << frase << endl;
	}
}

void menu_cadastro() {
	cout << "1 - Cadastrar aluno" << endl;
	cout << "2 - Cadastrar funcionário" << endl;
	cout << "3 - Cadastrar livro" << endl;
	cout << "4 - Voltar ao menu principal" << endl;
}

void menu_relatorio() {
	string array_menu[] = { // as opcoes do menu
		"Exibir o total a pagar por Aluno ",
		"Exibir o total de empréstimo por funcionário",
		"Voltar ao menu Principal"
	};
	//essa parte é só para eu não me preocupar com o tamnanho do array
	cout <<"      Menu" << endl;
	int ind = 1;
	for(string frase  : array_menu) {
		cout << ind << " - " << frase << endl;
	}
}


//tools
bool perm_case(int &op, char ficar, char sair, string frase) { // para perguntar a cada opcao se o usuario quer sair
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

// Funções cadastro:

void cadastrar_aluno() {
	for(int i = 0; i < 100; i++) {
		if(aluno[i].matricula == 0) {
			cout << "Informe a matricula do aluno" << endl;
			cin >> aluno[i].matricula;
			cout << "Informe o nome do aluno" << endl;
			cin >> aluno[i].nome;
			cout << "Informe a idade do aluno" << endl;
			cin >> aluno[i].idade;
			cout << "Informe o telefone do aluno" << endl;
			cin >> aluno[i].telefone;
			qtd_alunos++;
			system("pause");
			break;
		}
	}
}

void cadastrar_funcionario() {
	for(int i = 0; i < 100; i++) {
		if(funcionario[i].codigo == 0) {
			cout << "Informe o codigo do funcionario" << endl;
			cin >> funcionario[i].codigo;
			cout << "Informe o cpf do funcionario" << endl;
			cin >> funcionario[i].cpf;
			cout << "Informe o nome do funcionario" << endl;
			cin >> funcionario[i].nome;
			qtd_funcionarios++;
			system("pause");
			break;
		}
	}
}


void cadastrar_livro(){
	for(int i = 0; i < 100; i++){
		if(livro[i].ISBN == 0){
			cout << "Informe o ISBN do livro" << endl;
			cin >> livro[i].ISBN;
			cout << "Informe a descricao do livro" << endl;
			cin >> livro[i].descricao;
			cout << "Informe a quantidade do livro" << endl;
			cin >> livro[i].quantidade;
			cout << "Informe o valor do livro" << endl;
			cin >> livro[i].valor;
			qtd_livros++;
			system("pause");
			break;
		}
	}
}


void funcao_case(){
		int op = 0, op_cadastro, op_relatorio = 0;
	do{
		menu_principal();
		cout << "Informe a opcao desejada" << endl;
		cin >> op;
		
		switch(op){
			// Cadastros
			case 1: 
				do{
					menu_cadastro();
					cout << "Informe a opcao desejada" << endl;
					cin >> op_cadastro;
					switch(op_cadastro){
						case 1:
							cadastrar_aluno();
							break;
						case 2:
							cadastrar_funcionario();
							break;
						case 3:
							cadastrar_livro();
							break;
						case 4:
							cout << "Voltando ao menu principal" << endl;
							system("pause");
							break;
					}			
				}while(op_cadastro != 4);
				break;
			case 2:
				// Emprestimos
				//case_2(); // falta preencher
				break;	
			case 3:
				//Relatorios
				do{
					menu_relatorio();
					cout << "Informe a opcao desejada" << endl;
					cin >> op_relatorio;
					
					switch(op_relatorio){
						case 1:
							cout << "Total a pagar: " << endl; // falta preencher
							break;
						case 2:
							cout << "Total do emprestimo: " << endl; //falta preencher
							break;
						case 3:
							cout << "Voltando ao menu principal" << endl;
							system("pause");
							break;
					}
				}while(op_relatorio != 3);
				break;
			case 4:
				break;
		}
	}while(op != 4);
}
