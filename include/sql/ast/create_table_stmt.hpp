#ifndef SQL_PARSER_AST_CREATE_TABLE_STMT_HPP
#define SQL_PARSER_AST_CREATE_TABLE_STMT_HPP

#include "sql/ast/identifier.hpp"
#include "sql/ast/literal_value.hpp"
#include "sql/ast/table_or_subquery.hpp"

#include <boost/optional.hpp>
#include <boost/spirit/home/x3/support/ast/position_tagged.hpp>

#include <string>
#include <vector>

namespace sql { namespace ast
    {
        namespace x3 = boost::spirit::x3;
        using boost::optional;

        // https://www.sqlite.org/datatype3.html
        //
        struct type_name : x3::position_tagged
        {
            std::string name;
            optional<numeric_literal> lower_bound;
            optional<numeric_literal> upper_bound;
        };

        struct column_def : x3::position_tagged
        {
            identifier name;
            type_name type;
            //column_constraint_list constraints;
        };

        typedef std::vector<column_def> column_def_list;

        struct indexed_column : x3::position_tagged
        {
            identifier name; // variant<identifier, expr> required
            // collate
            direction_type direction;
        };

        typedef std::vector<indexed_column> indexed_column_list;

        struct table_constraint_primary_key : x3::position_tagged
        {
            indexed_column_list columns;
            // conflict clause
        };

        struct table_constraint_unique : x3::position_tagged
        {
            indexed_column_list columns;
            // conflict clause
        };

        struct table_constraint_foreign_key : x3::position_tagged
        {
            identifier_list columns;
            identifier foreign_table;
            identifier_list foreign_columns;
            // further options
        };

        struct table_constraint_type : x3::variant<
                  table_constraint_primary_key
                , table_constraint_unique
                // table_constraint_check
                , table_constraint_foreign_key
        >
        {
            using base_type::base_type;
            using base_type::operator=;
        };

        struct table_constraint : x3::position_tagged
        {
            boost::optional<identifier> name;
            table_constraint_type type;
        };

        typedef std::vector<table_constraint> table_constraint_list;

        struct create_table_stmt_columns : x3::position_tagged
        {
            column_def_list columns;
            boost::optional<table_constraint_list> constraints;
            bool rowid;
        };

        struct create_table_stmt_select : x3::position_tagged
        {
            select_stmt statement;
        };

        struct create_table_stmt_definition : x3::variant<
                  create_table_stmt_columns
                , create_table_stmt_select
        >
        {
            using base_type::base_type;
            using base_type::operator=;
        };

        // https://www.sqlite.org/lang_createtable.html
        //
        struct create_table_stmt : x3::position_tagged
        {
            bool temporary;
            bool if_not_exists;
            table_identifier name;
            create_table_stmt_definition definition;
        };
    }}

#endif //SQL_PARSER_AST_CREATE_TABLE_STMT_HPP
