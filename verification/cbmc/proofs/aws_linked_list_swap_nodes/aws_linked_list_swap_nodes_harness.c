/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/common/linked_list.h>
#include <proof_helpers/make_common_data_structures.h>

void aws_linked_list_swap_nodes_harness() {
    /* data structure */
    struct aws_linked_list_node a, b;

    /* Assume the preconditions */
    struct aws_linked_list_node a_prev;
    struct aws_linked_list_node a_next;
    struct aws_linked_list_node b_prev;
    struct aws_linked_list_node b_next;
    a.prev = &a_prev;
    a.next = &a_next;
    a_prev.next = &a;
    a_next.prev = &a;
    b.prev = &b_prev;
    b.next = &b_next;
    b_prev.next = &b;
    b_next.prev = &b;

    /* perform operation under verification */
    aws_linked_list_swap_nodes(&a, &b);

    /* assertions */
    assert(aws_linked_list_node_prev_is_valid(&a));
    assert(aws_linked_list_node_next_is_valid(&a));
    assert(aws_linked_list_node_prev_is_valid(&b));
    assert(aws_linked_list_node_next_is_valid(&b));
}
