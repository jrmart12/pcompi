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

static inline unsigned indexOf(Symbol s) {
    unsigned index = static_cast<unsigned>(s);
    if (index < 8) return index;
    else return (index - 8);
}

static inline bool isTerminal(Symbol s) {
    return static_cast<unsigned>(s) >= 8;
}

struct Rule {
    Symbol lhs;
    std::vector<Symbol> rhs;
    bool isEmpty() const { return rhs.empty(); }
};

Rule none;
std::vector<std::vector<Rule>> ll1_table = {
    /* input */ { none, none, none, none, none, none, none, {Symbol::input, {Symbol::stmlist, Symbol::Semicolon, }}, {Symbol::input, {Symbol::stmlist, Symbol::Semicolon, }}, {Symbol::input, {Symbol::stmlist, Symbol::Semicolon, }}, none, },
    /* stmlist */ { none, none, none, none, none, none, none, {Symbol::stmlist, {Symbol::expr, Symbol::stmlistp, }}, {Symbol::stmlist, {Symbol::expr, Symbol::stmlistp, }}, {Symbol::stmlist, {Symbol::expr, Symbol::stmlistp, }}, none, },
    /* expr */ { none, none, none, none, none, none, none, {Symbol::expr, {Symbol::term, Symbol::exprp, }}, {Symbol::expr, {Symbol::term, Symbol::exprp, }}, {Symbol::expr, {Symbol::term, Symbol::exprp, }}, none, },
    /* stmlistp */ { none, {Symbol::stmlistp, {Symbol::Semicolon, Symbol::expr, Symbol::stmp, }}, none, none, none, none, none, none, none, none, none, },
    /* term */ { none, none, none, none, none, none, none, {Symbol::term, {Symbol::factor, Symbol::termp, }}, {Symbol::term, {Symbol::factor, Symbol::termp, }}, {Symbol::term, {Symbol::factor, Symbol::termp, }}, none, },
    /* exprp */ { none, none, none, {Symbol::exprp, {Symbol::OpAdd, Symbol::term, Symbol::exprp, }}, {Symbol::exprp, {Symbol::OpSub, Symbol::term, Symbol::exprp, }}, {Symbol::exprp, {Symbol::OpMul, Symbol::term, Symbol::exprp, }}, {Symbol::exprp, {Symbol::OpDiv, Symbol::term, Symbol::exprp, }}, none, none, none, none, },
    /* factor */ { none, none, none, none, none, none, none, {Symbol::factor, {Symbol::Number, }}, {Symbol::factor, {Symbol::Ident, }}, {Symbol::factor, {Symbol::OpenPar, Symbol::expr, Symbol::ClosePar, }}, none, },
    /* termp */ { none, none, none, none, none, {Symbol::termp, {Symbol::OpMul, Symbol::factor, Symbol::termp, }}, none, none, none, none, none, },
};
