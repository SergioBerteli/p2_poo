#include<iostream>
#include"list.h"
#include"campeonato.h"
using namespace std;


class BancoDeDados
{
private:
    ListaDE<Campeonato> campeonatos;
public:
    void adiciona(string nome_camp, string modalidade, int qtd_jogadores_no_time, int numero_times);
    bool remove(int ID_camp_removido);
    bool edita(int ID_do_campeonato_a_ser_editado);
    void lista();
};


bool BancoDeDados::edita(int ID_do_campeonato_a_ser_editado) { // através de um menu, pede para o usuário inserir o atributo do campeonato que ele quer editar e depois pede para ele inserir o novo valor do atributo escolhido.
    ElementoListaDE<Campeonato> *nav = campeonatos.inicio;
    int n_times, qtd_jogadores_no_time;
    ListaDE<Time> novos_times;
    ListaDE<Jogador> novos_jogadores;
    Jogador * jog;
    Time * time;
    string nome_time, novo_nome;

    string nome_jog, posicao, sexo;
    int idade;
    while (nav != nullptr) {
        if (nav->dado.get_ID() == ID_do_campeonato_a_ser_editado) {
            break;
        } else {
            nav = nav->proximo;
        }
    }
    if (nav == nullptr) {
        cout<<"Id invalido."<<endl;
        return false;
    }
    cout<<"Qual atributos você quer editar?"<<endl;
    cout<<"1 - Nome do Campeonato"<<endl;
    cout<<"2 - Modalidade"<<endl;
    cout<<"3 - Times"<<endl;
    int opcao;
    cin>>opcao;
    switch (opcao) {
      case 1:
        cout<<"Qual o novo nome do campeonato?"<<endl;
        cin>>novo_nome;
        nav->dado.set_nome(novo_nome);
        break;
      case 2:  
        cout<<"Qual a nova modalidade do campeonato?"<<endl;
        cin>>novo_nome;
        nav->dado.set_modalidade(novo_nome);
        break;
      case 3:
        cout<<"Qual é o novo numero de times no campeonato?"<<endl;
        cin>>n_times;
        cout<<"Quantos jogadores terão em cada time?"<<endl;
        cin>>qtd_jogadores_no_time;
        for (int i = 0; i < n_times; i++) {
            cout<< "Insira o nome do time"<<endl;
            cin>>nome_time;
            for (int j= 0; j< qtd_jogadores_no_time; j++) {
                cout<< "Insira o nome do jogador"<<endl;
                cin>>nome_jog;
                cout<< "Insira a posição do jogador"<<endl;
                cin>>posicao;
                cout<< "Insira o sexo do jogador"<<endl;
                cin>>sexo;
                cout<< "Insira a idade do jogador"<<endl;
                cin>>idade;
                jog = new Jogador(nome_jog, posicao, sexo, idade);
                novos_jogadores.insere_fim(*jog);
            }
            time = new Time(nome_time, novos_jogadores);
            novos_times.insere_fim(*time);
        }
    };

    return true;
}


void BancoDeDados::adiciona(string nome_camp, string modalidade, int qtd_jogadores_no_time, int numero_times) {
    Campeonato temp(nome_camp, modalidade);
    ListaDE<Jogador> * jogadores;
    Jogador * jog;
    string nome_time;

    string nome_jog, posicao, sexo;
    int idade;

    for (int i=0; i<numero_times; i++) {
        cout<<"Insira o nome do time: "<<endl;
        cin>>nome_time;
        jogadores = new ListaDE<Jogador>;
        for (int j; j<qtd_jogadores_no_time; j++) {
            cout<<"Insira o nome do jogador "<<j<<endl;
            cin>>nome_jog;
            cout<<"Insira a idade do jogador "<<j<<endl;
            cin>>idade;
            cout<<"Insira a posicao do jogador "<<j<<endl;
            cin>>posicao;
            cout<<"Insira o sexo do jogador "<<j<<endl;
            cin>>sexo;
            jog = new Jogador(nome_jog, posicao, sexo, idade);
            jogadores->insere_fim(*jog);
        }
        temp.add_times(nome_time, *jogadores);
        delete jogadores;
    }
    campeonatos.insere_fim(temp);
}

bool BancoDeDados::remove(int ID_camp_removido) {
    ElementoListaDE<Campeonato> * nav = campeonatos.inicio;
    int cont = 0;
    while (nav != nullptr)
    {
        if (nav->dado.get_ID() == ID_camp_removido) {
            campeonatos.remove_pos(cont);
            return true;
        } else {
            cont ++;
        }
        nav = nav->proximo;
    }
    return false;
}

void BancoDeDados::lista() {
    ElementoListaDE<Campeonato> * nav = campeonatos.inicio;
    while (nav != nullptr)
    {
        nav->dado.imprime();
        nav = nav->proximo;
    }
    
}


class Menu
{
private:
    BancoDeDados ban;
public:
    ~Menu();
    void main();
};

Menu::~Menu()
{
    cout<<"\nObrigado por usar o menu!\n";
}

void Menu::main() {// crie um menu para manipular o banco de dados, ele consegue adicionar, remover, editar e listar campeonatos
    string nome_camp;
    string modalidade;
    int qtd_jogadores_no_time;
    int numero_times;
    int op = 0;
    while (true) {
        
    cout<<"Bem vindo ao menu"<<endl;
    cout<<"1 Adicionar"<<endl;
    cout<<"2 Remover"<<endl;
    cout<<"3 Editar"<<endl;
    cout<<"4 Listar"<<endl;
    cout<<"5 Sair"<<endl;
    cin>>op;
    switch(op){
        case 1:
            // Pede as informações para chamar o metodo "adiciona" do BancoDeDados
            cout<<"Insira o nome do campeonatos"<<endl;
            cin>>nome_camp;
            cout<<"Insira a modalidade"<<endl;
            cin>>modalidade;
            cout<<"Insira a quantidade de jogadores no time"<<endl;
            cin>>qtd_jogadores_no_time;
            cout<<"Insira o numero de times"<<endl;
            cin>>numero_times;
            ban.adiciona(nome_camp, modalidade, qtd_jogadores_no_time, numero_times);
            break;
        case 2:
            cout<<"Removendo campeonato"<<endl;
            break;
        case 3:
            cout<<"Editando campeonato"<<endl;
            break;
        case 4:
            // chama o metodo lista de BancoDeDados
            ban.lista();
            break;
        case 5:
            cout<<"Saindo do menu"<<endl;
            return ;
        default:
            cout<<"Opcao invalida"<<endl;
            break;
        }
    }
}



int main()
{
    Menu app;
    app.main();
    return 0;
}
