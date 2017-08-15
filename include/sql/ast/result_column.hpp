#ifndef SQL_PARSER_AST_RESULT_COLUMN_HPP
#define SQL_PARSER_AST_RESULT_COLUMN_HPP

#include "sql/ast/expr.hpp"
#include "sql/ast/identifier.hpp"

#include <boost/optional.hpp>
#include <boost/spirit/home/x3/support/ast/position_tagged.hpp>
#include <boost/spirit/home/x3/support/ast/variant.hpp>

#include <vector>

namespace sql { namespace ast
    {
        namespace x3 = boost::spirit::x3;

        struct result_column_all : x3::position_tagged {
        };

        struct result_column_table : x3::position_tagged {
            table_identifier identifier;
        };

        struct result_column_expr : x3::position_tagged {
            expr expression;
            boost::optional<identifier> alias;
        };

        struct result_column : x3::variant<
              result_column_all
            , result_column_table
            , result_column_expr
        >
        {
            using base_type::base_type;
            using base_type::operator=;
        };

        // forward AST required otherwise GCC fails because of the
        // implicitly deleted copy constructor of result_column
        typedef std::vector<x3::forward_ast<result_column>> result_column_list;
    }}

#endif
