#ifndef SQL_PARSER_FUSION_IDENTIFIER_HPP
#define SQL_PARSER_FUSION_IDENTIFIER_HPP

#include "sql/ast/identifier.hpp"

#include <boost/fusion/include/adapt_struct.hpp>

BOOST_FUSION_ADAPT_STRUCT(sql::ast::identifier,
                         (std::string, identifier)
                         (sql::ast::quot, quotation)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::simple_table_identifier,
                         (sql::ast::identifier, table)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::schema_table_identifier,
                         (sql::ast::identifier, schema)
                         (sql::ast::identifier, table)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::aliased_table_identifier,
                         (sql::ast::table_identifier, table)
                         (boost::optional<sql::ast::identifier>, alias)
)

#endif //SQL_PARSER_FUSION_IDENTIFIER_HPP
