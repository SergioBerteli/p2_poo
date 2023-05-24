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
};

Time::Time(string nome, ListaDE<Jogador> jogadores)
{
    this->nome = nome;
    this->jogadores = jogadores;
}
#endif