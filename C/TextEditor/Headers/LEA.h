#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void File_Menu();
void File_Receive(FILE **ptr,char File_Name[]);
void File_Read(FILE *ptr);
void File_OverWrite(FILE *ptr,int position);