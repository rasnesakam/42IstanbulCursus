#include <string>
#include <fstream>
#include <iostream>

class Degistirinator {
    private:
        std::string search;
        std::string replacement;
    public:
        Degistirinator(std::string search, std::string replacement){
            this->search = search;
            this->replacement = replacement;
        };
        std::string replace(std::string input) {
            std::string str = "";
            int founded = input.find(this->replacement);
            int cursor = 0;
            if (founded =-1)
                    return (input);
            while (founded > -1){
                founded = input.find(this->replacement);
                if (founded == -1)
                    founded = input.length();
                for (; cursor < founded; cursor++)
                    str += input[cursor];
                if (cursor < input.length())
                    str += this->replacement;
                cursor += this->replacement.length();
            }
            return str;
        }
};

class FileWriter {
    private:
        std::string fileName;
        std::ofstream outFile;
    public:
        FileWriter(std::string fileName) {
            this->fileName = fileName;
            this->outFile.open(fileName);
        }
        /*
        FileWriter(const FileWriter& writer) {
            this->fileName = writer.fileName;
            this->outFile.open(this->fileName);
        }
        */
        ~FileWriter(){
            this->outFile.close();
        }
        void writeLine(std::string input){
            this->outFile << input << std::endl;
        }
        std::string getFileName(){
            return this->fileName;
        }
};

void withFile(std::string file1, Degistirinator &manipulator, FileWriter &filewriter){
    std::string line;
    std::ifstream streamIn(file1);
    while (std::getline(streamIn, line)){
        filewriter.writeLine(manipulator.replace(line));
    }
    streamIn.close();

}

int main(int ac, char* av[]){
    if (ac == 4){
        std::string filename = av[1];
        std::string substitude = av[2];
        std::string replacement = av[3];
        std::string newfile = filename + ".replace";
        Degistirinator degistir(substitude, replacement);
        FileWriter writer(newfile);
        
        withFile(filename, degistir, writer);


    }
    return 0;
}