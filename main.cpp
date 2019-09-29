#include <iostream>
#define tam 200
using namespace std;

char txt[tam];
char vet[tam];
int po = 0;
int itensPilha = 0;
void ea(); // caso inicial
void ec();
void eb(); //caso final
void pilha(char a);
void pilha();

void ea(){
    if(txt[po] >= '0' && txt[po] <= '9'){
        po++;
        eb();
    }
    else if(txt[po] == '('){
        po++;
        ec();
    }
    else if(txt[po] == ')'){
        pilha();
    }
    else{
        puts("rejeita");
    }
}

void eb(){
    if((!(txt[po] >= '0' && txt[po] <= '9')) && ((txt[po] != '(') && txt[po] != ')') && txt[po] != '\0'){
        po++;
        ea();
    }
    else if(txt[po] == ')'){
        po++;
        pilha();
    }
    else{
        if(itensPilha == 0 && txt[po] == '\0'){
            puts("aceita");
        }
        else{
            puts("rejeita");
        }
    }
}

void ec(){
pilha(')');
ea();
}

void pilha(char a){
    vet[itensPilha] = a;
    itensPilha++;
}

void pilha(){
    itensPilha--;
    eb();
}

int main() {
    puts("insira uma expressão");
    scanf("%[^\n]", txt);
    fflush(stdin);
    ea();
    return 0;
}