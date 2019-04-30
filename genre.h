#ifndef GENRE_H_INCLUDED
#define GENRE_H_INCLUDED

#define infoGenre(G) (G)->infoGenre
#define nextGenre(G) (G)->nextGenre
#define prevGenre(G) (G)->prevGenre
#define isi(G) G->isi
#define firstGenre(G) ((G).firstGenre)
#define lastGenre(G) ((G).lastGenre)

#include <iostream>
using namespace std;

#include "lagu.h"

struct dataGenre
{
    string id;
    string descGenre;
    int banyakLagu = 0;
    int lamaLagu = 0;
};

typedef dataGenre infotypeGenre;
typedef struct elmListGenre *addressGenre;

struct elmListGenre
{
    infotypeGenre infoGenre;
    addressGenre nextGenre;
    addressGenre prevGenre;
    ListLagu isi;
};

struct ListGenre
{
    addressGenre firstGenre;
    addressGenre lastGenre;
};

bool isEmptyGenre(ListGenre LG);
void createListGenre (ListGenre &LG);
addressGenre alokasiGenre (infotypeGenre G);
void dealokasiGenre (addressGenre &G);
void insertGenre (ListGenre &LG, addressGenre G);
void deleteGenre (ListGenre &LG, addressGenre G);
addressGenre searchid (ListGenre LG, string cari);
bool cekDuplikatid (ListGenre LG, string cari);
void printListGenre (ListGenre LG);
void printDetailGenre(addressGenre G);
void tambahLagu(ListGenre &LG, addressGenre G, addressLagu L);
addressGenre genreTerbanyak (ListGenre LG);
addressGenre genreTerlama (ListGenre LG);

#endif // GENRE_H_INCLUDED
