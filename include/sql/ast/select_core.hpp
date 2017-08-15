#ifndef SQL_PARSER_AST_SELECT_CORE_HPP
#define SQL_PARSER_AST_SELECT_CORE_HPP

#include "sql/ast/expr.hpp"
#include "sql/ast/join_clause.hpp"
#include "sql/ast/result_column.hpp"
#include "sql/ast/table_or_subquery.hpp"

#include <boost/optional.hpp>
#include <boost/spirit/home/x3/support/ast/position_tagged.hpp>
#include <boost/spirit/home/x3/support/ast/variant.hpp>

#include <vector>

namespace sql { namespace ast
    {
        namespace x3 = boost::spirit::x3;

        enum class select_type { distinct, all, none };

        // forward declaration
        struct table_or_subquery;
        typedef std::vector<table_or_subquery> table_or_subquery_list;

        // forward declaration
        struct join_clause;

        struct from_clause : x3::variant<
                  x3::forward_ast<table_or_subquery_list>
                , x3::forward_ast<join_clause>
        >
        {
            using base_type::base_type;
            using base_type::operator=;
        };

        struct groupby_clause : x3::position_tagged {
            expr_list by;
            boost::optional<expr> having;
        };

        struct select_core_select : x3::position_tagged
        {
            select_type type;
            result_column_list columns;
            boost::optional<from_clause> from;
            boost::optional<expr> where;
            boost::optional<groupby_clause> grouping;
        };

        typedef std::vector<expr_list> expr_list_list;

        struct select_core_values : x3::position_tagged
        {
            expr_list_list expressions;
        };

        struct select_core : x3::variant<
                  select_core_select
                , select_core_values
        >
        {
            using base_type::base_type;
            using base_type::operator=;
        };
    }}

#endif //SQL_PARSER_AST_SELECT_CORE_HPP
