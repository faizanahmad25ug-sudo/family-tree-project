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

void link_parents(Person *child, Person *father, Person *mother)
{
    child->father = father;
    child->mother = mother;
}

void print_family_relationships(const Person *me)
{
    printf("\n===== FAMILY RELATIONSHIPS =====\n");

    printf("\nYourself:\n");
    printf("Name: %s\n", me->name);
    printf("Age: %d\n", me->age);

    printf("\nParents:\n");

    if (me->father != NULL)
    {
        printf("Father: %s, Age: %d\n",
               me->father->name,
               me->father->age);
    }

    if (me->mother != NULL)
    {
        printf("Mother: %s, Age: %d\n",
               me->mother->name,
               me->mother->age);
    }

    printf("\nPaternal Grandparents:\n");

    if (me->father != NULL && me->father->father != NULL)
    {
        printf("Grandfather: %s, Age: %d\n",
               me->father->father->name,
               me->father->father->age);
    }

    if (me->father != NULL && me->father->mother != NULL)
    {
        printf("Grandmother: %s, Age: %d\n",
               me->father->mother->name,
               me->father->mother->age);
    }

    printf("\nMaternal Grandparents:\n");

    if (me->mother != NULL && me->mother->father != NULL)
    {
        printf("Grandfather: %s, Age: %d\n",
               me->mother->father->name,
               me->mother->father->age);
    }

    if (me->mother != NULL && me->mother->mother != NULL)
    {
        printf("Grandmother: %s, Age: %d\n",
               me->mother->mother->name,
               me->mother->mother->age);
    }
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

    /* Input for paternal grandfather */
    read_person_info("Paternal Grandfather", name, &age);
    paternal_grandfather = create_person(name, age);

    /* Input for paternal grandmother */
    read_person_info("Paternal Grandmother", name, &age);
    paternal_grandmother = create_person(name, age);

    /* Input for maternal grandfather */
    read_person_info("Maternal Grandfather", name, &age);
    maternal_grandfather = create_person(name, age);

    /* Input for maternal grandmother */
    read_person_info("Maternal Grandmother", name, &age);
    maternal_grandmother = create_person(name, age);

    /* Input for father */
    read_person_info("Father", name, &age);
    father = create_person(name, age);

    /* Input for mother */
    read_person_info("Mother", name, &age);
    mother = create_person(name, age);

    /* Input for yourself */
    read_person_info("Yourself", name, &age);
    yourself = create_person(name, age);

    /* Link grandparents to father */
    link_parents(father,
                 paternal_grandfather,
                 paternal_grandmother);

    /* Link grandparents to mother */
    link_parents(mother,
                 maternal_grandfather,
                 maternal_grandmother);

    /* Link parents to yourself */
    link_parents(yourself,
                 father,
                 mother);

    /* Print family relationships */
    print_family_relationships(yourself);

    /* Temporary cleanup */
    free(paternal_grandfather);
    free(paternal_grandmother);
    free(maternal_grandfather);
    free(maternal_grandmother);
    free(father);
    free(mother);
    free(yourself);

    return 0;
}