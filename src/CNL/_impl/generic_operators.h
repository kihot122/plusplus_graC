
//          Copyright John McFarlane 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file ../LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

/// \file
/// \brief a place to centralize most duplicate arithmetic operator boilerplate

#if !defined(CNL_IMPL_GENERIC_OPERATORS_H)
#define CNL_IMPL_GENERIC_OPERATORS_H

#include "operators.h"
#include "type_traits/enable_if.h"
#include "../limits.h"

#include <type_traits>

/// compositional numeric library
namespace cnl {
    namespace _impl {
        ////////////////////////////////////////////////////////////////////////////////
        // cnl::_impl::wants_generic_ops

        // true iff T wants generic operator overloads
        template<class T, class Enable = void>
        struct wants_generic_ops : std::false_type {
        };

        ////////////////////////////////////////////////////////////////////////////////
        // generic operators

        // can be specialized for any types without need for excessive boilerplate;
        // will only match operands for which cnl::_impl::wants_generic_ops is defined
        template<class Operator, class Operand, class Enable = void>
        struct unary_operator;

        template<class Operator, class LhsOperand, class RhsOperand, class Enable = void>
        struct binary_operator;

        template<class Operator, class LhsOperand, class RhsOperand, class Enable = void>
        struct comparison_operator;

        template<class Operator, class RhsOperand, class Enable = void>
        struct pre_operator;

        template<class Operator, class LhsOperand, class Enable = void>
        struct post_operator;

        template<class Operator, class LhsOperand, class RhsOperand, class Enable = void>
        struct compound_assignment_operator {
            constexpr LhsOperand& operator()(LhsOperand& lhs, RhsOperand const& rhs) const
            {
                return lhs = static_cast<LhsOperand>(
                        binary_operator<typename Operator::binary, LhsOperand, RhsOperand>()(lhs, rhs));
            }
        };

        ////////////////////////////////////////////////////////////////////////////////
        // cnl::_impl::enable_unary_t

        template<class Operand, class T>
        using enable_unary_t = ::cnl::_impl::enable_if_t<_impl::wants_generic_ops<Operand>::value, T>;

        ////////////////////////////////////////////////////////////////////////////////
        // cnl::_impl::enable_binary_t

        template<class LhsOperand, class RhsOperand>
        struct enable_binary;

        template<class LhsOperand, int LhsSize, class RhsOperand>
        struct enable_binary<LhsOperand[LhsSize], RhsOperand> : std::false_type {
        };

        template<class LhsOperand, class RhsOperand, int RhsSize>
        struct enable_binary<LhsOperand, RhsOperand[RhsSize]> : std::false_type {
        };

        template<class LhsOperand, class RhsOperand>
        struct enable_binary
                : std::integral_constant<
                        bool,
                        (numeric_limits<LhsOperand>::is_specialized && numeric_limits<RhsOperand>::is_specialized)
                                && (_impl::wants_generic_ops<LhsOperand>::value
                                        || _impl::wants_generic_ops<RhsOperand>::value)> {
        };

        template<class LhsOperand, class RhsOperand, class T>
        using enable_binary_t = _impl::enable_if_t<enable_binary<LhsOperand, RhsOperand>::value, T>;

        ////////////////////////////////////////////////////////////////////////////////
        // operator overloads

        // unary operators
#define CNL_DEFINE_UNARY_OPERATOR(OP, NAME) \
        template<class Operand> \
        constexpr auto operator OP (Operand const& operand) \
        -> decltype(cnl::_impl::unary_operator<cnl::_impl::enable_unary_t< \
                Operand, cnl::_impl::NAME>, Operand>()(operand)) \
        { \
            return cnl::_impl::unary_operator<cnl::_impl::NAME, Operand>()(operand); \
        }

        CNL_DEFINE_UNARY_OPERATOR(+, plus_op)

        CNL_DEFINE_UNARY_OPERATOR(-, minus_op)

        CNL_DEFINE_UNARY_OPERATOR(~, bitwise_not_op)

        // binary operators
#define CNL_DEFINE_BINARY_OPERATOR(OP, NAME) \
        template<class LhsOperand, class RhsOperand> \
        constexpr auto operator OP (LhsOperand const& lhs, RhsOperand const& rhs) \
        -> decltype(cnl::_impl::binary_operator<cnl::_impl::enable_binary_t< \
                LhsOperand, RhsOperand, cnl::_impl::NAME>, LhsOperand, RhsOperand>()(lhs, rhs)) \
        { \
            return cnl::_impl::binary_operator<cnl::_impl::NAME, LhsOperand, RhsOperand>()(lhs, rhs); \
        }

        CNL_DEFINE_BINARY_OPERATOR(+, add_op)

        CNL_DEFINE_BINARY_OPERATOR(-, subtract_op)

        CNL_DEFINE_BINARY_OPERATOR(*, multiply_op)

        CNL_DEFINE_BINARY_OPERATOR(/, divide_op)

