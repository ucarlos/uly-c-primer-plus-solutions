//
// Created by ulysses on 5/8/17.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CLASS_SIZE 6
const char *player_class [] = {"Knight", "Mage", "Paldin", "Warrior", "Gunslinger", "Scholar"};
struct player_info{
    char name[20];
    char class[20];
    int health;
    int magic;
};

void game_over(char *player_name);
void initalize_character(struct player_info *pointer);
void display_class(void);
int check_error(char *name, int class);
void display_character(struct player_info *pointer);

int main(void){
    struct player_info player;
    initalize_character(&player);
    display_character(&player);
    return 0;
}

void initalize_character(struct player_info *pointer){
    char input, name[20];
    int class, error = 1;
    do{
        if (!error) printf("There seems to be an error. Please try again.\n");
        printf("Please name your character.\n");
        scanf("%s", name);
        printf("Please choose your class.\n");
        display_class();
        scanf("%d", &class);
        class--;

        error = check_error(name, class);
    }while(!error);
    strncpy(pointer->name, name, 20);
    strcpy(pointer->class, player_class[class]);

}
void display_class(){
    for (int i = 0; i < CLASS_SIZE; i++){
        printf((i % 2 == 0)? "\n%d) %s\t":"%d) %s\t",i + 1, player_class[i]);
    }
}
int check_error(char *name, int class){
    int length = (int)strlen(name);
    return (0 < length && length < 20) && (0 <= class && class < 6);
}
void display_character(struct player_info *pointer){
    printf("--------------------------------------------------\n");
    printf("Player Name: %s\t Class: %s\n", pointer->name, pointer->class);
    printf("--------------------------------------------------\n");
}
