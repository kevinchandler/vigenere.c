#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[]) {
    
    string keyword = argv[1];

       
    //only accept 2 command line args, or error
    if (argc != 2) {
        printf("Please enter two command line arguments\n");
        return 1;
    }
    
    for (int i=0; i < strlen(keyword); i++) {
        if (isdigit(keyword[i])) {
            printf("Please enter all letters\n");
            return 1;
        }
    }
    

  
    //make sure we have a positive, non-negative number
    if (argv[1]) {
    

    
    string lower_alphabet = "abcdefghijklmnopqrstuvwxyz";
    string upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
   //define text to cipher && encrypted text
   string text = GetString();
        
        //loop through each letter of text to encrypt it
        // k is the ith letter in the keyword
        for (int i=0, k=0, n = strlen(text); i < n; i++, k++) {
        int rotation = 0;
            if (k >= strlen(keyword)) {
                k = 0;
            }
            
             

            if (isalpha(text[i])) {

                //define shift length based on capilization
                if (isupper(keyword[k])) {
                    rotation = keyword[k] - 65;
                }
                else if (islower(keyword[k])) {
                    rotation = keyword[k] - 97;
                }
                else {
                    rotation = 0;
                }
                 
                //shift and print           
                if (isupper(text[i])) {
                    int letter = ((text[i] - 65) + rotation)%26;
                    printf("%c", upper_alphabet[letter]);
                }
                
                if (islower(text[i])) {
                    int letter = ((text[i] - 97) + rotation)%26;
                    printf("%c", lower_alphabet[letter]);
                }
            }
            
            //if current character is not a letter
            else {
                int letter = text[i];
                printf("%c", letter);
                k--;
            
            }
        }
        //new line after ciphering. 
        printf("\n");
    }
    
     else {
        return 1;
    }
  
 }
    
   
