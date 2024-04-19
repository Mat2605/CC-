#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void File_Menu();
void Menu_Options();
void File_Receive(FILE **ptr,char File_Name[]);
void File_Read(FILE *ptr);
void File_Remove(FILE *ptr,int position);
int File_WordsNumber(FILE *ptr);
void File_OverWrite(FILE *ptr,int position);
void File_InsertWord(FILE *ptr, int position, const char *word);