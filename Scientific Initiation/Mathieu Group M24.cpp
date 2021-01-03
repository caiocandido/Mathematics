// Please, verify the version of your compiler before and 
// avoid to change the code in order to run the simulations
// Any doubts or suggestions feel free to send me an email 
// caioeduardocandido@gmail.com

#include <bits/stdc++.h>
using namespace std;


char Representation[4][4][4];
char MOG[4][6];


////////////////////////////////// OPTION 1 /////////////////////////////////////
void initZeroRepresentation(){
	Representation[0][0][0] = '1';
	Representation[0][0][1] = '0';
	Representation[0][0][2] = '0';
	Representation[0][0][3] = '0';

	Representation[0][1][0] = '0';	
	Representation[0][1][1] = '1';
	Representation[0][1][2] = '1';
	Representation[0][1][3] = '1';

	Representation[0][2][0] = '0';
	Representation[0][2][1] = '0';
	Representation[0][2][2] = '0';
	Representation[0][2][3] = '0';

	Representation[0][3][0] = '1';
	Representation[0][3][1] = '1';
	Representation[0][3][2] = '1';
	Representation[0][3][3] = '1';
}

void initOneRepresentation(){
	Representation[1][0][0] = '0';
	Representation[1][0][1] = '1';
	Representation[1][0][2] = '0';
	Representation[1][0][3] = '0';

	Representation[1][1][0] = '1';
	Representation[1][1][1] = '0';
	Representation[1][1][2] = '1';
	Representation[1][1][3] = '1';

	Representation[1][2][0] = '1';
	Representation[1][2][1] = '1';
	Representation[1][2][2] = '0';
	Representation[1][2][3] = '0';

	Representation[1][3][0] = '0';
	Representation[1][3][1] = '0';
	Representation[1][3][2] = '1';
	Representation[1][3][3] = '1';
}

void initwRepresentation(){
	Representation[2][0][0] = '0';
	Representation[2][0][1] = '0';
	Representation[2][0][2] = '1';
	Representation[2][0][3] = '0';

	Representation[2][1][0] = '1';
	Representation[2][1][1] = '1';
	Representation[2][1][2] = '0';
	Representation[2][1][3] = '1';

	Representation[2][2][0] = '1';
	Representation[2][2][1] = '0';
	Representation[2][2][2] = '1';
	Representation[2][2][3] = '0';

	Representation[2][3][0] = '0';
	Representation[2][3][1] = '1';
	Representation[2][3][2] = '0';
	Representation[2][3][3] = '1';
}


void initWRepresentation(){
	Representation[3][0][0] = '0';
	Representation[3][0][1] = '0';
	Representation[3][0][2] = '0';
	Representation[3][0][3] = '1';

	Representation[3][1][0] = '1';
	Representation[3][1][1] = '1';
	Representation[3][1][2] = '1';
	Representation[3][1][3] = '0';

	Representation[3][2][0] = '1';
	Representation[3][2][1] = '0';
	Representation[3][2][2] = '0';
	Representation[3][2][3] = '1';

	Representation[3][3][0] = '0';
	Representation[3][3][1] = '1';
	Representation[3][3][2] = '1';
	Representation[3][3][3] = '0';
}

void initialization(){
	initZeroRepresentation();
	initOneRepresentation();
	initwRepresentation();
	initWRepresentation();	
}

void clearScreen(){
	for (int i = 0; i < 150; i++)
		printf ("\n");
}

void ERROR(){
	cout << "ERROR, something went wrong and the program is exiting!" << endl;
	exit(0);
}

string readHexacode(){
	printf ("Escreva sem espaços a palavra do hexacode que deseja gerar no MOG\n"); 
	printf ("Escreva w para omega e W para omega^barra");
	cout << endl;
	
	string hexacode;
	cin >> hexacode;
	return hexacode;
}

