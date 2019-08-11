#include <stdio.h>
#include <string.h>

void createTable(char lookupTable[26][26]);
void printTable(char lookupTable[26][26]);
void encrypt(char lookupTable[26][26], char keyword[20], char *plaintext, char *cipherText);
void decrypt(char lookupTable[26][26], char keyword[20], char *plaintext, char *cipherText);

int main()
{
    int choice;
    char keyword[20];
    char table[26][26];
    char plaintext[80], ciphertext[80];

    printf("ENCRYPTION PROGRAM \n");
    printf("1: createTable()\n");
    printf("2: printTable()\n");
    printf("3: enter a new keyword\n");
    printf("4: encrypt() a plaintext message \n");
    printf("5: decrypt() a ciphertext message \n");
    printf("6: quit \n");

    do{
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            createTable(table);
            printf("createTable() done \n");
            break;

        case 2:
            printf("printTable(): \n");
            createTable(table);
            printTable(table);
            break;

        case 3:
            printf("Enter a new keyword: \n");
            scanf("%s", keyword);
            break;

        case 4:
            printf("Enter a plaintext: \n");
            scanf("%s", plaintext);
            encrypt(table, keyword, plaintext, ciphertext);
            printf("plaintext: %s\n", plaintext);
            printf("ciphertext: %s\n", ciphertext);
            break;

        case 5:
            printf("Enter a ciphertext: \n");
            scanf("%s", ciphertext);
            decrypt(table, keyword, plaintext, ciphertext);
            printf("ciphertext: %s\n", ciphertext);
            printf("plaintext: %s\n", plaintext);
            break;

        default:
            break;
        }
    }
    while(choice<6);

    return 0;
}

void printTable(char lookupTable[26][26])
{
    int row, col;

    char c='a';

    printf(" "); printf(" ");

    for (row=0; row<26; ++row){
        printf("%c ", c); c=c+1;
    }

    printf("\n");
    c='a';

    for(row=0; row<26; ++row){
        printf("%c ", c); c=c+1;
        for(col=0; col<26; ++col){
            printf("%c ", lookupTable[row][col]);
        }
        printf("\n");
    }
}

void createTable(char lookupTable[26][26])
{
    char ALPH[26]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    int i=0, j=0;

    int k=0;

    for(i=0; i<26; i++){
        k=0;
        k=i+0;

        for(j=0; j<26; j++){
            if(k<26){
                lookupTable[i][j]=ALPH[k];
            }
            else if(k>=26)
            {
                lookupTable[i][j]=ALPH[(k%26)];
            }
            k++;
        }
    }


    /********************
    printf("\n\n\n");

    for(i=0;i<26;i++){
        for(j=0;j<26;j++){
            printf("%c ",vigenereTable[i][j]);
        }
        printf("\n");
    }******************/
}

void encrypt(char lookupTable[26][26], char keyword[20], char *plaintext, char *ciphertext)
{
    int i, j, numstr[100],numkey[100],numcipher[100];


    // Convert all characters to UPPERCASE LETTERS

    i=0;
    j=0;
    while(*(plaintext+i)!='\0'){
        if(*(plaintext+i)!=' ')
        {
            *(plaintext+j)=toupper(*(plaintext+i));
            j++;
        }
        i++;
    }

    *(plaintext+j)='\0';

  //////  printf("Entered string is : %s \n",plaintext);

    i=0;
    while(*(plaintext+i)!='\0'){
        numstr[i]=*(plaintext+i)-'A';
        i++;
    }

    // Convert all characters in keyword into UPPERCASE LETTERS
    for(i=0,j=0; i<strlen(keyword); i++)
    {
        if(keyword[i]!=' ')
        {
            keyword[j]=toupper(keyword[i]);
            j++;
        }
    }

    keyword[j]='\0';

   //////// printf("Entered keyword is : %s \n",keyword);


    //Assigning key to the string
    i=0;
    while(*(plaintext+i)!='\0'){
        for(j=0;(j<strlen(keyword))&&(i<strlen(plaintext));j++)
        {
            numkey[i]=keyword[j]-'A';
            i++;
        }
    }

    i=0;
    while(*(plaintext+i)!='\0'){
        numcipher[i]=numstr[i]+numkey[i];
        i++;
    }

    i=0;
    while(*(plaintext+i)!='\0'){
        if(numcipher[i]>25)
        {
            numcipher[i]=numcipher[i]-26;
        }
        i++;
    }

    // Convert plaintext back to lowercase letters
    i=0;
    j=0;
    while(*(plaintext+i)!='\0'){
        if(*(plaintext+i)!=' ')
        {
            *(plaintext+j)=tolower(*(plaintext+i));
            j++;
        }
        i++;
    }

    // Set ciphertext back to pointer 'ciphertext'
    i=0;
    while(*(plaintext+i)!='\0'){

        *(ciphertext+i)=(numcipher[i]+'A');
        i++;
    }


}

void decrypt(char lookupTable[26][26], char keyword[20], char *plaintext, char *ciphertext)
{
/*
     unsigned int i,j;
     char input[257],key[33];
     int value;

     printf("Enter Text to be Decrypted [Max. 256 characters/ only alphabets]:n ");
     gets(input);
     printf("Enter Decryption Key [Max. 32 Characters/ only aphabets]: ");

     gets(key);
     */
     //////////////
     unsigned int i,j;
     int value;

     i=0;
     j=0;

     while(*(ciphertext+i)!='\0')
     {
          //repeat the key if you are at end of it.
          if(j>=strlen(keyword))
          {
               j=0;
          }
          //similar to encipher only difference is you need to subtract
          value = (toupper(*(ciphertext+i))-64)-(toupper(keyword[j])-64);
          //if value is negative. We have to rotate it backwards (like backwards from z,y,x)

          //so add it to 26 (it's a negative value to adding will actually cause subtraction) to get original character.
          if( value < 0)
          {
               value = 26 + value;
          }
        //  printf("%c",65 + (value % 26));

          *(plaintext+i)= 65 + (value % 26);
          i++;
          j++;
     }

    // Convert plaintext back to lowercase letters
    i=0;
    j=0;
    while(*(plaintext+i)!='\0'){
        if(*(plaintext+i)!=' ')
        {
            *(plaintext+j)=tolower(*(plaintext+i));
            j++;
        }
        i++;
    }
}

