// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) 2020 MediaTek Inc.
 */
#include "eeprom_i2c_dev.h"

static enum EEPROM_I2C_DEV_IDX gi2c_dev_sel[IMGSENSOR_SENSOR_IDX_MAX_NUM] = {
	I2C_DEV_IDX_1, /* main */
	//+bug 612420,huangguoyong.wt,add,2020/12/25,add for n6 camera bring up
	I2C_DEV_IDX_2, /* sub */
	I2C_DEV_IDX_2, /* main2 */
	I2C_DEV_IDX_2, /* sub2 */
	//-bug 612420,huangguoyong.wt,add,2020/12/25,add for n6 camera bring up
	I2C_DEV_IDX_1, /* main3 */
};

enum EEPROM_I2C_DEV_IDX get_i2c_dev_sel(enum IMGSENSOR_SENSOR_IDX idx)
{
	if (idx >= IMGSENSOR_SENSOR_IDX_MIN_NUM &&
		idx < IMGSENSOR_SENSOR_IDX_MAX_NUM)
		return gi2c_dev_sel[idx];
	return I2C_DEV_IDX_1;
}

int gi2c_dev_timing[I2C_DEV_IDX_MAX] = {
	100, /* dev1, 100k */
	100, /* dev2, 100k */
	100, /* dev3, 100k */
};

