#include<iostream>
#include"list.h"
#include"campeonato.h"
using namespace std;


class Menu
{
private:
public:
    ~Menu();
    void main();
};

Menu::~Menu()
{
    cout<<"\nObrigado por usar o menu!\n";
}

void Menu::main() {
    
}


class BancoDeDados
{
private:
    ListaDE<Campeonato> campeonatos;
public:
    void adiciona(string nome_camp, string modalidade, int qtd_jogadores_no_time, int numero_times);
    bool remove(int ID);
    void edita(string nome_camp, string modalidade, int qtd_jogadores_no_time, int numero_times, int ID);
    void lista();
};


void BancoDeDados::edita(string nome_camp, string modalidade, int qtd_jogadores_no_time, int numero_times, int ID) {
    Campeonato temp(nome_camp, modalidade);
    ListaDE<Jogador> * jogadores;
    Jogador * jog;
    string nome_time;

    string nome_jog, posicao, sexo;
    int idade;

    for (int i; i<numero_times; i++) {
        cin>>nome_time;
        jogadores = new ListaDE<Jogador>;
        for (int j; j<qtd_jogadores_no_time; j++) {
            cin>>nome_jog;
            cin>>idade;
            cin>>posicao;
            cin>>sexo;
            jog = new Jogador(nome_jog, posicao, sexo, idade);
            jogadores->insere_fim(*jog);
        }
        temp.add_times(nome_time, *jogadores);
        delete jogadores;
    }
    ElementoListaDE<Campeonato> * nav = campeonatos.inicio;
    int cont;
    while (nav != nullptr)
    {
        if (nav->dado.get_ID() == ID) {
            campeonatos.remove_pos(cont);
            break;
        } else {
            cont ++;
        }
        nav = nav->proximo;
    }
    campeonatos.swap_p_indice(temp, cont);
}


void BancoDeDados::adiciona(string nome_camp, string modalidade, int qtd_jogadores_no_time, int numero_times) {
    Campeonato temp(nome_camp, modalidade);
    ListaDE<Jogador> * jogadores;
    Jogador * jog;
    string nome_time;

    string nome_jog, posicao, sexo;
    int idade;

    for (int i; i<numero_times; i++) {
        cin>>nome_time;
        jogadores = new ListaDE<Jogador>;
        for (int j; j<qtd_jogadores_no_time; j++) {
            cin>>nome_jog;
            cin>>idade;
            cin>>posicao;
            cin>>sexo;
            jog = new Jogador(nome_jog, posicao, sexo, idade);
            jogadores->insere_fim(*jog);
        }
        temp.add_times(nome_time, *jogadores);
        delete jogadores;
    }
    campeonatos.insere_fim(temp);
}

bool BancoDeDados::remove(int ID) {
    ElementoListaDE<Campeonato> * nav = campeonatos.inicio;
    int cont = 0;
    while (nav != nullptr)
    {
        if (nav->dado.get_ID() == ID) {
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

int main()
{
    Menu app;
    app.main();
    return 0;
}
