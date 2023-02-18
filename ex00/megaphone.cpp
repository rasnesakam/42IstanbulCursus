#include <iostream>

void print_big(char str[]){
    int i = 0;
    while (str[i] != '\0')
    {   
        std::cout << static_cast<char> (toupper(str[i]));
        i++;
    }
}

int main(int argc, char *argv[]){
    int i = 1;
    if (argc > 1)
        while (i < argc)
            print_big(argv[i++]);
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
}