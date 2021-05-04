#include <iostream>
#include "fonctions.h"

using namespace std;

int main()
{
    int choix, choix2, choix3, nombre, resultat;
    string n, result;
    menu();
    cout<<"Veuillez effectuer votre choix ";
    saisie_entier(choix);
    while (choix < 1 || choix > 4)
    {
        cout<<"Veuillez choisir un nombre entre 1 et 4"<<endl;
        saisie_entier(choix);
    }
    switch (choix)
    {
    case 1:
        cout<<"\t1.......... Decimal"<<endl;
        cout<<"\t2.......... Binaire"<<endl;
        cout<<"\t3.......... Hexadecimal"<<endl;
        saisie_entier(choix2);
        while (choix2 < 1 || choix2 > 3)
        {
            cout<<"Veuillez choisir un nombre entre 1 et 3."<<endl;
            saisie_entier(choix);
        }
        switch (choix2)
        {
        case 1:
            cout<<"Veuillez entrer un nombre decimal ";
            saisie_entier(nombre);
            cout<<"Veuillez choisir le systeme dans lequel vous voulez le convertir\n";
            cout<<"\t\t1.......... En binaire"<<endl;
            cout<<"\t\t2.......... En octal"<<endl;
            cout<<"\t\t3.......... En Hexadecimal"<<endl;
            saisie_entier(choix3);
            while (choix3 < 1 || choix3 > 3)
            {
                cout<<"Veuillez choisir un nombre entre 1 et 3."<<endl;
                saisie_entier(choix);
            }
            switch (choix3)
            {
            case 1:
                result = decimal_to_binary(nombre);
                cout<<"L'equivalent binaire de "<<nombre<<" est "<<result<<endl;
                break;
            case 2:
                result = decimal_to_octal(nombre);
                cout<<"L'equivalent octal de "<<nombre<<" est "<<result<<endl;
                break;
            case 3:
                result = decimal_to_hexa(nombre);
                cout<<"L'equivalent hexadecimal de "<<nombre<<" est "<<result<<endl;
                break;
            }
            break;
        case 2:
            cout<<"Veuillez entrer un nombre binaire ";
            saisie_binaire(n);
            cout<<"Veuillez choisir le systeme dans lequel vous voulez le convertir\n";
            cout<<"\t\t1.......... En Decimal"<<endl;
            cout<<"\t\t2.......... En octal"<<endl;
            cout<<"\t\t3.......... En Hexadecimal"<<endl;
            saisie_entier(choix3);
            while (choix3 < 1 || choix3 > 3)
            {
                cout<<"Veuillez choisir un nombre entre 1 et 3."<<endl;
                saisie_entier(choix);
            }
            switch (choix3)
            {
            case 1:
                resultat = binary_to_decimal(n);
                cout<<"L'equivalent decimal de "<<n<<" est "<<resultat<<endl;
                break;
            case 2:
                result = binary_to_octal(n);
                cout<<"L'equivalent octal de "<<n<<" est "<<result<<endl;
                break;
            case 3:
                result = binary_to_hexa(n);
                cout<<"L'equivalent hexadecimal de "<<n<<" est "<<resultat<<endl;
                break;
            }
            break;
        case 3:
            cout<<"Veuillez entrer un nombre hexadecimal ";
            saisie_hexa(n);
            cout<<"Veuillez choisir le systeme dans lequel vous voulez le convertir\n";
            cout<<"\t\t1.......... En Octal"<<endl;
            cout<<"\t\t2.......... En Binaire"<<endl;
            cout<<"\t\t3.......... En Decimal"<<endl;
            saisie_entier(choix3);
            while (choix3 < 1 || choix3 > 3)
            {
                cout<<"Veuillez choisir un nombre entre 1 et 3."<<endl;
                saisie_entier(choix);
            }
            switch (choix3)
            {
            case 1:
                result = hexa_to_octal(n);
                cout<<"L'equivalent octal de "<<n<<" est "<<resultat<<endl;
                break;
            case 2:
                result = hexa_to_binary(n);
                cout<<"L'equivalent binaire de "<<n<<" est "<<resultat<<endl;
                break;
            case 3:
                result = hexa_to_decimal(n);
                cout<<"L'equivalent hexadecimal de "<<n<<" est "<<resultat<<endl;
                break;
            }
            break;
        }
        break;
    case 2:
        cout<<"\t1.......... Carre magique d'ordre pair"<<endl;
        cout<<"\t2.......... Multiplication de deux matrices"<<endl;
        cout<<"\t3.......... Resolution d'un systeme d'equations a deux inconnues"<<endl;
        cout<<"\t4.......... Determinant et transposee d'une matrice"<<endl;
        saisie_entier(choix2);
        while (choix2 < 1 || choix2 > 4)
        {
            cout<<"Veuillez choisir un nombre entre 1 et 4"<<endl;
            saisie_entier(choix);
        }
        switch (choix2)
        {
        case 1:
            carre_magique();
            break;
        case 2:
            multiplication_matrices();
            break;
        case 3:
            systeme_equation();
            break;
        case 4:
            det_et_transposee();
            break;
        }      
        break;
    case 3:
        cout<<"\t1.......... Saisir les informations suivantes sur un etudiant "
            <<"(Code, Nom, Prenom, Adresse) dans un fichier Notepad."<<endl;
        cout<<"\t2.......... Affichage des informations du fichier"<<endl;
        cout<<"\t3.......... Affichage des informations par ordre alphabetique"<<endl;
        saisie_entier(choix2);
        while (choix2 < 1 || choix2 > 3)
        {
            cout<<"Veuillez choisir un nombre entre 1 et 3."<<endl;
            saisie_entier(choix);
        }
        switch (choix2)
        {
        case 1:
            saisir_info();
            break;
        case 2:
            affichage_info();
            break;
        case 3:
            classement_etudiant();
            break;
        }
        break;
    case 4:
        jouer();
        break;
    }

    cout<<"\n\n\n\n\n\n";
    main();    
    return 0;
}