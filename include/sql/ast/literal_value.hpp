#ifndef SQL_PARSER_AST_LITERAL_VALUE_HPP
#define SQL_PARSER_AST_LITERAL_VALUE_HPP

#include "sql/ast/common.hpp"

#include <boost/spirit/home/x3/support/ast/position_tagged.hpp>
#include <boost/spirit/home/x3/support/ast/variant.hpp>

#include <string>
#include <vector>

namespace sql { namespace ast
    {
        namespace x3 = boost::spirit::x3;

        struct integer_literal : x3::position_tagged {
            int literal;
        };

        struct floating_point_literal : x3::position_tagged {
            float literal;
        };

        struct numeric_literal : x3::variant<
                  integer_literal
                , floating_point_literal
        >
        {
            using base_type::base_type;
            using base_type::operator=;
        };

        struct string_literal : x3::position_tagged {
            std::string literal;
            quot quotation;
        };

        // blob-literal omitted
        struct null_literal : x3::position_tagged {
        };

        enum class fun_type {current_time, current_date, current_timestamp};

        struct function_literal : x3::position_tagged {
            fun_type literal;
        };

        struct literal_value : x3::variant<
                  string_literal
                , numeric_literal
                , null_literal
                , function_literal
        >
        {
            using base_type::base_type;
            using base_type::operator=;
        };
    }}

#endif //SQL_PARSER_AST_LITERAL_VALUE_HPP
