#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float calculate_index(int letters, int words, int sentences);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    float index = calculate_index(letters, words, sentences);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        // use round to get the nearest integer
        int rounded_index = (int)round(index);
        printf("Grade %i\n", rounded_index);
    }

}

int count_letters(string text)
{
    int letters = 0;
    // walk throught the string character by character
    for (int i = 0; text[i] != '\0'; i++)
    {
        // check whether the character is alphabetical
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

int count_words(string text)
{
    // spaces are between words so we can assume that words == spaces + 1
    int words = 1;
    // walk throught the string character by character
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }

    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    // walk throught the string character by character
    for (int i = 0; text[i] != '\0'; i++)
    {
        // this function is assuming that a sentence is terminated by '.', '!' or '?'
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}

float calculate_index(int letters, int words, int sentences)
{
    float average_letters = (float)letters / (float)words * 100; // L
    float average_sentences = (float)sentences / (float)words * 100; // S

    // Coleman-Liau index: index = 0.0588 * L - 0.296 * S - 15.8
    float index = 0.0588 * average_letters - 0.296 * average_sentences - 15.8;

    return index;
}
