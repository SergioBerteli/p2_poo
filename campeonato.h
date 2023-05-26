
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
    void set_nome(string nome);
    string get_nome();
    void set_modalidade(string modalidade);
    string get_modalidade();
};

void Campeonato::set_nome(string nome) {
    this->nome = nome;
}

string Campeonato::get_nome() {
    return this->nome;
}

void Campeonato::set_modalidade(string modalidade) {
    this->modalidade = modalidade;
}

string Campeonato::get_modalidade() {
    return this->modalidade;
}

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