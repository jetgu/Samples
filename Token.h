#pragma once
#include <string>
#include <map>
using namespace std;

#define GLOBAL_DICT_NAME "__G__"
#define ARGV_ARRAY_NAME "__ARGV__"

enum KEYWORD {
	PROGRAM, BEGIN, END, IF, ELSE, WHILE, FOR, ID, INTEGER, REAL, STRING,
	EQUAL, NOT_EQUAL, NOT, ASSIGN, PLUS, MINUS, MUL, DIV, MOD, SEMI, LPAREN, RPAREN,
	BREAK, RETURN, CONTINUE, GREATER, LESS, GREATER_EQUAL, LESS_EQUAL, AND, OR, COLON,
	BUILTIN, FUNCTION, COMMA, PLUS_PLUS, MINUS_MINUS, PLUS_EQUAL, MINUS_EQUAL, LSQUARE, RSQUARE, DOT, SHARP,  
	NONE, BTRUE, BFALSE, CLASS, EOFI
};

class CToken
{
public:
	CToken();
	CToken(KEYWORD type, const string& value, int lineNo, int column, const string& filename);
	~CToken();
	KEYWORD type() { return m_enuType; }
	string value() const { return m_strValue; }
	int lineNo() const { return m_nLineNo; }
	int column() const { return m_nColumn; }
	string filename() const { return m_strFilename; }
	void set_filename(const string& filename){ m_strFilename = filename; }
	void set_line_column(int lineNo, int column);
	static CToken getToken(const string& key, int lineNo, int column, const string& filename);
private:
	KEYWORD m_enuType;
	string m_strValue;
	int		m_nLineNo;
	int		m_nColumn;
	string m_strFilename;
};

