#ifndef SQL_PARSER_AST_TABLE_OR_SUBQUERY_HPP
#define SQL_PARSER_AST_TABLE_OR_SUBQUERY_HPP

#include "sql/ast/common.hpp"
#include "sql/ast/identifier.hpp"
#include "sql/ast/join_clause.hpp"
#include "sql/ast/select_stmt.hpp"

#include <boost/optional.hpp>
#include <boost/spirit/home/x3/support/ast/position_tagged.hpp>
#include <boost/spirit/home/x3/support/ast/variant.hpp>

#include <vector>

namespace sql { namespace ast
{
    enum class index_usage_type { not_specified, yes, no };

    struct table_or_subquery_index
    {
        boost::optional<identifier> index;
        index_usage_type index_usage;
    };

    struct table_or_subquery_table
    {
        aliased_table_identifier table;
        table_or_subquery_index index;
    };

    // forward declaration
    struct table_or_subquery;

    typedef std::vector<table_or_subquery> table_or_subquery_list;

    struct table_or_subquery_sublist
    {
        table_or_subquery_list list;
    };

    // forward declaration
    struct join_clause;

    struct table_or_subquery_join
    {
        x3::forward_ast<join_clause> join;
    };

    // forward declaration
    struct select_stmt;

    struct table_or_subquery_select
    {
        x3::forward_ast<select_stmt> stmt;
        boost::optional<identifier> alias;
    };

    struct table_or_subquery : x3::variant<
              table_or_subquery_table
    //      , table_or_subquery_function
            , table_or_subquery_sublist
            , table_or_subquery_join
            , table_or_subquery_select
    >
    {
        using base_type::base_type;
        using base_type::operator=;
    };
}}

#endif //SQL_PARSER_AST_TABLE_OR_SUBQUERY_HPP
