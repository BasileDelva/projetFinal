#include<iostream>
#include<vector>
#include<cmath>
#include "fonctions.h"
using namespace std;

void carre_magique()
{
    int n;
    cout<<"Entrer l'ordre du carre, entrez un nombre pair"<<endl;
    saisie_entier(n);
    while (n%2 != 0)
    {
        cout<<"Veuillez saisir un nombre pair SVP."<<endl;
        saisie_entier(n);
    }
    //Si le carre est doublement pair
    if(n%4==0)
        carre_doublement_pair(n);
    //Si le carre est simplement pair
    else
    {
        int t[n*n];
        carre_simplement_pair(t,n);
    }
}

void carre_doublement_pair(int n)
{
    int arr[n][n], i, j;
    // Remplissage de la matrice
    // en commencant par 1
    for ( i = 0; i < n; i++)
        for ( j = 0; j < n; j++)
            arr[i][j] = (n*i) + j + 1;
    
    // On change les valeurs des elements du tableau
    // Dans des positions fixes
    // (n*n+1)-arr[i][j]
    // Le carre a gauche et en haut
    // (ordre (n/4)*(n/4))
    for ( i = 0; i < n/4; i++)
        for ( j = 0; j < n/4; j++)
            arr[i][j] = (n*n + 1) - arr[i][j];
    
    // Le carre en haut et a droite
    // (ordre (n/4)*(n/4))
    for ( i = 0; i < n/4; i++)
        for ( j = 3 * (n/4); j < n; j++)
            arr[i][j] = (n*n + 1) - arr[i][j];
    
    // Le carre en bas a gauche
    // (ordre (n/4)*(n/4))
    for ( i = 3 * n/4; i < n; i++)
        for ( j = 0; j < n/4; j++)
            arr[i][j] = (n*n+1) - arr[i][j];
    
    // Carre en bas a droite
    // (ordre (n/4)*(n/4))
    for ( i = 3 * n/4; i < n; i++)
        for ( j = 3 * n/4; j < n; j++)
            arr[i][j] = (n*n + 1) - arr[i][j];
    
    // Centre de la matrice, ordre (n/2) * (n/2)
    for ( i = n/4; i < 3 * n/4; i++)
        for ( j = n/4; j < 3 * n/4; j++)
            arr[i][j] = (n*n + 1) - arr[i][j];

    // Affichage de la matrice
    for (i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
            cout <<"|"<<arr[i][j] << "|";
        cout << "\n";
    }
}
void remplisage_tableau(int* p,int* tab,int l,int c)
{
    int k=0;
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<c;j++)
        {
            p[k]=tab[k];
            k++;
        }
    }
    k=0;
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<tab[k]<<"|";
            k++;
        }
        cout<<endl;
    }
}

void ajout_valeur(int& val1,int& val2,int& val3,int& val4,int i,int j,int k,int L,int x,int n)
{
    if( (i==(L*2)-2 && j==n/2) || (i==(L*2)&& j!=n/2) )//cas de U
    {
        val1=k+3;
        val2=k+2;
        val3=k+1;
        val4=k;
    }
    else if(x-1!=0 && i>=(L*2)+2)//cas de X
    {
        val1=k+3;
        val2=k+1;
        val3=k+2;
        val4=k;
    }
    else//cas de L
    {
        val1=k;
        val2=k+2;
        val3=k+1;
        val4=k+3;
    }
}

void carre_simplement_pair(int *p, int n)
{
    int tab[n][n],i,j,k;
    int x=((n/2)-1)/2, L=x+1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            tab[i][j]=0;
        }
    }
    i=0;
    j=n/2;
    ajout_valeur(tab[i][j],tab[i+1][j],tab[i+1][j-1],tab[i][j-1],i,j,1,L,x,n);
    for(k=5;k<=n*n;k+=4)
    {
        i-=2;
        j+=2;
        if(i>=0 && j<n && tab[i][j]==0)//case ok
        {
             ajout_valeur(tab[i][j],tab[i+1][j],tab[i+1][j-1],tab[i][j-1],i,j,k,L,x,n);
        }
        else if(i>=0 && j<n && tab[i][j]!=0)//case occupe
        {
            i+=4;
            j-=2;
            ajout_valeur(tab[i][j],tab[i+1][j],tab[i+1][j-1],tab[i][j-1],i,j,k,L,x,n);
        }
        else if(i<0 && j<n)//debordement en haut
        {
            i=n-2;
            ajout_valeur(tab[i][j],tab[i+1][j],tab[i+1][j-1],tab[i][j-1],i,j,k,L,x,n);
        }
        else if(i>=0 && j>=n)//debordement a droite
        {
            j=1;
            ajout_valeur(tab[i][j],tab[i+1][j],tab[i+1][j-1],tab[i][j-1],i,j,k,L,x,n);
        }
        else
        {
            i+=4;
            j-=2;
            ajout_valeur(tab[i][j],tab[i+1][j],tab[i+1][j-1],tab[i][j-1],i,j,k,L,x,n);
        }
    }
    remplisage_tableau(p,(int*)tab,n,n);
}

