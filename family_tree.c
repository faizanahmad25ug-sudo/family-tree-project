
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;
} Person;

// Create a person
Person* create_person(const char *name, int age)
{
    Person *person = malloc(sizeof(Person));

    if (person == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    strcpy(person->name, name);
    person->age = age;
    person->father = NULL;
    person->mother = NULL;

    return person;
}

// Link father and mother to a child
void link_parents(Person *child, Person *father, Person *mother)
{
    child->father = father;
    child->mother = mother;
}

// Print all family relationships
void print_family_relationships(const Person *me)
{
    printf("\n=== FAMILY TREE RELATIONSHIPS ===\n");

    printf("\n1. YOURSELF:\n");
    printf("   - Name: %s | Age: %d\n", me->name, me->age);

    printf("\n2. PARENTS:\n");
    printf("   - Father: %s | Age: %d\n",
           me->father->name, me->father->age);

    printf("   - Mother: %s | Age: %d\n",
           me->mother->name, me->mother->age);

    printf("\n3. PATERNAL GRANDPARENTS (via Father's Pointers):\n");
    printf("   - Grandfather: %s | Age: %d\n",
           me->father->father->name,
           me->father->father->age);

    printf("   - Grandmother: %s | Age: %d\n",
           me->father->mother->name,
           me->father->mother->age);

    printf("\n4. MATERNAL GRANDPARENTS (via Mother's Pointers):\n");
    printf("   - Grandfather: %s | Age: %d\n",
           me->mother->father->name,
           me->mother->father->age);

    printf("   - Grandmother: %s | Age: %d\n",
           me->mother->mother->name,
           me->mother->mother->age);
}

// Free all family tree memory
void free_family_tree(Person *people[], int count)
{
    for (int i = 0; i < count; i++)
    {
        free(people[i]);
    }
}

int main()
{
    // Create all 7 people
    Person *paternal_grandfather = create_person("Ram", 75);
    Person *paternal_grandmother = create_person("Nagini", 72);

    Person *maternal_grandfather = create_person("Suresh", 78);
    Person *maternal_grandmother = create_person("Revathi", 74);

    Person *father = create_person("Krishna", 48);
    Person *mother = create_person("Divya", 46);

    Person *me = create_person("Chitra", 20);

    // Milestone 3: Link the family relationships
    link_parents(father, paternal_grandfather, paternal_grandmother);
    link_parents(mother, maternal_grandfather, maternal_grandmother);
    link_parents(me, father, mother);

    // Store all 7 people for memory cleanup
    Person *people[] = {
        paternal_grandfather,
        paternal_grandmother,
        maternal_grandfather,
        maternal_grandmother,
        father,
        mother,
        me
    };

    // Print family relationships
    print_family_relationships(me);

    // Free all allocated memory
    free_family_tree(people, 7);

    return 0;
}

