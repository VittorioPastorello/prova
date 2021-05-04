#include "moto.hpp"
#include "auto.hpp"
#include "gara.hpp"

int main(){
	
/*	double *array;
	array=new double [10];
for(int i=0; i<10;i++){
	cout<<array[i]<<" ";
}*/

cout<<endl;//questo stampera qualcosa perchè abbiamo una libreria definita per questa
//la classe astratta presenterà dei problemi, vedere array di veicoli in GARA
//utilizziamo array di puntatori
 moto m (120, 10000, "ducati", "1000cc");
 Auto a (160, 8000, "fiat punto","diesel","1300cc MTJ");
 Auto b (400, 20000, "ferrari gtx","diesel","5000cc");
 Auto c (400, 20000, "speed","diesel","2500cc");
  Auto u (400, 20000, "ferrari gtx","diesel","5000cc");
 cout<<m<<endl;
 cout<<a<<endl;
 cout<<b<<endl;
 
 gara Gara(10, 10);
	Gara.aggiungipartecipante(m);
	Gara.aggiungipartecipante(a);
	Gara.aggiungipartecipante(b);
	Gara.aggiungipartecipante(c);
	Gara.aggiungipartecipante(u);
	Gara.partenza();

}
