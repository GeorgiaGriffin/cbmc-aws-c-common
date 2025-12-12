/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/common/linked_list.h>
#include <proof_helpers/make_common_data_structures.h>

void aws_linked_list_move_all_back_harness() {
    /* data structure */
    struct aws_linked_list dst;
    struct aws_linked_list src;

    /* Assume the preconditions */
    ensure_linked_list_is_allocated(&dst, MAX_LINKED_LIST_ITEM_ALLOCATION);
    ensure_linked_list_is_allocated(&src, MAX_LINKED_LIST_ITEM_ALLOCATION);
    __CPROVER_assume(aws_linked_list_is_valid(&dst));
    __CPROVER_assume(aws_linked_list_is_valid(&src));
    __CPROVER_assume(&dst != &src);

    /* perform operation under verification */
    aws_linked_list_move_all_back(&dst, &src);

    /* assertions */
    assert(aws_linked_list_is_valid(&dst));
    assert(aws_linked_list_is_valid(&src));
    assert(aws_linked_list_empty(&src));
}