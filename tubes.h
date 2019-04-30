#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <conio.h>
#include <stdlib.h>
#include "genre.h"

void menuTambahGenre (ListGenre &LG);
void menuTambahLagu (ListGenre &LG);
void menuDetailGenre (ListGenre LG);
void menuHapusGenre (ListGenre &LG);
void menuHapusLagu (ListGenre &LG);
void menuGenreTerbanyak (ListGenre &LG);
void menuGenreTerlama (ListGenre &LG);

#endif // TUBES_H_INCLUDED
