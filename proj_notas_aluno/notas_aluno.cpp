#include <iostream>
#include <fstream>

using namespace std;
int TAM_MENU; //para facilitar alteração do codigo

struct ALUNO {
	char nome[100];
	long cpf;
	float notas[3];
	float media;
	bool status;
};

void menu();

int perm_case(int &op, string frase);

void add_aluno(ALUNO aluno, int &op);

int main() {
	bool perm = 1; // variavel para mandar o programa rodando
	int opcao = 0; // variavel para guardar a escolha do usuario

	while(perm) {
		switch(opcao) {
			case 0: {

				menu();
				cin >> opcao;
				break;
			}
			case 1: {
				ALUNO aluno; // criando a variavel aluno
				add_aluno(aluno, opcao);
				break;
			}
		}
	}
}


void menu() { // menu das opcoes
	string array_menu[] = { // as opcoes do menu
		"      Menu Principal",
		"Adicionar dados de aluno",
		"Excluir dados de aluno",
		"Calcular Media de todos os alunos",
		"Atualizar a situacao de acordo com as medias geradas",
		"Exibir todos os alunos Reprovados",
		"Exibir todos os alunos Aprovados",
		"Arredondar notas (alunos com media >= 6 e media < 7) arredondar para 7",
		"Sair"
	};
	//essa parte é só para eu não me preocupar com o tamnanho do array
	TAM_MENU = 1;
	for(int ind = 0; ind < TAM_MENU; ind++){
		TAM_MENU++;
	}
	//para ter um formatação certinha na saida do console
	for(int ind = 0; ind < TAM_MENU; ind++){
		cout << ind << " - " << array_menu[ind] << endl;
	}
	
}

int perm_case(int &op, string frase) { // para perguntar a cada opcao se o usuario quer sair
	char resp = ' ';
	while(resp != 's' && resp != 'n') {
		cout << frase;
		cin >> resp;
		if(resp == 's') {
			system("cls");
			return 1; // permanece na operacao
		} else if(resp == 'n') {
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

void add_aluno(ALUNO aluno, int &op){
	bool perm_local = 1;
	ofstream aqr_aluno;
	
	while(perm_local){	
		// cadastrar o aluno
		cout << "Qual o nome do aluno?" << endl;
		cin >> ws;
		cin.getline(aluno.nome, 100);
		cout << "Qual o CPF do aluno?" << endl;
		cin >> aluno.cpf;
		cout << "Quais as notas do aluno?" << endl;
		aluno.notas[3] = {};
		for(int ind=0; ind < 3; ind++){
			cin >> aluno.notas[ind];
		}
		aluno.media = 0;
		aluno.status = 0;
		
		aqr_aluno.write((char*) &aluno, sizeof(aluno)); //escrevendo em data_aluno.bin p cadastro
		aqr_aluno.close();	
		
		system("cls");
		perm_local = perm_case(op, "Voce que adicionar mais um aluno?");
	}
}
	
		
