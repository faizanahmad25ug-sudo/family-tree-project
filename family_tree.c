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

void read_person_info(const char *role, char *name_out, int *age_out)
{
    printf("Enter name for %s: ", role);
    fgets(name_out, 50, stdin);

    name_out[strcspn(name_out, "\n")] = '\0';

    printf("Enter age for %s: ", role);
    scanf("%d", age_out);

    getchar();
}

int main()
{
    char name[50];
    int age;

    Person *paternal_grandfather;
    Person *paternal_grandmother;
    Person *maternal_grandfather;
    Person *maternal_grandmother;
    Person *father;
    Person *mother;
    Person *yourself;

    read_person_info("Paternal Grandfather", name, &age);
    paternal_grandfather = create_person(name, age);

    read_person_info("Paternal Grandmother", name, &age);
    paternal_grandmother = create_person(name, age);

    read_person_info("Maternal Grandfather", name, &age);
    maternal_grandfather = create_person(name, age);

    read_person_info("Maternal Grandmother", name, &age);
    maternal_grandmother = create_person(name, age);

    read_person_info("Father", name, &age);
    father = create_person(name, age);

    read_person_info("Mother", name, &age);
    mother = create_person(name, age);

    read_person_info("Yourself", name, &age);
    yourself = create_person(name, age);

    printf("\nAll 7 family members have been created successfully!\n");

    free(paternal_grandfather);
    free(paternal_grandmother);
    free(maternal_grandfather);
    free(maternal_grandmother);
    free(father);
    free(mother);
    free(yourself);

    return 0;
}