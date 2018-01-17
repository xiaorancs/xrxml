/**
  Author: xiaoran
  Email: xiaoranone@gamil.com

  手动实现XML的解析工作

  */

#ifndef XRXML_INCLUDE
#define XRXML_INCLUDE

#include <ctype.h>
#include <climits>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <fstream>

#include <assert.h>
#define XRXMLASSERT assert


namespace xrxml{
class XMLDocument;    // 文档
class XMLElement;     // 元素
class XMLComment;     // 注释
class XMLDeclaration; // 声明 
class XMLAttribute;   // 属性
class XMLText;		  // XML文件中没有被标记的文本


/*
 XMLDeclaration
 */
class XMLDeclaration
{
public:
	XMLDeclaration();
	~XMLDeclaration();

	void Clear();

private:
	std::string _version;
	std::string _encoding;
	bool _standalone;
}; // XMLDeclaration


// --- XMLElement --- //
class XMLElement
{
friend class XMLDocument;
public:
	XMLElement();
	~XMLElement();

	void Clear();
	
	bool operator< (const XMLElement& ele) const {
		if(_key < ele._key) return true;
		if(_key == ele._key && _value < ele._value) return true;
		return false;
	}

private:

	std::string _key;
	std::string _value;
	int _subElementSize;
	
	std::list<XMLAttribute> _elementAttribute;
	
	// 根据下标得到
	int _nextIndex;
	int _prevIndex;
	
	std::list<XMLElement> _subElementSet;
	
}; // XMLElement


// --- XMLAttribute --- //
class XMLAttribute
{
public:
	XMLAttribute();
	~XMLAttribute();

private:
	std::string _key;
	std::string _value;

}; // XMLAttribute


// --- XMLComment --- //
class XMLComment
{
public:
	XMLComment();
	~XMLComment();

	bool operator < (XMLComment & comment ) const {
		return _commentLineNum < comment._commentLineNum;

	}
private:
	int _commentLineNum; // 注释的行号

	std::string _comment;// 只是内容

}; // XMLComment


// --- XMLText --- //
class XMLText
{
public:
	XMLText();
	~XMLText();

	bool operator < (XMLText& text) const {
		return _textLineNum < text._textLineNum;
	}

private:
	int _textLineNum;

	std::string _text;
};



/*
 XMLDocument
*/

class XMLDocument
{
friend class XMLElement;
friend class XMLComment;
friend class XMLDeclaration;
friend class XMLText;

public:
	XMLDocument();
	~XMLDocument();

	void Clear();
	inline int ErrorLineNum() const {
		return _errorLineNum;
	}
	void LoadFile(const char* filename);
	void LoadFile(const std::string filename);
	
	void SaveFile(const char* filename);
	void SaveFile(const std::string filename);

	XMLElement FirstElement();
	
	std::list<std::string> GetXMLElementName() const {
		return _elementName;
	}

	std::list<XMLElement> GetXMLElementSet() const {
		return _elementSet;
	}
	
	std::list<XMLAttribute> GetXMLAttributeSet() const {
		return _attributeSet;
	}

	std::list<XMLText> GetXMLTextSet() const {
		return _textSet;
	}

	std::list<XMLComment> GetXMLCommentSet() const {
		return _commentSet;
	}

	XMLDeclaration GetDeclaration() const {
		return _declaration;
	}

	std::string GetAllText() const {
		return _alltext;
	}

private:
	int _errorLineNum;
	int _elementSize;
	
	std::string _alltext;

	std::list<std::string> _elementName;
	std::list<XMLElement> _elementSet;
	std::list<XMLAttribute> _attributeSet;
	std::list<XMLText> _textSet;
	std::list<XMLComment> _commentSet;

	XMLDeclaration _declaration;

}; // XMLDocument




} // xrxml

#endif // XRXML_INCLUDE
