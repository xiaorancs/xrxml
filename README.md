ttribute值
删除指定的属性值
打印对应的文本值
打印xml的申明信息
理解tinyxml2的设计思路
所有节点的父节点，XMLNode{}，
关键新如何定义XMLNode的节点，好的接口，才能有好的代码。 主要的功能类，
XML文档的类，针对的是解释最上层的文档，读取，解析，创建，copy等
class XMLDocument : XMLNode{}
XML的属性对应的值，处理的方法和属性
class XMLElement : XMLNode{}
XML中的文本信息
class XMLText : XMLNode{}
XML中的注释信息 class XMLComment : XMLNode{}
XML中的声明的部分
class XMLDeclaration : XMLNode{}
XML中的不确定的部分信息
class XMLUnknow : XMLNode{}
先不要考虑其他，从主要功能出发，之后再次整理代码。

参考：tinyxml2
