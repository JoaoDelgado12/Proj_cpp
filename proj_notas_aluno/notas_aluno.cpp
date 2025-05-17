#include <iostream>
#include <fstream>

using namespace std;

struct ALUNO {
	char nome[100];
	long matricula;
};

struct PROF {
	char nome[100];
	long cod_acesso;
};

void menu();

int perm_case(int &op, string frase);

void add_aluno(ALUNO aluno, int &op);
void add_professor(PROF prof, int &op);

int main() {
	bool perm = 1; // variavel para mandar o programa rodando
	int opcao = 0; // variavel para guardar a escolha do usuario

	while(perm) {
		switch(opcao) {
			case 0: {
				menu();
				cin >> opcao;
				system("cls");
				break;
			}
			case 1: {	
				ALUNO aluno; // criando a variavel aluno
				add_aluno(aluno, opcao); //função para adicionar aluno
				break;        
			}
			case 2:{
				PROF professor; // criando a variavel professor
				add_professor(professor, opcao); //função para adicionar professor
				break;
			}
			case 5:{
				perm = 0;
				break;
			}
		}
	}
}


void menu() { // menu das opcoes
	string array_menu[] = { // as opcoes do menu
		"cadastrar dados de aluno",
		"cadastrar dados de professor",
		"Login - Aluno",
		"Login - Professor",
		"Sair"
	};
	
	cout << "        Menu Principal" << endl;
	int ind = 1;
	for(string frase : array_menu ){
		cout << ind << " - " << frase << endl;
		ind++;
	}
}

int perm_case(int &op, string frase) { // para perguntar a cada opcao se o usuario quer sair
	char resp = ' ';
	while(resp != 's' && resp != 'n') {
		cout << frase << endl;
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
	ofstream aqr_aluno("data_aluno.bin", ios::app | ios::binary);
	
	while(perm_local){	
		// cadastrar o aluno
		cout << "Qual o nome do aluno?" << endl;
		cin >> ws;
		cin.getline(aluno.nome, 100);
		cout << "Qual o matricula do aluno?" << endl;
		cin >> aluno.matricula;
		
		aqr_aluno.write((char*) &aluno, sizeof(aluno)); //escrevendo em data_aluno.bin p cadastro
		
		system("cls");
		perm_local = perm_case(op, "Voce que adicionar mais um aluno?(s/n)");
		
	}
	aqr_aluno.close();
}

void add_professor(PROF prof, int &op){
	bool perm_local = 1;
	ofstream aqr_prof("data_prof.bin", ios::app | ios::binary);
	
	while(perm_local){	
		// cadastrar o professor
		cout << "Qual o nome do professor?" << endl;
		cin >> ws;
		cin.getline(prof.nome, 100);
		cout << "Qual o codigo de cadastro do professor?" << endl;
		cin >> prof.cod_acesso;
		
		aqr_prof.write((char*) &prof, sizeof(prof)); //escrevendo em data_prof.bin para cadastro
			
		
		system("cls");
		perm_local = perm_case(op, "Voce que adicionar mais um professor?(s/n)");
		
	}
	aqr_prof.close();
}





