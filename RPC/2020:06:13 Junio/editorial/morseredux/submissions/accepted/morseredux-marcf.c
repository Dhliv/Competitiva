/*  2019/2020 Regional
    International Collegiate Programming Contest

    Problem ?
    Morse Redux
    M. K. Furon.                    2019-10-11.                       */




#include  <stdio.h>
#include  <stdlib.h>
#include  <ctype.h>




int i, letter, messagelength, offset, result;
int lettercount[26];
int codelength[26] =
{1, 3, 3, 5, 5, 5, 7, 7, 7, 7, 7,
9, 9, 9, 9, 9, 9, 9, 9,
11, 11, 11, 11, 11, 11, 11};




void abend (char *message)
{
(void) fputs (message, stderr);
(void) fputc ('\n', stderr);
exit (4);
}




int compareint (const void *counta, const void *countb)
{
/*  Compare two integers for Quicksort in descending order.           */
int *valuea, *valueb;
valuea = (int *) counta;
valueb = (int *) countb;
return (*valueb - *valuea);
}




int main (int argc, char *argv[], char *envp[])
{
messagelength = 0;
for (i = 0; i < 26; i++)
   lettercount[i] = 0;

/*  Process the input one character at a time, skipping all non-
    alphabetic characters.  Make all alphabetic characters upper-
    case and count them.  A new-line triggers code assignments.       */
while ((letter = getchar ()) != EOF)
   {
   if (isalpha (letter))            /*  If alphabetic character       */
      {
      offset = (toupper (letter)) - 'A';
      lettercount[offset]++;   
      messagelength++;
      }
   if (letter == '\n')              /*  If new-line, process letters  */ 
      {
      /*  Sort the letter counts to determine which letters appear
          most often.  Letter code lengths will be assigned in order,
	  with the shortest code going to the most frequent letter,
	  the next shortest to the next two letters, etc.             */
      qsort (lettercount, ((size_t) 26), (sizeof (int)), compareint);

      /*  Add up the code lengths based on letter frequencies.        */
      result = 0;
      for (i = 0; i < 26; i++)
         result += lettercount[i] * codelength[i];
      /*  Include the spaces between letters.                         */
      result += (messagelength - 1) * 3;

      /*  Print the result and reset for the next one-line message.   */
      (void) printf ("%d\n", result);
      messagelength = 0;
      for (i = 0; i < 26; i++)
         lettercount[i] = 0;
      }
   }

return (0);
}
