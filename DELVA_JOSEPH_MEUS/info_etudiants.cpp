#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include "fonctions.h"

using namespace std;

void saisir_info()
{
    int i, cont;
    string code, nom, prenom, adresse;
    string const nom_fichier("./info_etudiants.txt");
    ofstream mon_flux(nom_fichier.c_str(), ios::app);

    if(mon_flux)
    {
        cout<<"Ce programme permet de rassembler des informations concernant des ";
        cout<<"etudiants.\nCes dernieres sont leurs codes d'acces qui";
        cout<<", leurs noms, leurs prenoms et leurs adresses."<<endl;

        i = 1;
        while (true)
        {
            cout<<"Veuillez saisir les informations pour l'etudiant de position"<<i<<"\n";
            cout<<"Entrer son code d'acces : ";
            cin>>code;
            cout<<"Entrer son nom : ";
            cin>>nom;
            cout<<"Entrer son prenom : ";
            cin>>prenom;
            cout<<"Entrer son adresse : ";
            cin>>adresse;
            i++;
            mon_flux << code <<" " << nom << " " << prenom << " " << adresse <<endl;
            cout<<"\n\n\nVoulez-vous entrer des informations pour un autre etudiant?\n";
            cout<<"\nEntrer 1 si la reponse est positive, 0 sinon."<<endl;
            saisie_entier(cont);
            while (cont != 1 && cont != 0)
            {
                cout<<"\nEntrer 1 si la reponse est positive, 0 sinon."<<endl;
                saisie_entier(cont);
            }

            if(cont == 0)
                break;
        }   
    }
    else
    {
        cout<<"Erreur survenue lors de l'ouverture du fichier"<<endl;
    }
}

void affichage_info()
{
    int i(1);
    string ligne;
    ifstream mon_flux("./info_etudiants.txt");

    if(mon_flux)
    {
        cout<<"Les informations sont les suivantes"<<endl;
        cout<<"No Code Nom Prenom Adresse"<<endl;
        while (getline(mon_flux, ligne))
        {
            cout<<i<<" - " <<ligne<<endl;
            i++;
        }
    }
    else
    {
        cout<<"Erreur lors de l'ouverture du fichier en lecture"<<endl;
    }
}

void classement_etudiant()
{
    int j(0), index;
    string ligne, mot;
    vector<string> tab_code, tab_nom, tab_ord, tab_prenom, tab_adresse;
    ifstream mon_flux("./info_etudiants.txt");

    if(mon_flux)
    {
        while (mon_flux >> mot)
        {
            if(j %4 ==0)
                tab_code.push_back(mot);
            else if(j%4==1)
                tab_nom.push_back(mot);
            else if(j%4==2)
                tab_prenom.push_back(mot);
            else
                tab_adresse.push_back(mot);
            j++;
        }
    }
    else
    {
        cout<<"Erreur lors de l'ouverture du fichier."<<endl;
    }
    tab_ord = ordre_alphabetique(tab_nom);
    cout<<"Les informations sont les suivantes"<<endl;
    cout<<"No Code Nom Prenom Adresse"<<endl;
    for (int i = 0; i < tab_ord.size(); i++)
    {
        index = index_of(tab_nom,tab_ord[i]);
        cout<<i+1<<"- "<<tab_code[index]<<" "<<tab_nom[index]
        <<" "<<tab_prenom[index]<<" "<<tab_adresse[index]<<endl;

        tab_adresse.erase(tab_adresse.begin() + index);
        tab_nom.erase(tab_nom.begin() + index);
        tab_prenom.erase(tab_prenom.begin() + index);
        tab_code.erase(tab_code.begin() + index);
    }    
}