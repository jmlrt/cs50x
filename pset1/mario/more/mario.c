#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    bool is_valid = false;

    // keep prompting user until height is a positive integer between 1 and 8
    while (is_valid == false)
    {
        height = get_int("Height: ");
        if (height > 0 && height <= 8)
        {
            is_valid = true;
        }

    }

    // loop for lines
    for (int line = 1; line <= height; line++)
    {
        int blocks = line;
        int spaces = height - blocks;

        // loop for white spaces before blocks
        for (int i = 0; i < spaces; i++)
        {
            printf(" ");
        }

        // loop for left blocks
        for (int j = 0; j < blocks; j++)
        {
            printf("#");
        }

        printf("  ");

        // loop for right blocks
        for (int j = 0; j < blocks; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}
