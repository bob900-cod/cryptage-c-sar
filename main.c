#include <stdio.h>

void shift_character(char *c, int shift) {
    if (*c >= 'a' && *c <= 'z') {
        *c = (*c - 'a' + shift) % 26 + 'a';
    } else if (*c >= 'A' && *c <= 'Z') {
        *c = (*c - 'A' + shift) % 26 + 'A';
    }
}

int main() {
    FILE *file_read, *file_write;
    char c;
    int shift;

    printf("Entrez le decalage souhaite : ");
    scanf("%d", &shift);

    // Ouvrir le premier fichier en mode lecture
    file_read = fopen("phrase.txt", "r");

    // Vérifier si le premier fichier a été ouvert avec succes
    if (file_read == NULL) {
        printf("Erreur lors de l'ouverture du premier fichier.\n");
        return 1;
    }

    // Ouvrir le second fichier en mode écriture
    file_write = fopen("output.txt", "w");

    // Vérifier si le second fichier a été ouvert avec succès
    if (file_write == NULL) {
        printf("Erreur lors de l'ouverture du second fichier.\n");
        fclose(file_read);
        return 1;
    }

    // Lire et écrire chaque caractère avec le décalage souhaite
    while ((c = fgetc(file_read))!= EOF) {
        shift_character(&c, shift);
        fputc(c, file_write);
    }

    // Fermer les fichiers
    fclose(file_read);
    fclose(file_write);

    printf("Reussi.\n");

    return 0;
}
