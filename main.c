#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main (void)
{
    //prompt the user for text
    string text = get_string("You may now write ");

    //count the number of letters, words and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    //compute the coleman-Liau index
    float index = (0.0588 * letters / words * 100) - (0.296 * sentences / words * 100) - 15.8;
    int rounded_index =  round(index);
    
    //print the grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if(index >= 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", (rounded_index));
    }
}

//count number of letters
int count_letters(string text)
{
    int score = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(isupper(text[i]))
        {
            score++;
        }

        else if(islower(text[i]))
        {
            score++;
        }
    }
    return score;
}

//count the number of words
int count_words(string text)
{
    int score = 1;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(isblank(text[i]))
        score++;
    }
    return score;
}

//count the number of sentences
int count_sentences(string text)
{
    int score = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(text[i] == '.')
        {
            score++;
        }

        else if(text[i] == '!')
        {
            score++;
        }

        else if(text[i] == '?')
        {
            score++;
        }
    }
    return score;
}


