/* Calcolatore di indice di massa corporea */ 
//Inclusione librerie
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
//Definizione numero di totale di persone da generare (di default settato a 10)
#define totale_persone 1000
//Costanti per relogare il generatore: 
const int eta_min=18; 
const int eta_max=80; 
const float peso_min=50; //In chilogrammi 
const float peso_max=100; //In chilogrammi 
const float altezza_min=1.5; //In metri
const float altezza_max=2; //In metri 
//  Costanti per la stampa 
const float BMI_medio_std=25; //BMI medio standard (25 di default) 
//  Definizione del tipo di struttura dati 
typedef struct {
	float peso; //  Peso 
	float altezza; //  Altezza 			
	float bmi; //  Bmi 
	int eta; //  Eta
	short int indicatore; 
} strutturaPersone;
//  Prototipi di funzione
float generaFloat(const float max, const float min); //  Genera un float compreso tra min e un mas (tra un massimo o un minimo) 
float calcolaMedio(strutturaPersone persona[], short int indica); // Calcola la media *=degli under 40 se indica=1 e degli over 40 se e' 0
float pesoMassimo(strutturaPersone persona[], short int indica); //  Trova il peso massimo *
float altezzaMassima(strutturaPersone persona[], short int indica); // Trova l'altezza massima *

void generaPersone(strutturaPersone persona[]); //  Genera profili di persone (peso bmi altezza peso) utilizzando la pseudo-casualità
void stampa(strutturaPersone persona[]); //  Stampa [---]

// Main 
int main()
	{	
		strutturaPersone persona[totale_persone]; //  Dichiara la struttura persona avente persone pari a "totale_persone"
		srand(time(NULL)); //  Inizializza il seme utilizzando la funzione time 
		generaPersone(persona); //  Genera le persone
		stampa(persona); //  Stampa 
		return 0; //  Esce dal programma
		}
// Funzione che genera le persone
void generaPersone(strutturaPersone persona[])
	{
		for(int i=0; i<totale_persone; i++)
			{
				persona[i].peso = generaFloat(peso_max, peso_min); //  Genera peso in kg
				persona[i].altezza = generaFloat(altezza_max, altezza_min);//  Genera altezza in metri 
				persona[i].bmi = persona[i].peso / (persona[i].altezza*persona[i].altezza); //  Calcola il bmi
				persona[i].eta = (int)generaFloat(eta_max, eta_min); //  Genera eta e poi converte in intero 
				persona[i].indicatore = (persona[i].eta>40)? 0:1; //  Assume 0 se maggiore di 40, 1 altrimenti 
				}	
		} 
//  Funzione che genera un valore pseudocasuale a partire da due valori float (un massimo e un minimo) 
float generaFloat(const float max, const float min) 
	{ 	
		return (max - min) * ((float)rand() / RAND_MAX) + min; 
		/*  l'output di rand() viene convertito in reale e diviso poi col valore RAND_MAX
		 * 	il quale è il valore massimo che può assumere la funzione rand().
		 * 	La divisione darà per forza un valore compreso tra 0 e 1 (poiché RAND_MAX è 
		 * 	uguale o maggiore del valore di rand() ). 
		 * 	Il risultato viene moltiplicato con la differenza tra il massimo e il minimo 
		 *  (che sarebbe il range di numeri da prendere in considerazione). 
		 *  al range viene aggiunto min per farlo partire da min  
		 * */
		} 
float calcolaMedio(strutturaPersone persona[], short int indica)
	{
		float totale_bmi=0; //  Conterrà la somma di tutti i BMI 
		
		int contatore=0; //  Conta il numero di persone
		for (int i=0; i<totale_persone; i++)
			{	
				if(persona[i].indicatore==indica)
					{
						totale_bmi = persona[i].bmi + totale_bmi; //  Calcola il bmi totale
						contatore++; 
						}
					}
		return totale_bmi/contatore; 	//  Ritorna la media 
}
			
void stampa(strutturaPersone persona[])
	{
		for(int i=0; i<totale_persone; i++)
			{ 
				//  Stampa bmi calcolato di ogni persona
				printf("| Persona numero %d:\t| eta: %d anni | peso: %.2fkg | altezza: %.2fm | BMI: %.2f |", i+1, persona[i].eta, persona[i].peso, persona[i].altezza, persona[i].bmi);//Stampa i risultati ottenuti
				printf((persona[i].bmi>=BMI_medio_std)? "La persona e' mediamente sovrappeso\n":"La persona e' mediamente sottopeso\n");
				}
		//  Stampa media aritmetica di bmi di under 40 e over 40
		printf("\n| Media aritmetica BMI degli under 40 e' %.2f |", calcolaMedio(persona, 1));//Stampa i risultati ottenutif
		printf("\n| Media aritmetica BMI degli over 40 e' %.2f |", calcolaMedio(persona, 0));//Stampa i risultati ottenuti
		printf("\n| Il peso maggiore degli under 40 e' %.2f |", pesoMassimo(persona, 1));
		printf("\n| Il peso maggiore degli over 40 e' %.2f |", pesoMassimo(persona, 0));
		printf("\n| L'altezza maggiore degli under 40 e' %.2f |", altezzaMassima(persona, 1));
		printf("\n| L'altezza maggiore degli over 40 e' %.2f |\n", altezzaMassima(persona, 0));
		}

float pesoMassimo(strutturaPersone persona[], short int indica)
	{
		float peso_maggiore=0; 
		for (int i=0; i<totale_persone; i++)
			{	
				if(persona[i].indicatore==indica && persona[i].peso>peso_maggiore)
					{
						peso_maggiore = persona[i].peso; //  Assume il valore del peso maggiore
						}
					}
		return peso_maggiore; 	//  Ritorna il peso maggiore
		}
float altezzaMassima(strutturaPersone persona[], short int indica)
	{
		float alt_maggiore=0; 
		for (int i=0; i<totale_persone; i++)
			{	
				if(persona[i].indicatore==indica && persona[i].altezza>alt_maggiore)
					{
						alt_maggiore = persona[i].altezza; //  Assume il valore dell'altezza maggiore
						}
					}
		return alt_maggiore; 	//  Ritorna l'altezza maggiore
		}
		

