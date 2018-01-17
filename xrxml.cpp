/**
 * Author: xiaoran
 * Email: xiaoranone@gamil.com
 * xrxml.cpp
 */

#include "xrxml.h"


namespace xrxml{
	
// ------ XMLDocument ------ //
XMLDocument::XMLDocument() {
	
}

void XMLDocument::Clear() {
	
	_errorLineNum = 0;
	_elementSize = 0;
	if(!_elementName.empty()){
		_elementName.clear();
	}

	if(!_elementSet.empty()){
		_elementSet.clear();
	}

	if(!_attributeSet.empty()){
		_attributeSet.clear();
	}

	if(!_textSet.empty()){
		_textSet.clear();
	}

	if(!_commentSet.empty()){
		_commentSet.clear();
	}

	_declaration.Clear();
}

XMLDocument::~XMLDocument() {
	Clear();
}


void XMLDocument::LoadFile(const char* filename){
	std::ifstream readfile(filename, std::ifstream::in);

	if(! readfile) {
		printf("打开文件失败!");
	}

	std::string tmp;
	int i = 0;
	while(! readfile.eof() ){
		getline(readfile, tmp);
		
		XMLDocument::_alltext += tmp;	
	}
}

void XMLDocument::LoadFile(const std::string filename) {
	LoadFile(filename.c_str());
}

void XMLDocument::SaveFile(const char* filename){

}

void XMLDocument::SaveFile(const std::string filename) {
	SaveFile(filename.c_str());
}

XMLElement XMLDocument::FirstElement(){

}



// ------ XMLDeclaration ------ //
XMLDeclaration::XMLDeclaration(){

}

void XMLDeclaration::Clear() {


}

XMLDeclaration::~XMLDeclaration(){
	Clear();
}



// ------ XMLElement ------ //
XMLElement::XMLElement(){

}

void XMLElement::Clear(){

}

XMLElement::~XMLElement(){
	Clear();
}



// ------ XMLAttribute ------ //
XMLAttribute::XMLAttribute(){

}

XMLAttribute::~XMLAttribute(){

}




// ------ XMLComment ------ //
XMLComment::XMLComment(){

}

XMLComment::~XMLComment(){

}



// ------ XMLText ------ //
XMLText::XMLText(){

}

XMLText::~XMLText(){

}



} // xrxml


