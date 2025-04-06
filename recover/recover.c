#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("single argument only");
        return 1;
    }

    FILE *card = fopen(argv[1], "r")
    uint8_t buffer[512];
    int count = 0;
    while (fread(&buffer, 512, 1, card) == 512)
    {
        if ((buffer[0] == "0xff") && (buffer[1] == "0xd8") && (buffer[2] == "0xff") && (buffer[3] == ")
    }
}