// change '0' to 0, '1' to 1, 'w' to 2 and 'W' to 3
string transformHexacode(string hexacode){
	for (int i = 0; i < hexacode.size(); i++)
		if (hexacode[i] == '0' or hexacode[i] == '1') hexacode[i] = (hexacode[i] - '0');
		else if (hexacode[i] == 'w') hexacode[i] = 2;
		else if (hexacode[i] == 'W') hexacode[i] = 3;
		else ERROR();

	return hexacode;
}

void printMOG(int number){
	printf ("Representação número %d:\n", number);
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 6; j++){
			printf ("%c ", MOG[i][j]);
		}
		printf ("\n");
	}
	printf ("\n");
}

bool isNotHexacode(string hexacode){
	return false;
}

void option1(){
	string hexacode = readHexacode();

	if (isNotHexacode(hexacode)) ERROR();

	cout << "Representações do hexacode: " << hexacode << endl;

	// change '0' to 0, '1' to 1, 'w' to 2 and 'W' to 3
	string auxHexacode = transformHexacode(hexacode);


	int number = 1;
	for (int i1 = 0; i1 < 4; i1++){
		int element = auxHexacode[0];
		for (int j = 0; j < 4; j++)
			MOG[j][0] = Representation[element][i1][j];
		
		// parity = 0 means MOG is odd
		// parity = 1 means MOG is even
		int parity;
		if (i1 < 2) parity = 0;
		else parity = 1;

		for (int i2 = 0; i2 < 2; i2++){
			element = auxHexacode[1];
			for (int j = 0; j < 4; j++)
				MOG[j][1] = Representation[element][2 * parity + i2][j];

			for (int i3 = 0; i3 < 2; i3++){
				element = auxHexacode[2];
				for (int j = 0; j < 4; j++)
					MOG[j][2] = Representation[element][2 * parity + i3][j];

				for (int i4 = 0; i4 < 2; i4++){
					element = auxHexacode[3];
					for (int j = 0; j < 4; j++)
						MOG[j][3] = Representation[element][2 * parity + i4][j];

					for (int i5 = 0; i5 < 2; i5++){
						element = auxHexacode[4];
						for (int j = 0; j < 4; j++)
							MOG[j][4] = Representation[element][2 * parity + i5][j];

						for (int i6 = 0; i6 < 1; i6++){
							element = auxHexacode[5];
							
							int count = 0;
							for (int ii = 0; ii < 5; ii++)
								count += (MOG[0][ii] - '0');

							int selected = 2 * parity + i6;

							if ( (parity+1)%2 == ((Representation[element][selected][0] - '0') + count)%2 ){
								// selected is the right pick so the code does nothing
							}else {
								// pick the next element so the parity of the MOG turns right
								selected++;
							}

							for (int j = 0; j < 4; j++)
								MOG[j][5] = Representation[element][selected][j];
							
							printMOG(number++);
						}
					}
				}
			}
		}
	}		
}



////////////////////////////////// OPTION 2 /////////////////////////////////////
void printMatrix(int);

