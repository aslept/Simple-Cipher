#include <stdio.h>
#include <ctype.h>

char encrypt(char ch, int shift)
{
    if (isupper(ch))
    {
        return (ch - 'A' + shift)%26 + 'A';
    }
    
    else if (islower(ch))
    {
        return (ch - 'a' + shift)%26 + 'a';
    }

    else
        return ch;
    
}

char decrypt(char ch, int shift)
{
    if(isupper(ch))
    {
        return (ch - 'A' - shift +26)%26 +'A';
    }
    else if (islower(ch))
    {
        return (ch - 'a' - shift + 26)%26 + 'a';
    }
    else
    {
        return ch;
    }
    
}

void encryptstring(char *string, int shift)
{
    for(int i = 0; string[i] != '\0'; i++)
    {
        string[i] = encrypt(string[i], shift);
    }
}

void decryptstring(char *string, int shift)
{
    for(int i = 0; string[i] != '\0'; i++)
    {
        string[i] = decrypt(string[i], shift);
    }
}

int main()
{
    char string[20];
    int shift, switchcase;

    printf("\nEnter the text\n");
    fgets(string, sizeof(string), stdin);

    printf("\nEnter the number of shift\n");
    scanf("%d", &shift);
  
    shift = shift%26;

    printf("\nPress 1 for Encryption or 2 for Decryption\n");
    scanf("%d", &switchcase);

    switch (switchcase)
    {
    case 1:
        encryptstring(string, shift);
        printf("\nEncrypted text\n%s", string);
        break;

    case 2: 
        decryptstring(string, shift);
        printf("\nDecrypted text\n%s", string);
        break;
    
    default:
        printf("Invalid input");
        break;
    }

    return 0;
}