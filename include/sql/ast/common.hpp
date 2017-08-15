#ifndef SQL_PARSER_AST_COMMON_HPP
#define SQL_PARSER_AST_COMMON_HPP

#include <iostream>
#include <type_traits>

namespace sql { namespace ast {

        // quotations
        enum class quot
        {
            NONE,
            SINGLE,
            DOUBLE,
            SQUARED,
            BACKTICK
        };

        const bool left = false;
        const bool right = true;

        // cannot be used within parser directies
        inline std::string terminal(quot const q, bool const left)
        {
            const std::string quotation_terminals[][2] ={
                      {"",   ""}
                    , {"'",  "'"}
                    , {"\"", "\""}
                    , {"[",  "]"}
                    , {"`",  "`"}
            };

            typedef std::underlying_type<quot>::type utype;
            return quotation_terminals[static_cast<utype>(q)][left];
        };

        // binary operations
        // https://www.sqlite.org/lang_expr.html
        enum class bop
        {
            // String
              CAT           // 1
            // arithmetic
            , MUL           // 2
            , DIV           // 2
            , MOD           // 2
            , ADD           // 3
            , SUB           // 3
            // bit-wise
            , BSR           // 4
            , BSL           // 4
            , BAND          // 4
            , BOR           // 4
            // relational
            , LT            // 5
            , LE            // 5
            , GT            // 5
            , GE            // 5
            , EQ            // 6
            , EQQ           // 6
            , NE            // 6
            , NEE           // 6
            , IS            // 6
            , ISNOT         // 6
            // set
            , IN            // 6
            , LIKE          // 6
            , GLOB          // 6
            , MATCH         // 6
            , REGEXP        // 6
            , AND           // 7
            , OR            // 8
        };

        // cannot be used within parser directies
        inline std::string terminal(bop const op)
        {
            const std::string bop_terminals[] = {
                    // String
                    "||"
                    // arithmetic
                    , "*"
                    , "/"
                    , "%"
                    , "+"
                    , "-"
                    // bit
                    , ">>"
                    , "<<"
                    , "&"
                    , "|"
                    // relational
                    , "<"
                    , "<="
                    , ">"
                    , ">="
                    , "="
                    , "=="
                    , "!="
                    , "<>"
                    , "IS"
                    , "IS NOT"
                    // set
                    , "IN"
                    // string matching
                    , "LIKE"
                    , "GLOB"
                    , "MATCH"
                    , "REGEXP"
                    // boolean
                    , "AND"
                    , "OR"
            };

            typedef std::underlying_type<bop>::type utype;
            return bop_terminals[static_cast<utype>(op)];
        };

        enum class direction_type { asc, desc, omitted };
}}

#endif //SQL_PARSER_AST_COMMON_HPP
