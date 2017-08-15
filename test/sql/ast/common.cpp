#include "sql/ast/common.hpp"
#include "test/test.hpp"

namespace sql{ namespace  parser {
    using ast::bop;
    using ast::left;
    using ast::right;
    using ast::terminal;
    using ast::quot;

    TEST_CASE( "Terminal function for quotation terminals", "[common]" ) {
        CHECK( terminal(quot::NONE, left) == "" );
        CHECK( terminal(quot::NONE, right) == "" );
        CHECK( terminal(quot::SINGLE, left) == "'" );
        CHECK( terminal(quot::SINGLE, right) == "'" );
        CHECK( terminal(quot::DOUBLE, left) == "\"" );
        CHECK( terminal(quot::DOUBLE, right) == "\"" );
        CHECK( terminal(quot::SQUARED, left) == "[" );
        CHECK( terminal(quot::SQUARED, right) == "]" );
        CHECK( terminal(quot::BACKTICK, left) == "`" );
        CHECK( terminal(quot::BACKTICK, right) == "`" );
    }

    TEST_CASE( "Terminal function for binary operators", "[common]" ) {
        CHECK( terminal(bop::CAT) == "||" );

        CHECK( terminal(bop::MUL) == "*" );
        CHECK( terminal(bop::DIV) == "/" );
        CHECK( terminal(bop::MOD) == "%" );
        CHECK( terminal(bop::ADD) == "+" );
        CHECK( terminal(bop::SUB) == "-" );

        CHECK( terminal(bop::BSR) == ">>" );
        CHECK( terminal(bop::BSL) == "<<" );
        CHECK( terminal(bop::BAND) == "&" );
        CHECK( terminal(bop::BOR) == "|" );

        CHECK( terminal(bop::LT) == "<" );
        CHECK( terminal(bop::LE) == "<=" );
        CHECK( terminal(bop::GT) == ">" );
        CHECK( terminal(bop::GE) == ">=" );
        CHECK( terminal(bop::EQ) == "=" );
        CHECK( terminal(bop::EQQ) == "==" );
        CHECK( terminal(bop::NE) == "!=" );
        CHECK( terminal(bop::NEE) == "<>" );
        CHECK( terminal(bop::IS) == "IS" );
        CHECK( terminal(bop::ISNOT) == "IS NOT" );

        CHECK( terminal(bop::IN) == "IN" );

        CHECK( terminal(bop::LIKE) == "LIKE" );
        CHECK( terminal(bop::GLOB) == "GLOB" );
        CHECK( terminal(bop::MATCH) == "MATCH" );
        CHECK( terminal(bop::REGEXP) == "REGEXP" );

        CHECK( terminal(bop::AND) == "AND" );
        CHECK( terminal(bop::OR) == "OR" );
    }
}}
