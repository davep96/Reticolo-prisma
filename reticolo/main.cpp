#include "header.h"


int main(){
	//definizione delle variabili
	
	misura D; //potere dispersivo
	misura R; //potere risolutivo
	double L_Na1= 5890E(-10); //lunghezze d'onda del doppietto di sodio in metri
	double L_Na2= 5896E(-10);
	misura d; //passo del reticolo da calcolare
	misura d_na1, d_na2; //passo del reticolo con le due lunghezze d'onda date per il doppietto di sodio 
	misura Lente;
	
	Lente.mis= //inserire larghezza della lente
	Lente.err= //inserire sensibilità dello strumento
	
		
	//lettura del file e collocazione dei dati in un vettore di strutture
	ifstream input("data.dat");
	ifstream inputNA("Na.dat");
	ofstream output("results.txt");
	
	//calcolo del passo del reticolo con errore
	int K; //numero di angoli forniti per il doppietto di sodio
	inputNA>>K
	dati*v_na = new dati[K]; //vettore di struct per il doppietto
	misura d_NA1 = new misura [K];
	misura d_NA2 = new misura [K];
	
	for(int i =0; i<K; i++){
		inputNA>>v_na[i].grad>>v[i].prim>>v[i].ord>>v[i].err;
		v_na[i].rad= grad_to_rad(v_na[i].grad) + prim_to_rad(v_na[i].prim);
		v_na[i].err_rad= prim_to_rad(v_na[i].err);
		d_NA1[i].mis= v_na.ord[i]*L_Na1 /(sin(v_na[i].rad)) ;
		d_NA1[i].err = v_na.ord[i]*L_Na1*cos(v_na[i].rad) /(pow(sin(v_na[i].rad),2)) * v_na[i].rad;
		d_NA2[i].mis= v_na.ord[i]*L_Na2 /(sin(v_na[i].rad)) ;
		d_NA2[i].err = v_na.ord[i]*L_Na1*cos(v_na[i].rad) /(pow(sin(v_na[i].rad),2)) * v_na[i].rad;
	}
	
	d_na1.mis= W_Media(d_NA1,K);
	d_na2.mis= W_Media(d_NA2,K);
	d.mis= (d_na1.mis*1/pow(d_na1.err,2) + d_na2.mis*1/pow(d_na2.err,2)) /(1/pow(d_na1.err,2)+ 1/pow(d_na2.err,2)); //media pesata tra i due passi del reticolo
	d.err= pow(1/(1/pow(d_na1.err,2)+ 1/pow(d_na_2,2)),0.5); //errore sulla media pesata
	
	int N; //numero degli elementi su cui andrò a lavorare

	input>>N
	dati*v = new dati[N];
	misura*lambda = new misura[N];
	misura*disp = new misura[N];
	misura*resol = new misura[N];
	
	for(int i =0; i<N; i++){
		input>>v[i].grad>>v[i].prim>>v[i].ord>>v[i].err;
		v[i].rad= grad_to_rad(v[i].grad) + prim_to_rad(v[i].prim);
		v[i].err_rad= prim_to_rad(v[i].err);
	}
	
	//elaborazione dei dati per le lunghezze d'onda
	for(int i=0; i<N; i++){
		lambda[i].mis= (d.mis * sin(v[i].rad))/(v[i].ord);
		lambda[i].err= sqrt(pow(sin(v[i].rad),2)*pow(d.mis,2) + pow(-cos(v[i].rad),2)*pow(v[i].rad,2))
	}
	
	//elaborazione dei dati per il potere dispersivo
	for(int i=0; i<N; i++){
		disp[i].mis= v[i].ord / (d.mis * cos(v[i].rad));
		disp[i].err = pow(pow(v[i.ord/(pow(d.mis,2)*cos(v[i].rad)),2) * d.err + pow(v[i].ord*tan(v[i].rad)/(d.mis * cos(v[i].rad)),2) ,0.5)
	}
	//elaborazione dei dati per il potere risolutivo
	for(int i=0; i<N; i++){
		resol[i].mis = v[i].ord * Lente.mis * 1/d.mis;
		resol[i].err = pow(pow(v[i].ord * 1/d.mis,2) *Lente.err + pow(v[i].ord * Lente.mis * 1/pow(d.mis,2),2)* d.err,0.5);
	}
	
	//risultati
	output<<"il passo del reticolo e': "<<endl;
	output<<d.mis << " - " <<d.err;
	
	output<<"i dati delle lunghezze d'onda, e del potere dispersivo e rislutivo dello strumento, relative al file passato sono: "<<endl;
	for(int i=0; i<N; i++){
		output<< lambda[i].mis << " - " <<lambda[i].err <<endl;
		output<< disp[i].mis << " - " <<disp[i].err <<endl;
		output<< resol[i].mis <<" - " << resol[i].err
	}
	
	output<<"da cui  si ottengono i valori finali di lambda e errore: "<<endl;
	output<<W_Media(lambda, N)<<" - "<<W_Err(lambda, N)<<endl;
	
	
	
	
	return 0;
}