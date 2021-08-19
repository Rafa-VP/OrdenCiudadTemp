//Se tiene un vector que almacena las ciudades del mundo: Quito, Guayaquil, Cali, Bogotá, etc.
//Se tiene otro vector que almacena las temperaturas de estas ciudades.
//A cada ciudad le corresponde una temperatura
//Quito     17
//Guayaquil 23
//Esmeraldas 28
//Cali       18
//a) Se pide diseñar la función que ordene alfabéticamente por ciudades sin
//olvidar la temperatura. Resultado esperado de esta ordenación:
//Cali    18
//Esmeraldas 28
//Guayaquil 23
//Quito 17
//b) Se pide diseñar la función que ordene por la temperatura ascendentemente.
// (conservando la ciudad). Resultado esperado:
//  Quito   17
//  Cali 18
//  Guayaquil 23
//  Esmeraldas 28

#include <iostream>
using namespace std;

void imprimirVector(string vector[], int total){
	for(int i=0;i<total;i++)
	cout<<vector[i]<<endl;
}

void imprimirVectorDoble(string vector[], int vector2[], int total){
	for(int i=0;i<total;i++)
	cout<<vector[i]<<" - "<<vector2[i]<<endl;
}

void OrdenamientoQuicksortAlfabetico(string ciudades[],int temperaturas[], int primerValor, int ultimoValor){
    int central, i, j;
	string pivote;
    central= (primerValor+ultimoValor)/2; //Posicion central del arreglo
    pivote= ciudades[central]; // Capturar el valor medio del arreglo
    i = primerValor;
    j = ultimoValor;
    do{
       //Separando en dos partes el arreglo
    	while(ciudades[i] < pivote) i++; //Separando los valores menores al pivote
    	while(ciudades[j] > pivote) j--; //Separando los valores mayores al pivote
    	if(i<=j){
    	string temporal;
			int temporal2;
        //Intercambio de valores
        temporal = ciudades[i];
        ciudades[i] = ciudades[j];
        ciudades[j] = temporal;
				temporal2 = temperaturas[i];
				temperaturas[i] = temperaturas[j];
				temperaturas[j] = temporal2;
        i++;
        j--;
       }
    }while(i<=j);
		if (primerValor < j)
        	OrdenamientoQuicksortAlfabetico(ciudades, temperaturas, primerValor, j);
     	if (i < ultimoValor)
        	OrdenamientoQuicksortAlfabetico(ciudades, temperaturas, i, ultimoValor);
}

void OrdenamientoQuicksortNumerico(int temperaturas[], string ciudades[], int primerValor, int ultimoValor){
    int central, i, j, pivote;
    central= (primerValor+ultimoValor)/2; // Posicion central del arreglo
    pivote= temperaturas[central]; // Capturar el valor medio del arreglo
    i = primerValor;
    j = ultimoValor;

    do{
       //Separando en dos partes el arreglo
    	while(temperaturas[i] < pivote) i++; //Separando los valores menores al pivote
    	while(temperaturas[j] > pivote) j--; //Separando los valores mayores al pivote
    	if(i<=j){
        int temporal;
		string temporal2;
        //Intercambio de valores
        temporal = temperaturas[i];
        temperaturas[i] = temperaturas[j];
        temperaturas[j] = temporal;
		temporal2 = ciudades[i];
        ciudades[i] = ciudades[j];
        ciudades[j] = temporal2;
        i++;
        j--;
       }
     }while(i<=j);
     if (primerValor < j)
          OrdenamientoQuicksortNumerico(temperaturas, ciudades, primerValor, j);
     if (i < ultimoValor)
          OrdenamientoQuicksortNumerico(temperaturas, ciudades, i, ultimoValor);
}

int main(){
	
	string ciudades[]={"Quito", "Guayaquil", "Esmeraldas","Cali"};
	int temperatura[]={17, 23, 28, 18};
	
	// Orden por ciudades - QuickSort
	cout<<"Orden por ciudades - QuickSort"<<endl;
	OrdenamientoQuicksortAlfabetico(ciudades,temperatura,0,3);
	imprimirVectorDoble(ciudades,temperatura,4);

	cout<<endl;

	//Orden por temperatura - QuickSort
	cout<<"Orden por temperatura - QuickSort"<<endl;
	OrdenamientoQuicksortNumerico(temperatura,ciudades,0,3);
	imprimirVectorDoble(ciudades,temperatura,4);
	
}
