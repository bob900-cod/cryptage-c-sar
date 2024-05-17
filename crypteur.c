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
    char c, filename_read[50], filename_write[50];
    int shift;

    printf("Entrez le nom du fichier a lire : ");
    scanf("%s", filename_read);

    printf("Entrez le nom du fichier a %ccrire : ", 130);
    scanf("%s", filename_write);

    printf("Entrez le d%ccalage voulu : ", 130);
    scanf("%d", &shift);

    // Ouvrir le premier fichier en mode lecture
    file_read = fopen(filename_read, "r");

    // Vérifier si le premier fichier a été ouvert avec succès
    if (file_read == NULL) {
        printf("Erreur lors de l'ouverture du premier fichier.\n");
        return 1;
    }

    // Ouvrir le second fichier en mode écriture
    file_write = fopen(filename_write, "w");

    // Vérifier si le second fichier a été ouvert avec succès
    if (file_write == NULL) {
        printf("Erreur lors de l'ouverture du second fichier.\n");
        fclose(file_read);
        return 1;
    }

    // Lire et écrire chaque caractère avec le décalage souhaité
    while ((c = fgetc(file_read))!= EOF) {
        shift_character(&c, shift);
        fputc(c, file_write);
    }

    // Fermer les fichiers
    fclose(file_read);
    fclose(file_write);

    printf("R%cussi.\n", 130);

    return 0;
}
