#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Produto{
    public:
    string nome;
    string tipoProduto;
    string principio;
    string formaAdministracao;
    string tipoEmbalagem;
    string quantidade;
    string apresentacao;
    string concentracao;
    string fabricante;
    string tipo;
    string uso;
    string dataFabricacao;
    string dataVencimento;
    string lote;
    string descricao;
    string bula;
    string desconto;
    string entradaSistema;
    string fornecedor;
    string classeRemedio;
    string retemReceita;

    void insertDB(){
        cout << "Nome:" << endl;
        cin >> nome;
        cout << "Tipo Produto: " << endl;
        cin >> tipoProduto;
        cout << "Principio: " << endl;
        cin >> principio;
        cout << "Forma de administracao: " << endl;
        cin >> formaAdministracao;
        cout << "Tipo embalagem: " << endl;
        cin >> tipoEmbalagem;
        cout << "Quantidade: " << endl;
        cin >> quantidade;
        cout << "Apresentação: " << endl;
        cin >> apresentacao;
        cout << "Concentração: " << endl;
        cin >> concentracao;
        cout << "Fabricante/Laboratorio: " << endl;
        cin >> fabricante;
        cout << "Tipo: " << endl;
        cin >> tipo;
        cout << "Uso: " << endl;
        cin >> uso;
        cout << "Data de fabricação: " << endl;
        cin >> dataFabricacao;
        cout << "Data de vencimento: " << endl;
        cin >> dataVencimento;
        cout << "Lote: " << endl;
        cin >> lote;
        cout << "Descrição: " << endl;
        cin >> descricao;
        cout << "Bula: " << endl;
        cin >> bula;
        cout << "Desconto: " << endl;
        cin >> desconto;
        cout << "Entrada no sistema: " << endl;
        cin >> entradaSistema;
        cout << "Fornecedor: " << endl;
        cin >> fornecedor;
        cout << "Classe do remédio: " << endl;
        cin >> classeRemedio;
        cout << "Retém receita: " << endl;
        cin >> retemReceita;
    }
    void printProduto(){
        cout << "\nProduto registrado:" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Tipo Produto: " << tipoProduto << endl;
        cout << "Principio: " << principio << endl;
        cout << "Forma de Administracao: " << formaAdministracao << endl;
        cout << "Tipo de Embalagem: " << tipoEmbalagem << endl;
        cout << "Quantidade: " << quantidade << endl;
        cout << "Apresentacao: " << apresentacao << endl;
        cout << "Concentracao: " << concentracao << endl;
        cout << "Fabricante: " << fabricante << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Uso: " << uso << endl;
        cout << "Data de Fabricação: " << dataFabricacao << endl;
        cout << "Data de Vencimento: " << dataVencimento << endl;
        cout << "Lote: " << lote << endl;
        cout << "Descricao: " << descricao << endl;
        cout << "Bula: " << bula << endl;
        cout << "Desconto: " << desconto << endl;
        cout << "Entrada no Sistema: " << entradaSistema << endl;
        cout << "Fornecedor: " << fornecedor << endl;
        cout << "Classe do Remédio: " << classeRemedio << endl;
        cout << "Retém Receita: " << retemReceita << endl;
    }
};

void excluirProduto(map<string, Produto>& estoque) {

}

void registrarProduto(map<string, Produto>& estoque){
    bool exit = false;
    while(!exit){
        Produto p;
        p.insertDB();

        estoque[p.nome] = p;

        cout << "Deseja adicionar outro produto? (s/n): " << endl;
        string resposta;
        cin >> resposta;
        if (resposta != "s" && resposta != "S") { exit = true; }
    }
}
void consultarProduto(map<string, Produto>& estoque){
    cout << "Digite o nome do produto que deseja consultar: ";
    string nome;
    cin >> nome;

    auto it = estoque.find(nome);
    if (it != estoque.end()) {
        it->second.printProduto();
    } else { cout << "Produto nao encontrado" << endl; }
}
int main(){
    int opcao = 0;
    bool exit = false;
    map<string, Produto> db;

    while(!exit){
        cout << "Escolha opcao" << endl 
        <<  "1- Registrar produto" << endl 
        << "2- Consultar produto" << endl
        << "3- Excluir produto" << endl
        << "4- Sair da aplicação" << endl;

        int opcao = 0; cin >> opcao;
        switch(opcao){
        case 1:
            registrarProduto(db);
            break;
        case 2:
            consultarProduto(db);
            break;
        case 3:
            excluirProduto(db);
            break;
        case 4:
            exit = true;;
            break;
        default:
            break;
       }
    }
}