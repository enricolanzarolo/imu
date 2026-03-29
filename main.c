#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <windows.h>
#include "RenditaCatastale&Aliquote.h"
#include "quick_sort.h"

int main()
{
    //HWND hWnd = GetConsoleWindow();                     // Ottieni l'handle della finestra del prompt dei comandi
    //ShowWindow(hWnd, SW_MAXIMIZE);                      // Massimizza la finestra del prompt dei comandi
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize = {120, 80};
    DWORD written;

    FillConsoleOutputAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE, bufferSize.X * bufferSize.Y, (COORD){0, 0}, &written);
    SetConsoleTextAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);

    printf("|######################################################################################################################|\n");
    printf("||                     ||               CALCOLO IMU - Imposta Municipale Unica                 ||                     ||\n");
    printf("||                     || Valido nei comuni Legnago, Cerea, Andrano, Lecce e Isola della Scala ||                     ||\n");
    printf("|######################################################################################################################|\n");

    printf("\n \t  _____________________________________________          _____________________________________________");
    printf("\n \t  |   Elenco Categorie Catastali (gruppo A)   |          |   Elenco Categorie Catastali (gruppo C)   |");
    printf("\n \t  |___________________________________________|          |___________________________________________|");
    printf("\n \t  | 1 = (A/1) Abitazioni di tipo signorile    |          | 11 = (C/1) Negozi e botteghe              |");
    printf("\n \t  | 2 = (A/2) Abitazioni di tipo civile       |          | 12 = (C/2) Magazzini e locali di deposito |");
    printf("\n \t  | 3 = (A/3) Abitazioni di tipo economico    |          | 13 = (C/3) Laboratori per arti e mestieri |");
    printf("\n \t  | 4 = (A/4) Abitazioni di tipo popolare     |          | 14 = (C/4) Fabbricati e locali per        |");
    printf("\n \t  | 5 = (A/6) Abitazioni di tipo rurale       |          |      esercizi sportivi                    |");
    printf("\n \t  | 6 = (A/7) Abitazioni in villini           |          | 15 = (C/5) Stabilimenti balneari e di     |");
    printf("\n \t  | 7 = (A/8) Abitazioni in ville             |          |      acque curative                       |");
    printf("\n \t  | 8 = (A/9) Castelli e palazzi di prego     |          | 16 = (C/6) Stalle, scuderie, rimesse,     |");
    printf("\n \t  | 9 = (A/10) Uffici e studi privati         |          |      autorimesse                          |");
    printf("\n \t  | 10 = (A/11) Abitazioni tipiche dei luoghi |          | 17 = (C/7) Tettoie chiuse od aperte       |");
    printf("\n \t  |___________________________________________|          |___________________________________________|");
    printf("\n");

    // Area interna header (sfondo: verde chiaro)
    FillConsoleOutputAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_GREEN, 120 * 1, (COORD){0, 1}, &written);
    FillConsoleOutputAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_GREEN, 120 * 1, (COORD){0, 2}, &written);

    // Bordo esterno header (sfondo: verde chiaro, testo: verde scuro)
    FillConsoleOutputAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_GREEN | FOREGROUND_GREEN, 120 * 1, (COORD){0, 0}, &written);
    FillConsoleOutputAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_GREEN | FOREGROUND_GREEN, 120 * 1, (COORD){0, 3}, &written);

    // Bordo interno header (sfondo: verde chiaro, testo: verde scuro)
    FillConsoleOutputAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_GREEN | FOREGROUND_GREEN, 2 * 1, (COORD){0, 1}, &written);
    FillConsoleOutputAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_GREEN | FOREGROUND_GREEN, 2 * 1, (COORD){0, 2}, &written);

    FillConsoleOutputAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_GREEN | FOREGROUND_GREEN, 2 * 1, (COORD){23, 1}, &written);
    FillConsoleOutputAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_GREEN | FOREGROUND_GREEN, 2 * 1, (COORD){23, 2}, &written);

    FillConsoleOutputAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_GREEN | FOREGROUND_GREEN, 2 * 1, (COORD){95, 1}, &written);
    FillConsoleOutputAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_GREEN | FOREGROUND_GREEN, 2 * 1, (COORD){95, 2}, &written);

    FillConsoleOutputAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_GREEN | FOREGROUND_GREEN, 2 * 1, (COORD){118, 1}, &written);
    FillConsoleOutputAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_GREEN | FOREGROUND_GREEN, 2 * 1, (COORD){118, 2}, &written);

    // Bandiera italiana sinistra header
    FillConsoleOutputAttribute(hConsole, BACKGROUND_GREEN, 3 * 1, (COORD){8, 1}, &written);
    FillConsoleOutputAttribute(hConsole, BACKGROUND_GREEN, 3 * 1, (COORD){8, 2}, &written);

    FillConsoleOutputAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE, 3 * 1, (COORD){11, 1}, &written);
    FillConsoleOutputAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE, 3 * 1, (COORD){11, 2}, &written);

    FillConsoleOutputAttribute(hConsole, BACKGROUND_RED, 3 * 1, (COORD){14, 1}, &written);
    FillConsoleOutputAttribute(hConsole, BACKGROUND_RED, 3 * 1, (COORD){14, 2}, &written);

    // Bandiera italiana destra header
    FillConsoleOutputAttribute(hConsole, BACKGROUND_GREEN, 3 * 1, (COORD){103, 1}, &written);
    FillConsoleOutputAttribute(hConsole, BACKGROUND_GREEN, 3 * 1, (COORD){103, 2}, &written);

    FillConsoleOutputAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE, 3 * 1, (COORD){106, 1}, &written);
    FillConsoleOutputAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE, 3 * 1, (COORD){106, 2}, &written);

    FillConsoleOutputAttribute(hConsole, BACKGROUND_RED, 3 * 1, (COORD){109, 1}, &written);
    FillConsoleOutputAttribute(hConsole, BACKGROUND_RED, 3 * 1, (COORD){109, 2}, &written);

    // Bordo titolo tabella (sfondo: giallo chiaro, testo: nero)
    FillConsoleOutputAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN, 43 * 1, (COORD){11, 6}, &written);
    FillConsoleOutputAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN, 43 * 1, (COORD){66, 6}, &written);

    FillConsoleOutputAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN, 43 * 1, (COORD){11, 7}, &written);
    FillConsoleOutputAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN, 43 * 1, (COORD){66, 7}, &written);

    //---------------------------------------------------------------------------------------------------

    printf("\n\n");

    int nimmobili = 0;                                                        //numero immobili chiesti in input dall'utente
    int i = 0;
    int controllo = 0;                                                        //serve nella verifica della propriet� principale o meno
    int iprincipale = -1;                                                     //posizione dell'abitazione principale nell'array di immobili
    int sceltaprincipale = 0;                                                 //scelta tra fabbricato, area o terreno
    float renditacatastale = 0;
    int inagibilescelta = 0;                                                  //il fabbricato � agibile o inabitabile?
    int sceltacomodato = 0;                                                   //concesso in comodato?
    int condizione1 = 0;                                                      //condizione 1 e 2 (la terza gi� esclusa)
    int condizione2 = 0;
    int icomodato = 0;                                                        //controllo
    int sceltacanone = 0;                                                     //scelta agevolazione
    int err = 0;                                                              //eventuale errore
    int contp = 0;                                                            //conteggio pertinenze
    int pertmax = 0;                                                          //pertinenza con renditacatastale pi� alta
    int ipert = 0;                                                            //indice che segna la pertinenza max
    float aliquota = 0;
    int cata = 0;                                                             //cont cat catastale A -10
    int catc = 0;                                                             //cont cat catastale c2 c6 e c7
	int mesi[12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};		  //array con i giorni dei mesi
	int giornitot = 365;		                                              //numero tot di giorni
	int meseinput = 0;		                                                  //mese inserito in input di acquisto;
	int giornoinput = 0;	                                                  //giorno inserito in input sommato ai mesi d'acquisto trasformati in giorni;
	int giorniposs = 0;	                                                      //giorni di possesso (da convertire in mesi)		                                                  //mesi di possesso (FORMULA)
	int j = 0;		                                                          //indice 2
    int detrazione = 0;                                                       //eventuale detrazione in certi casi di 200 euro
    float tot = 0;                                                            //costo totale (somma degli imu dei vari immobili
    float imu_supp[nimmobili];

    printf(" Inserisci il numero di immobili posseduti:\n");
    do{
        printf(">> ");
        scanf("%d", &nimmobili);
        if(nimmobili <= 0)
        {
            printf(" Non si puo' inserire un valore inferiore a 1, inserisci nuovamente il numero degli immobili posseduti:\n");
        }

    }while(nimmobili < 1);

    int array[nimmobili];                                                    //array che continene gli immobili
    float baseimponibile[nimmobili];                                         //calcolo base imponibile per singolo immobile
    int comune[nimmobili];                                                   //comune in cui si trova l'immobile
    float percposs[nimmobili];
    float imu[nimmobili];
    int mesiposs[nimmobili];
	int areafabb[nimmobili];												//sentinella per le aliquote delle aree fabbricabili
	int terreno[nimmobili];
	
	for(i = 0; i < nimmobili; i++)        //inizializzazione di tutti gli array a 0
    {
		array[i] = 0;
		baseimponibile[i] = 0;
		comune[i] = 0;
		percposs[i] = 0;
		imu[i] = 0;
		terreno[i]=0;
		areafabb[i] = 0;
	}

    for(i = 0; i < nimmobili; i++)			//for principale
    {
        printf("\n");
        printf("        --------------------------------     Calcolo IMU immobile numero %d     --------------------------------", (i + 1));
        do{
            printf("\n\n");
            printf(" Definire la tipologia dell'immobile:\n");    //scelta
            printf(" 0 = Fabbricato     1 = Area fabbricabile     2 = Terreno\n");
            printf(">> ");
            scanf("%d", &sceltaprincipale);
        }while((sceltaprincipale < 0) || (sceltaprincipale > 2));

        do{
            printf("\n");
            printf(" L'immobile in quale comune si trova?\n");
            printf(" 0 = Legnago (E512)     1 = Cerea (C498)     2 = Andrano (A281)     3 = Lecce (E506)     4 = Isola della Scala (E349)\n");
            printf(">> ");
            scanf("%d", &comune[i]);
        }while((comune[i] < 0) || (comune[i] > 4));

        if(sceltaprincipale == 0)
        {
            if(controllo == 0)
            {
                do{
                    printf("\n");
                    printf(" L'abitazione e' la principale?\n");             //abitazione principale?
                    printf(" 0 = NO     1 = SI\n");
                    printf(">> ");
                    scanf("%d", &controllo);
                }while((controllo < 0) || (controllo > 1));

                if(controllo == 1)
                {
                    iprincipale = i;
                }
            }

            do{
                printf("\n Inserisci il numero della categoria catastale dell'immobile:\n");
                printf(">> ");
                scanf("%d", &array[i]);
            }while((array[i] < 1) || (array[i] > 17));

            if((iprincipale == i) && ((array[i] != 1) && (array[i] !=7 ) && (array[i] != 8)))                 //se la propriet� � principale e non � una di quelle
            {
                baseimponibile[i] = 0;
            }
            else if((iprincipale != i) || ((iprincipale == i) && ((array[i] == 1) || (array[i] == 7) || (array[i] == 8))))
            {

                //percentuale di possesso
                do{
                    printf("\n Inserisci la percentuale di possesso:\n");
                    printf(">> ");
                    scanf("%f", &percposs[i]);
                }while((percposs[i] < 1) || (percposs[i] > 100));

                renditacatastale = 0;

                do{
                    printf("\n Inserisci la rendita catastale dell'immobile:\n");        //chiediamo la rendita catastale
                    printf(">> ");
                    scanf("%f", &renditacatastale);
                }while(renditacatastale < 1);

                renditacatastale = ((renditacatastale / 100) * 5) + renditacatastale;          //rendita catastale rivalutata
                baseimponibile[i] = fbi(array[i], renditacatastale);         //funzione base imponibile

                //agevolazioni base imponibile
                if(iprincipale != i)
                {
                    do{
                        printf("\n Il fabbricato e' inagibile o inabitabile?\n");             //abitazione principale?
                        printf(" 0 = NO     1 = SI\n");
                        printf(">> ");
                        scanf("%d", &inagibilescelta);
                    }while((inagibilescelta < 0) || (inagibilescelta > 1));
                }

                if(inagibilescelta == 1)
                {
                    baseimponibile[i] = baseimponibile[i] / 2;     //diminuzione 50%
                }
                else if(inagibilescelta == 0)
                {
                    if((iprincipale != i) && (array[i] != 1) && (array[i] != 7) && (array[i] != 8))                  //comodato tranne a/1 a/8 e a/9
                    {
                        do{
                            printf("\n Il fabbricato e' concesso in comodato?\n");        //comodato
                            printf(" 0 = NO     1 = SI\n");
                            printf(">> ");
                            scanf("%d", &sceltacomodato);
                        }while((sceltacomodato < 0) || (sceltacomodato > 1));

                        if(sceltacomodato == 1)
                        {
                            err = 1;              //eventuale errore
                            do{
                                printf("\n Il contratto di comodato e' registrato?\n");       //comodato
                                printf(" 0 = NO     1 = SI\n");
                                printf(">> ");
                                scanf("%d", &condizione1);
                            }while((condizione1 < 0) || (condizione1 > 1));

                            if(condizione1 == 1)
                            {
                                do{
                                    printf("\n Il comodante risiede nello stesso comune dell'immobile?\n");      //comodato
                                    printf(" 0 = NO     1 = SI\n");
                                    printf(">> ");
                                    scanf("%d", &condizione2);
                                }while((condizione2 < 0) || (condizione2 > 1));

                                if(condizione2 == 1)
                                {
                                    baseimponibile[i] = baseimponibile[i]/2;        //-50%
                                    icomodato = i;                                  //futuro controllo se il comodante risiede nel comune del comodato
                                }
                                else
                                {

                                }
                            }
                            else
                            {

                            }
                        }
                        else if(sceltacomodato == 0)
                        {
                            if(iprincipale != i)
                            {
                                do{
                                    printf("\n E' un'abitazione locata a canone concordato?\n");      //comodato
                                    printf(" 0 = NO     1 = SI\n");
                                    printf(">> ");
                                    scanf("%d", &sceltacanone);
                                }while((sceltacanone < 0) || (sceltacanone > 1));

                                if(sceltacanone == 1)
                                {
                                    baseimponibile[i] = baseimponibile[i] - ((baseimponibile[i] * 75) / 100);      //riduco del 75%
                                }
                                else
                                {

                                }
                            }
                            else
                            {

                            }
                        }
                    }
                }
			}
		}
		else if(sceltaprincipale == 1)
       	 {
       	 		 do{
                    printf("\n Inserisci la percentuale di possesso:\n");
                    printf(">> ");
                    scanf("%f", &percposs[i]);
                }while((percposs[i] < 1) || (percposs[i] > 100));

                 do{
                    printf("\n Inserisci il valore venale dell'area fabbricabile:\n");        //chiediamo il valore venale
                    printf(">> ");
                    scanf("%f", &renditacatastale);
                }while(renditacatastale < 1);

                baseimponibile[i]=renditacatastale;		//la base imponibile � costituita dal valore venale
				areafabb[i]=1;
         }
        	else
        	{
				 do{
                    printf("\n Inserisci la percentuale di possesso:\n");
                    printf(">> ");
                    scanf("%f", &percposs[i]);
                }while((percposs[i] < 1) || (percposs[i] > 100));

                 do{
                    printf("\n Inserisci il reddito dominicale del terreno:\n");        //chiediamo il valore venale
                    printf(">> ");
                    scanf("%f", &renditacatastale);
                }while(renditacatastale < 1);

                renditacatastale= ((renditacatastale / 100) * 25) + renditacatastale; 		//la base imponibile � costituita dal valore venale
				baseimponibile[i]=renditacatastale*135;
				terreno[i]=1;
      		}
                //data di acquisto
                meseinput = 0;

                do{
                    printf("\n Inserisci il mese di acquisto:\n");
                    printf(">> ");
                    scanf("%d", &meseinput);
                }while((meseinput < 1) || (meseinput > 12));

                mesiposs[i] = 0;
                giornoinput = 0;

                do{
                    printf("\n Inserisci il giorno di acquisto:\n");
                    printf(">> ");
                    scanf("%d", &giornoinput);
                }while((giornoinput < 1) || (giornoinput > 30));

                if((giornoinput <= 15) && ((meseinput != 2) && (meseinput != 1)))                   //se non � febbraio
                {
                    mesiposs[i] = 1;
                }
                else if((giornoinput <= 14) && (meseinput == 2))                                     //se � febbraio
                {
                    mesiposs[i] = 1;
                }

                for(j = 1; j < meseinput; j++)            //trasformiamo i mesi in giorni e sommo
                {
                    giornoinput += mesi[j];		          //mesi[i] (� il numero di giorni dei mesi prima di quello di acquisto) con i giorni in input
                }

                giorniposs = 0;
                giorniposs = giornitot - giornoinput;
                mesiposs[i] += giorniposs / 30;

                //conteggi necessari per le condizioni delle aliquote ed esonero imu
                if((array[i] == 12) || (array[i] == 16) || array[i] == 17)                      //conteggio pertinenze e pertinenza max
                {
                    contp++;
                    if(renditacatastale >= pertmax)
                    {
                        pertmax = renditacatastale;
                        ipert = i;
                    }
                }

        }


    int princ = 0;

    if(contp > 1)
    {
        baseimponibile[ipert] = 0;        //alla pertinenza con rendita catastale maggiore esoneriamo l'imu
    }

    printf("\n        ------------------------------------------     Risultati     -------------------------------------------\n\n");

    //si � costretti ad usare un'altro for per il calcolo dell'imu in quanto certi valori come l'if precedente possiamo constatarli solo alla fine dell'inserimento di tutti gli immobili
    for(i = 0; i < nimmobili; i++)
    {
        if(((array[i] > 0) && (array[i] < 9)) || (array[i] == 10))
        {
            cata++;
        }
        else if((array[i] == 12) || (array[i] == 16) || (array[i] == 17))
        {
            catc++;
        }

        princ = 0;                  //alle funzioni per le aliquote passiamo anche il riferimento della casa principale
        if(iprincipale == i)
        {
            princ = 1;
        }

        detrazione = 0;     //eventuale detrazione in certi casi di 200 euro

        if(comune[i] == 0)
        {
            aliquota = alilegnago(array[i], princ, cata, catc,&detrazione);
            if(areafabb[i] == 1){
            	aliquota = 9.10;
			}
			else if(terreno[i]==1){
				aliquota=10.60;
			}
        }
        else if(comune[i] == 1)
        {
            aliquota = alicerea(array[i], princ, cata, catc,&detrazione);
            if(areafabb[i] == 1){
            	aliquota = 10.40;
			}
				else if(terreno[i]==1){
				aliquota=10.40;
			}
			
        }
        else if(comune[i] == 2)
        {
            aliquota = aliandrano(array[i], princ, cata, catc, &detrazione);
            if(areafabb[i] == 1){
            	aliquota = 7.60;
			}
				else if(terreno[i]==1){
				aliquota=10.60;
			}
        }
        else if(comune[i] == 3)
        {
            aliquota = alilecce(array[i], princ, cata, catc,&detrazione);
            if(areafabb[i] == 1){
            	aliquota = 10.60;
			}
				else if(terreno[i]==1){
				aliquota=10.60;
			}
        }
        else
        {
            aliquota = alisola(array[i], princ, cata, catc, &detrazione);
            if(areafabb[i] == 1){
            	aliquota = 10.60;
			}
				else if(terreno[i]==1){
				aliquota=9;
			}
        }

        imu[i] = ((baseimponibile[i]) * ((float)mesiposs[i] / 12) * (percposs[i] / 100) * (aliquota / 1000)) - detrazione;

        if(imu[i] < 0)
        {
            imu[i] = 0;
        }
    }

  //  quick_sort(imu, 0, nimmobili - 1);              // chiama funzione di ordinamento quick sort

    for(i = 0; i < nimmobili; i++)
    {
        printf(" ______________________________________________________________________________________________________________________\n");
        printf(" |  Immobile numero %d:    \n", (i + 1));
        printf(" |---------------------------------------------------------------------------------------------------------------------\n");

        if(imu[i] != 0)
        {
            printf(" |\t\t   Il dovuto IMU dell'immobile e' %.2f euro\n", imu[i]);
            printf(" |_____________________________________________________________________________________________________________________\n\n");
        }
        else
        {
            printf(" |\t\t   Il dovuto IMU dell'immobile e' nullo\n");
            printf(" |_____________________________________________________________________________________________________________________\n\n");

        }
        tot = tot + imu[i];
    }

    if(nimmobili != 1)
    {
        printf("\n");
        printf(" Il dovuto IMU totale di tutti gli immobili e' %.2f", tot);
    }

	if((contp > 0) && (iprincipale == -1))
    {
		printf("\n Errore: Non si possono avere pertinenze senza l'abitazione principale\n");
	}

    if(err == 1)
	{
        if(comune[icomodato] != comune[iprincipale])
        {
            printf("\n Errore: La riduzione del 50 percento della base imponibile concessa in comodato non e' stata effettuta perche' non e' stata rispettata la condizione secondo la cui il comodante doveva risiedere nello stesso comune del comodato\n\n\n\n");
        }
    }

    printf("\n\n");

    return 0;
}
