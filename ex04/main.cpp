#include <string>
#include <fstream>
#include <iostream>

class Degistirinator {
    private:
        std::string substitude;
        std::string replacement;
    public:
        Degistirinator(std::string substitude, std::string replacement){
            this->substitude = substitude;
            this->replacement = replacement;
        };
        std::string replace(std::string input) {
            return input;
        }
};

class FileWriter {
    private:
        std::ofstream outFile;
    public:
        FileWriter(std::string filename) {
            this->outFile = std::ofstream(filename);
        }
        ~FileWriter(){
            this->outFile.close();
        }
        void writeLine(std::string input){
            this->outFile << input;
        }
};

std::string withFile(std::string file1,  void(* func(std::string input))()){
    std::string line;
    std::ifstream streamIn(file1);
    while (std::getline(streamIn, line)){
        func(line)(line);
    }
    streamIn.close();
}


int outFile(std::string file, std::string (*contentProvider)()){}

int main(int ac, char* av[]){
    if (ac == 4){
        std::string filename = av[1];
        std::string substitude = av[2];
        std::string replacement = av[3];
        std::string newfile = filename + ".replace";
        Degistirinator degistir(substitude, replacement);
        
        withFile(filename);


    }
    return 0;
}