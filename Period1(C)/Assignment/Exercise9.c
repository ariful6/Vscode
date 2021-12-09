#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define INDEX 15
#define MAXINDEX 50
#define MAXINDEX2 25
#define MAX 15
#define MAX2 9
#define INPUT 25
#define WIDTH 25

struct Cars // Structure of the car
{
    int  make_of_the_car;
    char  model_of_the_car[MAXINDEX];
    char  rental_category;
    char  registration_plate[INDEX];
    int  current_mileage;
    int  availability;
};

struct Category
{
    char  short_key;
    char  rental_category[MAXINDEX2];
};

struct Category catlist[MAX2] = { {'M' , "Mini"},   // catlist = category list
                                  {'N' , "Mini Elite"},
                                  {'E' , "Economy" },
                                  {'C' , "Compact"},
                                  {'I' , "Intermediate" },
                                  {'S' , "Standard"},
                                  {'F' , "Full-size" },
                                  {'P' , "premium"},
                                  {'X' , "Special"} };

struct Cars carlist[MAX] = {  { 2014, "Fiat Panda" , 'M',"INJ100", 100019 , 1 },
                              { 2012, "Citroen C1" , 'N',"INJ101", 100023 , 1 },
                              { 2017, "Ford Fiesta" , 'E',"INJ102", 100043 , 0 },
                              { 2018, "Ford Focus" , 'C',"INJ103", 100054 , 1 },
                              { 2016, "VW Touran" , 'I',"INJ104", 100045 , 1 },
                              { 2016, "Audi A4" , 'S',"INJ105", 100545 , 1 },
                              { 2015, "Hyundai i10" , 'F',"INJ106", 100444 , 1 },
                              { 2018, "Porsche Cayman" , 'P',"INJ107", 100344 , 1 },
                              { 2019, "Aston Martin DB9" , 'X',"INJ108", 100345 , 1 },
                              { 2014, "Smart ForTwo" , 'M',"INJ109", 100055 , 1 },
                              { 2014, "Citroen C1" , 'N',"INJ110", 100345 , 1 },
                              { 2014, "Nissan Micra" , 'E',"INJ111", 100344 , 1 },
                              { 2014, "Opel Astra" , 'C',"INJ112", 102345 , 1 },
                              { 2015, "Renault Kangoo" , 'I',"INJ113", 104344 , 1 },
                              { 2016, "Skoda Octavia" , 'S',"INJ114", 103444 , 1 } };

void print_all_cars(struct Cars cars[MAX]);
void print_free_cars_by_given_category(struct Cars cars[MAX], int rental_category_key);
void change_state_of_a_car(struct Cars cars[MAX], char registration_plate[INPUT]);
char* get_rental_category(int r);
int get_rental_key(char* cate);
char ret_rental_category[MAXINDEX2];

int main()
{
    int x = 0;
    char registration_plate[INPUT];
    char txt_cate[INPUT];
    while (x != 4)
    {
        printf("1. print all cars\n2. print free cars of a given category\n3. change the state of a car\n4. quit the program.\n\nEnter your choice : ");
        scanf("%d", &x);
        if (x == 1)
        {
            print_all_cars(carlist);
        }
        else if (x == 2)
        {
            printf("Enter the category of the car : ");
            scanf(" %s\n]", txt_cate);
            print_free_cars_by_given_category(carlist, get_rental_key(txt_cate));
        }
        else if (x == 3)
        {
            printf("Enter the registration plate of the car :");
            scanf("%s", registration_plate);
            change_state_of_a_car(carlist, registration_plate);
        }
        else if (x == 3)
        {
            printf("Exit\n");
        }
        else
        {
            printf("Invaild input\n");
        }
    }
}

