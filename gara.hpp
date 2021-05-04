#include "veicolo.hpp"
#ifndef _gara_hpp_
#define _gara_hpp_
#include <cstdlib>
#include <ctime>
class gara{
	int durata;
	int numeropartecipanti;
	int numeroiscritti;//variabile di istanza;
	veicolo **veicoli;
	
	public:
	gara(int durata, int numeropartecipanti) : durata(durata), 
	numeropartecipanti(numeropartecipanti){
		veicoli= new veicolo* [numeropartecipanti];
		numeroiscritti=0;
	}
	
	~ gara(){	//elimina la memoria occupata perchè abbiamo un array inizializzato nel costruttore
		delete[] veicoli;
	}
	
/*	void partenza();
	void stampaclassifica();
	void aggiungipartecipante(veicolo& v);*/



void aggiungipartecipante( veicolo &v){
	cout<<"numero iscritti"<<numeroiscritti<<endl;
	veicoli[numeroiscritti++] = &v;
}


void partenza(){
	srand(time (NULL));
 for(int i=0; i<durata; i++){
	for(int j=0; j<numeroiscritti; j++){
		int scelta= rand()%2;
		if(scelta==1)
		veicoli[j]->accellera();
		else
		veicoli[j]->decellera();
		}
	this->controlla(i);
	}

//this->mergesort(veicoli, numeroiscritti);
this->ordinamento();	
 this->stampaclassifica(veicoli);
}

void stampaclassifica(veicolo**veicoli){
	int pos=1;
	 for(int i=numeroiscritti-1; i>=0; i--){
	 	cout<<"posizione:"<<pos<<" "<<*veicoli[i]<<endl;
	 	pos++;
		
}
}

void ordinamento(){
	int j=0;
	veicolo **velo;
	velo= new veicolo*[numeroiscritti];
	 for(int j=0;j<numeroiscritti;j++){
	 	int pos=veicoli[j]->getvelocita();
		for(int i=0;i<numeroiscritti;i++){
		
			if(veicoli[i]->getvelocita()>pos){
				//cout<<veicoli[j]->getvelocita()<<endl;
				//cout<<veicoli[i]->getvelocita<<endl;
				
				
				velo[j]=veicoli[j];
				veicoli[j]=veicoli[i];
				veicoli[i]=velo[j];
					cout<<"cont"<<j<<endl;
					cout<<veicoli[j]->getvelocita()<<endl;
			}
			}
		}
		//cout<<"velo"<<*velo[j]<<endl;
		/*velo[1]=veicoli[j];
		veicoli[j]=velo[0];
		veicoli[pos]=velo[1];
	 }
	 for(int i=0;i<numeroiscritti;i++){
		 veicoli[i]=velo[i];
	 	cout<<"bastaa:"<<*veicoli[i]<<endl;
	 }*/
}

/*
void merge( int m, int n) {   // complessità: spazio lineare; tempo lineare O(n)
    veicolo **a;
    a= new veicolo*[numeroiscritti];
	int i=0;
    int j=m;
    int k=0;
    while(i<m && j<n) {
        if(veicoli[i]->getvelocita()>=veicoli[j]->getvelocita()){
		 a[k++] = veicoli[j++];
		 cout<<"i:"<<**a<<endl;
     }
        else{
		a[k++] = veicoli[i++];
		cout<<"j:"<<**a<<endl;
		}
    }
    while(i<m) a[k++] = veicoli[i++];
    while(j<n) a[k++] = veicoli[j++];
    for(int i=0; i<n; i++){
	veicoli[i] = a[i];
	}
}

void mergesort(veicolo **veicoli,int n) {
    if(n<=1) return;
    int m = n/2;
    mergesort(veicoli,m);      // chiamata sul vettore v[0...m-1]
	mergesort(veicoli+m, n-m); // chiamata sul vettore v[m...n-1]
    merge(m,n);  // complessità temporale O(n)
}*/
void controlla(int t){
	
	int massimo_temp= veicoli[0]->getvelocita();
	int indicemax=0;
	//int massimo_temp=-1;
	
	for(int i=1; i<numeroiscritti; i++){
		//estrarre la velocità e verificare la distanza tra due veicoli
		if(veicoli[i]->getvelocita()>massimo_temp){
			massimo_temp=veicoli[i]->getvelocita();
			indicemax=i;
		}
	
	}
/*	for(int i=0; i<numeroiscritti; i++){
	 	cout<<"prova:"<<" "<<*veicoli[i]<<endl;
		
}
*/	
	cout<<*veicoli[indicemax]<<endl;	
}

};
#endif
