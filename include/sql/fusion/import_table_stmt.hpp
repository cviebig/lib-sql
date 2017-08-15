#ifndef SQL_PARSER_FUSION_IMPORT_TABLE_STMT_HPP
#define SQL_PARSER_FUSION_IMPORT_TABLE_STMT_HPP

#include "sql/ast/import_table_stmt.hpp"

#include <boost/fusion/include/adapt_struct.hpp>

BOOST_FUSION_ADAPT_STRUCT(sql::ast::import_table_source_csv,
                         (std::string, filename)
                         (sql::ast::string_literal, delimiter)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::import_table_stmt,
                         (sql::ast::table_identifier, table)
                         (sql::ast::import_table_source, source)
)

#endif //SQL_PARSER_FUSION_IMPORT_TABLE_STMT_HPP
