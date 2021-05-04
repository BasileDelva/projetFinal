#include<string>
#include<iostream>
#include<limits>
#include "fonctions.h"
#include<sstream>
#include<string.h>
using namespace std;


//Cette fonction permet de presenter le menu principal du programme
void menu()
{
    cout<<"1.......... Operation de Codage/Decodage/Transcodage"<<endl;
    cout<<"2.......... Operations mathematiques"<<endl;
    cout<<"3.......... Gestion d'informations sur etudiant"<<endl;
    cout<<"4.......... Realisation personnelle"<<endl;
}

//Cette fonction permet d'enlever les '0' inutiles qui peuvent se trouver dans un nombre
string format_number(string number)
{
    string result = "";
    int i (0);
    while (number[i] == '0' && i <= number.size())
        i++;
    if (i == number.size())
        result = '0';
    else
    {
        for ( i; i < number.size(); i++)
        {
            result += number[i];
        }    
    }
    return result;
}

//Cette fonction permet permet de changer les lettres minuscules en majuscules dans
//un nombre hexadecimal
string format_hexa_number(string number)
{
    string result = "";
    for (int i = 0; i < number.size(); i++)
    {
        if(number[i] == 'a')
            result += 'A';
        else if(number[i] == 'b')
            result += 'B';
        else if(number[i] == 'C')
            result += 'C';
        else if(number[i] == 'd')
            result += 'D';
        else if(number[i] == 'e')
            result += 'E';
        else if(number[i] == 'f')
            result += 'F';
        else
            result += number[i];
    }
    return result;
}

//Cette fonction permet de vider le buffer, utile aux saisies securisees
void vider_buffer()
{
    cin.clear();
    cin.seekg(0,ios::end);
    if(cin.fail())
      cin.clear();
    else
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

/*Les fonctions suivantes permettent de securiser la saisie de l'utilisateur.
Elles permettent respectivement que l'utilisateur saisisse correctement un nombre
hexadecimal, un nombre binaire et un nombre entier.
*/

//Cette fonction controle la saisie d'un nombre hexadecimal
bool saisie_hexa(string& number)
{
    while(true)
    {
        cout<<"Entrer un nombre hexadecimal SVP\n";
        cin>>number;
        if(cin.bad() || cin.eof())
        {
            cout<<"ERREUR critique survenue\n";
            if(cin.eof())
              break;
            vider_buffer();
            continue;
        }
        if(cin.fail() || number.find_first_not_of("0123456789abcdefABCDEF")!= string::npos)
        {
            cout<<"ERREUR! Un nombre hexadecimal svp.\n";
            vider_buffer();
            continue;
        }
        vider_buffer();
        return true;
    }
    return false;
}

//Cette fonction controle la saisie d'un nombre binaire
bool saisie_binaire(string& number)
{
    while(true)
    {
        cout<<"Entrer un nombre binaire SVP\n";
        cin>>number;
        if(cin.bad() || cin.eof())
        {
            cout<<"ERREUR critique survenue\n";
            if(cin.eof())
              break;
            vider_buffer();
            continue;
        }
        if(cin.fail() || number.find_first_not_of("01")!= string::npos)
        {
            cout<<"ERREUR! Un nombre binaire svp.\n";
            vider_buffer();
            continue;
        }
        vider_buffer();
        return true;
    }
    return false;
}

//Cette fonction controle la saisie d'un nombre entier
bool saisie_entier(int& nombre)
{
    string temp;
    while(true)
    {
        std::cin>>temp;
        if(std::cin.bad() || std::cin.eof())
        {
            std::cout<<"ERREUR critique survenue\n";
            if(std::cin.eof())
              break;
            vider_buffer();
            continue;
        }
        if(std::cin.fail() || temp.find_first_not_of("0123456789")!= string::npos)
        {
            std::cout<<"ERREUR!\n";
            vider_buffer();
            continue;
        }
        vider_buffer();
        istringstream st (temp);
        st >> nombre;
        if(st.fail() || !st.eof())
          std::cout<<"Mauvaise saisie\n";
        else
          return true;
    }
    return false;
}

//Cette fonction controle la saisie d'un nombre entier
bool saisie_reel(float& nombre)
{
    string temp;
    while(true)
    {
        std::cin>>temp;
        if(std::cin.bad() || std::cin.eof())
        {
            std::cout<<"ERREUR critique survenue\n";
            if(std::cin.eof())
              break;
            vider_buffer();
            continue;
        }
        if(std::cin.fail() || temp.find_first_not_of("-0123456789.")!= string::npos)
        {
            std::cout<<"ERREUR!\n";
            vider_buffer();
            continue;
        }
        vider_buffer();
        istringstream st (temp);
        st >> nombre;
        if(st.fail() || !st.eof())
          std::cout<<"Mauvaise saisie\n";
        else
          return true;
    }
    return false;
}

//Cette fonction permet de renvoyer la position d'un element dans un tableau
int index_of(const std::vector<string>& tableau, std::string nom)
{
    for (int i = 0; i < tableau.size(); i++)
    {
        if(tableau[i] == nom)
            return i;
    }
    return -1;
}

//Cette fonction permet de convertir un mot en majuscule
string to_upper(string mot)
{
    string result = "";
    for (int i = 0; i < mot.size(); i++)
    {
        if(mot[i] >= 97 && mot[i] <= 122)
            result += mot[i] - 32;
        else
            result += mot[i];
    }
    return result;
}

//Fonction qui permet de classer un tableau en ordre alphabetique
vector<string> ordre_alphabetique(std::vector<std::string> tableau)
{
    string temp;
    for (int i = 0; i < tableau.size() - 1; i++)
    {
        for (int j = 0; j < tableau.size() - 1; j++)
        {
            if(to_upper(tableau[j]).compare(to_upper(tableau[j+1])) > 0)
            {
                temp = tableau[j];
                tableau[j] = tableau[j+1];
                tableau[j+1] = temp;
            }
        }      
    }
    return tableau;   
}