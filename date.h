#pragma once
typedef struct
{
	int yr, mo, day;
}Date;
const int dys[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int leapyear(int y);
unsigned date_to_num(Date dt);//日期转整数
Date num_to_date(unsigned ndays);//整数转日期
int compare(Date dt1, Date dt2);//两日期比较,前大为1，后大为-1，相同为0
