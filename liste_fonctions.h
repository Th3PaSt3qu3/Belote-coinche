void initialisation_paquet_total(Carte *paquet_total);
void initialisation_joueurs(Carte *paquet_total, Joueur *joueur, char *nom_joueur);
void retour_paquet_total(Carte *paquet_total, Joueur *joueur, char *nom_joueur);
void melange(Carte *);
void affichage_contrat(Contrat *contrat);
void compteur_manche(int compteur);
void affichage_enchere(Joueur *joueur, Contrat *contrat, int compteur_passe);
void premier_tour(Contrat *contrat, Joueur *joueur, int compteur);
