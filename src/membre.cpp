#include <iostream>
#include "member.h"

using namespace std;

void saisir(Member &m) {
    cout << "ID : ";
    cin >> m.ID;
    cout << "Nom : ";
    cin >> m.nom;
    cout << "Prénom : ";
    cin >> m.prenom;
    cout << "Âge : ";
    cin >> m.age;
    cout << "Adresse : ";
    cin >> m.adresse;
    cout << "Cotisations (5 valeurs) : ";
    for (int i = 0; i < 5; ++i) {
        cin >> m.cotisations[i];
    }
}

void ajouter(Member membres[], int &nombreMembres) {
    if (nombreMembres < 100) { // Limite arbitraire de 100 membres
        saisir(membres[nombreMembres]);
        nombreMembres++;
    } else {
        cout << "Impossible d'ajouter plus de membres, la limite est atteinte." << endl;
    }
}

void modifier(Member membres[], int nombreMembres) {
    int id;
    cout << "Entrez l'ID du membre à modifier : ";
    cin >> id;

    for (int i = 0; i < nombreMembres; ++i) {
        if (membres[i].ID == id) {
            cout << "Nouvelles informations pour le membre " << membres[i].ID << " :" << endl;
            saisir(membres[i]);
            cout << "Membre modifié avec succès." << endl;
            return;
        }
    }
    cout << "Membre non trouvé." << endl;
}

void supprimer(Member membres[], int &nombreMembres, int ID) {
    for (int i = 0; i < nombreMembres; ++i) {
        if (membres[i].ID == ID) {
            // Déplacer les éléments restants d'un cran vers la gauche
            for (int j = i; j < nombreMembres - 1; ++j) {
                membres[j] = membres[j + 1];
            }
            nombreMembres--;
            cout << "Membre supprimé avec succès." << endl;
            return;
        }
    }
    cout << "Membre non trouvé." << endl;
}

void afficherListeEtCotisations(Member membres[], int nombreMembres) {
    cout << "Liste des membres et montant total de leurs cotisations :" << endl;
    float totalCotisations = 0;
    for (int i = 0; i < nombreMembres; ++i) {
        cout << "Membre " << membres[i].nom << " " << membres[i].prenom << " - Cotisations : ";
        float totalMembre = 0;
        for (int j = 0; j < 5; ++j) {
            cout << membres[i].cotisations[j] << " ";
            totalMembre += membres[i].cotisations[j];
        }
        totalCotisations += totalMembre;
        cout << "- Total : " << totalMembre << endl;
    }
    cout << "Montant total des cotisations de tous les membres : " << totalCotisations << endl;
}

void solvable(Member membres[], int nombreMembres) {
    cout << "Membres solvables :" << endl;
    for (int i = 0; i < nombreMembres; ++i) {
        float totalMembre = 0;
        for (int j = 0; j < 5; ++j) {
            totalMembre += membres[i].cotisations[j];
        }
        cout << membres[i].nom << " " << membres[i].prenom << " - Total cotisations : " << totalMembre << endl;
    }
}

void insolvable(Member membres[], int nombreMembres) {
    cout << "Membres insolvable :" << endl;
    for (int i = 0; i < nombreMembres; ++i) {
        bool insolvable = true;
        for (int j = 0; j < 5; ++j) {
            if (membres[i].cotisations[j] > 0) {
                insolvable = false;
                break;
            }
        }
        if (insolvable) {
            cout << membres[i].nom << " " << membres[i].prenom << endl;
        }
    }
}

float pourcentageMembresNonCotisants(Member membres[], int nombreMembres) {
    int nonCotisants = 0;
    for (int i = 0; i < nombreMembres; ++i) {
        bool cotisationEffectuee = false;
        for (int j = 0; j < 5; ++j) {
            if (membres[i].cotisations[j] > 0) {
                cotisationEffectuee = true;
                break;
            }
        }
        if (!cotisationEffectuee) {
            nonCotisants++;
        }
    }
    return (static_cast<float>(nonCotisants) / nombreMembres) * 100.0;
}

void supprimerNonCotisants(Member membres[], int &nombreMembres) {
    for (int i = 0; i < nombreMembres; ++i) {
        bool cotisationEffectuee = false;
        for (int j = 0; j < 5; ++j) {
            if (membres[i].cotisations[j] > 0) {
                cotisationEffectuee = true;
                break;
            }
        }
        if (!cotisationEffectuee) {
            supprimer(membres, nombreMembres, membres[i].ID);
        }
    }
}

void recherche(Member membres[], int nombreMembres, int ID) {
    for (int i = 0; i < nombreMembres; ++i) {
        if (membres[i].ID == ID) {
            cout << "Informations pour le membre " << membres[i].ID << " :" << endl;
            cout << "Nom : " << membres[i].nom << endl;
            cout << "Prénom : " << membres[i].prenom << endl;
            cout << "Âge : " << membres[i].age << endl;
            cout << "Adresse : " << membres[i].adresse << endl;
            cout << "Cotisations : ";
            for (int j = 0; j < 5; ++j) {
                cout << membres[i].cotisations[j] << " ";
            }
            cout << endl;
            return;
        }
    }
    cout << "Membre non trouvé." << endl;
}
