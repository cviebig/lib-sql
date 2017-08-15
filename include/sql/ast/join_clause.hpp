#ifndef SQL_PARSER_AST_JOIN_CLAUSE_HPP
#define SQL_PARSER_AST_JOIN_CLAUSE_HPP

#include "sql/ast/expr.hpp"
#include "sql/ast/identifier.hpp"
#include "sql/ast/table_or_subquery.hpp"

#include <boost/optional.hpp>
#include <boost/spirit/home/x3/support/ast/position_tagged.hpp>
#include <boost/spirit/home/x3/support/ast/variant.hpp>

#include <vector>

namespace sql { namespace ast
{
    namespace x3 = boost::spirit::x3;

    // https://www.sqlite.org/syntax/join-operator.html
    //
    enum class join_operator_type { plain, left, left_outer, inner, cross };

    struct join_operator
    {
        bool natural;
        join_operator_type type;
    };

    // https://www.sqlite.org/syntax/join-constraint.html
    //
    struct join_constraint_expr
    {
        expr expression;
    };

    struct join_constraint_columns
    {
        identifier_list columns;
    };

    struct join_constraint_omitted {};

    struct join_constraint : x3::variant<
              join_constraint_expr
            , join_constraint_columns
            , join_constraint_omitted
    >
    {
        using base_type::base_type;
        using base_type::operator=;
    };

    // forward declaration
    struct table_or_subquery;

    // https://www.sqlite.org/syntax/join-clause.html
    //
    struct join
    {
        join_operator op;
        x3::forward_ast<table_or_subquery> table;
        join_constraint constraint;
    };

    typedef std::vector<join> join_list;

    struct join_clause
    {
        x3::forward_ast<table_or_subquery> table;
        join_list joins;
    };
}}
#endif //SQL_PARSER_AST_JOIN_CLAUSE_HPP
