#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
	//struct é o escopo do meu objeto final, que irá me permitir manipular dados relacionados ao programa
struct campeao {
    int idade;
    string nome;
    string regiao_pais;
    int vitorias;
};
	/*Estou tentando descobrir o porque do codigo ir direto para o menu dps que consulta 
	o campeao listado*/ 
void consultarCampeoes(campeao lista[], int tamanho) {
    cout << "ENTREI NA FUNCAO CONSULTAR\n";
    if (tamanho == 0) {
        cout << "Nenhum campeao cadastrado\n";
        return;
    }

/*bloco onde é feita a varredura do campeao listado, linha por linha*/
    cout << "\n=== LISTA DE CAMPEOES ===\n";
    for (int i = 0; i < tamanho; i++) {
        cout << "Nome: " << lista[i].nome << endl;
        cout << "Idade: " << lista[i].idade << endl;
        cout << "Regiao/Pais: " << lista[i].regiao_pais << endl;
        cout << "Numero de vitorias: " << lista[i].vitorias << endl;
        cout << "-----------------------\n";
    }
    cout << "\nAperte enter para voltar para o menu\n";
    cin.ignore();
    cin.get();
}

void buscarCampeaoPorNome(campeao lista[], int tamanho){
    cout << "\n=== BUSCAR CAMPEAO ===\n";
    if(tamanho == 0){
    cout << "\nnenhum campeao cadastrado com o nome buscado\n\n";
    return;
    }
    string buscarNome;
    
    cout << "buscar campeao: ";
    cin.ignore();
    getline(cin,buscarNome);
    bool encontrado = false;

        for(int i=0; i < tamanho; i++){
            if(lista[i].nome == buscarNome)
            cout << "\nCampeao encontrado\n\n";
            cout << "Nome: " << lista[i].nome << endl;
            cout << "idade: " << lista[i].idade << endl;
            cout << "Regiao/País: " << lista[i].regiao_pais << endl;
            cout << "Vitorias: " << lista[i].vitorias << endl;
            cout << "-----------------------\n";
            encontrado = true;
        }
    if(!encontrado){
        cout << "\nNenhum campeao encontrado com o nome: " << buscarNome << endl;
    }
    cout << "\nAperte enter para voltar ao menu....";
    cin.get();
}
// bloco para cadastrar qualquer campeao
void cadastrarCampeao(campeao lista[], int &tamanho) {
    cout << "\n=== CADASTRO DE CAMPEAO ===\n";  

    cout << "Idade: ";
    cin >> lista[tamanho].idade;

    cout << "Nome: ";
    cin.ignore(); 
    getline(cin, lista[tamanho].nome);

    cout << "Regiao/Pais: ";
    getline(cin, lista[tamanho].regiao_pais);

    cout << "Numero de vitorias: ";
    cin >> lista[tamanho].vitorias;

    tamanho++;
    cout << "Campeao cadastrado com sucesso!\n\n";
}

void Menu() {
    cout << "VERSAO NOVA DO PROGRAMA\n";
    campeao listaDeCampeoes[50];
    int opcao;
    int tamanho = 0;

    do {
        cout << "Selecione uma opcao\n"
             << "[1] para consultar campeoes mundiais\n" 
             << "[2] para buscar campeoes por nome\n" 
             << "[3] para cadastrar novo campeao\n" 
             << "[4] para ordenar campeao\n" 
             << "[5] para comparar campeoes\n" 
             << "[6] para consultar estrategias\n" 
             << "[7] para salvar dados\n"
             << "[8] para sair\n"
             << "Escolha: ";
        cin >> opcao;
/*As opçoes nos cases serao atualizadas sempre que eu fizer uma implementaçao
   nova no codigo, de uma opçao, assim como a opçao 1 e 3 foram implementadas */
        switch (opcao) {
            case 1:
            cout << "ENTREI NA OPCAO 1\n";
            cout << "Tamanho: " << tamanho << endl;
                consultarCampeoes(listaDeCampeoes, tamanho);
                break;
            case 2: 
                buscarCampeaoPorNome(listaDeCampeoes, tamanho);
                break;
            case 3: 
                cadastrarCampeao(listaDeCampeoes, tamanho);
                break;
            case 4:
                cout << "Ordenar campeoes\n";
                break;
            case 5:
                cout << "Comparar campeo\n";
                break;
            case 6:
                cout << "Consultar estrategias\n";
                break;
            case 7:
                cout << "Salvar dados\n";
                break;
            case 8:
                cout << "Sair\n";
                break;
            default:
                cout << "opcao invalida\n";
                break;
        }
    } while (opcao != 8);
}

int main() {
    Menu();
    return 0;
}
