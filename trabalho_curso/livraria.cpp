#include <iostream>

using namespace std;

bool perm_case(int &op, char ficar, char sair, string frase);

//contadores/variaveis globais
int qtd_alunos = 0;
int qtd_funcionarios = 0;
int qtd_livros = 0;
int qtd_emprestimo = 0;

// codigo da sua mulher

struct data {
	unsigned dia;
	unsigned mes;
	unsigned ano;
};

struct alunos {
	unsigned matricula;
	string nome;
	unsigned idade;
	unsigned telefone;
};

struct emprestimos {
	unsigned codigo;
	data data_emprestimo;
	data data_devolucao;
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

//case 1
void menu_cadastro();
void cadastrar_livro(int &opcao_case1);
void cadastrar_funcionario(int &opcao_case1);
void cadastrar_aluno(int &opcao_case1);
void case1(int &opcao);

//case 2
void verificar_funcionario(int &opcao, unsigned &codigo_teste);
void verificar_aluno(int &opcao, unsigned &codigo_teste);
void verificar_livro(int &opcao, unsigned &codigo_livro);
void case2(int &opcao);

//case 3
void case3(int &opcao);
int contagem_data(unsigned matricula, unsigned codigo_livro, unsigned codigo_funcionario);

//case 4
void case4(int &opcao);
void menu_relatorio();
void total_aluno(int &opcao);
void total_funcionario(int &opcao);

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
				system("cls");
				case1(opcao);
				break;
			}
			case 2: {
				case2(opcao);
				break;
			}
			case 3: {
				case3(opcao);
				break;
			}
			case 4: {
				case4(opcao);
				break;
			}
			case 5: {
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

void case1(int &opcao) {
	bool perm_case1 = 1; // variavel para mandar o programa rodando
	int opcao_case1 = 0; // variavel para guardar a escolha do usuario


	while(perm_case1) {
		switch(opcao_case1) {
			case 0: {
				menu_cadastro();
				cin >> opcao_case1;
				system("cls");
				break;
			}
			case 1: {
				cadastrar_aluno(opcao_case1);
				break;
			}
			case 2: {
				cadastrar_funcionario(opcao_case1);
				break;
			}
			case 3: {
				cadastrar_livro(opcao_case1);
				break;
			}
			case 4: {
				perm_case1 = perm_case(opcao, 'n', 's', "Certeza que quer sair ?(s/n)");
				break;
			}
			default: {
				cout << "Entrada invalida.\n por favor coloque uma entrada validade de 1 a 4. \n" << endl;
				opcao_case1 = 0;
				system("pause");
				system("cls");
				break;
			}
		}
	}
}

void case2(int &opcao) {
	bool perm = 1;
	while(perm && qtd_emprestimo >= 0) {
		unsigned codigo_teste;// codigo do funcionario
		cout << "Qual seu codigo?";//pergunta o codigo
		cin >> codigo_teste;
		verificar_funcionario(opcao, codigo_teste); //verificar o funcionario;
		emprestimo[qtd_emprestimo].codigo_funcionario = codigo_teste; //registra o funcionario no emprestimo
		system("cls");

		unsigned matricula_teste;// matricula do aluno
		cout << "Qual a sua matricula?";//pergunta a matricula
		cin >> matricula_teste;
		verificar_aluno(opcao, matricula_teste);// verifica o aluno
		emprestimo[qtd_emprestimo].matricula_aluno = matricula_teste; // registra o aluno no emprestimo
		system("cls");

		unsigned codigo_livro;
		cout << "Qual o codigo do livro"; // pergunta o codigo do livro
		cin >> codigo_livro;
		verificar_livro(opcao, codigo_livro); //verifcar se tem o cadastro do livro e cadastrar
		for(int i=0; i < qtd_livros; i++) { //verificar se tem no estoque
			if(livro[i].ISBN == codigo_livro) {
				if(livro[i].quantidade < 0) {
					cout << "Não tem livro no estoque";
					return;
				}
			}
		}
		system("cls");
		
		emprestimo[qtd_emprestimo].codigo = qtd_emprestimo; // cadastro do codigo do emprestimo
		qtd_emprestimo++;

		cout << "Quantos livros ?";
		cin >> emprestimo[qtd_emprestimo].quantidade;// quantidade do livro
		qtd_livros = qtd_livros - emprestimo[qtd_emprestimo].quantidade;
		
		cout << "Qual a data de emprestimo?"; //data de emprestimo
		cout << "Dia: ";
		cin >> emprestimo[qtd_emprestimo].data_emprestimo.dia; // dia do emprestimo
		cout << "Mes: ";
		cin >> emprestimo[qtd_emprestimo].data_emprestimo.mes; //mes do emprestimo
		cout << "Ano: ";
		cin >> emprestimo[qtd_emprestimo].data_emprestimo.ano; //ano do emprestimo

		cout << "Qual a data de devolucao ?"; //data de devolucao
		cout << "Dia: ";
		cin >> emprestimo[qtd_emprestimo].data_devolucao.dia; // dia da devolucao
		cout << "Mes: ";
		cin >> emprestimo[qtd_emprestimo].data_devolucao.mes; //mes da devolucao
		cout << "Ano: ";
		cin >> emprestimo[qtd_emprestimo].data_devolucao.ano; //ano da devolucao

		char resp;
		cout << "Tem desconto ? (s/n)"; // pergunta ao funcionario se tem desconto
		cin >> resp;
		if(resp == 's') {//se tem então, escreve o desconto
			cout << "Qual e o desconto ?";
			cin >> emprestimo[qtd_emprestimo].desconto;
		} else {
			emprestimo[qtd_emprestimo].desconto = 1;
		}

		perm = perm_case(opcao, 's', 'n', "Mais algum emprestimo? (s/n)");
	}
}

void case3(int &opcao) {
	bool perm_case3 = 1;
	while(perm_case3) {
		unsigned codigo_livro;
		cout << "Qual o codigo do livro?"; //perguntar qual livro a devolver
		cin >> codigo_livro;
		verificar_livro(opcao, codigo_livro); //verificar se existe o livro
		system("cls");

		unsigned matricula;
		cout << "Qual a sua matricula?"; //pergunta qual a matricula do aluno
		cin >> matricula;
		verificar_aluno(opcao, matricula); //verificar se existe o aluno

		int contagem = contagem_data( matricula,  codigo_livro, 0); //chama a funcao e retorna a quantidade de dias ultrapassados

		if(contagem == 0) {
			cout << "Devolucao feita dentro do prazo.";
		} else {
			cout << "Infelizmente você ultrapassou a data de devolucao." << endl
			     << "A multa ficou: " << 2*contagem << "reais";
		}

		perm_case3 = perm_case(opcao, 's', 'n', "Mais algum emprestimo? (s/n)");
	}
}

void case4(int &opcao) {
	bool perm_case4 = 1; // variavel para mandar o programa rodando
	int opcao_case4 = 0; // variavel para guardar a escolha do usuario

	while(perm_case4) {
		switch(opcao_case4) {
			case 0: {
				menu_relatorio(); // mostrar o menu de relatorio
				cin >> opcao_case4;
				break;
			}
			case 1: {
				total_aluno(opcao_case4); //para mostrar o valor que o aluno está devendo no total
				break;
			}
			case 2: {
				total_funcionario(opcao_case4); // para mostrar o valor que um funcionario "vendeu"
				break;
			}
			case 3: {
				perm_case4 = perm_case(opcao, 'n', 's', "Certeza que quer sair ?(s/n)");
				break;
			}
			default: {
				cout << "Entrada inválida. \n por favor coloque uma entrada validade de 1 a 4. \n";
				break;
			}
		}
	}
}

// funções relatorio

void total_aluno(int &opcao) {
	unsigned matricula_teste;
	cout << "Digite sua matricula.";
	cin >> matricula_teste; //inserir matricula

	verificar_aluno(opcao, matricula_teste); //verifica a matricula do aluno

	double valor_total = 0; //para guardar o valor
	for(int i=0; i < qtd_emprestimo; i++){
		if(emprestimo[i].matricula_aluno == matricula_teste){ //achando o emprestimo do aluno
			for(int j=0; j < qtd_livros; j++) {
				if(emprestimo[i].ISBN == livro[j].ISBN) { // achando o livro alugando
					int contagem = contagem_data(matricula_teste, emprestimo[i].ISBN, 0);
					valor_total += livro[j].valor * emprestimo[i].quantidade * emprestimo[i].desconto + 2*contagem; //adcianando o valor do emprestimo do livro mais multa
				}
			}
		}
	}
	for(int i=0; i < qtd_alunos; i++){
		if(aluno[i].matricula == matricula_teste){
			cout << "O valor que " << aluno[i].nome << " deve é: " << valor_total << endl;
		}
	}
	
}

void total_funcionario(int &opcao) {
	unsigned codigo;
	cout << "Digite o codigo de funcionario.";
	cin >> codigo; //inserir codigo

	verificar_funcionario(opcao, codigo); //verifica o codigo do funcionario

	double valor_total = 0; //para guardar o valor
	for(int i=0; i < 100; i++) {
		if(emprestimo[i].codigo_funcionario == codigo) { //achando os emprestimos do funcionario
			for(int j=0; j < 100; j++) {
				if(emprestimo[i].ISBN == livro[j].ISBN) { /// achando o livro que foi alugado
					int contagem = contagem_data(0, emprestimo[i].ISBN, codigo);
					valor_total += livro[j].valor * emprestimo[i].quantidade * emprestimo[i].desconto + contagem; //adcianando o valor do emprestimo do livro mais multa
				}
			}
		}
	}
	for(int i=0; i < qtd_funcionarios; i++){
		if(funcionario[i].codigo == codigo){
			cout << "O valor que " << funcionario[i].nome << " arrecadou é: " << valor_total << endl;
		}
	}
}

//menus
void menu_principal() { // menu das opcoes
	string array_menu[] = { // as opcoes do menu
		"Cadastros",
		"Emprestimo",
		"Devolucao",
		"Relatorios",
		"Sair"
	};
	//essa parte é só para eu não me preocupar com o tamnanho do array
	cout <<"      Menu Principal" << endl;
	int ind = 1;
	for(string frase  : array_menu) {
		cout << ind++ << " - " << frase << endl;
	}
}

void menu_cadastro() {
	string array_menu[] = { // as opcoes do menu
		"Cadastrar aluno",
		"Cadastrar funcionario",
		"Cadastrar livro",
		"Voltar ao menu principal"
	};
	//essa parte é só para eu não me preocupar com o tamnanho do array
	cout <<"      Menu Cadastro" << endl;
	int ind = 1;
	for(string frase  : array_menu) {
		cout << ind++ << " - " << frase << endl;
	}
}

void menu_relatorio() {
	string array_menu[] = { // as opcoes do menu
		"Exibir o total a pagar por Aluno ",
		"Exibir o total de emprestimo por funcionario",
		"Voltar ao menu Principal"
	};
	//essa parte é só para eu não me preocupar com o tamnanho do array
	cout <<"      Menu" << endl;
	int ind = 1;
	for(string frase  : array_menu) {
		cout << ind++ << " - " << frase << endl;
	}
}


//tools
bool perm_case(int &op, char ficar, char sair, string frase) { // para perguntar a cada opcao se o usuario quer sair
	char resp = ' ';
	while(resp != ficar && resp != sair) {
		cout << frase << endl;
		cin >> resp;
		if(resp == ficar) {
			op = 0;
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

int contagem_data(unsigned matricula, unsigned codigo_livro, unsigned codigo_funcionario) {
	data data_hoje;//coletar a data de hoje
	cout << "Qual a data de hoje ?";
	cout << "Dia: ";
	cin >> data_hoje.dia;
	cout << "Mes: ";
	cin >> data_hoje.mes;
	cout << "Ano: ";
	cin >> data_hoje.ano;

	unsigned cont=0;
	for(int i=0; i < 100; i++) { //para fazer as contas de dias
		if(emprestimo[i].ISBN == codigo_livro && (emprestimo[i].matricula_aluno == matricula ||
		        emprestimo[i].codigo_funcionario == codigo_funcionario )) { //achando o emprestimo do livro que o aluno alugou
			if(data_hoje.ano > emprestimo[i].data_devolucao.ano ||
			        (data_hoje.ano == emprestimo[i].data_devolucao.ano &&
			         data_hoje.mes > emprestimo[i].data_devolucao.mes) ||
			        (data_hoje.ano == emprestimo[i].data_devolucao.ano &&
			         data_hoje.mes == emprestimo[i].data_devolucao.mes &&
			         data_hoje.dia == emprestimo[i].data_devolucao.dia) ) { //verificando os casos de o ano ser igual ou diferente
				unsigned dia = data_hoje.dia;
				unsigned mes = data_hoje.mes;
				unsigned ano = data_hoje.ano;
				while(!(dia == emprestimo[i].data_devolucao.dia &&
				        mes == emprestimo[i].data_devolucao.mes && ano == emprestimo[i].data_devolucao.ano)) {
					cont++; //contagem do dia
					if(dia%30 == 0 ) {
						mes++;
						dia=1;
						if(mes%12 == 0) {
							ano++;
							mes=1;
						} else {
							mes++;
						}
					} else {
						dia++;
					}
				}
			}
			break;
		}
	}
	return cont;
}

// Funções cadastro:

void cadastrar_aluno(int &opcao_case1) {
	bool perm = 1; // variavel para mandar o programa rodando

	if(qtd_alunos < 100){
		while(perm && qtd_alunos <100) {
		cout << "Informe a matricula do aluno." << endl;
		cin >> aluno[qtd_alunos].matricula; //inserindo matricula
		cout << "Informe o nome do aluno." << endl;
		cin >> ws;
		cin >> aluno[qtd_alunos].nome; //inserindo nome sem espaço da frente
		cout << "Informe a idade do aluno" << endl;
		cin >> aluno[qtd_alunos].idade; //inserindo idade
		cout << "Informe o telefone do aluno" << endl;
		cin >> aluno[qtd_alunos].telefone; //inserindo telefone
		qtd_alunos++;
		system("cls");

		perm = perm_case(opcao_case1, 's', 'n', "Quer adicionar mais alunos ?");
		}
	}else{
		cout << "Limite de armazenamento. Nao pode mais adicionar alunos.";
	}
}

void cadastrar_funcionario(int &opcao_case1) {
	bool perm = 1; // variavel para mandar o programa rodando

	if(qtd_funcionarios < 100){
		while(perm) {
		cout << "Informe o codigo do funcionario" << endl;
		cin >> funcionario[qtd_funcionarios].codigo; //inserir codigo
		cout << "Informe o cpf do funcionario" << endl;
		cin >> funcionario[qtd_funcionarios].cpf;//inserir cpf
		cout << "Informe o nome do funcionario" << endl;
		cin >> ws;
		cin >> funcionario[qtd_funcionarios].nome; //inserir nome
		qtd_funcionarios++;
		system("cls");

		perm = perm_case(opcao_case1, 's', 'n', "Quer adicionar mais funcionarios ?");
		}
	}else{
		cout << "Limite de armazenamento. Nao pode mais adicionar funcionarios.";
	}
}

void cadastrar_livro(int &opcao_case1) {
	bool perm = 1; // variavel para mandar o programa rodando

	if(qtd_livros < 100){
		while(perm) {
		cout << "Informe o ISBN do livro" << endl;
		cin >> livro[qtd_livros].ISBN; //inserir o codigo do livro
		cout << "Informe a descricao do livro" << endl;
		cin >> ws;
		cin >> livro[qtd_livros].descricao; //descrição do livro
		cout << "Informe a quantidade do livro" << endl;
		cin >> livro[qtd_livros].quantidade;//quantidade de livros no estoque
		cout << "Informe o valor do livro" << endl;
		cin >> livro[qtd_livros].valor; // inserir o valor do livro
		qtd_livros++;

		perm = perm_case(opcao_case1, 's', 'n', "Quer adicionar mais funcionarios ?");
		}
	}else{
		cout << "Limite de espaço. Não pode mais adicionar livros.";	
	}
}

// Funções de verificação:
void verificar_funcionario(int &opcao, unsigned &codigo_teste) {
	bool teste_cadastro = 0;// faz o teste se tem o codigo
	for(int i=0; i < 100; i++) {
		if(funcionario[i].codigo == codigo_teste) {
			teste_cadastro = 1;
		}
	}
	if(!teste_cadastro) { //se não tiver, então faça o cadastro e retone para fazer o emprestimo
		cout << "Voce ainda nao tem cadastro. Por favor realize o cadastro para exercer essa funcao.";
		system("cls");
		cadastrar_funcionario(opcao);
		return;
	}
}

void verificar_aluno(int &opcao, unsigned &matricula_teste) {
	bool teste_cadastro = 0;// faz o teste se tem a matricula
	for(int i=0; i < qtd_alunos; i++) {
		if(aluno[i].matricula == matricula_teste) {
			teste_cadastro = 1;
		}
	}
	if(!teste_cadastro) { //se não tiver, então faça o cadastro e retone para fazer o emprestimo
		cout << "Voce ainda nao tem cadastro. Por favor realize o cadastro para fazer o emprestimo.";
		system("cls");
		cadastrar_aluno(opcao);
		opcao = 0; // voltar ao menu
		return;
	}
}

void verificar_livro(int &opcao, unsigned &codigo_livro) {
	bool teste_cadastro = 0;// faz o teste se tem a matricula
	for(int i=0; i < 100; i++) {
		if(livro[i].ISBN == codigo_livro) {
			teste_cadastro = 1;
		}
	}
	if(!teste_cadastro) { //se não tiver, então faça o cadastro e retone para fazer o emprestimo
		cout << "O livro não tem cadastro.";
		system("cls");
		return;
	}

}
