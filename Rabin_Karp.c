#include <stdio.h> 
#include <string.h> 
  
#define d 256 
void search(char pat[], char txt[], int q) //q:we use length of pattern for modulus
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
    int i, j; 
    int p = 0;
    int t = 0;
    int h = 1; 
    
    for (i = 0; i < M - 1; i++) 
        h = (h * d) % q; 
  
    for (i = 0; i < M; i++) { 
        p = (d * p + pat[i]) % q; 
        t = (d * t + txt[i]) % q; 
    } 
  
    for (i = 0; i <= N - M; i++) {   
  
        if (p == t) {    //if hash values of pattern and window of characters of text match, character to character comparison
            for (j = 0; j < M; j++) { 
                if (txt[i + j] != pat[j]) 
                    break; 
            } 
  
            if (j == M) 
                printf("Pattern found between index %d and %d\n", i, (i+M)); 
        } 
  
        if (i < N - M) { 
            t = (d * (t - txt[i] * h) + txt[i + M]) % q; 
                         //updates the hash value t of the current window of the text using a rolling hash technique.
                        //If t becomes negative, it adjusts it to ensure it remains within the range of q.
            if (t < 0) 
                t = (t + q); 
        } 
    } 
} 
  
int main() 
{
    char txt[100], pat[20]; 
    printf("Enter text:");
    scanf("%s", txt);
    printf("Enter pattern:");
    scanf("%s", pat);
    int q = strlen(pat);
    search(pat, txt, q); 
    return 0; 
} 
