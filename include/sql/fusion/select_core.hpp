#ifndef SQL_PARSER_FUSION_SELECT_CORE_HPP
#define SQL_PARSER_FUSION_SELECT_CORE_HPP

#include "sql/ast/select_core.hpp"

#include <boost/fusion/include/adapt_struct.hpp>

BOOST_FUSION_ADAPT_STRUCT(sql::ast::groupby_clause,
                         (sql::ast::expr_list, by)
                         (boost::optional<sql::ast::expr>, having)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::select_core_select,
                         (sql::ast::select_type, type)
                         (sql::ast::result_column_list, columns)
                         (boost::optional<sql::ast::from_clause>, from)
                         (boost::optional<sql::ast::expr>, where)
                         (boost::optional<sql::ast::groupby_clause>, grouping)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::select_core_values,
                         (sql::ast::expr_list_list, expressions)
)

#endif //SQL_PARSER_FUSION_SELECT_CORE_HPP
