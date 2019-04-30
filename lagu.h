#ifndef LAGU_H_INCLUDED
#define LAGU_H_INCLUDED

#define infoLagu(L) (L)->infoLagu
#define nextLagu(L) (L)->nextLagu
#define prevLagu(L) (L)->prevLagu
#define firstLagu(L) ((L).firstLagu)
#define lastLagu(L) ((L).lastLagu)

#include <iostream>
using namespace std;

struct dataLagu
{
    string judulLagu;
    string namaPenyanyi;
    string namaAlbum;
    int durasiLagu;
};

typedef dataLagu infotypeLagu;
typedef struct elmListLagu *addressLagu;

struct elmListLagu
{
    infotypeLagu infoLagu;
    addressLagu nextLagu;
    addressLagu prevLagu;
};

struct ListLagu
{
    addressLagu firstLagu;
    addressLagu lastLagu;
};

void createListLagu (ListLagu &LL);
addressLagu alokasiLagu (infotypeLagu L);
void dealokasiLagu (addressLagu &L);
void insertLagu (ListLagu &LL, addressLagu L);
void deleteLagu (ListLagu &LL, addressLagu L);
addressLagu searchLagu (ListLagu LL, string dicari);
void printListLagu (ListLagu LL);
bool cekDuplikatLagu (ListLagu LL, string dicari);

#endif // LAGU_H_INCLUDED
