#include <stdio.h>
#include <string.h>

#define STR_SIZE 150

void caserCipher(char *str, int shift);

int main()
{
    char str[STR_SIZE];
    int shift;
    
    printf("Enter string to be encrypted (max 150 character): ");
    scanf("%99[^\n]", &str[0]);                     //[^\n] reads until \n is not found
    printf("Enter the shift value : ");
    scanf("%d", &shift);
    
    //converting string to uppercase
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a') && (str[i] <= 'z')){
            str[i] = str[i] - 32;
        }
    }
    
    printf("Original string: %s\n", str);
    caserCipher(str, shift);
    printf("Encrypted string: %s\n", str);
    caserCipher(str, -1*shift);
    printf("Decrypted string: %s\n", str);
    
    return 0;

}
void caserCipher(char *str, int shift)
{
    int change = 0;
    //making the shift in 26 letter range
    while (shift > 26) shift -= 26;
    while (shift < -26) shift += 26;
    
    // shifting the value
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 65) && (str[i] <= 90)){
            change = str[i] + shift;
            //white space or any other character checking and shifting
            if (change < 65) {
                str[i] = change + 26;
            }
            else if(change > 90){
                str[i] = change - 26;
            }
            else{
                str[i] = change;
            }
        }
    }
}
