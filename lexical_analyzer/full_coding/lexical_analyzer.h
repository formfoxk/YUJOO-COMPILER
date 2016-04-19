#ifndef __LEXICAL_ANALYZER_H
#define __LEXICAL_ANALYZER_H

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

#endif