#include "tubes.h"

int main()
{
    ListGenre LG;
    createListGenre(LG);

    int menu;

    while (menu != 0)
    {
        system("cls");
        cout << " = = = = = = = = = = = = =" << endl;
        cout << " |     PLAYLIST LAGU     |" << endl;
        cout << " = = = = = = = = = = = = =" << endl;
        cout << "" << endl;
        cout << "1. Tambah ID Genre " << endl;
        cout << "2. Tambah Lagu " << endl;
        cout << "3. Lihat List Genre " << endl;
        cout << "4. Lihat Detail Genre " << endl;
        cout << "5. Hapus ID Genre " << endl;
        cout << "6. Hapus Lagu" << endl;
        cout << "7. Lihat ID Genre Dengan Lagu Terbanyak " << endl;
        cout << "8. Lihat ID Genre Dengan Durasi Paling Lama " << endl;
        cout << "0. Keluar Program "<< endl;
        cout << "\n\nPilih menu: ";
        cin >> menu;

        switch(menu)
        {

        case(1):
            system("cls");
            menuTambahGenre(LG);
            getch();
            break;

        case(2):
            system("cls");
            menuTambahLagu(LG);
            getch;
            break;

        case(3):
            system("cls");
            printListGenre(LG);
            getch();
            break;

        case(4):
            system("cls");
            menuDetailGenre(LG);
            getch();
            break;

        case(5):
            system("cls");
            menuHapusGenre(LG);
            getch();
            break;

        case(6):
            system("cls");
            menuHapusLagu(LG);
            getch();
            break;

        case(7):
            system("cls");
            menuGenreTerbanyak(LG);
            getch();
            break;

        case(8):
            system("cls");
            menuGenreTerlama(LG);
            getch();
            break;
        }
    }
    return 0;
}
