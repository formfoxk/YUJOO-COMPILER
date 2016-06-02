#ifndef __SCANNER_H
#define __SCANNER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// 각 토큰의 토큰 번호를 나타내는 tsymbol
enum tsymbol {	tnull = -1,
	tnot,				tnotequ,		tmod,				tmodAssign,	tident,			tnumber,
/*0						1						2						3						4						5*/
	tand,				tlparen,		trparen,		tmul,				tmulAssign,	tplus,
/*6						7						8						9						10					11*/
	tinc,				taddAssign,	tcomma,			tminus,			tdec,				tsubAssign,
/*12					13					14					15					16					17*/
	tdiv,				tdivAssign,	tsemicolon,	tless,			tlesse,			tassign,
/*18					19					20					21					22					23*/
	tequal,			tgreat,			tgreate,		tlbracket,	trbracket,	teof,
/*24					25					26					27					28					29*/
/*											word symbols													*/
	tconst,			telse,			tif,				tint,				treturn,		tvoid,
/*30					31					32					33					34					35*/
	twhile,			tlbrace,		tor,				trbrace
/*36					37					38					39*/
};

// ID_LENGTH : 유효한 명칭의 길이를 정의하는 상수
// NO_KEYWORDS : 단어 심벌의 개수, Mini C에서는 7개의 단어 심벌이 존재
#define NO_KEYWORDS 7
#define ID_LENGTH 12

// tokenType은 파서에게 넘겨주는 형태로 구조형으로 정의
struct tokenType {
	
int number;							// token number
	union {

		char id[ID_LENGTH];		//	토큰 값을 갖는 명칭
		int num;							//	상수의 값
	} value;								// token value
};

// keyword : 각 지정어의 스트링 값을 갖는 배열
// tnum : 각 지정어에 해당하는 토큰 번호를 갖는 배열
char *keyword[NO_KEYWORDS] = {
	"const", "else", "if", "int", "return", "void", "while"
};
enum tsymbol tnum[NO_KEYWORDS] = {
	tconst, telse, tif, tint, treturn, tvoid, twhile
};

void lexicalError(int n){

	printf(" *** Lexical Error : ");
	switch(n){
		case 1: printf("an identifier length must be less than 12.\n");
			break;	
		case 2: printf("next character must be &.\n");
			break;
		case 3: printf("next character must be |.\n");
			break;
		case 4: printf("invalid character!!!\n");
			break;
	}
}

int superLetter(char ch){

	if(isalpha(ch) || ch == '_') return 1;
	else return 0;
}

int superLetterOrDigit(char ch){

	if(isalnum(ch) || ch == '_') return 1;
	else return 0;
}

int hexValue(char ch)
{
	switch(ch){
		case '0':	case '1':	case '2':	case '3':	case '4':
		case '5':	case '6':	case '7':	case '8':	case '9':
							return (ch - '-');
		case 'A':	case 'B':	case 'C':	case 'D':	case 'E':	case 'F':
							return (ch - 'A' + 10);
		case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
							return (ch - 'a' + 10);
		default: return -1;
	}
}

int getIntNum(char firstCharacter){

	int num = 0;
	int value;
	char ch;

	if(firstCharacter != '0'){							// decimal
		ch = firstCharacter;
		do{
			num = 10*num + (int)(ch - '0');
			ch = getchar();
		}while(isdigit(ch));
	}else{
		ch = getchar();
		if((ch >= '0') && (ch <= '7'))				// octal
			do{
				num = 8*num + (int)(ch - '0');
				ch = getchar();
			}while((ch >= '0') || (ch <= '7'));
		else if((ch == 'X') || (ch == 'x')){	// hexa decimal
				while((value = hexValue(ch = getchar())) != -1)
					num = 16*num + value;
			}
		else num = 0;													// zero
	}
	ungetc(ch, stdin);	/* retract */
	return num;
}

// enum으로 정의된 symbol의 값의 문자열을 반환하는 함수
char * getSymbol(int n){

	char * symbol = "";
	switch(n){
		case tnull:	symbol = "NULL";	break;
		case tnot:	symbol =  "!";	break;
		case tnotequ:	symbol = "!=";	break;
		case tmod:	symbol = "%";	break;
		case tmodAssign:	symbol = "%=";	break;
		case tident:	symbol = "ident";	break;
		case tnumber:	symbol = "number";	break;
		case tand:	symbol = "&&";	break;
		case tlparen:	symbol = "(";	break;
		case trparen:	symbol = ")";	break;
		case tmul:	symbol =  "*";	break;
		case tmulAssign:	symbol = "*=";	break;
		case tplus:	symbol = "+";	break;
		case tinc:	symbol = "++";	break;
		case taddAssign:	symbol =  "+=";	break;
		case tcomma:	symbol =  ",";	break;
		case tminus:	symbol =  "-";	break;
		case tdec:	symbol = "--";	break;
		case tsubAssign:	symbol =  "-=";	break;
		case tdiv: symbol = "/"; break;
		case tdivAssign: symbol = "/="; break;
		case tsemicolon: symbol = ";"; break;
		case tless: symbol = "<"; break;
		case tlesse: symbol = "<="; break;
		case tassign: symbol = "="; break;
		case tequal:	symbol =  "==";	break;
		case tgreat:	symbol =  "";	break;
		case tgreate:	symbol =  ">=";	break;
		case tlbracket:	symbol = "[";	break;
		case trbracket:	symbol = "]";	break;
		case teof:	symbol = "EOF";	break;
		case tconst:	symbol = "const";	break;
		case telse:	symbol = "else";	break;
		case tif:	symbol = "if";	break;
		case tint:	symbol = "int";	break;
		case treturn:	symbol = "return";	break;
		case tvoid:	symbol = "void";	break;
		case twhile:	symbol = "while";	break;
		case tlbrace:	symbol = "{";	break;
		case tor:	symbol = "||";	break;
		case trbrace:	symbol = "}";	break;
	}

	return symbol;
}

#endif