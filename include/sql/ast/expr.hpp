#ifndef SQL_PARSER_AST_EXPR_HPP
#define SQL_PARSER_AST_EXPR_HPP

#include "sql/ast/common.hpp"
#include "sql/ast/identifier.hpp"
#include "sql/ast/literal_value.hpp"

#include <boost/optional.hpp>
#include <boost/spirit/home/x3/support/ast/position_tagged.hpp>
#include <boost/spirit/home/x3/support/ast/variant.hpp>

#include <vector>

namespace sql { namespace ast
    {
        namespace x3 = boost::spirit::x3;

        struct bind_parameter : x3::position_tagged {
        };

        struct schema_column_identifier : x3::position_tagged {
            identifier schema;
            identifier table;
            identifier column;
        };

        struct table_column_identifier : x3::position_tagged {
            identifier table;
            identifier column;
        };

        struct simple_column_identifier : x3::position_tagged {
            identifier column;
        };

        struct column_identifier : x3::variant<
                  schema_column_identifier
                ,  table_column_identifier
                , simple_column_identifier
        >
        {
            using base_type::base_type;
            using base_type::operator=;
        };

        // forward declaration
        struct binary_operation;
        struct function_call;

        struct expr : x3::variant<
                  literal_value
                , bind_parameter
                , column_identifier
                , x3::forward_ast<binary_operation>
                , x3::forward_ast<function_call>
        >
        {
            using base_type::base_type;
            using base_type::operator=;
        };

        typedef std::vector<expr> expr_list;

        struct binary_operation : x3::position_tagged {
            expr first;
            bop op;
            expr second;
        };

        struct function_params_expr_list : x3::position_tagged {
            bool distinct;
            expr_list expressions;
        };

        struct function_params_none : x3::position_tagged {
        };

        struct function_params_row : x3::position_tagged {
        };

        struct function_params : x3::variant<
                  function_params_expr_list
                , function_params_none
                , function_params_row
        >
        {
            using base_type::base_type;
            using base_type::operator=;
        };

        struct function_call : x3::position_tagged {
            identifier name;
            function_params parameters;
        };
    }}

#endif //SQL_PARSER_AST_EXPR_HPP
