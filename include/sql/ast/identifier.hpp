#ifndef SQL_PARSER_AST_IDENTIFIER_HPP
#define SQL_PARSER_AST_IDENTIFIER_HPP

#include "sql/ast/common.hpp"

#include <boost/optional.hpp>
#include <boost/spirit/home/x3/support/ast/position_tagged.hpp>
#include <boost/spirit/home/x3/support/ast/variant.hpp>

#include <vector>

namespace sql { namespace ast
{
        namespace x3 = boost::spirit::x3;

        struct identifier : x3::position_tagged {
            std::string identifier;
            quot quotation;
        };

        typedef std::vector<identifier> identifier_list;

        struct simple_table_identifier
        {
            identifier table;
        };

        struct schema_table_identifier
        {
            identifier schema;
            identifier table;
        };

        struct table_identifier : x3::variant<
                schema_table_identifier
                , simple_table_identifier
        >
        {
            using base_type::base_type;
            using base_type::operator=;
        };

        struct aliased_table_identifier
        {
            table_identifier table;
            boost::optional<identifier> alias;
        };
}}

#endif //SQL_PARSER_AST_IDENTIFIER_HPP
