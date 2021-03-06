/*
	STV6110(A) Silicon tuner driver

	Copyright (C) Manu Abraham <abraham.manu@gmail.com>

	Copyright (C) ST Microelectronics

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#ifndef __STV6110x_PRIV_H
#define __STV6110x_PRIV_H

#define STV6110x_SETFIELD(mask, bitf, val) \
	(mask = (mask & (~(((1 << STV6110x_WIDTH_##bitf) - 1) << STV6110x_OFFST_##bitf))) | (val << STV6110x_OFFST_##bitf))

#define STV6110x_GETFIELD(bitf, val) \
	((val >> STV6110x_OFFST_##bitf) & ((1 << STV6110x_WIDTH_##bitf) - 1))

#define MAKEWORD16(a, b) (((a) << 8) | (b))

#define LSB(x)           ((x & 0xff))
#define MSB(y)           ((y >> 8) & 0xff)

#define TRIALS           10
#define R_DIV(__div)     (1 << (__div + 1))
#define REFCLOCK_kHz     (stv6110x->config->refclk /    1000)
#define REFCLOCK_MHz     (stv6110x->config->refclk / 1000000)

struct stv6110x_state
{
	struct tuner_devctl          *devctl;
	struct i2c_adapter           *i2c;
	const struct stv6110x_config *config;
	u8                           regs[8];
};

#endif /* __STV6110x_PRIV_H */
// vim:ts=4
