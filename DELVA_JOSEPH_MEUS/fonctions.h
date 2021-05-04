#include<string>
#include<vector>

//Fonctions generales, s'appliquant a tous les fichiers
//Elles sont definies dans le fichier "format_fonctions.cpp"
void menu();
std::string format_number(std::string number);
std::string format_hexa_number(std::string number);
void vider_buffer();
bool saisie_hexa(std::string& number);
bool saisie_entier(int& nombre);
bool saisie_binaire(std::string& number);
bool saisie_reel(float& nombre);
int index_of(const std::vector<std::string>& tableau, std::string nom);
std::string to_upper(std::string mot);
std::vector<std::string> ordre_alphabetique(std::vector<std::string> tableau);

/*Fonctions ayant rapport a la premiere partie*/
//Elles sont definies dans le fichier "co_de_trans_codage.cpp"
//Fonctions correspondant aux conversions des nombres decimaux
std::string decimal_to_binary(int number);
std::string decimal_to_octal(int number);
std::string decimal_to_hexa(int number);

//Fonctions correspondant aux conversions des nombres binaires
int binary_to_decimal(std::string number);
std::string binary_to_octal(std::string number);
std::string binary_to_hexa(std::string number);

//Fonctions correspondant aux conversions des nombres hexadecimaux
std::string hexa_to_octal(std::string number);
std::string hexa_to_binary(std::string number);
int hexa_to_decimal(std::string number);

/*Fonctions concernant la deuxieme partie*/
//Elles sont definies dans le fichier "fonctions_maths.cpp"
void carre_magique();
void carre_doublement_pair(int n);
void remplisage_tableau(int* p,int* tab,int l,int c);
void ajout_valeur(int& val1,int& val2,int& val3,int& val4,int i,int j,int k,int L,int x,int n);
void carre_simplement_pair(int *p, int n);
void multiplication_matrices();
void systeme_equation();
void det_et_transposee();
double determinant(int n, double mat[10][10]);

/*Fonctions concernant la troisieme partie*/
//Elles sont definies dans le fichier "info_etudiants.cpp"
void saisir_info();
void affichage_info();
void classement_etudiant();

/*Fonction concernant la realisation personnelle*/
//Cette fonction permet de jouer le jeu "pendu" dans la console
// Elle est definie dans le fichier "pendu.cpp"
void jouer();