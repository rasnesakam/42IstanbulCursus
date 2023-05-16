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
            size_t position;
			while((position = input.find(search)) != std::string::npos){
				input.erase(position,search.length());
				input.insert(position,replacement);
			}
            return input;
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

int withFile(std::string file1, Degistirinator &manipulator, FileWriter &filewriter){
    std::string line;
    std::ifstream streamIn(file1);
	if (!streamIn.good())
	{
		std::cerr << file1 << ": Invalid file" << std::endl;
		return 1;
	}
    while (std::getline(streamIn, line)){
        filewriter.writeLine(manipulator.replace(line));
    }
    streamIn.close();
	return 0;
}

int main(int ac, char *av[]){
    if (ac == 4){
        std::string filename = av[1];
        std::string substitude = av[2];
        std::string replacement(av[3]);
        std::string newfile = filename + ".replace";
        Degistirinator degistir(substitude, replacement);
        FileWriter writer(newfile);
        return withFile(filename, degistir, writer);
    }
    return 0;
}