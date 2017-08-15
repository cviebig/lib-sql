#ifndef SQL_PARSER_FUSION_TABLE_OR_SUBQUERY_HPP
#define SQL_PARSER_FUSION_TABLE_OR_SUBQUERY_HPP

#include "sql/ast/table_or_subquery.hpp"

#include <boost/fusion/include/adapt_struct.hpp>

BOOST_FUSION_ADAPT_STRUCT(sql::ast::table_or_subquery_index,
                         (boost::optional<sql::ast::identifier>, index)
                         (sql::ast::index_usage_type, index_usage)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::table_or_subquery_table,
                         (sql::ast::aliased_table_identifier, table)
                         (sql::ast::table_or_subquery_index, index)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::table_or_subquery_sublist,
                         (sql::ast::table_or_subquery_list, list;)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::table_or_subquery_join,
                         (sql::ast::join_clause, join)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::table_or_subquery_select,
                         (sql::ast::select_stmt, stmt)
                         (boost::optional<sql::ast::identifier>, alias)
)

#endif //SQL_PARSER_FUSION_TABLE_OR_SUBQUERY_HPP
