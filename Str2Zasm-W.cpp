// Str2Zasm-W.cpp
//

#include <iostream>
#include "zx81charcodes.h"

char* zxstring(char* string) {
    size_t string_len = strlen(string);
    size_t new_len = 4 * string_len + 1;
    char* retstring = new  char[new_len]; *retstring = 0;

    size_t f;
    for (f = 0; f < string_len; f++) {
        int ascii = string[f];
        char c[4]; *c = 0;
        strcpy_s(c, 4, asciicharcodes[ascii]);
        if (0 == strlen(c)) {
            sprintf_s(c, 4, "$%02X", ascii);
        }
        strcat_s(retstring, new_len, c);
        if (f != string_len - 1) {
            strcat_s(retstring, new_len, ",");
        }
    }
    return retstring;
}
void asciiToDB(char* inputString)
{
    char* dbstring = zxstring(inputString);
    std::cout << dbstring << std::endl;
    if (dbstring) {
        delete dbstring;
    }
}
int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        std::cout << "ZX81 string to assembler define-byte utility\n\n";
        std::cout << "Usage: Str2Zasm \"[string to convert]\"\n\n";
        std::cout << "For example: Str2Zasm \"Hello World\"\n";
        char c[256];
        strcpy_s(c, "Hello World");
        asciiToDB(c);
        std::cout << "\nFor example: Str2Zasm ZX81\n";
        strcpy_s(c, "ZX81");
        asciiToDB(c);
    }
    else
    {
        asciiToDB(argv[1]);
    }
}