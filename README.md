# XRXML
<b> 目的：实现C++11支持的XML解析器，提高对C++的理解和使用能力。

## 阅读好的源码tinyxml2
关键新如何定义XMLNode的节点，好的接口，才能有好的代码。 主要的功能类，     
XML文档的类，针对的是解释最上层的文档，读取，解析，创建，copy等。    
class XMLDocument          
XML的属性对应的值，处理的方法和属性         
class XMLElement            
XML中的文本信息           
class XMLText          
XML中的注释信息 class XMLComment : 
XML中的声明的部分
class XMLDeclaration     
XML中的不确定的部分信息   
先不要考虑其他，从主要功能出发，之后再次整理代码。

参考：tinyxml2
