#include <iostream>
#include "member.h"

using namespace std;

int main() {
    Member membres[100]; // Tableau de membres (limite de 100 membres)
    int nombreMembres = 0; // Nombre de membres actuels

    int choix;
    do {
        cout << "\nMenu : " << endl;
        cout << "1. Ajouter un membre" << endl;
        cout << "2. Modifier un membre" << endl;
        cout << "3. Supprimer un membre" << endl;
        cout << "4. Afficher la liste des membres et le montant total de leurs cotisations" << endl;
        cout << "5. Afficher les membres solvables" << endl;
        cout << "6. Afficher les membres insolvable" << endl;
        cout << "7. Afficher le pourcentage des membres n’ayant pas effectué toutes les cotisations" << endl;
        cout << "8. Supprimer les membres n’ayant rien cotisé" << endl;
        cout << "9. Rechercher un membre par ID" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1:
                ajouter(membres, nombreMembres);
                break;
            case 2:
                modifier(membres, nombreMembres);
                break;
            case 3: {
                int id;
                cout << "Entrez l'ID du membre à supprimer : ";
                cin >> id;
                supprimer(membres, nombreMembres, id);
                break;
            }
            case 4:
                afficherListeEtCotisations(membres, nombreMembres);
                break;
            case 5:
                solvable(membres, nombreMembres);
                break;
            case 6:
                insolvable(membres, nombreMembres);
                break;
            case 7:
                cout << "Pourcentage de membres n’ayant pas effectué toutes les cotisations : "
                     << pourcentageMembresNonCotisants(membres, nombreMembres) << "%" << endl;
                break;
            case 8:
                supprimerNonCotisants(membres, nombreMembres);
                cout << "Les membres n’ayant rien cotisé ont été supprimés." << endl;
                break;
            case 9: {
                int id;
                cout << "Entrez l'ID du membre à rechercher : ";
                cin >> id;
                recherche(membres, nombreMembres, id);
                break;
            }
            case 0:
                cout << "Au revoir !" << endl;
                break;
            default:
                cout << "Choix invalide, veuillez réessayer." << endl;
        }
    } while (choix != 0);

    return 0;
}
