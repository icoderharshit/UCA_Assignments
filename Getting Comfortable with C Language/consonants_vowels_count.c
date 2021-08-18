/*
 * Program to calculate the total number of alphabets and consonants in the entered string
 * Harshit Sharma 1910990073, 25 July, 2021 
 * Assignment - Getting Comforable with C Language
*/

#include <stdio.h>
int main(){
  int size;
  char string[100];
  fgets(string,100,stdin);
  int vowels=0,consonants=0;
  for(int i=0;i<string[i]!='\0';i++)
  {
  //vowels are a,e,i,o,u similiarly capital letters for the same   
          if(string[i]=='a' || string[i]=='e' || string[i]=='i' || string[i]=='o' || string[i]=='u' || string[i]=='A' || string[i]=='E' || string[i]=='I' || string[i]=='O' || string[i]=='U')
          {
                  vowels++;
          }
          else if(string[i]!='\n')
          {
                  consonants++;
          }
  }
    printf("Vowels= %d, Consonants=%d \n",vowels,consonants);
        return 0;
}