void systeme_equation()
{
    float a, b, c, a_1, b_1, c_1, x, y;
    cout<<"Cette fonction permet de resoudre une equation de la forme :"<<endl;
    cout<<"{ax + by = c"<<endl<<"{a'x + b'y = c'"<<endl;
    cout<<"Vous allez saisir respectivement les valeurs de a, b, c, a', b' et c'.\n";
    cout<<"Entrer une valeur pour a"<<endl;
    saisie_reel(a);
    cout<<"Entrer une valeur pour b"<<endl;
    saisie_reel(b);
    cout<<"Entrer une valeur pour c"<<endl;
    saisie_reel(c);
    cout<<"Entrer une valeur pour a'"<<endl;
    saisie_reel(a_1);
    cout<<"Entrer une valeur pour b'"<<endl;
    saisie_reel(b_1);
    cout<<"Entrer une valeur pour c'"<<endl;
    saisie_reel(c_1);
    cout<<"Le systeme a resoudre est celui-ci"<<endl;
    cout<<"{"<<a<<"x + "<<b<<"y = "<<c<<"\n{"<<a_1<<"x + "<<b_1<<"y = "<<c_1<<endl;

    if (a*b_1 == b*a_1)
    {
        if (a/a_1 == c/c_1)
            cout<<"Il existe une infinite de solutions"<<endl;
        else
            cout<<"Pas de solution!"<<endl;
    }
    else
    {
        x = (c*b_1 - b*c_1) / (a*b_1 - b*a_1);
        y = (a*c_1 - c*a_1) / (a*b_1 - b*a_1);
        
        cout<<"La solution de l'equation est : {("<<x<<", "<<y<<")}"<<endl;
    } 
}

