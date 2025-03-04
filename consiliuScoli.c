#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char nume[50];
    char clasa[10];
    int id;
} Elev;

typedef struct {
    char nume[100];
    char director[50];
    Elev *elevi;
    int nr_elevi;
    char tip[20];
} Scoala;

typedef struct {
    Scoala *scoli_primare;
    int nr_scoli;
    char nume_director[50];
} ConsiliuPrimare;

typedef struct {
    Scoala *scoli_gimnaziale;
    int nr_scoli;
    char nume_director[50];
    int reprezentanti_elevi;
} ConsiliuGimnaziale;

typedef struct {
    Scoala *scoli_liceale;
    int nr_scoli;
    char nume_director[50];
    int reprezentanti_elevi;
    int reputatie;
} ConsiliuLiceale;

typedef struct {
    ConsiliuPrimare consiliu_primar;
    ConsiliuGimnaziale consiliu_gimnazial;
    ConsiliuLiceale consiliu_liceal;
    char nume_director_general[50];
} ConsiliuGeneral;

void consiliu_director_general(ConsiliuGeneral consiliu) {
    printf("Directorul general: %s\n", consiliu.nume_director_general);
    printf("Directorii consiliilor:\n");
    printf("Primar: %s\n", consiliu.consiliu_primar.nume_director);
    printf("Gimnazial: %s\n", consiliu.consiliu_gimnazial.nume_director);
    printf("Liceal: %s\n", consiliu.consiliu_liceal.nume_director);
    printf("numele primului elev din a 2a scoala gimnaziala: %s\n", consiliu.consiliu_gimnazial.scoli_gimnaziale[1].elevi[0].nume);
}

void scoala_director_consiliu(ConsiliuGeneral consiliu, const char *nume_director) {
    for (int i = 0; i < consiliu.consiliu_primar.nr_scoli; i++) {
        if (strcmp(consiliu.consiliu_primar.scoli_primare[i].director, nume_director) == 0) {
            printf("Directorul %s conduce scoala: %s (primara)\n", nume_director, consiliu.consiliu_primar.scoli_primare[i].nume);
            return;
        }
    }
    for (int i = 0; i < consiliu.consiliu_gimnazial.nr_scoli; i++) {
        if (strcmp(consiliu.consiliu_gimnazial.scoli_gimnaziale[i].director, nume_director) == 0) {
            printf("Directorul %s conduce scoala: %s (gimnaziala)\n", nume_director, consiliu.consiliu_gimnazial.scoli_gimnaziale[i].nume);
            return;
        }
    }
    for (int i = 0; i < consiliu.consiliu_liceal.nr_scoli; i++) {
        if (strcmp(consiliu.consiliu_liceal.scoli_liceale[i].director, nume_director) == 0) {
            printf("Directorul %s conduce scoala: %s (liceala)\n", nume_director, consiliu.consiliu_liceal.scoli_liceale[i].nume);
            return;
        }
    }
    printf("Directorul %s nu a fost gasit in niciun consiliu.\n", nume_director);
}

void scoala_director_general(ConsiliuGeneral consiliu) {
    printf("Directorul general %s coordoneaza urmatoarele scoli:\n", consiliu.nume_director_general);
    for (int i = 0; i < consiliu.consiliu_primar.nr_scoli; i++) {
        printf("- %s (primara)\n", consiliu.consiliu_primar.scoli_primare[i].nume);
    }
    for (int i = 0; i < consiliu.consiliu_gimnazial.nr_scoli; i++) {
        printf("- %s (gimnaziala)\n", consiliu.consiliu_gimnazial.scoli_gimnaziale[i].nume);
    }
    for (int i = 0; i < consiliu.consiliu_liceal.nr_scoli; i++) {
        printf("- %s (liceala)\n", consiliu.consiliu_liceal.scoli_liceale[i].nume);
    }
}

int main() {
    ConsiliuGeneral consiliu = {
        .nume_director_general = "Popescu Ion",
        .consiliu_primar = {
            .nr_scoli = 2,
            .nume_director = "Ionescu Maria",
            .scoli_primare = (Scoala[]){
                {"Scoala Primara nr. 1", "Director 1", NULL, 0, "primara"},
                {"Scoala Primara nr. 2", "Director 2", NULL, 0, "primara"}
            }
        },
        .consiliu_gimnazial = {
            .nr_scoli = 1,
            .nume_director = "Georgescu Andrei",
            .scoli_gimnaziale = (Scoala[]){
                {"Scoala Gimnaziala nr. 1", "Director 3", NULL, 0, "gimnaziala"}
            }
        },
        .consiliu_liceal = {
            .nr_scoli = 1,
            .nume_director = "Dumitru Vasile",
            .scoli_liceale = (Scoala[]){
                {"Liceul Teoretic nr. 1", "Director 4", NULL, 0, "liceala"}
            }
        }
    };

    consiliu_director_general(consiliu);
    scoala_director_consiliu(consiliu, "Georgescu Andrei");
    scoala_director_general(consiliu);

    return 0;
}
