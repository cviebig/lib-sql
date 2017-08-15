#ifndef SQL_PARSER_AST_SQL_STMT_HPP
#define SQL_PARSER_AST_SQL_STMT_HPP

#include "sql/ast/create_table_stmt.hpp"
#include "sql/ast/import_table_stmt.hpp"
#include "sql/ast/select_stmt.hpp"

#include <boost/spirit/home/x3/support/ast/position_tagged.hpp>

#include <vector>

namespace sql { namespace ast
{
    namespace x3 = boost::spirit::x3;

    struct explain_clause : x3::position_tagged {
        bool explain;
        bool query_plan;
    };

    struct sql_stmt_variant : x3::variant<
              select_stmt
            , create_table_stmt
            , import_table_stmt
    >
    {
        using base_type::base_type;
        using base_type::operator=;
    };

    struct sql_stmt : x3::position_tagged
    {
        explain_clause explain;
        sql_stmt_variant stmt;
    };

    typedef std::vector<sql_stmt> sql_stmt_list;
}}

#endif //SQL_PARSER_AST_SQL_STMT_HPP
