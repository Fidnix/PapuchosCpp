#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;
#include "papitolindo.h"
#include "funcione.h"
#define MAX_PAPUCHOS 20

void llenaPapuchos(struct PapitoLindo *papuchos,int &cantPapu){
    ifstream archPapuchos("bellacos.csv", ios::in);
    if(not archPapuchos.is_open()){
        cout << "Error: Los papis no existen :(" << endl;
        exit(1);
    }

    archPapuchos.clear();
    archPapuchos.seekg(0);

    double tamano;
    char comma, nombre[50];
    int esBlanco, eBer, eFuck;
    while(true){
        archPapuchos >> tamano;
        if(archPapuchos.eof()) break;
        archPapuchos >> comma;

        archPapuchos.get(nombre, 50, ';');

        archPapuchos >> comma >> esBlanco
            >> comma >> papuchos[cantPapu].edad
            >> comma >> papuchos[cantPapu].numeroDeNovias
            >> comma >> eBer
            >> comma >> eFuck;
        
        papuchos[cantPapu].tamanoDelMalandrin = tamano;
        papuchos[cantPapu].esBlanco = (bool) esBlanco;
        papuchos[cantPapu].eBerraco = (bool) eBer;
        papuchos[cantPapu].eFuckBoi = (bool) eFuck;
        
        papuchos[cantPapu].nombres = new char[ strlen(nombre) +1 ];
        strcpy(papuchos[cantPapu].nombres, nombre);

        cantPapu++;
    }
}
void calculaProbabilidaDeQueterobe(struct PapitoLindo *papuchos,int cantPapu,double *probabilida){

    for(int i=0;i<cantPapu;i++){
        if(papuchos[i].nombres=="Bryan" or papuchos[i].nombres == "Brian"){
            if(not papuchos[i].esBlanco) probabilida[i]=1000;
            else probabilida[i]=0.7;
        }
        else if(not papuchos[i].esBlanco){
            probabilida[i] = 0.5;
        }
        else{
            probabilida[i] = 0.01;
        }
        if(papuchos[i].numeroDeNovias>3)probabilida[i]=probabilida[i]+probabilida[i]*0.15;
    }
}

void crearReporte(struct PapitoLindo *papuchos, int cantPapu, double * probabilida){
    ofstream archRepor("ReportePoliciaco.txt",ios::out);
    if(not archRepor.is_open()){
        cout << "Error: Nao Nao Nao, Voce debe comer vrga" << endl;
        exit(1);
    }

    archRepor << "Probabilidad de morir xdxdxd" << endl;
    imprimirLinea(archRepor, '=');
    
    
    for(int i = 0; i < cantPapu; i++){
        if(papuchos[i].eFuckBoi){
            if(papuchos[i].tamanoDelMalandrin>70){
                if(probabilida[i]>0.5){
                    archRepor<<papuchos[i].nombres<<" probablemente te va a robar y te violara hasta que mueras"<<endl;
                }
                else if(probabilida[i]==0.5)archRepor<<papuchos[i].nombres<<" probablemente no te va a robar, pero yo que tu me cuidaría"<<endl;
                else archRepor<<papuchos[i].nombres<<" probablemente no te va a robar, pero ta loquito"<<endl;
            }
            else if(probabilida[i]>0.5){
                    archRepor<<papuchos[i].nombres<<" probablemente te va a robar y intentara violarte"<<endl;
                }
            else if(probabilida[i]==0.5)archRepor<<papuchos[i].nombres<<" probablemente no te va a robar, pero yo que tu me cuidaría"<<endl;
            else archRepor<<papuchos[i].nombres<<" probablemente no te va a robar, pero e alto"<<endl;
        }
        else if(probabilida[i]>0.5){
                    archRepor<<papuchos[i].nombres<<" probablemente te va a robar el muy negro"<<endl;
                }
        else if(probabilida[i]==0.5)archRepor<<papuchos[i].nombres<<" probablemente no te va a robar, pero ojo al color de piel"<<endl;
        else archRepor<<papuchos[i].nombres<<" probablemente no te va a robar"<<endl;
         }
}
//Comando
//g++ main.cpp -o test.exe
// Crea el test.exe

void imprimirLinea( ofstream &arch, char car){
    arch << setw(20) << setfill(car) << car << setfill(' ') << endl;
}