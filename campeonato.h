#ifndef CAMPEONATO_H
#define CAMPEONATO_H

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
};

Campeonato::Campeonato(string nome, string modalidade)
{
    this->nome = nome;
    this->modalidade = modalidade;
    this->id = cont;
    cont++;
}

int Campeonato::cont = 1;

void Campeonato::add_times(string nome, ListaDE<Jogador> integrantes) {
    Time temp(nome, integrantes);
}

#endif