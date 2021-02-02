//
// Created by ulysses on 5/13/17.
//
#include<stdio.h>
#include<stdlib.h>
#define CSIZE 2
struct name{
    char first_name[20];
    char last_name[20];
};
struct student{
    struct name student_name;
    double grade_scores[3];
    double grade_average;
};
void print_structure(struct student *begin, const struct student *end, int struct_size);
int main(void){
    struct student list[CSIZE];
    printf("The following message will prompt you to enter in some information.\n");
    for (int i = 0; i < CSIZE; i++){
        printf("For student %d, please enter their first and last names.\n", i + 1);
        scanf("%s %s", list[i].student_name.first_name, list[i].student_name.last_name);
        printf("Now enter their scores for Physics, Math and History.\n");
        scanf("%lf %lf %lf", &list[i].grade_scores[0], &list[i].grade_scores[1], &list[i].grade_scores[2]);

        list[i].grade_average = (list[i].grade_scores[0] + list[i].grade_scores[1] + list[i].grade_scores[2])/3.0;
    }
    print_structure(&list[0], &list[CSIZE - 1], sizeof(struct student));

    return 0;
}
void print_structure(struct student *begin, const struct student *end, int struct_size){
    struct student *pointer = begin;
    double class_average = 0;
    system("clear");
    while (pointer <=end){
        printf("Name: %s %s\nGrade Average: %.2f\n\n", pointer->student_name.first_name, pointer->student_name.last_name,
        pointer->grade_average);
        class_average += pointer->grade_average;
        pointer++;
    }
    printf("The class average is %.2f", class_average / CSIZE);
}
