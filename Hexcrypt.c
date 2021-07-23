/*
Author : Pratik U. Jadhav

Hello this C program 'Hexcrpyt' is used to Encrypt a string
into hex string. Also encrpyted string can be Decrypted
into a message.

*/

#include<stdio.h>
#include<stdlib.h>
#define HEXLENGTH 2
#define TRUE 1

void string_to_hex();
void hex_to_string();


int main(int argc, char const *argv[])
{
  printf("\n\n\t\t\tWelcome to Hexcrpyt!\n\n ");

  int get_input;
  while (TRUE) {
    printf("\n Pick your conversion\n\n1.Encrypt a Message\n2.Decrypt Hex Message\n3.EXIT\n");
    scanf("%c", &get_input );

      switch ( get_input )
       {
        case '1':
        string_to_hex();
        break;

        case '2':
        hex_to_string();
        break;

        case '3':
        exit(0);
        break;

        default:
        printf("Please choose appropriate choice\n" );
        break;

      }//end switch


  }//end while


  return 0;
}//end main

void string_to_hex(){

printf("\nEnter a message to Encrypt\n" );
      int char_input;
      char_input = getchar();
      while ( ( char_input = getchar() ) != '\n')
       {

        if( char_input == '\n' )
        break;

        //convert char to hex

        char hex_number[HEXLENGTH];
        char hex_reverse[HEXLENGTH];

        //initialization
        for (int i = 0; i < HEXLENGTH; ++i)
          hex_number[i] = hex_reverse [i] = '0';


        int input = char_input;
        int position = -1;
        //conversion to hex
        while ( input > 0 )
        {
          position++;

          if( input % 16 >= 0 && input % 16 <= 9 )
          hex_reverse[position] = (input % 16) + '0';
          else if( input % 16 >= 10 && input % 16 <= 15 )
          hex_reverse[position] = (input % 16) - 10 + 'a';


          input /= 16;
          if ( (position + 1) == HEXLENGTH )
            break;

        }

        //reverse the result to get actual hex result
        for (int i = HEXLENGTH - ( position + 1 ); i < HEXLENGTH; ++i)
          hex_number[i] = hex_reverse[position--];

        for (int i = 0; i < HEXLENGTH; ++i)
        printf("%c",hex_number[i] );


      }//end while
printf("\n" );

}

void hex_to_string(){

printf("\nEnter a hex Decrypted message\n");

    int bin_input;
    int length = 0;

    char hex_number[HEXLENGTH];
    for (int i = 0; i < HEXLENGTH; ++i)
      hex_number[i] = '0';

    bin_input = getchar();
    while ( ( bin_input = getchar() ) != EOF)
    {
      if ( bin_input == '\n' )
      break;

      hex_number[length++] = bin_input;

      if( length > HEXLENGTH - 1 )
      {
        int number=0;
        int power = 1 ;
        //now hex number is filled in hex_number array
        //to do process it and display char

          for (int i = HEXLENGTH - 1; i >=0 ; --i)
          {
              if( hex_number[i] >= '0' && hex_number[i] <= '9' )
                number += power * ( hex_number[i] - '0' );
              else if( hex_number[i] >= 'a' && hex_number[i] <= 'f' )
                number += power * ( hex_number[i] - 'a' + 10 );

              power *= 16;
          }
          printf("%c",number );

            length = 0;
      }

    }//end while
printf("\n");

}