// Function to print all the cars
void print_all_cars(struct Cars cars[MAX])
{
    printf("all car\n");
    char ret_rental_category[MAXINDEX2];
    printf("Make of the car | Model of the car | Rental category       | Registration plate | Current mileage| Availability \n");
    for (int i = 0; i < MAX; i++)
    {
        strcpy(ret_rental_category, get_rental_category(i));
        printf(" %*d ",-15,cars[i].make_of_the_car);
        printf(" %*s", -18, cars[i].model_of_the_car);
        printf(" %*s ", -23, ret_rental_category);
        printf(" %*s ", -19, cars[i].registration_plate);
        printf(" %*d ", -16, cars[i].current_mileage);
        if (cars[i].availability == 1)
        {
            printf(" %*s\n", -18, "Available");
        }
        else
        {
            printf(" %*s\n", -18, "Not available");
        }
    }
    printf("\n");
}

char* get_rental_category(int r)
{
    for (int i = 0; i < MAX2; i++)
    {
        if (catlist[i].short_key == carlist[r].rental_category)
        {
            strcpy(ret_rental_category, catlist[i].rental_category);
        }
    }
    return ret_rental_category;
}

int get_rental_key(char* cate)
{
    int r = 9;
    for (int i = 0; i < strlen(cate) && 1 < strlen(cate); i++)
    {
        if (i == 0)
        {
            cate[i] = toupper(cate[i]);
        }
        else if (cate[i] == ' ')
        {
            cate[i + 1] = toupper(cate[i + 1]);
        }
    }
    if ('*' == cate[0])
    {
        r = (int)'*';
    }
    else
    {
        for (int i = 0; i < MAX2; i++)
        {
            int ret1 = strncmp(cate, catlist[i].rental_category, WIDTH);
            if (ret1 == 0 || catlist[i].short_key == cate[0])
            {
                r = i;
            }
        }
    }
    return r;
}

void print_free_cars_by_given_category(struct Cars cars[MAX], int rental_category_key) // Function to print cars by category
{
    printf("free car\n");
    int found = 0;
    char ret_rental_category[MAXINDEX2];
    printf("Make of the car | Model of the car | Rental category       | Registration plate | Current mileage| Availability \n");
    for (int i = 0; i < MAX; i++) {
        if ((catlist[rental_category_key].short_key == cars[i].rental_category || 42 == rental_category_key) && cars[i].availability == 1)
        {
            strcpy(ret_rental_category, get_rental_category(i));
            printf(" %*d ",-15,cars[i].make_of_the_car);
            printf(" %*s", -18, cars[i].model_of_the_car);
            printf(" %*s ", -23, ret_rental_category);
            printf(" %*s ", -19, cars[i].registration_plate);
            printf(" %*d ", -16, cars[i].current_mileage);
            printf(" %s\n","Available");
            found = 1;
        }
    }
    if (found == 0)
    {
        printf(" %s\n\n", "Result is empty");
    }
    else
    {
        printf("\n");
    }
}

void change_state_of_a_car(struct Cars cars[MAX], char registration_plate[INPUT]) // Function to change the state of any car
{
    int found = 15;
    char state_of_a_car[INPUT];
    for (int i = 0; i < MAX; i++)
    {
        int ret = strncmp(registration_plate, cars[i].registration_plate, 20);
        if (ret == 0)
        {
            found = i;
        }
    }
    if (found < 15)
    {
        printf("Enter the  state of a car (available/not available) :");
        scanf(" %c\n]", state_of_a_car);
        //strlwr(state_of_a_car);
        int ret1 = strncmp(state_of_a_car, "not available", 20);
        int ret2 = strncmp(state_of_a_car, "available", 20);
        if (ret1 == 0 && cars[found].availability == 1)
        {
            cars[found].availability = 0;
            print_all_cars(cars);
        }
        else if (ret2 == 0 && cars[found].availability != 1)
        {
            cars[found].availability = 1;
            print_all_cars(cars);
        }
        else {
            printf("Invaild input \"%s\" or please check the state of the car\n\n", state_of_a_car);
        }
    }
    else
    {
        printf("Information not Available\n\n");
    }
}
