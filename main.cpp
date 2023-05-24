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
    void adiciona();
    void remove();
    void edita();
    void lista();
};


void BancoDeDados::adiciona() {
    
}


int main()
{
    Menu app;
    return 0;
}
