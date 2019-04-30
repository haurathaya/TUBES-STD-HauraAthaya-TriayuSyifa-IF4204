#include "genre.h"

bool isEmptyGenre(ListGenre LG)
{
    addressGenre P = firstGenre(LG);
    if  (P == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createListGenre (ListGenre &LG)
{
    firstGenre(LG) = NULL;
    lastGenre(LG) = NULL;
}

addressGenre alokasiGenre (infotypeGenre G)
{
    addressGenre P = new elmListGenre;
    nextGenre(P) = NULL;
    prevGenre(P) = NULL;
    infoGenre(P) = G;
    return P;
}

void dealokasiGenre (addressGenre &G)
{
    delete G;
}

void insertGenre (ListGenre &LG, addressGenre G)
{
    if (firstGenre(LG) == NULL)
    {
        firstGenre(LG) = G;
        lastGenre(LG) = G;
    }
    else
    {
        prevGenre(G) = lastGenre(LG);
        nextGenre(lastGenre(LG)) = G;
        lastGenre(LG) = G;
    }
}

void deleteGenre (ListGenre &LG, addressGenre G)
{
    addressGenre Q = firstGenre(LG);
    if (Q == NULL)
    {
        cout << "LIST GENRE KOSONG!" << endl;
    }
    else
    {
        if ((firstGenre(LG) == G) && (lastGenre(LG)) == G)
        {
            firstGenre(LG) = NULL;
            lastGenre(LG) = NULL;
        }
        else if (firstGenre(LG) == G)
        {
            firstGenre(LG) = nextGenre(G);
            prevGenre(G) = NULL;
        }
        else if (lastGenre(LG) == G)
        {
            lastGenre(LG) = prevGenre(lastGenre(LG));
            nextGenre(lastGenre(LG)) = NULL;

        }
        else
        {
            nextGenre(prevGenre(G)) = nextGenre(G);
            prevGenre(nextGenre(G)) = prevGenre(G);
        }
    }
}

addressGenre searchid (ListGenre LG, string cari)
{
    addressGenre Q = firstGenre(LG);
    addressGenre out = NULL;
    bool ketemu = false;
    while (Q != NULL && !ketemu)
    {
        if (infoGenre(Q).id == cari)
        {
            out = Q;
            ketemu = true;
        }
        Q = nextGenre(Q);
    }
    return out;
}

bool cekDuplikatid (ListGenre LG, string cari)
{
    addressGenre Q = searchid(LG, cari);
    if (Q == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void printListGenre (ListGenre LG)
{
    addressGenre G = firstGenre(LG);
    int i = 1;
    cout << "\nLIST GENRE: " << endl;
    if (G == NULL)
    {
        cout << "GENRE KOSONG! " << endl;
    }
    while (G != NULL)
    {
        cout << i << "   ID GENRE : " << infoGenre(G).id << endl;
        cout << "   DESKRIPSI ID GENRE : " << infoGenre(G).descGenre << endl;
        i++;
        G = nextGenre(G);
    }
}

void printDetailGenre(addressGenre G)
{
    cout << "DETAIL GENRE  : \n" << endl;
    cout << "ID GENRE: " << infoGenre(G).id << endl;
    cout << "DESKRIPSI ID GENRE : " << infoGenre(G).descGenre << endl;
    cout << "BANYAK LAGU: " << infoGenre(G).banyakLagu << endl;
    cout << "TOTAL DURASI LAGU   : " << infoGenre(G).lamaLagu << endl;
    ListLagu LL = isi(G);
    printListLagu(LL);
}

void tambahLagu(ListGenre &LG, addressGenre G, addressLagu L)
{
    ListLagu LL = isi(G);
    insertLagu(LL, L);
    infoGenre(G).banyakLagu++;
}

addressGenre genreTerbanyak (ListGenre LG)
{
    addressGenre G = firstGenre(LG);
    addressGenre maxGenre = G;
    while(G != NULL)
    {
        if(infoGenre(maxGenre).banyakLagu <= infoGenre(G).banyakLagu)
        {
            maxGenre = G;
        }
        G = nextGenre(G);
    }
    return maxGenre;
}

addressGenre genreTerlama (ListGenre LG)
{
    addressGenre G = firstGenre(LG);
    addressGenre maxGenre = G;
    while(G != NULL)
    {
        if(infoGenre(maxGenre).lamaLagu <= infoGenre(G).lamaLagu)
        {
            maxGenre = G;
        }
        G = nextGenre(G);
    }
    return maxGenre;
}
