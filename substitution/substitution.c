#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* encode(string plain, string key);

int main(int argc, string argv[])
{
        int len = strlen(argv[1]);
        for (int i = 0; i < len; i++)
        {
            if (isalpha(argv[1][i]))
            {
                continue;
            }
            else
            {
                printf("your key has nonalpha chars");
                return 1;
            }
        }
        if (argc == 2)
        {
            if (strlen(argv[1]) == 26)
            {
                string plain = get_string("plain-text: ");
                string key = argv[1];
                char* encoded = encode(plain, key);
                printf("ciphertext: %s\n", encoded);
                free(encoded);
            }
            else
            {
                printf("your key is not sufficient.");
                return 1;
            }
        }
        else
        {
            printf("you should have given exactly two command-line arguments");
            return 1;
        }
}


char* encode(string plain, string key)
{

        int plain_length = strlen(plain);
        char* encoded = malloc(plain_length + 1);
        for (int i = 0; i < plain_length; i++)
        {
            if (isalpha(plain[i]))
            {
                if (isupper(plain[i]))
                {

                    encoded[i] = toupper(key[plain[i] - 'A']);
                }
                else
                {

                    encoded[i] = tolower(key[plain[i] - 'a']);
                }
            }
            else
            {
                encoded[i] = plain[i];
            }
        }


        encoded[plain_length] = '\0';
        return encoded;
}
