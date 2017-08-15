#ifndef SQL_PARSER_AST_IMPORT_TABLE_STMT_HPP
#define SQL_PARSER_AST_IMPORT_TABLE_STMT_HPP

#include "sql/ast/identifier.hpp"
#include "sql/ast/literal_value.hpp"

#include <boost/spirit/home/x3/support/ast/position_tagged.hpp>
#include <boost/spirit/home/x3/support/ast/variant.hpp>

#include <string>

namespace sql { namespace ast
{
    namespace x3 = boost::spirit::x3;

    struct import_table_source_csv : x3::position_tagged
    {
        std::string filename;
        string_literal delimiter;
    };

    struct import_table_source : x3::variant<
              import_table_source_csv
    >
    {
        using base_type::base_type;
        using base_type::operator=;
    };

    struct import_table_stmt : x3::position_tagged
    {
        table_identifier table;
        import_table_source source;
    };
}}

#endif //SQL_PARSER_AST_IMPORT_TABLE_STMT_HPP
