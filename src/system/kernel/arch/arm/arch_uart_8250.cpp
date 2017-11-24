/*
 * Copyright 2011-2012 Haiku, Inc. All rights reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 *		François Revol, revol@free.fr
 */


#include <arch/arm/reg.h>
#include <arch/generic/debug_uart_8250.h>
#include <debug.h>
#include <new>


class ArchUART8250 : public DebugUART8250 {
public:
							ArchUART8250(addr_t base, int32 shift, int64 clock);
							~ArchUART8250();
	void					InitEarly();

	// ARM MMIO: on ARM the UART regs are aligned on 32bit
	virtual void			Out8(int reg, uint8 value);
	virtual uint8			In8(int reg);
};


ArchUART8250::ArchUART8250(addr_t base, int32 shift, int64 clock)
	:
	DebugUART8250(base, shift, clock)
{
}


ArchUART8250::~ArchUART8250()
{
}


void
ArchUART8250::InitEarly()
{
	// Perform special hardware UART configuration
}


void
ArchUART8250::Out8(int reg, uint8 value)
{
	*((uint8 *)Base() + (reg << fShift) * sizeof(uint32));
}


uint8
ArchUART8250::In8(int reg)
{
	return *((uint8 *)Base() + (reg << fShift) * sizeof(uint32));
}


DebugUART8250 *arch_get_uart_8250(addr_t base, int32 shift, int64 clock)
{
	static char buffer[sizeof(ArchUART8250)];
	ArchUART8250 *uart = new(buffer) ArchUART8250(base, shift, clock);
	return uart;
}
