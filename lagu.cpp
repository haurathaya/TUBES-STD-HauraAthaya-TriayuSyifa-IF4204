#include "lagu.h"

void createListLagu (ListLagu &LL)
{
    firstLagu(LL) = NULL;
    lastLagu(LL) = NULL;
}

addressLagu alokasiLagu (infotypeLagu L)
{
    addressLagu P = new elmListLagu;
    nextLagu(P) = NULL;
    prevLagu(P) = NULL;
    infoLagu(P) = L;
    return P;
}

void dealokasiLagu (addressLagu &L)
{
    delete L;
}

void insertLagu (ListLagu &LL, addressLagu L)
{
    if (firstLagu(LL) == NULL)
    {
        firstLagu(LL) = L;
        lastLagu(LL) = L;
    }
    else
    {
        prevLagu(L) = lastLagu(LL);
        nextLagu(lastLagu(LL)) = L;
        lastLagu(LL) = L;
    }
}

void deleteLagu (ListLagu &LL, addressLagu L)
{
    addressLagu Q = firstLagu(LL);
    if (Q == NULL)
    {
        cout << "LIST GENRE KOSONG!" << endl;
    }
    else
    {
        if ((firstLagu(LL) == L) && (lastLagu(LL)) == L)
        {
            firstLagu(LL) = NULL;
            lastLagu(LL) = NULL;
        }
        else if (firstLagu(LL) == L)
        {
            firstLagu(LL) = nextLagu(L);
            prevLagu(L) = NULL;
        }
        else if (lastLagu(LL) == L)
        {
            lastLagu(LL) = prevLagu(lastLagu(LL));
            nextLagu(lastLagu(LL)) = NULL;

        }
        else
        {
            nextLagu(prevLagu(L)) = nextLagu(L);
            prevLagu(nextLagu(L)) = prevLagu(L);
        }
    }
}

addressLagu searchLagu (ListLagu LL, string dicari)
{
    addressLagu Q = firstLagu(LL);
    addressLagu out = NULL;
    bool ketemu = false;
    while (Q != NULL && !ketemu)
    {
        if (infoLagu(Q).judulLagu == dicari)
        {
            out = Q;
            ketemu = true;
        }
        Q = nextLagu(Q);
    }
    return out;
}

void printListLagu (ListLagu LL)
{
    addressLagu L = firstLagu(LL);
    int i = 1;
    cout << "\nLIST LAGU: " << endl;
    if(L == NULL)
    {
        cout << "LAGU KOSONG! " << endl;
    }
    while(L != NULL)
    {
        cout << i << ". JUDUL LAGU : " << infoLagu(L).judulLagu << endl;
        cout << "   NAMA PENYANYI : " << infoLagu(L).namaPenyanyi << endl;
        cout << "   NAMA ALBUM : " << infoLagu(L).namaAlbum  << endl;
        cout << "   DURASI LAGU : " << infoLagu(L).durasiLagu << " menit" << endl;
        i++;
        L = nextLagu(L);
    }
}

bool cekDuplikatLagu (ListLagu LL, string dicari)
{
    addressLagu Q = searchLagu(LL, dicari);
    if (Q == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

