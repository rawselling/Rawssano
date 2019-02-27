/* Calcolatore di indice di massa corporea! 
 * Autore: problem_solving (?)
 * */ 
//Inclusione librerie
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#define N 10 //		Definisce il numero di persone
const float bmedio=25; //Definisce il numero di BMI medio 
typedef struct {float peso; //	Struttura dati 
	float altezza; //			Definisce una struttura di tipo "cristiano" che 			
	float bmi;} cristiano;//	contiene il peso, l'altezza e il bmi
//Prototipi di funzione
float generaFloat(const float mas, const float min); //	Genera un float compreso tra min e un mas (tra un massimo o un minimo) 
void generaCristiani(cristiano persona[]); //			Genera dati casuali su ipotetiche persone {peso e altezza} e calcola il bmi
void stampa(cristiano persona[]); //					Stampa l'elaborato 
int main(){	
	cristiano persona[N]; //	Dichiarazione N persone 
	srand(time(NULL)); //		Inizializza casualita basa su funzione time()
	generaCristiani(persona); //Genera le persone
	stampa(persona); //			Stampa
	return 0;} //				Esce dal programma 
void generaCristiani(cristiano persona[]){for(int i=0; i<N; i++){//Itera gli elementi N volte
		persona[i].peso=generaFloat(100, 60); //genera peso in kg
		persona[i].altezza=generaFloat(2, 1.5);//genera altezza in metri 
		persona[i].bmi=persona[i].peso/(persona[i].altezza*persona[i].altezza);}} //calcola bmi in base ai dati generati
float generaFloat(const float mas, const float min){ // Funzione che restituisce un valore reale casuale compreso tra mas e min (massimo e minimo) 
    return (mas - min) * ((float)rand() / RAND_MAX) + min;} //In questo caso (float converte il risultato della funzione rand (che restituisce un intero) il quale diviso per il massimo che può assumere darà un reale compreso fra 0 e 1. Aggiungendo il minimo (così da poter partire da min) 
void stampa(cristiano persona[]){
	for(int i=0; i<N; i++){ //Per ogni persona
		printf("Persona numero %d:\t peso: %.2fkg altezza: %.2fm BMI: %.2f ", i+1, persona[i].peso, persona[i].altezza, persona[i].bmi);//Stampa i risultati ottenuti
		printf((persona[i].bmi>=bmedio)? "La persona e' sovrappeso\n":"La persona e' sottopeso\n");}}//									  Stampa se la persona è sottopeso o sovrappeso
