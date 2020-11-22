#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int validate_key(string key);
string encipher_text(string key, string plaintext);

int main(int argc, string argv[])
{
    // Check arguments count
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    int rc = validate_key(key);

    // Exit if key isn't valid
    if (rc != 0)
    {
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    string ciphertext = encipher_text(key, plaintext);

    printf("ciphertext: %s\n", ciphertext);
}

int validate_key(string key)
{
    // Check key length
    int key_size = strlen(key);
    if (key_size != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Walk through the key character by character
    for (int i = 0; i < key_size; i++)
    {
        char c = key[i];
        // Check for non-alphabetic characters
        if (!(isalpha(c)))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }

        // Check for repeated characters (case-insensitive)
        for (int j = 0; j < i; j++)
        {
            // Uppercase characters to compare to be case insensitive
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }
    return 0;
}

string encipher_text(string key, string plaintext)
{
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int text_size = strlen(plaintext);
    string ciphertext = plaintext;

    // Walk through the text character by character
    for (int i = 0; i < text_size; i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            for (int j = 0; j < 26; j++)
            {
                if (alphabet[j] == toupper(c))
                {
                    if (isupper(c))
                    {
                        ciphertext[i] = toupper(key[j]);
                    }
                    else
                    {
                        ciphertext[i] = tolower(key[j]);
                    }
                }
            }
        }
        else
        {
            ciphertext[i] = c;
        }
    }

    return ciphertext;
}