void multiplication_matrices()
{
    int i, j, l;
    float somme, n;
    cout<<"Ce programme permet de multiplier deux matrices."<<endl;
    cout<<"Suivez avec attention les regles qui regissent la multiplication de deux matrices.\n";
    cout<<"Soient A[i,j] et B[k,l] deux matrices (i et k designent respectivement ";
    cout<<"le nombre de lignes de chacune, et j et l le nombre deux colonnes.";
    cout<<"Pour que la multiplication soit effective, il faut que :"<<endl;
    cout<<"\t*i,j,k,l soient des entiers naturels\n\t*j soit egal a k."<<endl;
    cout<<"Vous aurez une matrice de la forme C[i,l]"<<endl;
    cout<<"Vous n'aurez donc qu'a fournir les valeurs pour i,j et l."<<endl;
    cout<<"\n\n\nVeuillez entrer le nombre de lignes pour la premiere matrice"<<endl;
    saisie_entier(i);
    cout<<"Entrez le nombre de colonne de la premiere qui sera utilise comme le nombre";
    cout<<" de ligne de la seconde matrice"<<endl;
    saisie_entier(j);
    cout<<"Saisissez le nombre de colonne de la seconde"<<endl;
    saisie_entier(l);
    float A[j][i], B[i][l], C[j][l];
    cout<<"Les matrices qui seront multiplies auront ces formes : "<<endl;
    cout<<"Matrice A : "<<endl;
    for (int a = 0; a < i; a++)
    {
        for ( int b = 0; b < j; b++)
        {
            cout<<"A"<<a+1<<b+1<<" ";
        }
        cout<<endl;
    }
    cout<<"Matrice B "<<endl;
    for (int a = 0; a < j; a++)
    {
        for ( int b = 0; b < l; b++)
        {
            cout<<"A"<<a+1<<b+1<<" ";
        }
        cout<<endl;
    }
    cout<<"Maintenant, vous allez remplir les matrices : "<<endl;
    cout<<"Remplissage de la premiere matrice"<<endl;
    for (int a = 0; a < i; a++)
    {
        for ( int b = 0; b < j; b++)
        {
            cout<<"Entrer la valeur de position A"<<a+1<<b+1<<" ";
            saisie_reel(n);
            A[b][a] = n;
        }
    }
    cout<<"Remplissage de la seconde matrice"<<endl;
    for (int a = 0; a < j; a++)
    {
        for ( int b = 0; b < l; b++)
        {
            cout<<"Entrer la valeur de position B"<<a+1<<b+1<<" ";
            saisie_reel(n);
            B[b][a] = n;
        }
    }

    cout<<"Le produit des matrices suivantes : "<<endl;
    for (int a = 0; a < i; a++)
    {
        for ( int b = 0; b < j; b++)
        {
            cout<<A[b][a]<<" ";
        }
        cout<<endl;
    }
    cout<<"Et : "<<endl;
    for (int a = 0; a < j; a++)
    {
        for ( int b = 0; b < l; b++)
        {
            cout<<B[b][a]<<" ";
        }
        cout<<endl;
    }

//Calcul de la multiplication des matrices
    for (int a = 0; a < l; a++)
    {
        for (int b = 0; b < l; b++)
        {
            C[a][b] = 0;
            for (int c = 0; c < l; c++)
                C[a][b] += A[a][c] * B[c][b]; 
        } 
    }
    cout<<"Le produit des matrices suivantes : "<<endl;
    for (int a = 0; a < i; a++)
    {
        for ( int b = 0; b < j; b++)
        {
            cout<<A[b][a]<<" ";
        }
        cout<<endl;
    }
    cout<<"Et : "<<endl;
    for (int a = 0; a < j; a++)
    {
        for ( int b = 0; b < l; b++)
        {
            cout<<B[b][a]<<" ";
        }
        cout<<endl;
    }
    cout<<"est"<<endl;

    for (int a = 0; a < i; a++)
    {
        for ( int b = 0; b < l; b++)
        {
            cout<<C[b][a]<<" ";
        }
        cout<<endl;
    }
}

void det_et_transposee()
{
    int n;
    float nombre;
    cout<<"Vous allez creer une matrice carre, nous determinerons sa transposee ";
    cout<<"et son determinant."<<endl;
    cout<<"Veuillez entrer l'ordre de la matrice"<<endl;
    saisie_entier(n);
    float A[n][n], B[n][n]; double mat[10][10];
    cout<<"La matrice aura la forme suivante"<<endl;
    for (int a = 0; a < n; a++)
    {
        for ( int b = 0; b < n; b++)
        {
            cout<<"A"<<a+1<<b+1<<" ";
        }
        cout<<endl;
    }
    cout<<"Remplissage de la matrice"<<endl;
    for (int a = 0; a < n; a++)
    {
        for ( int b = 0; b < n; b++)
        {
            cout<<"Entrer la valeur de position A"<<a+1<<b+1<<" ";
            saisie_reel(nombre);
            A[b][a] = nombre;
            mat[b][a] = nombre;
        }
    }
    for (int a = 0; a < n; a++)
    {
        for ( int b = 0; b < n; b++)
        {
            B[a][b] = A[b][a];
        }
        cout<<endl;
    }
    cout<<"La matrice originale est"<<endl;
    for (int a = 0; a < n; a++)
    {
        for ( int b = 0; b < n; b++)
        {
            cout<<A[b][a]<<" ";
        }
        cout<<endl;
    }
    cout<<"Sa transposee est"<<endl;
    for (int a = 0; a < n; a++)
    {
        for ( int b = 0; b < n; b++)
        {
            cout<<B[b][a]<<" ";
        }
        cout<<endl;
    }

    cout<<"\n\nSon determinant est : "<<determinant(n, mat)<<endl;
}
double determinant(int n, double mat[10][10])
{
    double sous_matrice[10][10];
    double d;
    if (n == 2)
        return ((mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
    else
    {
        for (int c = 0; c < n; c++)
        {
            int subi = 0; //submatrix's i value
            for (int i = 1; i < n; i++)
            {
                int subj = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j == c)
                        continue;
                    sous_matrice[subi][subj] = mat[i][j];
                    subj++;
                }
                subi++;
 
            }
            d = d + (pow(-1, c) * mat[0][c] * determinant(n - 1, sous_matrice));
        }
    }
    return d;
}