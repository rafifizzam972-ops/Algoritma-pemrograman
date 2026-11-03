#include <iostream>

using namespace std;

void copyString(char *src, char *dest)
{
    while (*src)
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0'; 
}

int main()
{
    char src[] = "Hello";
    char dest[10];

    copyString(src, dest);

    cout << "Hasil copy string: " << dest << endl; 
    
    return 0;
}