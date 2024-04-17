#include "../Headers/LEA.h"

void File_Menu(){
    int User_Option;
    char File_Name[35];
    FILE *ptr;
    printf("Enter the file name: ");
    gets(File_Name);
    File_Receive(&ptr,File_Name);
    while(1){
        printf("[1] Read File\n ");
        printf("[2] OverWrite File\n");
        printf("[3] Delete Text\n");
        printf("[4] Clear the Screen\n");
        scanf("%d",&User_Option);
        if(User_Option==1){
            File_Read(ptr);
            fclose(ptr);
        }else if(User_Option==2){
            ptr = fopen(File_Name,"r+");
            printf("Enter Position: ");
            scanf("%d", &User_Option);
            File_OverWrite(ptr,User_Option);
        }else if(User_Option==4){
            system("cls");
        }else{
            printf("Finishing the execution");
            break;
        }
    }


}

void File_Receive(FILE **ptr,char File_Name[]){
    *ptr = fopen(File_Name,"r+");
    if (*ptr == NULL) {
        printf("Error\n");
        exit(1);
    }else{
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
    fseek(ptr,0,SEEK_SET);
}

void File_OverWrite(FILE *ptr, int position){
    fseek(ptr, position, SEEK_SET);
    char input[100];
    //printf("Enter New String; ");
    fgets(input, sizeof(input), stdin);
    fputs(input, ptr);
    fclose(ptr);

}