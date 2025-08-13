#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utility.h"

void toLower(char text[512]){
    for(int i=0;i<strlen(text);i++){
        text[i] = tolower((unsigned char)text[i]);
    }
}

int getLineCount(FILE *fp,char *listName){
    fp = fopen(listName,"r");
    if (fp == NULL){
        printf("Can not open file.");
        return -1;
    }else {
        int lines = 0;
        char line[512];
        while (fgets(line,sizeof(line),fp)!=NULL){
            lines++;
        }
        return lines;
    }
}

FILE *createList(const char listName[512]){
    FILE *fp;
    fp = fopen(listName,"a");
    if (fp == NULL){
        printf("Can not open file.");
        return NULL;
    }else {
        return fp;
    }
}

void addTodo(const char *listName,Todo todo){
    FILE *fp = fopen(listName,"a");
    if(fp == NULL){
        printf("Can not open file.");
        return;
    } else {
        fprintf(fp,"%d.%s, done:%s\n",todo.id,todo.todoDesc,todo.done ? "true":"false");
        printf("\n%d.%s, done:%s",todo.id,todo.todoDesc,todo.done ? "true":"false");
        fclose(fp);
    }

}

void deleteTodo(const char *listName, int todoId){
    FILE *fp;
    fp = fopen(listName,"r");
    FILE *temp;
    temp = fopen("temp.txt","w");
    if(fp == NULL || temp == NULL){
        printf("Can not open file.");
        return;
    }else {

        char line[512];
        while(fgets(line, sizeof(line), fp) != NULL){
            int lineId;
            sscanf(line, "%d.", &lineId);
            if(lineId == todoId){
                continue; // delete lines
            }
            fputs(line, temp); // write remaining
        }
        fclose(fp);
        fclose(temp);

        remove(listName);
        rename("temp.txt", listName);

    }
}

void markDone(const char *listName, int todoId){
    FILE *fp = fopen(listName,"r");
    FILE *temp = fopen("temp.txt","w");
    if(!fp || !temp){
        printf("Can not open file.");
        return;
    }

    char line[512];
    while(fgets(line,sizeof(line),fp)){
        int lineId;
        char desc[512];
        char doneStr[10];

        // split the line
        sscanf(line, "%d.%[^,], done:%s", &lineId, desc, doneStr);

        if(lineId == todoId){
            fprintf(temp, "%d.%s, done:true\n", lineId, desc);
        } else {
            fputs(line, temp);
        }
    }

    fclose(fp);
    fclose(temp);
    remove(listName);
    rename("temp.txt", listName);
}

void markUndone(const char *listName, int todoId){
    FILE *fp = fopen(listName,"r");
    FILE *temp = fopen("temp.txt","w");
    if(!fp || !temp){
        printf("Can not open file.");
        return;
    }

    char line[512];
    while(fgets(line,sizeof(line),fp)){
        int lineId;
        char desc[512];
        char doneStr[10];

        // split the line
        sscanf(line, "%d.%[^,], done:%s", &lineId, desc, doneStr);

        if(lineId == todoId){
            fprintf(temp, "%d.%s, done:false\n", lineId, desc);
        } else {
            fputs(line, temp);
        }
    }

    fclose(fp);
    fclose(temp);
    remove(listName);
    rename("temp.txt", listName);
}

void listTodo(const char *listName){
    FILE *fp = fopen(listName,"r");
    if (fp == NULL){
        printf("Can not open file.");
        return;
    }else {

        char line[512];
        while(fgets(line,sizeof(line),fp)!=NULL){
            printf("%s\n",line);
        }
        fclose(fp);
    }
}

int getNextId(const char *listName){
    FILE *fp = fopen(listName, "r");
    if(!fp) return 1; // dosya yoksa ID = 1

    char line[512];
    int lastId = 0;
    while(fgets(line, sizeof(line), fp)){
        int id;
        sscanf(line, "%d.", &id);
        if(id > lastId) lastId = id;
    }

    fclose(fp);
    return lastId + 1;
}
