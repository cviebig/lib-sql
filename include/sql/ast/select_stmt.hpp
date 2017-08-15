#ifndef SQL_PARSER_AST_SELECT_STMT_HPP
#define SQL_PARSER_AST_SELECT_STMT_HPP

#include "sql/ast/common.hpp"
#include "sql/ast/select_core.hpp"

#include <boost/optional.hpp>
#include <boost/spirit/home/x3/support/ast/position_tagged.hpp>

#include <vector>

namespace sql { namespace ast
{
    namespace x3 = boost::spirit::x3;

    struct ordering_term : x3::position_tagged {
        expr expression;
        direction_type direction;
    };

    typedef std::vector<ordering_term> ordering_term_list;

    struct orderby_clause : x3::position_tagged {
        ordering_term_list by;
        bool dummy;
    };

    struct limit_clause : x3::position_tagged {
        expr limit;
        boost::optional<expr> offset;
    };

    // forward declaration
    struct select_core;

    struct select_stmt : x3::position_tagged
    {
        x3::forward_ast<select_core> core;
        boost::optional<orderby_clause> ordering;
        boost::optional<limit_clause> limits;
    };
}}

#endif //SQL_PARSER_AST_SELECT_STMT_HPP
