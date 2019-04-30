#include "tubes.h"

void menuTambahGenre(ListGenre &LG)
{
    infotypeGenre X;
    cout << "MENU TAMBAH GENRE\n" << endl;
    cout << "ID Genre: ";
    cin >> X.id;
    cout << "Deskripsi Genre: ";
    cin >> X.descGenre;
    if (cekDuplikatid(LG, X.id))
    {
        cout << "\n GENRE ADA DUPLIKAT!\n" << endl;
    }
    else
    {
        addressGenre G = alokasiGenre(X);
        insertGenre(LG, G);
        cout << "\nINPUT SUKSES!" << endl;
    }
}

void menuTambahLagu(ListGenre &LG)
{
    printListGenre(LG);
    if (!isEmptyGenre(LG))
    {
        string cari;
        cout << "MASUKKAN ID GENRE: ";
        cin >> cari;
        addressGenre G = searchid(LG, cari);
        if (G != NULL)
        {
            infotypeLagu Lagu;
            printListLagu(isi(G));
            cout << "\n TAMBAH DATA LAGU: " << endl;
            cout << "JUDUL LAGU : " ;
            cin >> Lagu.judulLagu;
            cout << "NAMA PENYANYI : " ;
            cin >> Lagu.namaPenyanyi;
            cout << "NAMA ALBUM: " ;
            cin >> Lagu.namaAlbum;
            cout << "DURASI LAGU: " ;
            cin >> Lagu.durasiLagu;

            if (!cekDuplikatLagu(isi(G), Lagu.judulLagu))
            {
                addressLagu L = alokasiLagu(Lagu);
                insertLagu(isi(G),L);
                infoGenre(G).banyakLagu++;
                infoGenre(G).lamaLagu+=Lagu.durasiLagu;
                cout <<"\nINPUT SUKSES!" << endl;
            }
            else
            {
                cout <<"\nLAGU SUDAH ADA!\n" << endl;
            }
        }
    }
    getch();
}

void menuDetailGenre(ListGenre LG)
{
    printListGenre(LG);
    if(!isEmptyGenre(LG))
    {
        string cari;
        cout <<"\nPILIH ID GENRE: ";
        cin >> cari;
        addressGenre P = searchid(LG, cari);
        system("cls");
        if(P != NULL)
        {
            printDetailGenre(P);
        }
        else
        {
            cout << "ID GENRE TIDAK DITEMUKAN!" << endl;
        }
    }
}

void menuHapusGenre(ListGenre &LG)
{
    printListGenre(LG);
    if(!isEmptyGenre(LG))
    {
        string cari;
        cout <<"\nPILIH ID GENRE: ";
        cin >> cari;
        addressGenre P = searchid(LG, cari);
        system("cls");
        if(P != NULL)
        {
            deleteGenre(LG, P);
            cout << "\nGENRE SUKSES DIHAPUS" << endl;
        }
        else
        {
            cout << "NAMA TIDAK DITEMUKAN!" << endl;
        }
    }
}

void menuHapusLagu(ListGenre &LG)
{
    printListGenre(LG);
    if(!isEmptyGenre(LG))
    {
        string cari;
        cout <<"\nPILIH ID GENRE: ";
        cin >> cari;
        addressGenre G = searchid(LG, cari);
        system("cls");
        if (G != NULL)
        {
            printDetailGenre(G);
            string cariLagu;
            cout <<"\nPILIH JUDUL LAGU YANG AKAN DIHAPUS: ";
            cin >> cariLagu;
            addressLagu PL = searchLagu(isi(G), cariLagu);
            if (PL != NULL)
            {
                infoGenre(G).banyakLagu--;
                deleteLagu(isi(G), PL);
                cout << "\nLAGU SUKSES DIHAPUS!" << endl;
            }
        }
        else
        {
            cout << " ID GENRE TIDAK DITEMUKAN!" << endl;
        }
    }
}

void menuGenreTerbanyak(ListGenre &LG)
{
    addressGenre G = genreTerbanyak(LG);
    if (G == NULL)
    {
        cout << "\nDATA GENRE KOSONG!" << endl;
    }
    else
    {
        cout << "GENRE DENGAN LAGU TERBANYAK - ";
        printDetailGenre(G);
    }
}

void menuGenreTerlama (ListGenre &LG)
{
    addressGenre G = genreTerlama(LG);
    if (G == NULL)
    {
        cout << "\nDATA GENRE KOSONG!" << endl;
    }
    else
    {
        cout << "GENRE DENGAN LAGU TERBANYAK - ";
        printDetailGenre(G);
    }
}
