//
// Created by ulysses on 5/13/17.
// Some edits were made on 3/14/20: created clear_buffer()
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <unistd.h>
#define SEAT_CAP 12
typedef struct passenger{
    unsigned int seat_id;
    _Bool seat_taken;
    char seat_first_name[20];
    char seat_last_name[20];
}Passenger;

void main_menu_options(void);
void show_empty_seats(void);
void show_alpha_seats(void);
void initialize_seats(void);
int compare(const Passenger *pointer1, const Passenger *pointer2);
void assign_passenger(void);
void delete_passenger(void);
void main_menu(void);
inline static void clear_buffer();

Passenger list[12];


inline static void clear_buffer(){
    char c;
    
    // flush buffer first
    while ((c = getchar()) != '\n' && c != EOF)
        continue;

}



int main(void){
    initialize_seats();
    main_menu();
    return 0;
}


void main_menu_options(void){
    printf("a) Show list of empty seats\n"
                   "b) Show Alphabetical list of seats\n"
                   "c) Assign a customer to a seat assignment\n"
    "d) Delete a seat assignment\n"
                   "e) Quit\n");
}
void show_empty_seats(void){
    void (*function_pointer)(void);
    system("clear");
    char input;
    int empty_seats_num = 0;
    for (int i = 0; i < SEAT_CAP;i++){
        if (list[i].seat_taken != 1)
            empty_seats_num++;
    }
    printf((empty_seats_num < 2)? ((empty_seats_num == 0)? "There are no empty seats." :
                                   "There is only one empty seat.")
           :"There are %d empty seats.", empty_seats_num);
    printf("They are displayed below.\n");
    printf("ID Number\n");
    for (int i = 0; i < SEAT_CAP; i++){
        if (list[i].seat_taken != 1)
            printf("%d\n", list[i].seat_id);
    }
    printf("To return to the main menu, press b.\n");
    input = getchar();

    while (tolower(input) != 'b')
        input = getchar();

    function_pointer = main_menu;
    function_pointer();
}
void show_alpha_seats(void){
    void (*function_pointer)(void);
    system("clear");
    qsort(&list[0], SEAT_CAP, sizeof(Passenger), compare);

    printf("First Name \tLast Name\tID Number\t Is Occupied?\n");
    for (int i = 0; i < SEAT_CAP; i++){
        printf("%s\t\t%s\t\t", list[i].seat_first_name, list[i].seat_last_name);
        printf("%d\t\t", list[i].seat_id);
        printf((!list[i].seat_taken)? "No\n" :"Yes\n");
    }
    printf("To return to the main menu, press b.\n");
    char input = getchar();

    while (tolower(input) != 'b')
        input = getchar();

    function_pointer = main_menu;
    function_pointer();
}
void initialize_seats(void){
    for (int i = 0; i < SEAT_CAP; i++) {
        strcpy(list[i].seat_first_name, "NOT");
        strcpy(list[i].seat_last_name, "TAKEN");
        list[i].seat_taken = 0;
        list[i].seat_id = i + 1;
    }
}
int compare(const Passenger *pointer1, const Passenger *pointer2){
    // Rather redundant.
    /* if (!(strcmp(pointer1->seat_last_name, pointer2->seat_last_name))) */
    /*     return strcmp(pointer1->seat_first_name, pointer2->seat_first_name); */
    /* else return strcmp(pointer1->seat_last_name, pointer2->seat_last_name); */

    // Removes an additional strcmp call.
    int result = strcmp(pointer1->seat_last_name, pointer2->seat_last_name);
    if (!result)
	return strcmp(pointer1->seat_first_name, pointer2->seat_first_name);
    else
	return result;    
    
    
}
void main_menu(void){
    void (*function_pointer)(void);
    char input;
    system("clear");
    printf("Please make a selection from the following options:\n");
    main_menu_options();
    input = (char)getchar();

    switch(input){
        case 'a':
            function_pointer = show_empty_seats;break;
        case 'b':
            function_pointer = show_alpha_seats;break;
        case 'c':
            function_pointer = assign_passenger;break;
        case 'd':
            function_pointer = delete_passenger;break;
        case 'e':
            exit(EXIT_SUCCESS);
        default:
            function_pointer = main_menu;

    }
    function_pointer();
}
void assign_passenger(void){
    void (*function_pointer)(void);
    system("clear");
    
    printf("If you have selected this by accident, press \"b\" to return to the main menu.\n"
                   "Otherwise, press any key to continue.");

    clear_buffer();
    
    char input = getchar();
    if (input == 'b') {
        function_pointer = main_menu;
        function_pointer();
    }
    int temp_id;
    char first_temp[20], last_temp[20];
    printf("Please enter the id, first name, and last name.\n");
    scanf("%d %s %s", &temp_id, first_temp, last_temp);
    while (!(1 <= temp_id && temp_id <= SEAT_CAP) || (strlen(first_temp) >= 20) || (strlen(last_temp) >= 20)){
        printf("You have entered incorrect information. Try again.\n");
        scanf("%d %s %s", &temp_id, first_temp, last_temp);
    }
    strncpy(list[temp_id].seat_first_name, first_temp, 20);
    strncpy(list[temp_id].seat_last_name, last_temp, 20);
    list[temp_id].seat_taken = 1;

    printf("Passenger added! Returning to main menu...\n");
    sleep(5);
    function_pointer = main_menu;
    function_pointer();

}
void delete_passenger(void){
    char input;
    void (*function_pointer)(void);
    system("clear");
    printf("If you have selected this by accident, press \"b\" to return to the main menu.\n"
                   "Otherwise, press any key to continue.");

    clear_buffer();

    input = getchar();
    if (input == 'b') {
        function_pointer = main_menu;
        function_pointer();
    }

    int temp_id;
    printf("Please enter the Passenger id:\n");
    scanf("%d", &temp_id);
    while (!(1 <= temp_id && temp_id <= SEAT_CAP)){
        printf("Invalid id number. Try again.");
        scanf("%d", &temp_id);
    }
    printf("Are you sure you want to delete this passenger[y/n]?\n");

    //flush buffer again
    clear_buffer();

    input = getchar();
    if ((input != 'y')){
        printf("Returning to main menu...\n");
        sleep(5);
        function_pointer = main_menu;
        function_pointer();
    }
    strcpy(list[temp_id].seat_first_name, "NOT");
    strcpy(list[temp_id].seat_last_name, "TAKEN");
    list[temp_id].seat_taken = 0;

    printf("Passenger removed. Returning to main menu...\n");
    sleep(5);
    function_pointer = main_menu;
    function_pointer();


}
