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
        FileWriter(std::string filename) : outFile(std::ofstream(filename)) {
            this->outFile = std::ofstream("");
        }
        ~FileWriter(){
            this->outFile.close();
        }
        void writeLine(std::string input){
            this->outFile << input;
        }
};

std::string withFile(std::string file1, Degistirinator degistirinator, FileWriter filewriter){
    std::string line;
    std::ifstream streamIn(file1);
    while (std::getline(streamIn, line)){
        filewriter.writeLine(degistirinator.replace(line));
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
        FileWriter filewriter(newfile);
        
        withFile(filename, degistir, filewriter);


    }
    return 0;
}