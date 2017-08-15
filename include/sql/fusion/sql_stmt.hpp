#ifndef SQL_PARSER_FUSION_SQL_STMT_HPP
#define SQL_PARSER_FUSION_SQL_STMT_HPP

#include "sql/ast/sql_stmt.hpp"

#include <boost/fusion/include/adapt_struct.hpp>

BOOST_FUSION_ADAPT_STRUCT(sql::ast::explain_clause,
                         (bool, explain)
                         (bool, query_plan)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::sql_stmt,
                         (sql::ast::explain_clause, explain)
                         (sql::ast::sql_stmt_variant, stmt)
)

#endif //SQL_PARSER_FUSION_SQL_STMT_HPP
