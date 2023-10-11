#include "ScalarConverter.hpp"
#include <iostream>
ScalarConverter::Type ScalarConverter::getType(std::string& literal)
{
	if (literal == "+inf")
		return (INF);
	else if (literal == "nan")
		return (NaN);
	else if (literal == "-inf")
		return (NINF);
	else if (literal == "+inff")
		return (INFF);
	else if (literal == "-inff")
		return (NINFF);
	else if (literal == "nanf")
		return (NANF);
	else if (literal.length() == 1 && !std::isdigit(literal[0]))
		return (CHARACTER);
	else if (literal.find('.') != std::string::npos && literal.back() == 'f')
		return (FLOAT);
	else if (literal.find('.') != std::string::npos)
		return (DOUBLE);
	else
		return (INTEGER);
}

char ScalarConverter::getChar(std::string& literal)
{
	return (literal[0]);
}

int ScalarConverter::getInt(std::string& literal)
{
	try {
        int i = std::stoi(literal);
		return i;
    } catch (const std::invalid_argument& e) {
        throw ConvertionException("Literal '"+ literal + "' can not convert to float");
    } catch (const std::out_of_range& e) {
        throw ConvertionException("Literal '"+ literal + "' exceeds the range of float");
    }
}

float ScalarConverter::getFloat(std::string& literal){
	try {
        float f = std::stof(literal);
		return f;
    } catch (const std::invalid_argument& e) {
        throw ConvertionException("Literal '"+ literal + "' can not convert to float");
    } catch (const std::out_of_range& e) {
        throw ConvertionException("Literal '"+ literal + "' exceeds the range of float");
    }
}

double ScalarConverter::getDouble(std::string& literal){
	try {
        double d = std::stof(literal);
		return d;
    } catch (const std::invalid_argument& e) {
        throw ConvertionException("Literal '"+ literal + "' can not convert to float");
    } catch (const std::out_of_range& e) {
        throw ConvertionException("Literal '"+ literal + "' exceeds the range of float");
    }
}
void ScalarConverter::printLiteral(char c, int i, float f, double d, ScalarConverter::Type t){
	if (t == INF || t == NINF || t == NaN || t == INFF || t == NINFF || t == NANF) {
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		if (t == INF || t == INFF || t == NINF || t == NINFF){
			std::cout << "float: ";
			if (t == NINF || t == NINFF)
				std::cout << "-";
			std::cout << "inff" << std::endl;
			std::cout << "double: ";
			if (t == NINF || t == NINFF)
				std::cout << "-";
			std::cout << "inf" << std::endl;
			
		}
		else if (t == NaN || t == NANF) {
			std::cout << "float: " << "nanf" << std::endl;
			std::cout << "double: " << "nan" << std::endl;
		}
	}
	else {
		if (isprint(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: " << "not printable" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float" << f << std::endl;
		std::cout << "double" << d << std::endl;
	}
}


bool ScalarConverter::convert(std::string& literal){
	ScalarConverter::Type type = getType(literal);
	try {
		switch (type)
		{
			case CHARACTER:
				printLiteral(getChar(literal),
					static_cast<int>(getChar(literal)),
					static_cast<float>(getChar(literal)),
					static_cast<double>(getChar(literal)),type);
				break;
			case INTEGER:
				printLiteral(getInt(literal),
					static_cast<int>(getInt(literal)),
					static_cast<float>(getInt(literal)),
					static_cast<double>(getInt(literal)),type);
				break;
			case FLOAT:
				printLiteral(getFloat(literal),
					static_cast<int>(getFloat(literal)),
					static_cast<float>(getFloat(literal)),
					static_cast<double>(getFloat(literal)),type);
				break;
			case DOUBLE:
				printLiteral(getDouble(literal),
					static_cast<int>(getDouble(literal)),
					static_cast<float>(getDouble(literal)),
					static_cast<double>(getDouble(literal)),type);
				break;
			default:
				printLiteral(0,0,0,0,type);
				break;
		}
	}catch (ConvertionException& e){
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	return true;
}

ScalarConverter::ConvertionException::ConvertionException(const std::string& message): message(message.c_str()) {}
const char* ScalarConverter::ConvertionException::what() const throw(){
	return this->message;
}