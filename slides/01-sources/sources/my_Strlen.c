/* Suposeu la següent execució:
    ./my_Strlen GeometryDash
    Sortida : 12
*/

#include <stdio.h> //Crida a sistema

int my_strlen(char *str);

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Ús : %s <string>\n", argv[0]);
        return 1;
    }

    char* string = argv[1];
    int len = my_strlen(string);
    printf("La mida de l'String és: %d \n", len );
    return 0;

}

int my_strlen(char * str)
{
    int len;
    while(*str != '\0')
    {
        len++;
        str++;
    }
    return len;
}