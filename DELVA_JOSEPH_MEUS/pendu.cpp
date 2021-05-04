#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include "fonctions.h"

using namespace std;

string mot_aleatoire();
bool contient(string mot, char lettre);
void jouer()
{
    char lettre, nouvelle_partie;
    string mot_secret, devinette;
    int essai;
    bool echec, jouer;
    
    cout<<"\t\t\t\t- Bienvenue au jeu pendu -"<<endl;
    cout<<"\n\n\nSavez-vous deja comment joue-t-on a ce jeu?"<<endl;
    cout<<"Quelle que soit votre reponse, nous vous presentons la notre."<<endl;
    cout<<"\n\n\nDans ce jeu, vous allez deviner un mot cache lettre par lettre."<<endl;
    cout<<"\nD'abord on vous presente le mot cache ou les lettres sont remplaces par des \"*\"";
    cout<<", ensuite vous entrerez un caractere, puis nous verifierons si ce dernier se trouve";
    cout<<" reellement dans le mot."<<endl;
    cout<<"\n\nS'il y est, nous remplacerons toutes les occurences de ce caractere par ";
    cout<<"ce dernier, sinon les \"*\" restent a leurs places."<<endl;
    cout<<"\n\nVous aurez 10 essais au maximum.\n\n";
    cout<<"Pret a vous lancer????\n\n\n\nBON SUCCES!\n\n";

    //Lecture d'un caractere
    do
    {
        devinette = "";
        essai = 10;
        jouer = false;
        echec = true;
        mot_secret = mot_aleatoire();
        for (int i = 0; i < mot_secret.size(); i++)
        {
            devinette += "*";
        }
        cout<<"Le mot a deviner est donc : "<<devinette<<endl;
        cout<<"C'est parti!!! A vous de jouer.\n\n\n";
        while (essai > 0 && echec)
        {
            cout<<"Il ne vous reste que "<<essai<<" essais."<<endl;
            cout<<"Entrer un caractere ";
            cin>>lettre;
            lettre = toupper(lettre);
            vider_buffer();
            if (contient(mot_secret, lettre))
            {
                for (int i = 0; i < devinette.size(); i++)
                {
                    if (mot_secret[i] == lettre)
                        devinette[i] = lettre;
                }
                cout<<devinette<<" continuez."<<endl;
            }
            else
            {
                cout<<"Malheuresement, ce caractere n'est pas dans le mot secret."<<endl;
                cout<<"\t"<<devinette<<"\nReessayez!"<<endl;
            }
            if (mot_secret == devinette)
                echec = false;
            essai--;
        }
        if (!echec)
            cout<<"Felicitations! Vous avez pu deviner le mot secret!"<<endl;
        else
            cout<<"Le mot a deviner etait "<<mot_secret<<", a la prochaine."<<endl;
        cout<<"\n\nVoulez-vous jouer une nouvelle partie?"<<endl;
        cout<<"Appuyez sur 'O' pour Oui, ou sur 'N' sinon."<<endl;
        cin>>nouvelle_partie;
        vider_buffer();
        while (nouvelle_partie != 'n' && nouvelle_partie != 'N' && nouvelle_partie != 'o' && nouvelle_partie != 'O')
        {
            cout<<"Veuillez ppuyer sur 'O' pour Oui, ou sur 'N' sinon."<<endl;
            cin>>nouvelle_partie;
        }
        if(nouvelle_partie == 'o' || nouvelle_partie == 'O')
            jouer = true;
        vider_buffer();
    }while (jouer);      
}

string mot_aleatoire()
{
    srand(time(0));
    int index;
    vector<string>dico;
    string mot_secret;
    ifstream flux("./dico.txt");
    
    if (flux)
    {
        while (getline(flux, mot_secret))
        {
            dico.push_back(mot_secret);
        }  
    }
    else
    {
        cout<<"Erreur dans l'ouverture du fichier!"<<endl;
    }
    index = rand() % (dico.size());

    return dico[index];
}

bool contient(string mot, char lettre)
{
    for (int i = 0; i < mot.size(); i++)
    {
        if (mot[i] == lettre)
            return true;
    }
    return false;
}