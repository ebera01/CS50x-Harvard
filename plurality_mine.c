#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    int number;
}
person;

int main(int argc, string argv[])
{
    person people[argc - 1];

    for (int i = 0; i < argc - 1; i++)
    {
        people[i].name = argv[i + 1];
        people[i].number = 0;
    }

    int number_of_voters = get_int("Number of voters: ");

    for (int j = 0; j < number_of_voters; j++)
    {
        string vote = get_string("Vote :");
        for (int k = 0; k < (argc - 1); k++)
            if (strcmp(vote, people[k].name) == 0)
            {
                people[k].number += 1;
            }
    }

    int win_num = 0;
    string winner;

    for(int i = 0; i < argc - 1; i++)
    {
        if (people[i].number > win_num)
        {
            winner = people[i].name;
            win_num = people[i].number;
        }

    }
    printf("%s\n", winner);
}
