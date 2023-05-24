
#include<iostream>
#include"list.h"
#include"times.h"
using namespace std;

class Campeonato
{
private:
    string nome;
    string modalidade;
    int id;
    static int cont;
    ListaDE<Time> times;
public:
    Campeonato(string nome, string modalidade);
    void add_times(string nome, ListaDE<Jogador> integrantes);
    int get_ID();
    void imprime();
};

Campeonato::Campeonato(string nome, string modalidade)
{
    this->nome = nome;
    this->modalidade = modalidade;
    this->id = cont;
    cont++;
}

int Campeonato::cont = 0;

void Campeonato::add_times(string nome, ListaDE<Jogador> integrantes) {
    Time temp(nome, integrantes);
    times.insere_fim(temp);
}

int Campeonato::get_ID() {
    return id;
}

void Campeonato::imprime() {
    ElementoListaDE<Time> * nav = times.inicio;
    while (nav != nullptr)
    {
        nav->dado.imprime();
        nav = nav->proximo;
    }
    
}