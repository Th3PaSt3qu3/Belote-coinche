void affichage_enchere(Joueur *joueur, Contrat *contrat, int compteur_passe)
{
    type_contrat meilleur_contrat;
    int meilleur_score_mini = 0;
    int nb_contrat_annonce = 0;

    int score_mini = 0;

    int contrat_tmp;
    if(compteur % 4 == 0){
        printf("\nVous choisissez ! Quel contrat lancez-vous ? Tapez 0 pour passer, 1 pour miser, 2 pour capot ou 3 pour generale\n");
        do{
            scanf("%d", &contrat_tmp);
        }
        while(contrat_tmp < 0 && contrat_tmp > 3);

    switch(contrat_tmp){
        case 0 :
            compteur_passe++;
            meilleur_contrat = PASSE;
            score_mini = 0;
            meilleur_score_mini = score_mini;
            strcpy(contrat->affichage, "Passe\0");
            printf("Vous passez !\n");
            break;
        case 1 :
            printf("Vous misez ! Valeur a miser : ");
            do{
            scanf("%d", &score_mini);
            }while(score_mini < 80 && score_mini > 160);
            meilleur_score_mini = score_mini;
            printf("Vous misez %d points\n", meilleur_score_mini);
            meilleur_contrat = MISE;
            strcpy(contrat->affichage, "Mise\0");
            nb_contrat_annonce++;
            break;
        case 2 :
            meilleur_contrat = CAPOT;
            printf("Vous pariez que vous faites capot ! 250 points mis en jeu\n");
            score_mini = 250;
            meilleur_score_mini = score_mini;
            strcpy(contrat->affichage, "Capot\0");
            nb_contrat_annonce++;
            break;
        case 3 :
            meilleur_contrat = GENERAL;
            printf("Vous pariez que vous faites une Generale ! 500 points mis en jeu\n");
            score_mini = 500;
            meilleur_score_mini = score_mini;
            strcpy(contrat->affichage, "General\0");
            nb_contrat_annonce++;
            break;
    }
if(contrat_tmp != 0){
    printf("A quel atout voulez-vous prendre ? Pressez 0 pour ♠, 1 pour ♣, 2 pour ♥, 3 pour ♦, 4 pour ♠ ♣ ♥ ♦, 5 pour sans atout\n");
    scanf("%d", &contrat->atout);
        switch (contrat->atout)
        {
        case 0:
            strcat(contrat->affichage, " ♠");
            break;
        case 1:
            strcat(contrat->affichage, " ♣");
            break;
        case 2:
            strcat(contrat->affichage, " ♥");
            break;
        case 3:
            strcat(contrat->affichage, " ♦");
            break;
        case 4:
            strcat(contrat->affichage, " ♠ ♣ ♥ ♦");
            break;
        case 5:
            strcat(contrat->affichage, " *");
            break;
        }
    }
    printf("Vous posez donc un contrat de type %s a %d pts.\n", contrat->affichage, meilleur_score_mini);

    int i, j, k;
    int nb_carte_pique[4];
        for(int a = 0; a<4; a++){
            nb_carte_pique[a] = 0;
        }
    int nb_carte_coeur[4];
        for(int a = 0; a<4; a++){
            nb_carte_coeur[a] = 0;
        }
    int nb_carte_carreau[4];
        for(int a = 0; a<4; a++){
            nb_carte_carreau[a] = 0;
        }
    int nb_carte_trefle[4];
        for(int a = 0; a<4; a++){
            nb_carte_trefle[a] = 0;
        }

    int trefle;
    int pique;
    int coeur;
    int carreau;

    int fort_pique = 0;
    int fort_coeur = 0;
    int fort_carreau = 0;
    int fort_trefle = 0;

    int atout_bot[4];
        for(int a = 0; a<4; a++){
            atout_bot[a] = 0;
        }

    for(i = 1; i<4; i++){
            trefle = 0;
            pique = 0;
            coeur = 0;
            carreau = 0;

            fort_carreau = 0;
            fort_coeur = 0;
            fort_pique = 0;
            fort_trefle = 0;

    printf("%s réfléchi à une surenchere...\n", joueur[i].nom);
        for(j = 0; j<8; j++){
            if(strstr(joueur[i].carte[j].affichage, "♠") != NULL){
                pique++;
            }else if(strstr(joueur[i].carte[j].affichage, "♣") != NULL){
                trefle++;
            }else if(strstr(joueur[i].carte[j].affichage, "♥") != NULL){
                coeur++;
            }else if(strstr(joueur[i].carte[j].affichage, "♦") != NULL){
               carreau++;
            }
        }

    nb_carte_pique[i] = pique;
    nb_carte_coeur[i] = coeur;
    nb_carte_carreau[i] = carreau;
    nb_carte_trefle[i] = trefle;

        if(nb_carte_pique[i] > nb_carte_coeur[i] && nb_carte_pique[i] > nb_carte_carreau[i] && nb_carte_pique[i] > nb_carte_trefle[i]){
            nb_carte_coeur[i] = 0;
            nb_carte_carreau[i] = 0;
            nb_carte_trefle[i] = 0;
            }
        if(nb_carte_coeur[i] > nb_carte_carreau[i] && nb_carte_coeur[i] > nb_carte_pique[i] && nb_carte_coeur[i] > nb_carte_trefle[i]){
            nb_carte_pique[i] = 0;
            nb_carte_carreau[i] = 0;
            nb_carte_trefle[i] = 0;
            }
        if(nb_carte_carreau[i] > nb_carte_trefle[i] && nb_carte_carreau[i] > nb_carte_coeur[i] && nb_carte_carreau[i] > nb_carte_pique[i]){
            nb_carte_trefle[i] = 0;
            nb_carte_coeur[i] = 0;
            nb_carte_pique[i] = 0;
            }
        if(nb_carte_trefle[i] > nb_carte_carreau[i] && nb_carte_trefle[i] > nb_carte_coeur[i] && nb_carte_trefle[i] > nb_carte_pique[i]){
            nb_carte_carreau[i] = 0;
            nb_carte_coeur[i] = 0;
            nb_carte_pique[i] = 0;
            }

            for(k = 0; k<8; k++){
                if(nb_carte_pique[i] != 0){
                     if(strcoll(joueur[i].carte[j].affichage, "V♠") == 0 || strcoll(joueur[i].carte[j].affichage, "9♠") == 0 || strcoll(joueur[i].carte[j].affichage, "A♠") == 0 || strcoll(joueur[i].carte[j].affichage, "10♠") == 0){
                        fort_pique++;
                        }
                }else if(nb_carte_coeur[i] != 0){
                     if(strstr(joueur[i].carte[j].affichage, "V♥") != NULL || strstr(joueur[i].carte[j].affichage, "9♥") != NULL || strstr(joueur[i].carte[j].affichage, "A♥") != NULL || strstr(joueur[i].carte[j].affichage, "10♥") != NULL){
                        fort_coeur++;
                        }
                }else if(nb_carte_carreau[i] != 0){
                     if(strstr(joueur[i].carte[j].affichage, "V♦") != NULL || strstr(joueur[i].carte[j].affichage, "9♦") != NULL || strstr(joueur[i].carte[j].affichage, "A♦") != NULL || strstr(joueur[i].carte[j].affichage, "10♦") != NULL){
                        fort_carreau++;
                        }
                }else if(nb_carte_trefle[i] != 0){
                     if(strstr(joueur[i].carte[j].affichage, "V♣") != NULL || strstr(joueur[i].carte[j].affichage, "9♣") != NULL || strstr(joueur[i].carte[j].affichage, "A♣") != NULL || strstr(joueur[i].carte[j].affichage, "10♣") != NULL){
                        fort_trefle++;
                        }
                }
            }

            if(fort_pique != 0){
                            atout_bot[i] = fort_pique;
                            }
            if(fort_coeur != 0){
                            atout_bot[i] = fort_coeur;
                            }
            if(fort_carreau != 0){
                            atout_bot[i] = fort_carreau;
                            }
            if(fort_trefle != 0){
                            atout_bot[i] = fort_trefle;
                            }

            if(atout_bot[i] == 3 && meilleur_contrat < MISE){
                meilleur_contrat = MISE;
                meilleur_score_mini = 80;
                strcpy(contrat->affichage, "Mise\0");
                nb_contrat_annonce++;
                printf("%s mise %d\n", joueur[i].nom, meilleur_score_mini);
            }else if(atout_bot[i] == 8 && meilleur_contrat < GENERAL){
                meilleur_contrat = GENERAL;
                meilleur_score_mini = 500;
                strcpy(contrat->affichage, "General\0");
                nb_contrat_annonce++;
                printf("%s mise %d\n", joueur[i].nom, meilleur_score_mini);
            }else if(atout_bot[i] > 3 && atout_bot[i] < 8 && meilleur_score_mini < 120){
                meilleur_contrat = MISE;
                meilleur_score_mini = 120;
                strcpy(contrat->affichage, "Mise\0");
                nb_contrat_annonce++;
                printf("%s mise %d\n", joueur[i].nom, meilleur_score_mini);
            }else{
            printf("%s passe !\n", joueur[i].nom);
            compteur_passe++;
            }
        }
    }else if(compteur % 4 == 1){
        int i, j, k;
    int nb_carte_pique[4];
        for(int a = 0; a<4; a++){
            nb_carte_pique[a] = 0;
        }
    int nb_carte_coeur[4];
        for(int a = 0; a<4; a++){
            nb_carte_coeur[a] = 0;
        }
    int nb_carte_carreau[4];
        for(int a = 0; a<4; a++){
            nb_carte_carreau[a] = 0;
        }
    int nb_carte_trefle[4];
        for(int a = 0; a<4; a++){
            nb_carte_trefle[a] = 0;
        }

    int trefle;
    int pique;
    int coeur;
    int carreau;

    int fort_pique = 0;
    int fort_coeur = 0;
    int fort_carreau = 0;
    int fort_trefle = 0;

    int atout_bot[4];
        for(int a = 0; a<4; a++){
            atout_bot[a] = 0;
        }

    for(i = 1; i<4; i++){
            trefle = 0;
            pique = 0;
            coeur = 0;
            carreau = 0;

            fort_carreau = 0;
            fort_coeur = 0;
            fort_pique = 0;
            fort_trefle = 0;

    printf("%s réfléchi à une surenchere...\n", joueur[i].nom);
        for(j = 0; j<8; j++){
            if(strstr(joueur[i].carte[j].affichage, "♠") != NULL){
                pique++;
            }else if(strstr(joueur[i].carte[j].affichage, "♣") != NULL){
                trefle++;
            }else if(strstr(joueur[i].carte[j].affichage, "♥") != NULL){
                coeur++;
            }else if(strstr(joueur[i].carte[j].affichage, "♦") != NULL){
               carreau++;
            }
        }

    nb_carte_pique[i] = pique;
    nb_carte_coeur[i] = coeur;
    nb_carte_carreau[i] = carreau;
    nb_carte_trefle[i] = trefle;

        if(nb_carte_pique[i] > nb_carte_coeur[i] && nb_carte_pique[i] > nb_carte_carreau[i] && nb_carte_pique[i] > nb_carte_trefle[i]){
            nb_carte_coeur[i] = 0;
            nb_carte_carreau[i] = 0;
            nb_carte_trefle[i] = 0;
            }
        if(nb_carte_coeur[i] > nb_carte_carreau[i] && nb_carte_coeur[i] > nb_carte_pique[i] && nb_carte_coeur[i] > nb_carte_trefle[i]){
            nb_carte_pique[i] = 0;
            nb_carte_carreau[i] = 0;
            nb_carte_trefle[i] = 0;
            }
        if(nb_carte_carreau[i] > nb_carte_trefle[i] && nb_carte_carreau[i] > nb_carte_coeur[i] && nb_carte_carreau[i] > nb_carte_pique[i]){
            nb_carte_trefle[i] = 0;
            nb_carte_coeur[i] = 0;
            nb_carte_pique[i] = 0;
            }
        if(nb_carte_trefle[i] > nb_carte_carreau[i] && nb_carte_trefle[i] > nb_carte_coeur[i] && nb_carte_trefle[i] > nb_carte_pique[i]){
            nb_carte_carreau[i] = 0;
            nb_carte_coeur[i] = 0;
            nb_carte_pique[i] = 0;
            }

            for(k = 0; k<8; k++){
                if(nb_carte_pique[i] != 0){
                     if(strcoll(joueur[i].carte[j].affichage, "V♠") == 0 || strcoll(joueur[i].carte[j].affichage, "9♠") == 0 || strcoll(joueur[i].carte[j].affichage, "A♠") == 0 || strcoll(joueur[i].carte[j].affichage, "10♠") == 0){
                        fort_pique++;
                        }
                }else if(nb_carte_coeur[i] != 0){
                     if(strstr(joueur[i].carte[j].affichage, "V♥") != NULL || strstr(joueur[i].carte[j].affichage, "9♥") != NULL || strstr(joueur[i].carte[j].affichage, "A♥") != NULL || strstr(joueur[i].carte[j].affichage, "10♥") != NULL){
                        fort_coeur++;
                        }
                }else if(nb_carte_carreau[i] != 0){
                     if(strstr(joueur[i].carte[j].affichage, "V♦") != NULL || strstr(joueur[i].carte[j].affichage, "9♦") != NULL || strstr(joueur[i].carte[j].affichage, "A♦") != NULL || strstr(joueur[i].carte[j].affichage, "10♦") != NULL){
                        fort_carreau++;
                        }
                }else if(nb_carte_trefle[i] != 0){
                     if(strstr(joueur[i].carte[j].affichage, "V♣") != NULL || strstr(joueur[i].carte[j].affichage, "9♣") != NULL || strstr(joueur[i].carte[j].affichage, "A♣") != NULL || strstr(joueur[i].carte[j].affichage, "10♣") != NULL){
                        fort_trefle++;
                        }
                }
            }

            if(fort_pique != 0){
                            atout_bot[i] = fort_pique;
                            }
            if(fort_coeur != 0){
                            atout_bot[i] = fort_coeur;
                            }
            if(fort_carreau != 0){
                            atout_bot[i] = fort_carreau;
                            }
            if(fort_trefle != 0){
                            atout_bot[i] = fort_trefle;
                            }

            if(atout_bot[i] == 3 && meilleur_contrat < MISE){
                meilleur_contrat = MISE;
                meilleur_score_mini = 80;
                strcpy(contrat->affichage, "Mise\0");
                nb_contrat_annonce++;
                printf("%s mise %d\n", joueur[i].nom, meilleur_score_mini);
            }else if(atout_bot[i] == 8 && meilleur_contrat < GENERAL){
                meilleur_contrat = GENERAL;
                meilleur_score_mini = 500;
                strcpy(contrat->affichage, "General\0");
                nb_contrat_annonce++;
                printf("%s mise %d\n", joueur[i].nom, meilleur_score_mini);
            }else if(atout_bot[i] > 3 && atout_bot[i] < 8 && meilleur_score_mini < 120){
                meilleur_contrat = MISE;
                meilleur_score_mini = 120;
                strcpy(contrat->affichage, "Mise\0");
                nb_contrat_annonce++;
                printf("%s mise %d\n", joueur[i].nom, meilleur_score_mini);
            }else{
            printf("%s passe !\n", joueur[i].nom);
            compteur_passe++;
            }
        }
             printf("\nVous choisissez ! Quel contrat lancez-vous ? Tapez 0 pour passer, 1 pour miser, 2 pour capot ou 3 pour generale\n");
        do{
            scanf("%d", &contrat_tmp);
        }
        while(contrat_tmp < 0 && contrat_tmp > 3);

    switch(contrat_tmp){
        case 0 :
            compteur_passe++;
            meilleur_contrat = PASSE;
            score_mini = 0;
            meilleur_score_mini = score_mini;
            strcpy(contrat->affichage, "Passe\0");
            printf("Vous passez !\n");
            break;
        case 1 :
            printf("Vous misez ! Valeur a miser : ");
            do{
            scanf("%d", &score_mini);
            }while(score_mini < 80 && score_mini > 160);
            meilleur_score_mini = score_mini;
            printf("Vous misez %d points\n", meilleur_score_mini);
            meilleur_contrat = MISE;
            strcpy(contrat->affichage, "Mise\0");
            nb_contrat_annonce++;
            break;
        case 2 :
            meilleur_contrat = CAPOT;
            printf("Vous pariez que vous faites capot ! 250 points mis en jeu\n");
            score_mini = 250;
            meilleur_score_mini = score_mini;
            strcpy(contrat->affichage, "Capot\0");
            nb_contrat_annonce++;
            break;
        case 3 :
            meilleur_contrat = GENERAL;
            printf("Vous pariez que vous faites une Generale ! 500 points mis en jeu\n");
            score_mini = 500;
            meilleur_score_mini = score_mini;
            strcpy(contrat->affichage, "General\0");
            nb_contrat_annonce++;
            break;
    }
if(contrat_tmp != 0){
    printf("A quel atout voulez-vous prendre ? Pressez 0 pour ♠, 1 pour ♣, 2 pour ♥, 3 pour ♦, 4 pour ♠ ♣ ♥ ♦, 5 pour sans atout\n");
    scanf("%d", &contrat->atout);
        switch (contrat->atout)
        {
        case 0:
            strcat(contrat->affichage, " ♠");
            break;
        case 1:
            strcat(contrat->affichage, " ♣");
            break;
        case 2:
            strcat(contrat->affichage, " ♥");
            break;
        case 3:
            strcat(contrat->affichage, " ♦");
            break;
        case 4:
            strcat(contrat->affichage, " ♠ ♣ ♥ ♦");
            break;
        case 5:
            strcat(contrat->affichage, " *");
            break;
        }
    }
    printf("Vous posez donc un contrat de type %s a %d pts.\n", contrat->affichage, meilleur_score_mini);

    }else if(compteur % 4 == 2){
        int i, j, k;
    int nb_carte_pique[4];
        for(int a = 0; a<4; a++){
            nb_carte_pique[a] = 0;
        }
    int nb_carte_coeur[4];
        for(int a = 0; a<4; a++){
            nb_carte_coeur[a] = 0;
        }
    int nb_carte_carreau[4];
        for(int a = 0; a<4; a++){
            nb_carte_carreau[a] = 0;
        }
    int nb_carte_trefle[4];
        for(int a = 0; a<4; a++){
            nb_carte_trefle[a] = 0;
        }

    int trefle;
    int pique;
    int coeur;
    int carreau;

    int fort_pique = 0;
    int fort_coeur = 0;
    int fort_carreau = 0;
    int fort_trefle = 0;

    int atout_bot[4];
        for(int a = 0; a<4; a++){
            atout_bot[a] = 0;
        }

    for(i = 2; i<4; i++){
            trefle = 0;
            pique = 0;
            coeur = 0;
            carreau = 0;

            fort_carreau = 0;
            fort_coeur = 0;
            fort_pique = 0;
            fort_trefle = 0;

    printf("%s réfléchi à une surenchere...\n", joueur[i].nom);
        for(j = 0; j<8; j++){
            if(strstr(joueur[i].carte[j].affichage, "♠") != NULL){
                pique++;
            }else if(strstr(joueur[i].carte[j].affichage, "♣") != NULL){
                trefle++;
            }else if(strstr(joueur[i].carte[j].affichage, "♥") != NULL){
                coeur++;
            }else if(strstr(joueur[i].carte[j].affichage, "♦") != NULL){
               carreau++;
            }
        }

    nb_carte_pique[i] = pique;
    nb_carte_coeur[i] = coeur;
    nb_carte_carreau[i] = carreau;
    nb_carte_trefle[i] = trefle;

        if(nb_carte_pique[i] > nb_carte_coeur[i] && nb_carte_pique[i] > nb_carte_carreau[i] && nb_carte_pique[i] > nb_carte_trefle[i]){
            nb_carte_coeur[i] = 0;
            nb_carte_carreau[i] = 0;
            nb_carte_trefle[i] = 0;
            }
        if(nb_carte_coeur[i] > nb_carte_carreau[i] && nb_carte_coeur[i] > nb_carte_pique[i] && nb_carte_coeur[i] > nb_carte_trefle[i]){
            nb_carte_pique[i] = 0;
            nb_carte_carreau[i] = 0;
            nb_carte_trefle[i] = 0;
            }
        if(nb_carte_carreau[i] > nb_carte_trefle[i] && nb_carte_carreau[i] > nb_carte_coeur[i] && nb_carte_carreau[i] > nb_carte_pique[i]){
            nb_carte_trefle[i] = 0;
            nb_carte_coeur[i] = 0;
            nb_carte_pique[i] = 0;
            }
        if(nb_carte_trefle[i] > nb_carte_carreau[i] && nb_carte_trefle[i] > nb_carte_coeur[i] && nb_carte_trefle[i] > nb_carte_pique[i]){
            nb_carte_carreau[i] = 0;
            nb_carte_coeur[i] = 0;
            nb_carte_pique[i] = 0;
            }

            for(k = 0; k<8; k++){
                if(nb_carte_pique[i] != 0){
                     if(strcoll(joueur[i].carte[j].affichage, "V♠") == 0 || strcoll(joueur[i].carte[j].affichage, "9♠") == 0 || strcoll(joueur[i].carte[j].affichage, "A♠") == 0 || strcoll(joueur[i].carte[j].affichage, "10♠") == 0){
                        fort_pique++;
                        }
                }else if(nb_carte_coeur[i] != 0){
                     if(strstr(joueur[i].carte[j].affichage, "V♥") != NULL || strstr(joueur[i].carte[j].affichage, "9♥") != NULL || strstr(joueur[i].carte[j].affichage, "A♥") != NULL || strstr(joueur[i].carte[j].affichage, "10♥") != NULL){
                        fort_coeur++;
                        }
                }else if(nb_carte_carreau[i] != 0){
                     if(strstr(joueur[i].carte[j].affichage, "V♦") != NULL || strstr(joueur[i].carte[j].affichage, "9♦") != NULL || strstr(joueur[i].carte[j].affichage, "A♦") != NULL || strstr(joueur[i].carte[j].affichage, "10♦") != NULL){
                        fort_carreau++;
                        }
                }else if(nb_carte_trefle[i] != 0){
                     if(strstr(joueur[i].carte[j].affichage, "V♣") != NULL || strstr(joueur[i].carte[j].affichage, "9♣") != NULL || strstr(joueur[i].carte[j].affichage, "A♣") != NULL || strstr(joueur[i].carte[j].affichage, "10♣") != NULL){
                        fort_trefle++;
                        }
                }
            }

            if(fort_pique != 0){
                            atout_bot[i] = fort_pique;
                            }
            if(fort_coeur != 0){
                            atout_bot[i] = fort_coeur;
                            }
            if(fort_carreau != 0){
                            atout_bot[i] = fort_carreau;
                            }
            if(fort_trefle != 0){
                            atout_bot[i] = fort_trefle;
                            }

            if(atout_bot[i] == 3 && meilleur_contrat < MISE){
                meilleur_contrat = MISE;
                meilleur_score_mini = 80;
                strcpy(contrat->affichage, "Mise\0");
                nb_contrat_annonce++;
                printf("%s mise %d\n", joueur[i].nom, meilleur_score_mini);
            }else if(atout_bot[i] == 8 && meilleur_contrat < GENERAL){
                meilleur_contrat = GENERAL;
                meilleur_score_mini = 500;
                strcpy(contrat->affichage, "General\0");
                nb_contrat_annonce++;
                printf("%s mise %d\n", joueur[i].nom, meilleur_score_mini);
            }else if(atout_bot[i] > 3 && atout_bot[i] < 8 && meilleur_score_mini < 120){
                meilleur_contrat = MISE;
                meilleur_score_mini = 120;
                strcpy(contrat->affichage, "Mise\0");
                nb_contrat_annonce++;
                printf("%s mise %d\n", joueur[i].nom, meilleur_score_mini);
            }else{
            printf("%s passe !\n", joueur[i].nom);
            compteur_passe++;
            }
        }
           printf("\nVous choisissez ! Quel contrat lancez-vous ? Tapez 0 pour passer, 1 pour miser, 2 pour capot ou 3 pour generale\n");
        do{
            scanf("%d", &contrat_tmp);
        }
        while(contrat_tmp < 0 && contrat_tmp > 3);

    switch(contrat_tmp){
        case 0 :
            compteur_passe++;
            meilleur_contrat = PASSE;
            score_mini = 0;
            meilleur_score_mini = score_mini;
            strcpy(contrat->affichage, "Passe\0");
            printf("Vous passez !\n");
            break;
        case 1 :
            printf("Vous misez ! Valeur a miser : ");
            do{
            scanf("%d", &score_mini);
            }while(score_mini < 80 && score_mini > 160);
            meilleur_score_mini = score_mini;
            printf("Vous misez %d points\n", meilleur_score_mini);
            meilleur_contrat = MISE;
            strcpy(contrat->affichage, "Mise\0");
            nb_contrat_annonce++;
            break;
        case 2 :
            meilleur_contrat = CAPOT;
            printf("Vous pariez que vous faites capot ! 250 points mis en jeu\n");
            score_mini = 250;
            meilleur_score_mini = score_mini;
            strcpy(contrat->affichage, "Capot\0");
            nb_contrat_annonce++;
            break;
        case 3 :
            meilleur_contrat = GENERAL;
            printf("Vous pariez que vous faites une Generale ! 500 points mis en jeu\n");
            score_mini = 500;
            meilleur_score_mini = score_mini;
            strcpy(contrat->affichage, "General\0");
            nb_contrat_annonce++;
            break;
    }
if(contrat_tmp != 0){
    printf("A quel atout voulez-vous prendre ? Pressez 0 pour ♠, 1 pour ♣, 2 pour ♥, 3 pour ♦, 4 pour ♠ ♣ ♥ ♦, 5 pour sans atout\n");
    scanf("%d", &contrat->atout);
        switch (contrat->atout)
        {
        case 0:
            strcat(contrat->affichage, " ♠");
            break;
        case 1:
            strcat(contrat->affichage, " ♣");
            break;
        case 2:
            strcat(contrat->affichage, " ♥");
            break;
        case 3:
            strcat(contrat->affichage, " ♦");
            break;
        case 4:
            strcat(contrat->affichage, " ♠ ♣ ♥ ♦");
            break;
        case 5:
            strcat(contrat->affichage, " *");
            break;
        }
    }
    printf("Vous posez donc un contrat de type %s a %d pts.\n", contrat->affichage, meilleur_score_mini);

    for(i = 1; i<2 ; i++){
            trefle = 0;
            pique = 0;
            coeur = 0;
            carreau = 0;

            fort_carreau = 0;
            fort_coeur = 0;
            fort_pique = 0;
            fort_trefle = 0;

    printf("%s réfléchi à une surenchere...\n", joueur[i].nom);
        for(j = 0; j<8; j++){
            if(strstr(joueur[i].carte[j].affichage, "♠") != NULL){
                pique++;
            }else if(strstr(joueur[i].carte[j].affichage, "♣") != NULL){
                trefle++;
            }else if(strstr(joueur[i].carte[j].affichage, "♥") != NULL){
                coeur++;
            }else if(strstr(joueur[i].carte[j].affichage, "♦") != NULL){
               carreau++;
            }
        }

    nb_carte_pique[i] = pique;
    nb_carte_coeur[i] = coeur;
    nb_carte_carreau[i] = carreau;
    nb_carte_trefle[i] = trefle;

        if(nb_carte_pique[i] > nb_carte_coeur[i] && nb_carte_pique[i] > nb_carte_carreau[i] && nb_carte_pique[i] > nb_carte_trefle[i]){
            nb_carte_coeur[i] = 0;
            nb_carte_carreau[i] = 0;
            nb_carte_trefle[i] = 0;
            }
        if(nb_carte_coeur[i] > nb_carte_carreau[i] && nb_carte_coeur[i] > nb_carte_pique[i] && nb_carte_coeur[i] > nb_carte_trefle[i]){
            nb_carte_pique[i] = 0;
            nb_carte_carreau[i] = 0;
            nb_carte_trefle[i] = 0;
            }
        if(nb_carte_carreau[i] > nb_carte_trefle[i] && nb_carte_carreau[i] > nb_carte_coeur[i] && nb_carte_carreau[i] > nb_carte_pique[i]){
            nb_carte_trefle[i] = 0;
            nb_carte_coeur[i] = 0;
            nb_carte_pique[i] = 0;
            }
        if(nb_carte_trefle[i] > nb_carte_carreau[i] && nb_carte_trefle[i] > nb_carte_coeur[i] && nb_carte_trefle[i] > nb_carte_pique[i]){
            nb_carte_carreau[i] = 0;
            nb_carte_coeur[i] = 0;
            nb_carte_pique[i] = 0;
            }

            for(k = 0; k<8; k++){
                if(nb_carte_pique[i] != 0){
                     if(strcoll(joueur[i].carte[j].affichage, "V♠") == 0 || strcoll(joueur[i].carte[j].affichage, "9♠") == 0 || strcoll(joueur[i].carte[j].affichage, "A♠") == 0 || strcoll(joueur[i].carte[j].affichage, "10♠") == 0){
                        fort_pique++;
                        }
                }else if(nb_carte_coeur[i] != 0){
                     if(strstr(joueur[i].carte[j].affichage, "V♥") != NULL || strstr(joueur[i].carte[j].affichage, "9♥") != NULL || strstr(joueur[i].carte[j].affichage, "A♥") != NULL || strstr(joueur[i].carte[j].affichage, "10♥") != NULL){
                        fort_coeur++;
                        }
                }else if(nb_carte_carreau[i] != 0){
                     if(strstr(joueur[i].carte[j].affichage, "V♦") != NULL || strstr(joueur[i].carte[j].affichage, "9♦") != NULL || strstr(joueur[i].carte[j].affichage, "A♦") != NULL || strstr(joueur[i].carte[j].affichage, "10♦") != NULL){
                        fort_carreau++;
                        }
                }else if(nb_carte_trefle[i] != 0){
                     if(strstr(joueur[i].carte[j].affichage, "V♣") != NULL || strstr(joueur[i].carte[j].affichage, "9♣") != NULL || strstr(joueur[i].carte[j].affichage, "A♣") != NULL || strstr(joueur[i].carte[j].affichage, "10♣") != NULL){
                        fort_trefle++;
                        }
                }
            }

            if(fort_pique != 0){
                            atout_bot[i] = fort_pique;
                            }
            if(fort_coeur != 0){
                            atout_bot[i] = fort_coeur;
                            }
            if(fort_carreau != 0){
                            atout_bot[i] = fort_carreau;
                            }
            if(fort_trefle != 0){
                            atout_bot[i] = fort_trefle;
                            }

            if(atout_bot[i] == 3 && meilleur_contrat < MISE){
                meilleur_contrat = MISE;
                meilleur_score_mini = 80;
                strcpy(contrat->affichage, "Mise\0");
                nb_contrat_annonce++;
                printf("%s mise %d\n", joueur[i].nom, meilleur_score_mini);
            }else if(atout_bot[i] == 8 && meilleur_contrat < GENERAL){
                meilleur_contrat = GENERAL;
                meilleur_score_mini = 500;
                strcpy(contrat->affichage, "General\0");
                nb_contrat_annonce++;
                printf("%s mise %d\n", joueur[i].nom, meilleur_score_mini);
            }else if(atout_bot[i] > 3 && atout_bot[i] < 8 && meilleur_score_mini < 120){
                meilleur_contrat = MISE;
                meilleur_score_mini = 120;
                strcpy(contrat->affichage, "Mise\0");
                nb_contrat_annonce++;
                printf("%s mise %d\n", joueur[i].nom, meilleur_score_mini);
            }else{
            printf("%s passe !\n", joueur[i].nom);
            compteur_passe++;
            }
        }
    }else if(compteur % 4 == 3){
        int i, j, k;
    int nb_carte_pique[4];
        for(int a = 0; a<4; a++){
            nb_carte_pique[a] = 0;
        }
    int nb_carte_coeur[4];
        for(int a = 0; a<4; a++){
            nb_carte_coeur[a] = 0;
        }
    int nb_carte_carreau[4];
        for(int a = 0; a<4; a++){
            nb_carte_carreau[a] = 0;
        }
    int nb_carte_trefle[4];
        for(int a = 0; a<4; a++){
            nb_carte_trefle[a] = 0;
        }

    int trefle;
    int pique;
    int coeur;
    int carreau;

    int fort_pique = 0;
    int fort_coeur = 0;
    int fort_carreau = 0;
    int fort_trefle = 0;

    int atout_bot[4];
        for(int a = 0; a<4; a++){
            atout_bot[a] = 0;
        }
        for(i = 3; i<4; i++){
            trefle = 0;
            pique = 0;
            coeur = 0;
            carreau = 0;

            fort_carreau = 0;
            fort_coeur = 0;
            fort_pique = 0;
            fort_trefle = 0;

    printf("%s réfléchi à une surenchere...\n", joueur[i].nom);
        for(j = 0; j<8; j++){
            if(strstr(joueur[i].carte[j].affichage, "♠") != NULL){
                pique++;
            }else if(strstr(joueur[i].carte[j].affichage, "♣") != NULL){
                trefle++;
            }else if(strstr(joueur[i].carte[j].affichage, "♥") != NULL){
                coeur++;
            }else if(strstr(joueur[i].carte[j].affichage, "♦") != NULL){
               carreau++;
            }
        }

    nb_carte_pique[i] = pique;
    nb_carte_coeur[i] = coeur;
    nb_carte_carreau[i] = carreau;
    nb_carte_trefle[i] = trefle;

        if(nb_carte_pique[i] > nb_carte_coeur[i] && nb_carte_pique[i] > nb_carte_carreau[i] && nb_carte_pique[i] > nb_carte_trefle[i]){
            nb_carte_coeur[i] = 0;
            nb_carte_carreau[i] = 0;
            nb_carte_trefle[i] = 0;
            }
        if(nb_carte_coeur[i] > nb_carte_carreau[i] && nb_carte_coeur[i] > nb_carte_pique[i] && nb_carte_coeur[i] > nb_carte_trefle[i]){
            nb_carte_pique[i] = 0;
            nb_carte_carreau[i] = 0;
            nb_carte_trefle[i] = 0;
            }
        if(nb_carte_carreau[i] > nb_carte_trefle[i] && nb_carte_carreau[i] > nb_carte_coeur[i] && nb_carte_carreau[i] > nb_carte_pique[i]){
            nb_carte_trefle[i] = 0;
            nb_carte_coeur[i] = 0;
            nb_carte_pique[i] = 0;
            }
        if(nb_carte_trefle[i] > nb_carte_carreau[i] && nb_carte_trefle[i] > nb_carte_coeur[i] && nb_carte_trefle[i] > nb_carte_pique[i]){
            nb_carte_carreau[i] = 0;
            nb_carte_coeur[i] = 0;
            nb_carte_pique[i] = 0;
            }

            for(k = 0; k<8; k++){
                if(nb_carte_pique[i] != 0){
                     if(strcoll(joueur[i].carte[j].affichage, "V♠") == 0 || strcoll(joueur[i].carte[j].affichage, "9♠") == 0 || strcoll(joueur[i].carte[j].affichage, "A♠") == 0 || strcoll(joueur[i].carte[j].affichage, "10♠") == 0){
                        fort_pique++;
                        }
                }else if(nb_carte_coeur[i] != 0){
                     if(strstr(joueur[i].carte[j].affichage, "V♥") != NULL || strstr(joueur[i].carte[j].affichage, "9♥") != NULL || strstr(joueur[i].carte[j].affichage, "A♥") != NULL || strstr(joueur[i].carte[j].affichage, "10♥") != NULL){
                        fort_coeur++;
                        }
                }else if(nb_carte_carreau[i] != 0){
                     if(strstr(joueur[i].carte[j].affichage, "V♦") != NULL || strstr(joueur[i].carte[j].affichage, "9♦") != NULL || strstr(joueur[i].carte[j].affichage, "A♦") != NULL || strstr(joueur[i].carte[j].affichage, "10♦") != NULL){
                        fort_carreau++;
                        }
                }else if(nb_carte_trefle[i] != 0){
                     if(strstr(joueur[i].carte[j].affichage, "V♣") != NULL || strstr(joueur[i].carte[j].affichage, "9♣") != NULL || strstr(joueur[i].carte[j].affichage, "A♣") != NULL || strstr(joueur[i].carte[j].affichage, "10♣") != NULL){
                        fort_trefle++;
                        }
                }
            }

            if(fort_pique != 0){
                            atout_bot[i] = fort_pique;
                            }
            if(fort_coeur != 0){
                            atout_bot[i] = fort_coeur;
                            }
            if(fort_carreau != 0){
                            atout_bot[i] = fort_carreau;
                            }
            if(fort_trefle != 0){
                            atout_bot[i] = fort_trefle;
                            }

            if(atout_bot[i] == 3 && meilleur_contrat < MISE){
                meilleur_contrat = MISE;
                meilleur_score_mini = 80;
                strcpy(contrat->affichage, "Mise\0");
                nb_contrat_annonce++;
                printf("%s mise %d\n", joueur[i].nom, meilleur_score_mini);
            }else if(atout_bot[i] == 8 && meilleur_contrat < GENERAL){
                meilleur_contrat = GENERAL;
                meilleur_score_mini = 500;
                strcpy(contrat->affichage, "General\0");
                nb_contrat_annonce++;
                printf("%s mise %d\n", joueur[i].nom, meilleur_score_mini);
            }else if(atout_bot[i] > 3 && atout_bot[i] < 8 && meilleur_score_mini < 120){
                meilleur_contrat = MISE;
                meilleur_score_mini = 120;
                strcpy(contrat->affichage, "Mise\0");
                nb_contrat_annonce++;
                printf("%s mise %d\n", joueur[i].nom, meilleur_score_mini);
            }else{
            printf("%s passe !\n", joueur[i].nom);
            compteur_passe++;
            }
        }
         printf("\nVous choisissez ! Quel contrat lancez-vous ? Tapez 0 pour passer, 1 pour miser, 2 pour capot ou 3 pour generale\n");
        do{
            scanf("%d", &contrat_tmp);
        }
        while(contrat_tmp < 0 && contrat_tmp > 3);

    switch(contrat_tmp){
        case 0 :
            compteur_passe++;
            meilleur_contrat = PASSE;
            score_mini = 0;
            meilleur_score_mini = score_mini;
            strcpy(contrat->affichage, "Passe\0");
            printf("Vous passez !\n");
            break;
        case 1 :
            printf("Vous misez ! Valeur a miser : ");
            do{
            scanf("%d", &score_mini);
            }while(score_mini < 80 && score_mini > 160);
            meilleur_score_mini = score_mini;
            printf("Vous misez %d points\n", meilleur_score_mini);
            meilleur_contrat = MISE;
            strcpy(contrat->affichage, "Mise\0");
            nb_contrat_annonce++;
            break;
        case 2 :
            meilleur_contrat = CAPOT;
            printf("Vous pariez que vous faites capot ! 250 points mis en jeu\n");
            score_mini = 250;
            meilleur_score_mini = score_mini;
            strcpy(contrat->affichage, "Capot\0");
            nb_contrat_annonce++;
            break;
        case 3 :
            meilleur_contrat = GENERAL;
            printf("Vous pariez que vous faites une Generale ! 500 points mis en jeu\n");
            score_mini = 500;
            meilleur_score_mini = score_mini;
            strcpy(contrat->affichage, "General\0");
            nb_contrat_annonce++;
            break;
    }
if(contrat_tmp != 0){
    printf("A quel atout voulez-vous prendre ? Pressez 0 pour ♠, 1 pour ♣, 2 pour ♥, 3 pour ♦, 4 pour ♠ ♣ ♥ ♦, 5 pour sans atout\n");
    scanf("%d", &contrat->atout);
        switch (contrat->atout)
        {
        case 0:
            strcat(contrat->affichage, " ♠");
            break;
        case 1:
            strcat(contrat->affichage, " ♣");
            break;
        case 2:
            strcat(contrat->affichage, " ♥");
            break;
        case 3:
            strcat(contrat->affichage, " ♦");
            break;
        case 4:
            strcat(contrat->affichage, " ♠ ♣ ♥ ♦");
            break;
        case 5:
            strcat(contrat->affichage, " *");
            break;
        }
    }
    printf("Vous posez donc un contrat de type %s a %d pts.\n", contrat->affichage, meilleur_score_mini);
    for(i = 1; i<3; i++){
            trefle = 0;
            pique = 0;
            coeur = 0;
            carreau = 0;

            fort_carreau = 0;
            fort_coeur = 0;
            fort_pique = 0;
            fort_trefle = 0;

    printf("%s réfléchi à une surenchere...\n", joueur[i].nom);
        for(j = 0; j<8; j++){
            if(strstr(joueur[i].carte[j].affichage, "♠") != NULL){
                pique++;
            }else if(strstr(joueur[i].carte[j].affichage, "♣") != NULL){
                trefle++;
            }else if(strstr(joueur[i].carte[j].affichage, "♥") != NULL){
                coeur++;
            }else if(strstr(joueur[i].carte[j].affichage, "♦") != NULL){
               carreau++;
            }
        }

    nb_carte_pique[i] = pique;
    nb_carte_coeur[i] = coeur;
    nb_carte_carreau[i] = carreau;
    nb_carte_trefle[i] = trefle;

        if(nb_carte_pique[i] > nb_carte_coeur[i] && nb_carte_pique[i] > nb_carte_carreau[i] && nb_carte_pique[i] > nb_carte_trefle[i]){
            nb_carte_coeur[i] = 0;
            nb_carte_carreau[i] = 0;
            nb_carte_trefle[i] = 0;
            }
        if(nb_carte_coeur[i] > nb_carte_carreau[i] && nb_carte_coeur[i] > nb_carte_pique[i] && nb_carte_coeur[i] > nb_carte_trefle[i]){
            nb_carte_pique[i] = 0;
            nb_carte_carreau[i] = 0;
            nb_carte_trefle[i] = 0;
            }
        if(nb_carte_carreau[i] > nb_carte_trefle[i] && nb_carte_carreau[i] > nb_carte_coeur[i] && nb_carte_carreau[i] > nb_carte_pique[i]){
            nb_carte_trefle[i] = 0;
            nb_carte_coeur[i] = 0;
            nb_carte_pique[i] = 0;
            }
        if(nb_carte_trefle[i] > nb_carte_carreau[i] && nb_carte_trefle[i] > nb_carte_coeur[i] && nb_carte_trefle[i] > nb_carte_pique[i]){
            nb_carte_carreau[i] = 0;
            nb_carte_coeur[i] = 0;
            nb_carte_pique[i] = 0;
            }

            for(k = 0; k<8; k++){
                if(nb_carte_pique[i] != 0){
                     if(strcoll(joueur[i].carte[j].affichage, "V♠") == 0 || strcoll(joueur[i].carte[j].affichage, "9♠") == 0 || strcoll(joueur[i].carte[j].affichage, "A♠") == 0 || strcoll(joueur[i].carte[j].affichage, "10♠") == 0){
                        fort_pique++;
                        }
                }else if(nb_carte_coeur[i] != 0){
                     if(strstr(joueur[i].carte[j].affichage, "V♥") != NULL || strstr(joueur[i].carte[j].affichage, "9♥") != NULL || strstr(joueur[i].carte[j].affichage, "A♥") != NULL || strstr(joueur[i].carte[j].affichage, "10♥") != NULL){
                        fort_coeur++;
                        }
                }else if(nb_carte_carreau[i] != 0){
                     if(strstr(joueur[i].carte[j].affichage, "V♦") != NULL || strstr(joueur[i].carte[j].affichage, "9♦") != NULL || strstr(joueur[i].carte[j].affichage, "A♦") != NULL || strstr(joueur[i].carte[j].affichage, "10♦") != NULL){
                        fort_carreau++;
                        }
                }else if(nb_carte_trefle[i] != 0){
                     if(strstr(joueur[i].carte[j].affichage, "V♣") != NULL || strstr(joueur[i].carte[j].affichage, "9♣") != NULL || strstr(joueur[i].carte[j].affichage, "A♣") != NULL || strstr(joueur[i].carte[j].affichage, "10♣") != NULL){
                        fort_trefle++;
                        }
                }
            }

            if(fort_pique != 0){
                            atout_bot[i] = fort_pique;
                            }
            if(fort_coeur != 0){
                            atout_bot[i] = fort_coeur;
                            }
            if(fort_carreau != 0){
                            atout_bot[i] = fort_carreau;
                            }
            if(fort_trefle != 0){
                            atout_bot[i] = fort_trefle;
                            }

            if(atout_bot[i] == 3 && meilleur_contrat < MISE){
                meilleur_contrat = MISE;
                meilleur_score_mini = 80;
                strcpy(contrat->affichage, "Mise\0");
                nb_contrat_annonce++;
                printf("%s mise %d\n", joueur[i].nom, meilleur_score_mini);
            }else if(atout_bot[i] == 8 && meilleur_contrat < GENERAL){
                meilleur_contrat = GENERAL;
                meilleur_score_mini = 500;
                strcpy(contrat->affichage, "General\0");
                nb_contrat_annonce++;
                printf("%s mise %d\n", joueur[i].nom, meilleur_score_mini);
            }else if(atout_bot[i] > 3 && atout_bot[i] < 8 && meilleur_score_mini < 120){
                meilleur_contrat = MISE;
                meilleur_score_mini = 120;
                strcpy(contrat->affichage, "Mise\0");
                nb_contrat_annonce++;
                printf("%s mise %d\n", joueur[i].nom, meilleur_score_mini);
            }else{
            printf("%s passe !\n", joueur[i].nom);
            compteur_passe++;
            }
        }
    }
}   
