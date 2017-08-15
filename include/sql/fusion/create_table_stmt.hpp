#ifndef SQL_PARSER_FUSION_CREATE_TABLE_STMT_HPP
#define SQL_PARSER_FUSION_CREATE_TABLE_STMT_HPP

#include "sql/ast/create_table_stmt.hpp"

#include <boost/fusion/include/adapt_struct.hpp>

BOOST_FUSION_ADAPT_STRUCT(sql::ast::type_name,
                         (std::string, name)
                         (boost::optional<sql::ast::numeric_literal>, lower_bound)
                         (boost::optional<sql::ast::numeric_literal>, upper_bound)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::column_def,
                         (sql::ast::identifier, name)
                         (sql::ast::type_name, type)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::indexed_column,
                         (sql::ast::identifier, name)
                         (sql::ast::direction_type, direction)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::table_constraint_primary_key,
                         (sql::ast::indexed_column_list, columns)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::table_constraint_unique,
                         (sql::ast::indexed_column_list, columns)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::table_constraint_foreign_key,
                         (sql::ast::identifier_list, columns)
                         (sql::ast::identifier, foreign_table)
                         (sql::ast::identifier_list, foreign_columns)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::table_constraint,
                         (boost::optional<sql::ast::identifier>, name)
                         (sql::ast::table_constraint_type, type)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::create_table_stmt_columns,
                         (sql::ast::column_def_list, columns)
                         (boost::optional<sql::ast::table_constraint_list>, constraints)
                         (bool, rowid)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::create_table_stmt_select,
                         (sql::ast::select_stmt, statement)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::create_table_stmt,
                          (bool, temporary)
                          (bool, if_not_exists)
                          (sql::ast::table_identifier, name)
                          (sql::ast::create_table_stmt_definition, definition)
)

#endif //SQL_PARSER_FUSION_CREATE_TABLE_STMT_HPP