typedef struct SEXTET{
	int matrix[4][6];
	int sizeOfTree;
	int id;
	int parentId;
	int visited;
	
	void actionLeftGenerator(){
		swap(this->matrix[0][1], this->matrix[1][1]);
		swap(this->matrix[2][1], this->matrix[3][1]);
		swap(this->matrix[0][3], this->matrix[1][3]);
		swap(this->matrix[2][3], this->matrix[3][3]);
		swap(this->matrix[0][4], this->matrix[2][4]);
		swap(this->matrix[1][4], this->matrix[3][4]);
		swap(this->matrix[0][5], this->matrix[3][5]);
		swap(this->matrix[1][5], this->matrix[2][5]);
	}

	void actionCenterGenerator(){
		swap(this->matrix[0][3], this->matrix[0][4]);
		swap(this->matrix[0][2], this->matrix[0][3]);
		swap(this->matrix[0][1], this->matrix[0][2]);
		swap(this->matrix[0][0], this->matrix[0][1]);

		swap(this->matrix[3][3], this->matrix[1][4]);
		swap(this->matrix[1][2], this->matrix[3][3]);
		swap(this->matrix[1][1], this->matrix[1][2]);
		swap(this->matrix[3][0], this->matrix[1][1]);

		swap(this->matrix[1][3], this->matrix[2][4]);
		swap(this->matrix[2][2], this->matrix[1][3]);
		swap(this->matrix[2][1], this->matrix[2][2]);
		swap(this->matrix[1][0], this->matrix[2][1]);

		swap(this->matrix[2][3], this->matrix[3][4]);
		swap(this->matrix[3][2], this->matrix[2][3]);
		swap(this->matrix[3][1], this->matrix[3][2]);
		swap(this->matrix[2][0], this->matrix[3][1]);
	}

	void actionRightGenerator(){
		swap(this->matrix[2][0], this->matrix[3][0]);
		swap(this->matrix[2][1], this->matrix[3][1]);
		swap(this->matrix[2][2], this->matrix[3][2]);
		swap(this->matrix[2][3], this->matrix[3][3]);
		swap(this->matrix[0][4], this->matrix[0][5]);
		swap(this->matrix[1][4], this->matrix[1][5]);
		swap(this->matrix[2][4], this->matrix[3][5]);
		swap(this->matrix[3][4], this->matrix[2][5]);
	}

	void actionElementM0(){
		swap(this->matrix[2][0], this->matrix[2][1]);
		swap(this->matrix[3][0], this->matrix[3][1]);
		swap(this->matrix[2][2], this->matrix[2][3]);
		swap(this->matrix[3][2], this->matrix[3][3]);
		swap(this->matrix[2][4], this->matrix[3][4]);
		swap(this->matrix[2][5], this->matrix[3][5]);
		swap(this->matrix[0][4], this->matrix[1][5]);
		swap(this->matrix[1][4], this->matrix[0][5]);
	}

}SEXTET;

SEXTET sextet[11234567];
int N;
set< vector<int> >sextetSet;
vector<int>sextetVector[11234567];

void printMatrix(int id){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 6; j++)
			printf ("%d ", sextet[id].matrix[i][j]);
		printf ("\n");
	}
}

void matrixToVector(int id){
	if (sextetVector[id].size() == 0){
		vector< pair<int,int> >aux[6+1];
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 6; j++){
				aux[ sextet[id].matrix[i][j] ].emplace_back(i,j);
				//sextetVector[id].emplace_back(sextet[id].matrix[i][j]);
			}
		}

		vector< vector< pair<int,int> > >partition;
		for (int x = 1; x <= 6; x++)
			partition.emplace_back(aux[x]);
		sort(partition.begin(), partition.end());

		int auxSextetVector[24];
		for (int x = 0; x < 6; x++){
			for (int l = 0; l < partition[x].size(); l++){
				int i = partition[x][l].first;
				int j = partition[x][l].second;
				auxSextetVector[6*i+j] = x+1;
			}
		}

		for (int l = 0; l < 24; l++)
			sextetVector[id].emplace_back(auxSextetVector[l]);
	}
}

void insertSextet(int id){
	matrixToVector(id);
	sextetSet.insert(sextetVector[id]);
}	

bool countSextet(int id){
	matrixToVector(id);
	return sextetSet.count(sextetVector[id]);
}


int find(int id){
	while (sextet[id].parentId != -1)
		id = sextet[id].parentId;
	return id;
}

void join(int aId, int bId){
	aId = find(aId);
	bId = find(bId);

	sextet[bId].parentId = aId;
	sextet[aId].sizeOfTree += sextet[bId].sizeOfTree;
}


