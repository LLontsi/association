#ifndef MEMBER_H
#define MEMBER_H

#include <string>

struct Member {
    int ID;
    std::string nom;
    std::string prenom;
    int age;
    std::string adresse;
    float cotisations[5];
};

void saisir(Member &m);
void ajouter(Member membres[], int &nombreMembres);
void modifier(Member membres[], int nombreMembres);
void supprimer(Member membres[], int &nombreMembres, int ID);
void afficherListeEtCotisations(Member membres[], int nombreMembres);
void solvable(Member membres[], int nombreMembres);
void insolvable(Member membres[], int nombreMembres);
float pourcentageMembresNonCotisants(Member membres[], int nombreMembres);
void supprimerNonCotisants(Member membres[], int &nombreMembres);
void recherche(Member membres[], int nombreMembres, int ID);

#endif
