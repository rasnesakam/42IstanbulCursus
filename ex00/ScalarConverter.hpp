#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP
#include <string>
class ScalarConverter {
	private:
		enum Type {
			CHARACTER,
			INTEGER,
			FLOAT,
			DOUBLE,
			INF,
			NINF,
			NaN,
			INFF,
			NINFF,
			NANF
		};
		static Type getType(std::string& literal);
		static char getChar(std::string& literal);
		static int getInt(std::string& literal);
		static float getFloat(std::string& literal);
		static double getDouble(std::string& literal);
		static void displayChar(char c);
		static void displayInt(int i);
		static void displayFloat(float f);
		static void displayDouble(double d);
		static void printLiteral(char c, int i, float f, double d, ScalarConverter::Type t);
	public:
		static bool convert(std::string& literal);
		class ConvertionException: public std::exception {
			private:
				const std::string message;
			public:
				ConvertionException(const std::string& message);
				const char* what() const throw();
				~ConvertionException() throw();
		};
};


#endif