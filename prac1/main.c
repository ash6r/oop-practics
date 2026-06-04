#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *user = NULL;

    if (argc > 1)
    {
        user = argv[1];
    }
    else
    {
        user = getenv("USERNAME");
    }
    printf("Привет, %s!\n", user);

    return 0;
}