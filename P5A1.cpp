/********************************************/
/* AUtor: Thomas Lödige                     */
/* Datum : 30.10.2016                       */
/* Projekt: P5A1                            */
/* Beschreibung: Rueckgabe von Geld in Euro */
/********************************************/

#define _CRT_SECURE_NO_WARNINGS	// Fehlermeiden von scanf

#include<stdio.h>	// Bibliotheken einbinden
#include<math.h>

#define anzahl_der_muenzen 4	// Größe für die Anzahl der Münzen

int main(void) {	// Hauptprogramm
	int werte_muenzen[anzahl_der_muenzen] = { 0 };		// Array

	int index = 0;			// Initialisierungen
	char beenden = 0;
	int betrag = 0, mom_wert = 0;
	float geld = 0.0;

	while (beenden != 'e') {		// Endlosschleife
		printf("Geben sie einen Betrag in EURO ein:\t");		// textausgabe
		scanf("%f", &geld);		// Texteingabe / Betrag in Cent weil wenn ich eine Komma Zahl * 100 rechne, nciht der genaue Wert bei
									// raus kommt. bsp.: 0.08 * 100 steht da  7.99998 und als Integer Wert wird der dann abgerundet also 7
		betrag = (int)(geld * 100);
		fflush(stdin);		// Tastaturpuffer
		if (betrag <= 4) {		// Eine Bedingung
			printf("Ungueltiger Wert\n");
		}
		// geld = betrag * 100.0;	// um die Komma Zahl weg zu kriegen
		if (betrag >= 5) {
			mom_wert = betrag / 200;		// Rechnung fuer die Anzahl von 2 Euro stuecken
			werte_muenzen[0] = mom_wert;	// Setzt den Wert von dem Wert momentan_wert zu der ersten Stelle des Arrays 
			betrag = betrag - mom_wert * 200;	// Rechnet den Restwert von betrag was noch uebrig bleibt

			mom_wert = betrag/ 50;		// Rechnug fuer die Anzahl von 50 Cent stuecken
			werte_muenzen[1] = mom_wert;
			betrag = betrag - mom_wert * 50;
	
			mom_wert = betrag / 5;		// Rechnung fuer die Anzahl von 5 Cent stuecken
			werte_muenzen[2] = mom_wert;
			betrag = betrag - mom_wert * 5;
			
			if (betrag == 1 || betrag == 3) {		// Damit kein Cent uebrig bleibt, hab cih die Bedingung erstellt
				if (werte_muenzen[0] > 0 && werte_muenzen[1] == 0 && werte_muenzen[2] == 0) {
					werte_muenzen[0]--;		// 2 euro stücke -1 damit er bei den anderen münzen mehr zur verfügung hat
					werte_muenzen[1] = 2 + 1;	// und einmal +5 cent bei dem hauptbetrag durchführen um betrag auf 0 zu kriegen
					werte_muenzen[2] = 8 + 1;
					betrag = betrag + 5;
				}
				else if (werte_muenzen[1] > 0 && werte_muenzen[2] == 0) {
					werte_muenzen[1]--;		// 50 cent stücke -1 damit er bei den anderen münzen mehr zur verfügung hat
					werte_muenzen[2] = 8 + 1;	// und einmal +5 cent bei dem hauptbetrag durchführen um betrag auf 0 zu kriegen
					betrag = betrag + 5;
				}
				else if (werte_muenzen[2] > 0) {
					werte_muenzen[2]--;		// Dekrementiert die dritte Stelle des Arrays (5 Cent stuecke)
					betrag = betrag + 5;
				}
			}
			
			mom_wert = betrag / 2;		// Rechnung fuer die Anzahl von 2 Cent stuecken
			werte_muenzen[3] = mom_wert;
			betrag = betrag - mom_wert * 2;

			printf("Sie erhalten %i stueck von 2.00 Euro muenzen\n", werte_muenzen[0]);		// Gibt alle Werte aus
			printf("Sie erhalten %i stueck von 0.50 Euro muenzen\n", werte_muenzen[1]);
			printf("Sie erhalten %i stueck von 0.05 Euro muenzen\n", werte_muenzen[2]);
			printf("Sie erhalten %i stueck von 0.02 Euro muenzen\n\n", werte_muenzen[3]);
			printf("Geben sie \"e\" ein, wenn sie das Programm beenden moechten:\t");
			scanf("%s", &beenden);		// Wegen der Endlosschleife um die Schleife zu verlassen
			fflush(stdin);
		}
	}
	return(1);	// Rueckgabewert
}	// Ende Fertig (>^.^)> schlafen