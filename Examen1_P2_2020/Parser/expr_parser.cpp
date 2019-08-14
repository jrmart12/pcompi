#include "expr_parser.h"

int Parser::parse() {
    cant = 0;
    token = lexer.getNextToken();
    input();
    return cant;
    
}

void Parser::input(){
        stmlist();

}

void Parser::stmlist(){
    expr();
    stmlistp();
}

void Parser::stmlistp(){
    if(token == Symbol::Semicolon){
        std::cout<<"semicolon"<<std::endl;
        token = lexer.getNextToken();
        cant++;
        if(token==Symbol::Eof){
             std::cout<<"eof"<<std::endl;
            return ;
        }
        expr();
        stmlistp();
    } 
}


void Parser::expr(){
    term();
    exprp();
}

void Parser::exprp(){
    if(token == Symbol::OpAdd || token == Symbol::OpSub || token == Symbol::OpMul || token  == Symbol::OpDiv){
        token = lexer.getNextToken();
        std::cout<<"+-"<<std::endl;
        term();
        exprp();
    } 
}

void Parser::term(){
    factor();
    termp();
}

void Parser::termp(){
    if(token == Symbol::OpMul){
        std::cout<<"eof"<<std::endl;
        token = lexer.getNextToken();
        factor();
        termp();
    } 
}

void Parser::factor(){
    if(token == Symbol::Ident){
        throw "ERROR";
    } 
    else if(token == Symbol::Number){
        std::cout<<"number"<<std::endl;
        token = lexer.getNextToken();
    } 
    else if(token == Symbol::OpenPar){
        token = lexer.getNextToken();
        expr();
        if(token != Symbol::ClosePar){
            throw "ERROR";
        } 
        token = lexer.getNextToken();
    } else{
        throw "ERROR";
    }
}