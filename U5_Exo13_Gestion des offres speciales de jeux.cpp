/*
	 Programmer: Fabrice Kouonang
	 Date:      07/10/2024
	 But:       Le programme gère des offres spéciales d’un magasin de jeux(Xbox et Ps)
				vidéo pour un magisin

*/

#include <iostream>
#include<iomanip>
#include<string>

//Liste des constantes du programme
const unsigned short QUANTITE_MIN_XBOX = 3;
const unsigned short QUANTITE_MIN_PS   = 3;
const double   PRIX_UNIT_XBOX_QTE_INF  = 59.99; //PU de xbox si qte <= a la limite de 3=qute minimale
const double   PRIX_UNIT_XBOX_QTE_SUP  = 39.99; //PU de xbox si qte superieure a la limite de 3=qute minimale
const double   PRIX_UNIT_PS            = 57.99;
const double   POURCENTAGE_REMISE_PS   = (double)15/100;

using namespace std;

int main(void)
{
	//Liste des inputs du programmes
	char     typeJeux             = ' ';
	unsigned short qteXbox        = 0;
	unsigned short qtePs          = 0;

	//Liste des variables intermedieres
	unsigned short qteXboxMin     = 0;
	unsigned short qteXboxSurplus = 0;

	//Liste des output
	double   rabaisPs             = 0.0;
	double   montantPs            = 0.0;
	double   montantXbox          = 0.0;

	cout << "\t\t Bienvenu dans votre plateforme"
		<< endl
		<< "\t\t qui vous permet d'evaluer vos offres speciales"
		<<endl
		<<"\t\t de jeux de XBOX ET PS en magasin"
		<<endl<<endl
		<<"Pour commencer, merci de preciser le type de jeux vendu, choisir soit X=Xbox ou P=Playtstation: "
		<< fixed << setprecision(2);
	   
	//Recuperation des data
	cin >> typeJeux;
	typeJeux = toupper(typeJeux);
	if (typeJeux != 'X')
		if (typeJeux != 'P')
		{
			cout << typeJeux<<" Votre saisie est incorrecte, merci de choisir X =Xbox ou P=Playstation"
				 <<endl<<endl;
			return 0;
		}
	

	//Traitements et affichage

	if (typeJeux == 'X')
	{
		cout << "Donnez la quantite de jeux Xbox vendue: ";
		cin >> qteXbox;
		qteXboxMin = qteXbox;
		if (qteXbox > QUANTITE_MIN_XBOX)
		{
			qteXboxMin = QUANTITE_MIN_XBOX;
			qteXboxSurplus = qteXbox - qteXboxMin;
		}
		montantXbox = qteXboxMin * PRIX_UNIT_XBOX_QTE_INF + qteXboxSurplus * PRIX_UNIT_XBOX_QTE_SUP;
		cout << endl<<endl
			 <<" Pour "<<qteXbox<< " jeux Xbox vous devez payer: "
			 <<montantXbox<<" $ merci!!!";
	}
	
	else
	{
		cout << "Donnez la quantite de jeux Ps vendue: ";
		cin >> qtePs;
		montantPs = qtePs * PRIX_UNIT_PS;
		if (qtePs > QUANTITE_MIN_PS)
			rabaisPs = montantPs * POURCENTAGE_REMISE_PS;
		
		cout << endl << endl
			<< " Pour " << qtePs << " jeux PlayStation votre montant total a payer: "
			<< montantPs << " $ ";
		if (rabaisPs != 0)
		{
			cout << " avec un rabais de : " << rabaisPs << " $ "
				<< "montant net a payer: "
				<<montantPs-rabaisPs<< " $ merci!!!";
		}
		
	}

	cout << endl
		<< endl;

	system("pause");
	return 0;
}
