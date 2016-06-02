%{
	#include <stdio.h>
	#include <stdlib.h>
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
%}

%%
"const"		return(tconst);
"else"		return(telse);
"if"			return(tif);
"int"			return(tint);
"return"	return(treturn);
"void"		return(tvoid);
"while"		return(twhile);

"!"				return(tnot);
"&"				return(tand);
"|"				return(tor);
"*"				return(tmul);
"%"				return(tmod);
"/"				return(tdiv);
"+"				return(tplus);
"-"				return(tminus);

","				return(tcomma);
";"				return(tsemicolon);

"="				return(tassign);
"<"				return(tless);
">"				return(tgreat);

"=="			return(tequal);
"!="			return(tnotequ);
"<="			return(tlesse);
">="			return(tgreate);
"&&"			return(tand);
"||"			return(tor);
"++"			return(tinc);
"--"			return(tdec);
"+="			return(taddAssign);
"-="			return(tsubAssign);
"*="			return(tmulAssign);
"/="			return(tdivAssign);
"%="			return(tmodAssign);

"("				return(tlparen);
")"				return(trparen);
"["				return(tlbracket);
"]"				return(trbracket);
"{"				return(tlbrace);
"}"				return(trbrace);

[A-Za-z_][A-Za-z0-9_]*											return(tident);
[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)?		return(tnumber);
"/*"([^*]|\*+[^*/])*\**"*/"		;
"//".*												;
[ \t\n]												;
							return(yytext[0]);
%%

int yywrap(){

	printf(" End of Lex\n");
	return 1;
}

int main(){

	enum tsymbol tn;
	while ((tn = yylex())) {
		printf("%s\t%d\t", yytext, tn);
		if (tn == tident || tn == tnumber) 
			printf("%s\n", yytext);
		else 
			printf("%d\n", 0);
  }

  return 0;
}