#ifndef PESSOA_H
#define PESSOA_H
#include<iostream>
using namespace std;
class Pessoa
{
private:
    string nome;
    int Idade;
    string sexo;
public:
    Pessoa(string nome, int idade, string sexo);
};

Pessoa::Pessoa(string nome, int idade, string sexo)
{
    this->nome = nome;
    this->Idade = idade;
    this->sexo = sexo;
}


class Jogador: public Pessoa
{
private:
    string posicao;
public:
    Jogador(string nome, string posicao, string sexo, int idade);
};

Jogador::Jogador(string nome, string posicao, string sexo, int idade) : Pessoa(nome, idade, sexo)
{
    this->posicao = posicao;
}


#endif