#ifndef _LEXER_H
#define _LEXER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
enum class Symbol: unsigned {
    input = 0,
    stmlist = 1,
    expr = 2,
    stmlistp = 3,
    term = 4,
    exprp = 5,
    factor = 6,
    termp = 7,
    Eof = 8,
    Semicolon = 9,
    stmp = 10,
    OpAdd = 11,
    OpSub = 12,
    OpMul = 13,
    OpDiv = 14,
    Number = 15,
    Ident = 16,
    OpenPar = 17,
    ClosePar = 18,
    Epsilon = 19
};
using SymbolInfo = std::pair<Symbol, std::string>;

class Lexer {
public:
    Lexer(const std::vector<SymbolInfo>& tklst): tklist(tklst) {
        it = tklist.begin();
    }

    Symbol getNextToken() {
        if (it == tklist.end()) {
            return Symbol::Eof;
        }
        Symbol tk = it->first;
        text = it->second;
        it++;
        
        return tk;
    }
    
    bool hasTokens() { return it != tklist.end(); }
    std::string getText() { return text; }

private:
    std::string text;
    std::vector<SymbolInfo> tklist;
    std::vector<SymbolInfo>::iterator it;
};
#endif
