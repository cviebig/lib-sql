#ifndef SQL_PARSER_FUSION_SELECT_STMT_HPP
#define SQL_PARSER_FUSION_SELECT_STMT_HPP

#include "sql/ast/select_stmt.hpp"

#include <boost/fusion/include/adapt_struct.hpp>

BOOST_FUSION_ADAPT_STRUCT(sql::ast::ordering_term,
                         (sql::ast::expr, expression)
                         (sql::ast::direction_type, direction)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::orderby_clause,
                         (sql::ast::ordering_term_list, by) (bool, dummy)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::limit_clause,
                         (sql::ast::expr, limit)
                         (boost::optional<sql::ast::expr>, offset)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::select_stmt,
                         (sql::ast::select_core, core)
                         (boost::optional<sql::ast::orderby_clause>, ordering)
                         (boost::optional<sql::ast::limit_clause>, limits)
)

#endif //SQL_PARSER_FUSION_SELECT_STMT_HPP
