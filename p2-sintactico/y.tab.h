/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_MAIN = 258,
    TOK_INT = 259,
    TOK_BOOLEAN = 260,
    TOK_ARRAY = 261,
    TOK_FUNCTION = 262,
    TOK_IF = 263,
    TOK_ELSE = 264,
    TOK_WHILE = 265,
    TOK_SCANF = 266,
    TOK_PRINTF = 267,
    TOK_RETURN = 268,
    TOK_ERROR = 269,
    TOK_PUNTOYCOMA = 270,
    TOK_COMA = 271,
    TOK_PARENTESISIZQUIERDO = 272,
    TOK_PARENTESISDERECHO = 273,
    TOK_CORCHETEIZQUIERDO = 274,
    TOK_CORCHETEDERECHO = 275,
    TOK_LLAVEIZQUIERDA = 276,
    TOK_LLAVEDERECHA = 277,
    TOK_ASIGNACION = 278,
    TOK_MAS = 279,
    TOK_MENOS = 280,
    TOK_DIVISION = 281,
    TOK_ASTERISCO = 282,
    TOK_AND = 283,
    TOK_OR = 284,
    TOK_NOT = 285,
    TOK_IGUAL = 286,
    TOK_DISTINTO = 287,
    TOK_MENORIGUAL = 288,
    TOK_MAYORIGUAL = 289,
    TOK_MENOR = 290,
    TOK_MAYOR = 291,
    TOK_IDENTIFICADOR = 292,
    TOK_CONSTANTE_ENTERA = 293,
    TOK_TRUE = 294,
    TOK_FALSE = 295
  };
#endif
/* Tokens.  */
#define TOK_MAIN 258
#define TOK_INT 259
#define TOK_BOOLEAN 260
#define TOK_ARRAY 261
#define TOK_FUNCTION 262
#define TOK_IF 263
#define TOK_ELSE 264
#define TOK_WHILE 265
#define TOK_SCANF 266
#define TOK_PRINTF 267
#define TOK_RETURN 268
#define TOK_ERROR 269
#define TOK_PUNTOYCOMA 270
#define TOK_COMA 271
#define TOK_PARENTESISIZQUIERDO 272
#define TOK_PARENTESISDERECHO 273
#define TOK_CORCHETEIZQUIERDO 274
#define TOK_CORCHETEDERECHO 275
#define TOK_LLAVEIZQUIERDA 276
#define TOK_LLAVEDERECHA 277
#define TOK_ASIGNACION 278
#define TOK_MAS 279
#define TOK_MENOS 280
#define TOK_DIVISION 281
#define TOK_ASTERISCO 282
#define TOK_AND 283
#define TOK_OR 284
#define TOK_NOT 285
#define TOK_IGUAL 286
#define TOK_DISTINTO 287
#define TOK_MENORIGUAL 288
#define TOK_MAYORIGUAL 289
#define TOK_MENOR 290
#define TOK_MAYOR 291
#define TOK_IDENTIFICADOR 292
#define TOK_CONSTANTE_ENTERA 293
#define TOK_TRUE 294
#define TOK_FALSE 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
