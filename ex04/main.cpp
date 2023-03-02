#include <string>
#include <fstream>

int withFile(std::string file1, std::string file2, std::string replacement, std::string (*manipulator)(std::string input, std::string replaceWith)){
    std::string line;
    std::ifstream streamIn(file1);
    std::ofstream streamOut(file2);
    while (std::getline(streamIn, line)){
        streamOut << manipulator(line, replacement);
    }
    streamIn.close();
}

std::string manipulator(std::string input, std::string replace){
    
}

int outFile(std::string file, std::string (*contentProvider)()){}

int main(int ac, char* av[]){
    if (ac == 4){
        std::string filename = av[1];
        std::string substitude = av[2];
        std::string replacement = av[3];
        std::string newfile = filename + ".replace";

    }
    return 0;
}