/*
 * Copyright © 2009 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 * Authors:
 *    Eric Anholt <eric@anholt.net>
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "set.h"
#include "fnv_hash.h"

int
main(int argc, char **argv)
{
	struct set *set;
	const char *str1 = "test1";
	const char *str2 = "test2";
	uint32_t hash_str1 = fnv1_hash_string(str1);
	uint32_t hash_str2 = fnv1_hash_string(str2);
	struct set_entry *entry;

	set = set_create(string_key_equals);

	set_add(set, hash_str1, str1);
	set_add(set, hash_str2, str2);

	assert(set_contains(set, hash_str1, str1));
	entry = set_search(set, hash_str1, str1);
	assert(strcmp(entry->key, str1) == 0);

	assert(set_contains(set, hash_str2, str2));
	entry = set_search(set, hash_str2, str2);
	assert(strcmp(entry->key, str2) == 0);

	set_destroy(set, NULL);

	return 0;
}
