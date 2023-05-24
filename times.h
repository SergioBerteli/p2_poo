#ifndef TIMES_H
#define TIMES_H
#include<iostream>
#include"list.h"
#include"pessoa.h"
using namespace std;
class Time
{
private:
    string nome;
    ListaDE<Jogador> jogadores;
public:
    Time(string nome, ListaDE<Jogador> jogadores);
    void imprime();
};

Time::Time(string nome, ListaDE<Jogador> jogadores)
{
    this->nome = nome;
    this->jogadores = jogadores;
}

void Time::imprime() {
    cout<<endl<<"Nome do time: "<<nome<<endl<<endl;
    ElementoListaDE<Jogador> * nav = jogadores.inicio;
    cout<<"Jogadorez:\n\n";
    while (nav != nullptr)
    {
        nav->dado.imprime();
        nav = nav->proximo;
    }
    
}
#endif