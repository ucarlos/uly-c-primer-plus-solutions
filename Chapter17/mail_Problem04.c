//
// Created by ulysses on 7/2/17.
//
#include "queue.h"
#include <time.h>
#define MIN_PER_HR 60.0

bool newcustomer(double x);
Item customertime(long when);

typedef struct booth{
    Queue line;
    Item temp; // new customer data
    int hours; // hours of simulation
    int perhour; // average # of arrivals per hour
    long cycle, cyclelimit; // loop counter, limit
    long turnaways; // turned away by full queue
    long customers; // joined the queue
    long served; // served during the simulation
    long sum_line; // cumulative line length
    int wait_time ; // time until Sigmund is free
    double min_per_cust; // average time between arrivals
    long line_wait; // cumulative time in line
}Booth;
void ProcessCustomer(Booth *pbooth);
void InitializeBooth(Booth *pbooth);
void PrintBooth(Booth *pbooth);
void EmptyBooth(Booth *pbooth);
int main(void){
    Booth booth1, booth2;

    InitializeBooth(&booth1);
    InitializeBooth(&booth2);

    srand((unsigned int)time(0)); // random initializing of rand().
    puts("Case Study: Sigmund Lander's Advise Booths");
    puts("Enter the number of simulation hours for both booths:");
    scanf("%d %d", &booth1.hours, &booth2.hours);
    booth1.cyclelimit = MIN_PER_HR * booth1.hours;
    booth2.cyclelimit = MIN_PER_HR * booth2.hours;
    puts("Enter the average number of customers per hour for both booths:");
    scanf("%d %d", &booth1.perhour, &booth2.perhour);
    booth1.min_per_cust = MIN_PER_HR / booth1.perhour;
    booth2.min_per_cust = MIN_PER_HR / booth2.perhour;

    ProcessCustomer(&booth1);
    ProcessCustomer(&booth2);

    PrintBooth(&booth1);
    PrintBooth(&booth2);

    EmptyBooth(&booth1);
    EmptyBooth(&booth2);

    puts("Bye.");

    return 0;
}
// x= average time, in minutes, between customers
//return value is true if customer shows up this minute.
bool newcustomer(double x){
    return ((rand() * x / RAND_MAX) < 1);
}

//When is the time at which the customer arrives
//Function returns an Item structure with the arrival time
//set to when and the processing time set to a random value
//is in the range i - 3.
Item customertime(long when){
    Item cust;
    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;
    return cust;
}
void ProcessCustomer(Booth *pbooth){
    for (pbooth->cycle = 0; pbooth->cycle < pbooth->cyclelimit;
            pbooth->cycle++) {
        if (newcustomer(pbooth->min_per_cust)) {
            if (QueueIsFull(&pbooth->line))
                pbooth->turnaways++;
            else {
                pbooth->customers++;
                pbooth->temp = customertime(pbooth->cycle);
                EnQueue(pbooth->temp, &pbooth->line);
            }
        }
        if (pbooth->wait_time <= 0 && !QueueIsEmpty(&pbooth->line)) {
            DeQueue(&pbooth->temp, &pbooth->line);
            pbooth->wait_time = pbooth->temp.processtime;
            pbooth->line_wait += (pbooth->cycle - pbooth->temp.arrive);
            pbooth->served++;
        }
        if (pbooth->wait_time > 0) pbooth->wait_time--;
        pbooth->sum_line += QueueItemCount(&pbooth->line);
    }
}
void InitializeBooth(Booth *pbooth){
    InitializeQueue(&(pbooth)->line);
    (pbooth)->turnaways = (pbooth)->customers = 0;
    (pbooth)->served = (pbooth)->sum_line = 0;
    (pbooth)->wait_time = (pbooth)->line_wait = 0;
}
void PrintBooth(Booth *pbooth){
    if (pbooth->customers > 0){
        printf("Customers accepted: %ld\n", pbooth->customers);
        printf("Customers served: %ld\n", pbooth->served);
        printf("Customers turned away: %ld\n", pbooth->turnaways);
        printf("Average queue size: %.2f\n", (double)pbooth->sum_line
        / pbooth->cyclelimit);
        printf("Avearge wait time: %.2f\n\n", (double)pbooth->line_wait
        / pbooth->served);
    }
    else puts("No customers.\n\n");
}
void EmptyBooth(Booth *pbooth){
    EmptyTheQueue(&pbooth->line);

}