void initOrbitRepresentatives(){

	// sextet 0
	for (int i = 0; i < 4; i++){
		sextet[N].matrix[i][0] = 1;
		sextet[N].matrix[i][1] = 2;
		sextet[N].matrix[i][2] = 3;
		sextet[N].matrix[i][3] = 4;
		sextet[N].matrix[i][4] = 5;
		sextet[N].matrix[i][5] = 6;
	}
	sextet[N].sizeOfTree = 1;
	sextet[N].id = N;
	sextet[N].parentId = -1;
	sextet[N].visited = false;
	//insertSextet(N);
	N++;


	// sextet 1
	sextet[N].matrix[0][0] = 1;
	sextet[N].matrix[0][1] = 1;
	sextet[N].matrix[0][2] = 3;
	sextet[N].matrix[0][3] = 3;
	sextet[N].matrix[0][4] = 5;
	sextet[N].matrix[0][5] = 5;
	sextet[N].matrix[1][0] = 1;
	sextet[N].matrix[1][1] = 1;
	sextet[N].matrix[1][2] = 3;
	sextet[N].matrix[1][3] = 3;
	sextet[N].matrix[1][4] = 5;
	sextet[N].matrix[1][5] = 5;
	sextet[N].matrix[2][0] = 2;
	sextet[N].matrix[2][1] = 2;
	sextet[N].matrix[2][2] = 4;
	sextet[N].matrix[2][3] = 4;
	sextet[N].matrix[2][4] = 6;
	sextet[N].matrix[2][5] = 6;
	sextet[N].matrix[3][0] = 2;
	sextet[N].matrix[3][1] = 2;
	sextet[N].matrix[3][2] = 4;
	sextet[N].matrix[3][3] = 4;
	sextet[N].matrix[3][4] = 6;
	sextet[N].matrix[3][5] = 6;
	sextet[N].sizeOfTree = 1;
	sextet[N].id = N;
	sextet[N].parentId = -1;
	sextet[N].visited = false;
	//insertSextet(N);
	N++;

	// sextet 2
	for (int j = 2; j < 6; j++){
		sextet[N].matrix[0][j] = 3;
		sextet[N].matrix[1][j] = 4;
		sextet[N].matrix[2][j] = 5;
		sextet[N].matrix[3][j] = 6;
	}
	sextet[N].matrix[0][0] = 1;
	sextet[N].matrix[0][1] = 2;
	for (int i = 1; i < 4; i++){
		sextet[N].matrix[i][0] = 2;
		sextet[N].matrix[i][1] = 1;
	}
	sextet[N].sizeOfTree = 1;
	sextet[N].id = N;
	sextet[N].parentId = -1;
	sextet[N].visited = false;
	//insertSextet(N);
	N++;

	// sextet 3
	sextet[N].matrix[0][0] = 1;
	sextet[N].matrix[0][1] = 1;
	sextet[N].matrix[0][2] = 1;
	sextet[N].matrix[0][3] = 2;
	sextet[N].matrix[0][4] = 5;
	sextet[N].matrix[0][5] = 6;
	sextet[N].matrix[1][0] = 1;
	sextet[N].matrix[1][1] = 2;
	sextet[N].matrix[1][2] = 2;
	sextet[N].matrix[1][3] = 2;
	sextet[N].matrix[1][4] = 4;
	sextet[N].matrix[1][5] = 3;
	sextet[N].matrix[2][0] = 3;
	sextet[N].matrix[2][1] = 5;
	sextet[N].matrix[2][2] = 6;
	sextet[N].matrix[2][3] = 4;
	sextet[N].matrix[2][4] = 3;
	sextet[N].matrix[2][5] = 6;
	sextet[N].matrix[3][0] = 4;
	sextet[N].matrix[3][1] = 6;
	sextet[N].matrix[3][2] = 5;
	sextet[N].matrix[3][3] = 3;
	sextet[N].matrix[3][4] = 5;
	sextet[N].matrix[3][5] = 4;
	sextet[N].sizeOfTree = 1;
	sextet[N].id = N;
	sextet[N].parentId = -1;
	sextet[N].visited = false;
	//insertSextet(N);
	N++;
}

void addSextet(int id){
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 6; j++)
			sextet[N].matrix[i][j] = sextet[id].matrix[i][j];
	sextet[N].sizeOfTree = 1;
	sextet[N].id = N;
	sextet[N].parentId = -1;
	sextet[N].visited = false;
	N++;
}

