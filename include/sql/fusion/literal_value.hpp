#ifndef SQL_PARSER_FUSION_LITERAL_VALUE_HPP
#define SQL_PARSER_FUSION_LITERAL_VALUE_HPP

#include "sql/ast/literal_value.hpp"

#include <boost/fusion/include/adapt_struct.hpp>

BOOST_FUSION_ADAPT_STRUCT(sql::ast::integer_literal,
                         (int, literal)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::floating_point_literal,
                         (float, literal)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::string_literal,
                         (std::string, literal)
                         (sql::ast::quot, quotation)
)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::null_literal)

BOOST_FUSION_ADAPT_STRUCT(sql::ast::function_literal,
                         (sql::ast::fun_type, literal)
)

#endif //SQL_PARSER_FUSION_LITERAL_VALUE_HPP
