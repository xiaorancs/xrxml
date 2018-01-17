#include "xrxml.h"
#include "xrxml.cpp"


int main()
{
	xrxml::XMLDocument doc;
	std::string file = "in.txt";

	doc.LoadFile(file);

	std::cout<< doc.GetAllText() << std::endl;

	return 0;
}