void popbackSextet(){
	N--;
	sextetVector[N].clear();
}

void clearDataProcessed(){
	// Clearing datas processed
	sextetSet.clear();
	for (int i = 0; i < N; i++){
		sextetVector[i].clear();
		sextet[i].sizeOfTree = 1;
		sextet[i].parentId = -1;
		sextet[i].visited = false;
	}
	N = 0;
}

int print;
void dfs(int id, bool m0){
	if (sextet[id].visited) return;

	if (print){
		printf ("Elemento da órbita número %d:\n", print++);
		printMatrix(id);
		cout << endl;
	}
	
	sextet[id].visited = true;
	insertSextet(id);

	// Applying action of leftmost generator
	addSextet(id);
	sextet[N-1].actionLeftGenerator();
	if (!countSextet(N-1)){
		join(id, N-1);
		insertSextet(N-1);
		dfs(N-1,m0);
	}else {
		popbackSextet();
	}

	// Applying medium generator action
	addSextet(id);
	sextet[N-1].actionCenterGenerator();
	if (!countSextet(N-1)){
		join(id, N-1);
		insertSextet(N-1);
		dfs(N-1,m0);
	}else {
		popbackSextet();
	}

	// Applying rightmost generator action
	addSextet(id);
	sextet[N-1].actionRightGenerator();
	if (!countSextet(N-1)){
		join(id, N-1);
		insertSextet(N-1);
		dfs(N-1,m0);
	}else {
		popbackSextet();
	}	

	if (m0 == true){
		// Applying the action of element m0
		// to get the transitivity
		addSextet(id);
		sextet[N-1].actionElementM0();
		if (!countSextet(N-1)){
			join(id, N-1);
			insertSextet(N-1);
			dfs(N-1,m0);
		}else {
			popbackSextet();
		}	
	}
}



void option2(){
	// Clearing datas processed
	//clearDataProcessed();

	initOrbitRepresentatives();
	for (int i = 0; i < N; i++){
		//printf ("chamando dfs(%d):\n",i);
		dfs(i,false);
	}

	cout << endl << endl << "Execução do algoritmo concluída com sucesso!" << endl << endl;
	for (int i = 0; i < 4; i++)
		printf ("Tamanho da órbita do representante %d: %d\n", i+1, sextet[find(i)].sizeOfTree);
	cout << endl << endl;

	printf ("Digite 1) para gerar todos os sextetos da órbita 1\n");
	printf ("Digite 2) para gerar todos os sextetos da órbita 2\n");
	printf ("Digite 3) para gerar todos os sextetos da órbita 3\n");
	printf ("Digite 4) para gerar todos os sextetos da órbita 4\n");
	printf ("Digite 0) para voltar ao Menu principal\n");

	string reading = "";
	while (reading != "1" and reading != "2" and reading != "3" and reading != "4" and reading != "0"){
		cin >> reading;
	}

	// Clearing datas processed
	clearDataProcessed();
	initOrbitRepresentatives();
	print = 1;

	if (reading == "1") {dfs(0,0);}
	else if (reading == "2") {dfs(1,0);}
	else if (reading == "3") {dfs(2,0);}
	else if (reading == "4") {dfs(3,0);}
	else if (reading == "0") {}
	else ERROR();

	print = 0;
}






////////////////////////////////// OPTION 3 /////////////////////////////////////
void option3(){
	// Clearing datas processed
	clearDataProcessed();

	initOrbitRepresentatives();
	dfs(0,true);

	cout << endl << endl << "Execução do algoritmo concluída com sucesso!" << endl << endl;
	printf ("Tamanho da órbita partindo do representante 1: %d\n", sextet[find(0)].sizeOfTree);
	cout << endl << endl;

	printf ("Digite 1) para gerar todos os sextetos da órbita\n");
	printf ("Digite 0) para voltar ao Menu principal\n");	

	string reading = "";
	while (reading != "1" and reading != "0"){
		cin >> reading;
	}

	clearDataProcessed();
	initOrbitRepresentatives();
	print = 1;

	if (reading == "1") {dfs(0,1);}
	else if (reading == "0") {}
	else ERROR();

	print = 0;
}

