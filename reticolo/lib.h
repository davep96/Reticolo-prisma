struct dati{ 
	double grad, prim,  rad, err, err_rad ;
	int ord;
	};

struct misura{
	double mis, err;
};

//passa da primi di grado a radianti
void prim_to_rad(double x){
	x = (x/60) *0.0175;
	return ;
}

//passa da gradi a radianti
void grad_to_rad(double x){
	x= x*0.0175;
}

//Media Pesata
double W_Media (misura*v, int n){
	double media=0;
	double weight=0;
	
	for (int i=0;i<n;i++){
		media= media+ v[i].mis/pow(v[i].err,2);
		weight = weight +1/pow(v[i].err,2);
	}

	return media/weight;
}

//Errore per la media pesata
double W_Err (misura*v, int n){
	double err=0;
	for(int i=0; i<n; i++)
		err= err + 1/pow(v[i].err,2);
	
	return sqrt(1/err);
}