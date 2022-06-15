#include<iostream>
using std::cout;
using std::endl;
using std::string;
using std::cin;

int main(int argc, char *argv[])
{
    char lol[7]={0,0,0,0,0,0,0};
    for(int i=0;i<7;i++){
    cout<<"Valor "<<i<<"negado: "<<!*lol+i<<endl;

    }
    return 0;
}