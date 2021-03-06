/* Hashtable implementation.
 *
 * Copyright (c) 2013 Zoltan Kovacs
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef _LIBSUPPORT_HASHTABLE_H_
#define _LIBSUPPORT_HASHTABLE_H_

#include <stddef.h>

struct hashitem
{
    struct hashitem* next;
};

typedef const void* key_func_t(struct hashitem* i);
typedef unsigned hash_func_t(const void*);
typedef int compare_func_t(const void* k1, const void* k2);

struct hashtable
{
    struct hashitem** table;
    // the size of the table
    size_t size;
    // number of items in the table
    size_t items;

    key_func_t* key;
    hash_func_t* hash;
    compare_func_t* compare;
};

unsigned hashtable_hash_int(const void* k);
int hashtable_compare_int(const void* k1, const void* k2);

void hashtable_add(struct hashtable* table, struct hashitem* item);
struct hashitem* hashtable_get(struct hashtable* table, const void* key);
struct hashitem* hashtable_remove(struct hashtable* t, const void* key);

int hashtable_init(struct hashtable* t, key_func_t* key, hash_func_t* hash, compare_func_t* compare);

#endif
