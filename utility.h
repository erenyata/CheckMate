#ifndef UTILITY_H
#define UTILITY_H

typedef enum {false,true} bool;

typedef struct {
    int id;
    char *todoDesc;
    bool done;

}Todo;

void toLower(char text[512]);
int getLineCount(FILE *fp,char *listName);
FILE *createList(const char listName[512]);
void addTodo(const char *listName,Todo todo);
void deleteTodo(const char *listName, int todoId);
void markDone(const char *listName, int todoId);
void markUndone(const char *listName, int todoId);
void listTodo(const char *listName);
int getNextId(const char *listName);
#endif
