/*
	Questo programma esegue il prodotto tra polinomi. il grado massimo deve essere 8.
	I coeffcienti devono essere tutti positivi.
*/
# include <stdio.h>

int inserimento_grado();
void valorizza_polinomio(int[], int);
void stampa_polinomi(int[], int[], int, int);
void prodotto(int[], int[], int, int);

int main ( void ) {

	// dichiarazione dei gradi dei polinomi (min 0, max 8).
	int grado1;
	int grado2;

	// inserimento dei gradi da parte dell'utente.
	printf("\nPRIMO POLINOMIO: ");
	grado1 = inserimento_grado();
	printf("\nSECONDO POLINOMIO: ");
	grado2 = inserimento_grado();

	// dichiarazione dei polinomi, questi sono vettori che racchiudono i propri coeff.
	int polinomio1[grado1];
	int polinomio2[grado2];

	// i polinomi vengono valorizzati.
	printf("\nPRIMO POLINOMIO: ");
	valorizza_polinomio(polinomio1, grado1);
	printf("\nSECONDO POLINOMIO: ");
	valorizza_polinomio(polinomio2, grado2);

	// stampa del prodotto.
	printf("\nSTAMPA DEI POLINOMI DA MOLTIPLICARE: ");
	stampa_polinomi(polinomio1, polinomio2, grado1, grado2);

	// risultato.
	printf("\nRISULTATO:\n");
	prodotto(polinomio1, polinomio2, grado1, grado2);

	printf("\n");
	return 0;
};

// funzione di inserimento del grado del polinomio.
int inserimento_grado() {

	int grado = 0;				// grado del polinomio.
	int grado_valido = 0;		// flag di successo.

	printf("\n");
	do {
		printf("\nInserire il grado del polinomio [0, 1, ... 8]: ");
		scanf("%i", &grado);

		grado_valido = (grado > 8 || grado < 0) ? 0 : 1;	// il grado deve essere tra 0 e 8.

	} while (grado_valido == 0);

	printf("\n");
	return grado;
};

// funzione di valorizzazione dei polinomi. Vengono inseriti i coefficenti.
void valorizza_polinomio(int polinomio[], int grado) {

	int coeff_positivo = 1;

	printf("\n");
	for (int i = 0; i<grado; i++) {
		do {
			printf("\nInserisci il coefficente del valore numero %i: ", i+1);
			scanf("%i", &polinomio[i]);

			coeff_positivo = (polinomio[i] >= 0) ? 1 : 0;	// il coeff deve essere maggiore o uguale di 0.

		} while (coeff_positivo == 0);
	};

	printf("\n");
};

// funzione di stampa dei polinomi.
void stampa_polinomi(int primo[], int secondo[], int grado1, int grado2) {

	// alfa e beta sono i gradi del polinimio che corrispondono all'index che scorre al contrario.
	int alfa = grado1 - 1;
	int beta = grado2 - 1;

	printf("\n\n");

	printf("( ");
	for (int i = 0; i < grado1; i++) {
		if (i != grado1-1) {
			printf(" %ix ^ %i +", primo[i], alfa);
		} else {
			printf(" %ix ^ %i  ", primo[i], alfa);
		};
		
		alfa--;
	};
	printf(" ) * (  ");
	for (int i = 0; i < grado2; i++) {
		if (i != grado2-1) {
			printf(" %ix ^ %i +", secondo[i], beta);
		} else {
			printf(" %ix ^ %i  ", secondo[i], beta);
		};
		
		beta--;
	};
	printf(" ) ");


	printf("\n");
};

void prodotto(int primo[], int secondo[], int grado1, int grado2) {

	int quante_volte = grado1 * grado2;		// l'operazione deve essere effettuata piu volte.
	int risultato[quante_volte];			// array in cui vi e' il prodotto.
	int coeff[quante_volte];				// array che contiene i coeff da sommare durante il prodotto.
	int index = 0;
	int alfa = grado1 - 1;
	int beta = grado2 - 1;

	for (int i = 0; i < grado1; i++) {
		for (int j = 0; j < grado2; j++) {
			
			// debug!
			// printf("\n >>> Ora faccio %i * %i e sommo %i a %i \n", primo[i], secondo[j], alfa, beta);
			
			risultato[index] = primo[i] * secondo[j];
			coeff[index] = alfa + beta;
			beta--;

			index++;

		};
		alfa--;
		beta = grado2 - 1;
	};

	printf("\n");
	printf("( ");
	for (int i = 0; i<quante_volte; i++) {

		if (i != quante_volte - 1) {
			printf(" %ix ^ %i +", risultato[i], coeff[i]);	
		} else  {
			printf(" %ix ^ %i  ", risultato[i], coeff[i]);	
		};
			
	};
	printf(" )");





	printf("\n");
};










