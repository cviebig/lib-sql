#ifndef SQL_PARSER_FUSION_EXPR_HPP
#define SQL_PARSER_FUSION_EXPR_HPP

#include "sql/ast/expr.hpp"

#include <boost/fusion/include/adapt_struct.hpp>

BOOST_FUSION_ADAPT_STRUCT(sql::ast::bind_parameter)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::schema_column_identifier,
                         (sql::ast::identifier, schema)
                         (sql::ast::identifier, table)
                         (sql::ast::identifier, column)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::table_column_identifier,
                         (sql::ast::identifier, table)
                         (sql::ast::identifier, column)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::simple_column_identifier,
                         (sql::ast::identifier, column)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::binary_operation,
                         (sql::ast::expr, first)
                         (sql::ast::bop, op)
                         (sql::ast::expr, second)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::function_params_expr_list,
                         (bool, distinct)
                         (sql::ast::expr_list, expressions)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::function_params_none)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::function_params_row)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::function_call,
                         (sql::ast::identifier, name)
                         (sql::ast::function_params, parameters)
)

#endif //SQL_PARSER_FUSION_EXPR_HPP
