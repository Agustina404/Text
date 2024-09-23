#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main (void)

{
    string text = get_string("Text: \n");

    int letters = 0;
    int words = 0;
    int sentences = 0;
    bool in_word = false;
    int n = strlen(text);

    for (int i = 0; i < n; i++)

    {
        if (isalpha(text[i]))
          {
            letters++;
        }

        if (!in_word)

        {
            words++;
            in_word = true;
        }
            else if (isspace(text[i]))

            {
                in_word = false;
            }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            if (i + 1 < n && text[i + 1] == ' ' && isalpha(text[i + 2]))


        {
            sentences++;

        }

        if (isalpha(text[i - 1]))
            {
                in_word = false;
            }
    }

    else if (isspace(text[i]))

    {
            in_word = false;
        }

    }

        float L = (float) letters / words * 100;
        float S = (float) sentences / words * 100;
        int index = (int) (0.0588 * L - 0.296 * S - 15.8);

        string grade;

        if (index < 1)
        {
           grade = "Before Grade 1";
        }

        else if (index >= 16)
        {
            grade = "Grade 16+";
        }

        else

        {
            char grade_str[50];
            sprintf(grade_str, "Grade %d", index);
            grade = grade_str;

                    }

    printf("%s\n", grade);

    return 0;
}
