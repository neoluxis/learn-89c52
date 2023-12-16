#include "keys.h"
#include "delay.h"

u8 key_scan(u8 mode)
{
	static u8 key_up = 1;
	if (mode)
		key_up = 1;
	P3 = 0xff;
	if (key_up)
	{
		if (P3 != 0xff)
		{
			delay_ms(1);
			if (P3 != 0xff)
			{
				key_up = 0;
				switch (P3)
				{
				case 0xfe:
					return 1;
				case 0xfd:
					return 2;
				case 0xfb:
					return 3;
				case 0xf7:
					return 4;
				}
			}
		}
	}
	else
	{
		if (P3 == 0xff)
			key_up = 1;
	}
	return 0;
}

u8 matrix_key_scan(u8 mode)
{
	static u8 key_up = 1;
	u8 keyval = 0;
	if (mode)
		key_up = 1;
	if (key_up)
	{
		P3 = 0Xf0;		// column scanner
		if (P3 != 0Xf0) // whether key pressed
		{
			delay_ms(5);	// delay 5ms
			if (P3 != 0Xf0) // whether key pressed
			{
				key_up = 0;
				switch (P3) // which column pressed
				{
				case 0xe0:
					keyval = 0x10;
					break; // column 1 pressed
				case 0xd0:
					keyval = 0x11;
					break; // column 2 pressed
				case 0xb0:
					keyval = 0x12;
					break; // column 3 pressed
				case 0x70:
					keyval = 0x13;
					break; // column 4 pressed
				}
				P3 = 0X0f;	// row scanner
				switch (P3) // which row pressed
				{
				case 0x0e:
					keyval += 0x00;
					break; // row 1 pressed
				case 0x0d:
					keyval += 0x04;
					break; // row 2 pressed
				case 0x0b:
					keyval += 0x08;
					break; // row 3 pressed
				case 0x07:
					keyval += 0x0c;
					break; // row 4 pressed
				}
			}
		}
	}
	else
	{
		P3 = 0xf0;
		if (P3 == 0xf0)
			key_up = 1;
	}
	return keyval;
}

u8 all_key_scan(u8 mode, u8 pri)
{
	// TODO: Need to be implemented
	return 0;
}
