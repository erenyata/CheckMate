#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include <stdbool.h>


int main(int argc, char *argv[])
{
    const char *listName = "todo.txt";

    // En az 2 argüman gerekli
    if(argc < 2){
        printf("USAGE: ./todo (add,delete,list,done,undone) (string or line id)\n");
        return -1;
    }

    toLower(argv[1]);

    if(strcmp(argv[1],"add") == 0){
        if(argc != 3){
            printf("USAGE: ./todo add \"task description\"\n");
            return -1;
        }

        Todo todo;
        todo.id = getNextId(listName);

        // argv[2]’yi güvenli þekilde kopyala
        todo.todoDesc = malloc(strlen(argv[2]) + 1);
        if(!todo.todoDesc){
            printf("Memory allocation failed.\n");
            return -1;
        }
        strcpy(todo.todoDesc, argv[2]);
        todo.done = false;

        addTodo(listName, todo);

        free(todo.todoDesc); // hafýzayý temizle

    } else if(strcmp(argv[1],"delete") == 0 || strcmp(argv[1],"done") == 0 || strcmp(argv[1],"undone") == 0){
        if(argc != 3){
            printf("USAGE: ./todo %s <id>\n", argv[1]);
            return -1;
        }

        int id = atoi(argv[2]);
        if(id <= 0){
            printf("Invalid ID.\n");
            return -1;
        }

        if(strcmp(argv[1],"delete") == 0){
            deleteTodo(listName, id);
        } else if(strcmp(argv[1],"done") == 0){
            markDone(listName, id);
        } else if(strcmp(argv[1],"undone") == 0){
            markUndone(listName, id);
        }

    } else if(strcmp(argv[1],"list") == 0){
        listTodo(listName);

    } else {
        printf("Unknown Command.\nUSAGE: ./todo (add,delete,list,done,undone) (string or line id)\n");
        return -1;
    }

    return 0;
}
