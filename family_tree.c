#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;
} Person;

Person* create_person(const char *name, int age)
{
    Person *person = malloc(sizeof(Person));

    if (person == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    strcpy(person->name, name);
    person->age = age;

    person->father = NULL;
    person->mother = NULL;

    return person;
}

int main()
{
    Person *person = create_person("Ahmed", 20);

    if (person != NULL)
    {
        printf("Name: %s\n", person->name);
        printf("Age: %d\n", person->age);
    }

    free(person);

    return 0;
}