#include "../Headers/LEA.h"


void Menu_Options(){
    printf("\t\t\t\t[1] Read File\n ");
    printf("\t\t\t\t[2] OverWrite File\n");
    printf("\t\t\t\t[3] Delete Text\n");
    printf("\t\t\t\t[4] Clear the Screen\n");
    printf("\t\t\t\t[5] Count File Words\n");
    printf("\t\t\t\t[6] Insert Word\n");
    printf("\t\t\t\t[0] Exit\n");
    printf("\t\tUser: ");
}
void File_Menu(){
    int User_Option,position;
    char File_Name[35],NewWord[50];
    FILE *ptr;
    printf("\t\t\t\tEnter the file name: ");
    gets(File_Name);
    File_Receive(&ptr,File_Name);
    while(1){
        fseek(ptr,0,SEEK_SET);
        Menu_Options();
        scanf("%d",&User_Option);
        switch (User_Option){
        case 1:
            File_Read(ptr);
            break;
        case 2:
            ptr = fopen(File_Name,"r+");
            printf("Enter Position: ");
            scanf("%d", &User_Option);
            File_OverWrite(ptr,User_Option);
            break;
        case 3:
            printf("Enter Position: ");
            scanf("%d", &User_Option);
            File_Remove(ptr,User_Option);
            break;
        case 4:
            system("cls");
            break;
        case 5:
            printf("[~%d~]",File_WordsNumber(ptr));
            break;
        case 6:
            printf("\t\tDigite uma palavra a ser inserida:  ");
            scanf("%s",&NewWord);
            printf("\t\tDigite a posição a ser inserida a nova palavra: ");
            scanf("%d",&position);
            File_InsertWord(ptr,position,NewWord);    
            break;
        case 0:
            printf("Finishing the execution");
            exit(1);
        }

        }
    }


void File_Receive(FILE **ptr,char File_Name[]){
    *ptr = fopen(File_Name,"r+");
    if (*ptr == NULL) {
        printf("Error\n");
        exit(1);
    }else{
        printf("File Open\n");
        return;
    }
}

void File_Read(FILE *ptr){
    char buffer[100];
    while (fgets(buffer, 100, ptr) != NULL) {
        char* palavra = strtok(buffer, " \t\n");
        while (palavra != NULL) {
            printf(" %s ",palavra);
            palavra = strtok(NULL, " \t\n");
        }
    }
    printf("\n");
}
void File_Remove(FILE *ptr, int position) {
    fseek(ptr, position, SEEK_SET);
    char buffer[1000];
    int bytesRead = fread(buffer, 1, sizeof(buffer), ptr);
    int start = position;
    int end = position;
    while (start > 0 && buffer[start - 1] != ' ' && buffer[start - 1] != '\n') {
        start--;
    }
    while (end < bytesRead && buffer[end] != ' ' && buffer[end] != '\n') {
        end++;
    }
    fseek(ptr, start, SEEK_SET);
    for (int i = start; i < end; i++) {
        fputc(' ', ptr);
    }
}


int File_WordsNumber(FILE *ptr){
    int Words = 0,inWord = 0;
    char caractere;
    fseek(ptr,0,SEEK_SET);
    while((caractere = fgetc(ptr)) != EOF){
        if(caractere == ' ' || caractere == '\n' || caractere == '\t'){
            inWord = 0;
        } else if (!inWord) {
            Words++;
            inWord = 1; 
        }
    }
    return Words;
}

void File_OverWrite(FILE *ptr, int position){
    fseek(ptr, position, SEEK_SET);
    char input[100];
    fgets(input, sizeof(input), stdin);
    fputs(input, ptr);
}

void File_InsertWord(FILE *ptr, int position, const char *word){
    fseek(ptr, 0, SEEK_END);
    long fileSize = ftell(ptr);
    if (position < 0 || position > fileSize) {
        printf("Not Valid\n");
        return;
    }
    fseek(ptr, position, SEEK_SET);
    char buffer[1000]; 
    int bytesRead = fread(buffer, 1, sizeof(buffer), ptr); 

    fseek(ptr, position, SEEK_SET);
    fprintf(ptr, " %s ", word); 

    if (bytesRead > 0) {
        fwrite(buffer, 1, bytesRead, ptr);
    }
}


