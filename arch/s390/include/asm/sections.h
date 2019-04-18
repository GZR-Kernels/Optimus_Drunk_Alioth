/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _S390_SECTIONS_H
#define _S390_SECTIONS_H

#define arch_is_kernel_initmem_freed arch_is_kernel_initmem_freed

#include <asm-generic/sections.h>

extern bool initmem_freed;

static inline int arch_is_kernel_initmem_freed(unsigned long addr)
{
	if (!initmem_freed)
		return 0;
	return addr >= (unsigned long)__init_begin &&
	       addr < (unsigned long)__init_end;
}

#endif
