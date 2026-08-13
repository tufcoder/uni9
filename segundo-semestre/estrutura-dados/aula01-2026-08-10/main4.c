#include <stdio.h>

// argc: argument count
// argv: argument vector
int main(int argc, char* argv[])
{
    printf("argc: %d\n", argc);

    // for (int i = 0; i < argc; i++)
    // {
    //     printf("argv: %s\n", argv[i]);
    // }

    while (*argv)
    {
        printf("argv: %s\n", *argv);
        argv++;
    }

    return 0;
}
