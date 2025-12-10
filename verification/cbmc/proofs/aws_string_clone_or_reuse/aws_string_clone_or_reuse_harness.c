/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <proof_helpers/make_common_data_structures.h>

#include <aws/common/string.h>

void aws_string_clone_or_reuse_harness() {
    /* Parameters */
    struct aws_allocator *allocator = aws_default_allocator();
    struct aws_string *str = nondet_allocate_string_bounded_length(MAX_STRING_LEN);

    /* assume preconditions */
    __CPROVER_assume(allocator);
    __CPROVER_assume(aws_string_is_valid(str));

    /* operation under verification */
    struct aws_string *result = aws_string_clone_or_reuse(allocator, str);

    /* assertions */
    assert(aws_string_is_valid(result));
    assert(aws_string_is_valid(str));
    assert(result->len == str->len);

    if (str->allocator != NULL) {
        // String was dynamically allocated, clone it
        assert(result != str);
    } else {
        // String was statically allocated, return original string
        assert(result == str);
    }
}