        CNL_DEFINE_BINARY_OPERATOR(%, modulo_op)

        CNL_DEFINE_BINARY_OPERATOR(|, bitwise_or_op)

        CNL_DEFINE_BINARY_OPERATOR(&, bitwise_and_op)

        CNL_DEFINE_BINARY_OPERATOR(^, bitwise_xor_op)

        CNL_DEFINE_BINARY_OPERATOR(<<, shift_left_op)

        CNL_DEFINE_BINARY_OPERATOR(>>, shift_right_op)

        // comparison operators
#define CNL_DEFINE_COMPARISON_OPERATOR(OP, NAME) \
        template<class LhsOperand, class RhsOperand> \
        constexpr auto operator OP (LhsOperand const& lhs, RhsOperand const& rhs) \
        -> decltype(cnl::_impl::comparison_operator<cnl::_impl::enable_binary_t< \
                LhsOperand, RhsOperand, cnl::_impl::NAME>, LhsOperand, RhsOperand>()(lhs, rhs)) \
        { \
            return cnl::_impl::comparison_operator<cnl::_impl::NAME, LhsOperand, RhsOperand>()(lhs, rhs); \
        }

        CNL_DEFINE_COMPARISON_OPERATOR(==, equal_op)

        CNL_DEFINE_COMPARISON_OPERATOR(!=, not_equal_op)

        CNL_DEFINE_COMPARISON_OPERATOR(<, less_than_op)

        CNL_DEFINE_COMPARISON_OPERATOR(>, greater_than_op)

        CNL_DEFINE_COMPARISON_OPERATOR(<=, less_than_or_equal_op)

        CNL_DEFINE_COMPARISON_OPERATOR(>=, greater_than_or_equal_op)

        // pre increment/decrement
#define CNL_DEFINE_PRE_OPERATOR(OP, NAME) \
        template<class RhsOperand> \
        constexpr auto operator OP (RhsOperand& rhs) \
        -> decltype(cnl::_impl::pre_operator<cnl::_impl::NAME, RhsOperand>()(rhs)) \
        { \
            return cnl::_impl::pre_operator<cnl::_impl::NAME, RhsOperand>()(rhs); \
        }

        CNL_DEFINE_PRE_OPERATOR(++, pre_increment_op)

        CNL_DEFINE_PRE_OPERATOR(--, pre_decrement_op)

        // post increment/decrement
#define CNL_DEFINE_POST_OPERATOR(OP, NAME) \
        template<class LhsOperand> \
        constexpr auto operator OP (LhsOperand& lhs, int) \
        -> decltype(cnl::_impl::post_operator<cnl::_impl::NAME, LhsOperand>()(lhs)) \
        { \
            return cnl::_impl::post_operator<cnl::_impl::NAME, LhsOperand>()(lhs); \
        }

        CNL_DEFINE_POST_OPERATOR(++, post_increment_op)

        CNL_DEFINE_POST_OPERATOR(--, post_decrement_op)

        // compound assignment operators
#define CNL_DEFINE_COMPOUND_ASSIGNMENT_OPERATOR(OP, NAME) \
        template<class LhsOperand, class RhsOperand> \
        constexpr auto operator OP (LhsOperand& lhs, RhsOperand const& rhs) \
        -> cnl::_impl::enable_binary_t<LhsOperand, RhsOperand, decltype( \
                cnl::_impl::compound_assignment_operator<cnl::_impl::NAME, LhsOperand, RhsOperand>()(lhs, rhs))> \
        { \
            return cnl::_impl::compound_assignment_operator<cnl::_impl::NAME, LhsOperand, RhsOperand>()(lhs, rhs); \
        }

        CNL_DEFINE_COMPOUND_ASSIGNMENT_OPERATOR(+=, assign_add_op)

        CNL_DEFINE_COMPOUND_ASSIGNMENT_OPERATOR(-=, assign_subtract_op)

        CNL_DEFINE_COMPOUND_ASSIGNMENT_OPERATOR(*=, assign_multiply_op)

        CNL_DEFINE_COMPOUND_ASSIGNMENT_OPERATOR(/=, assign_divide_op)

        CNL_DEFINE_COMPOUND_ASSIGNMENT_OPERATOR(%=, assign_modulo_op)

        CNL_DEFINE_COMPOUND_ASSIGNMENT_OPERATOR(|=, assign_bitwise_or_op)

        CNL_DEFINE_COMPOUND_ASSIGNMENT_OPERATOR(&=, assign_bitwise_and_op)

        CNL_DEFINE_COMPOUND_ASSIGNMENT_OPERATOR(^=, assign_bitwise_xor_op)

        CNL_DEFINE_COMPOUND_ASSIGNMENT_OPERATOR(<<=, assign_shift_left_op)

        CNL_DEFINE_COMPOUND_ASSIGNMENT_OPERATOR(>>=, assign_shift_right_op)
    }
}

#endif  // CNL_IMPL_GENERIC_OPERATORS_H
