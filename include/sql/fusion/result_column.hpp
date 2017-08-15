#ifndef SQL_PARSER_FUSION_RESULT_COLUMN_HPP
#define SQL_PARSER_FUSION_RESULT_COLUMN_HPP

#include "sql/ast/result_column.hpp"

#include <boost/fusion/include/adapt_struct.hpp>

namespace x3 = boost::spirit::x3;

BOOST_FUSION_ADAPT_STRUCT(sql::ast::result_column_all)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::result_column_table,
                         (sql::ast::table_identifier, identifier)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::result_column_expr,
                         (sql::ast::expr, expression)
                         (boost::optional<sql::ast::identifier>, alias)
)

#endif //SQL_PARSER_FUSION_RESULT_COLUMN_HPP
