#ifndef SQL_PARSER_FUSION_JOIN_CLAUSE_HPP
#define SQL_PARSER_FUSION_JOIN_CLAUSE_HPP

#include "sql/ast/join_clause.hpp"

#include <boost/fusion/include/adapt_struct.hpp>

BOOST_FUSION_ADAPT_STRUCT(sql::ast::join_operator,
                         (bool, natural)
                         (sql::ast::join_operator_type, type)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::join_constraint_expr,
                         (sql::ast::expr, expression)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::join_constraint_columns,
                         (sql::ast::identifier_list, columns)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::join_constraint_omitted)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::join,
                         (sql::ast::join_operator, op)
                         (sql::ast::table_or_subquery, table)
                         (sql::ast::join_constraint, constraint)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::join_clause,
                         (sql::ast::table_or_subquery, table)
                         (sql::ast::join_list, joins)
)

#endif //SQL_PARSER_FUSION_JOIN_CLAUSE_HPP