void printMenu(){
	cout << endl << endl;
	printf ("MENU:\n");
	printf ("Digite 1) para gerar todas as 64 representações de um determinado Hexacode\n");
	printf ("Digite 2) para calcular as órbitas do semigrupo direto 2^6 : 3 * S6 agindo sob os sextetos\n");
	printf ("Digite 3) para executar o algoritmo que prova que o elemento m0 une as quatro órbitas\n");
	printf ("Digite 0) para fechar o programa\n");

	string reading = "";
	while (reading != "1" and reading != "2" and reading != "3" and reading != "0"){
		cin >> reading;
	}

	if (reading == "1") option1();
	else if (reading == "2") option2();
	else if (reading == "3") option3();
	else if (reading == "0") exit(0);
	else ERROR();
}


int main(){
	initialization();
	while(true)
		printMenu();
}








/*
void initZeroRepresentation(){
	zeroRepresentation[0][0] = '1';
	zeroRepresentation[0][1] = '0';
	zeroRepresentation[0][2] = '0';
	zeroRepresentation[0][3] = '0';

	zeroRepresentation[1][0] = '0';
	zeroRepresentation[1][1] = '1';
	zeroRepresentation[1][2] = '1';
	zeroRepresentation[1][3] = '1';

	zeroRepresentation[2][0] = '0';
	zeroRepresentation[2][1] = '0';
	zeroRepresentation[2][2] = '0';
	zeroRepresentation[2][3] = '0';

	zeroRepresentation[3][0] = '1';
	zeroRepresentation[3][1] = '1';
	zeroRepresentation[3][2] = '1';
	zeroRepresentation[3][3] = '1';
}

void initOneRepresentation(){
	oneRepresentation[0][0] = '0';
	oneRepresentation[0][1] = '1';
	oneRepresentation[0][2] = '0';
	oneRepresentation[0][3] = '0';

	oneRepresentation[1][0] = '1';
	oneRepresentation[1][1] = '0';
	oneRepresentation[1][2] = '1';
	oneRepresentation[1][3] = '1';

	oneRepresentation[2][0] = '1';
	oneRepresentation[2][1] = '1';
	oneRepresentation[2][2] = '0';
	oneRepresentation[2][3] = '0';

	oneRepresentation[3][0] = '0';
	oneRepresentation[3][1] = '0';
	oneRepresentation[3][2] = '1';
	oneRepresentation[3][3] = '1';
}

void initwRepresentation(){
	wRepresentation[0][0] = '0';
	wRepresentation[0][1] = '0';
	wRepresentation[0][2] = '1';
	wRepresentation[0][3] = '0';

	wRepresentation[1][0] = '1';
	wRepresentation[1][1] = '1';
	wRepresentation[1][2] = '0';
	wRepresentation[1][3] = '1';

	wRepresentation[2][0] = '1';
	wRepresentation[2][1] = '0';
	wRepresentation[2][2] = '1';
	wRepresentation[2][3] = '0';

	wRepresentation[3][0] = '0';
	wRepresentation[3][1] = '1';
	wRepresentation[3][2] = '0';
	wRepresentation[3][3] = '1';
}


void initWRepresentation(){
	WRepresentation[0][0] = '0';
	WRepresentation[0][1] = '0';
	WRepresentation[0][2] = '0';
	WRepresentation[0][3] = '1';

	WRepresentation[1][0] = '1';
	WRepresentation[1][1] = '1';
	WRepresentation[1][2] = '1';
	WRepresentation[1][3] = '0';

	WRepresentation[2][0] = '1';
	WRepresentation[2][1] = '0';
	WRepresentation[2][2] = '0';
	WRepresentation[2][3] = '1';

	WRepresentation[3][0] = '0';
	WRepresentation[3][1] = '1';
	WRepresentation[3][2] = '1';
	WRepresentation[3][3] = '0';
}*/