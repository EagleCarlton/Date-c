#include "stdafx.h"
#include "date.h"
int leapyear(int y)
{
	return(y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}
unsigned date_to_num(Date dt)
{
	int i;
	unsigned ndays = 0;
	for (i = 1; i < dt.yr; ++i)
		ndays += leapyear(i) ? 366 : 365;
	for (i = 1; i < dt.mo; ++i)
		ndays += dys[i - 1];
	if (dt.mo > 2 && leapyear(dt.yr))
		++ndays;
	ndays += dt.day;
	return ndays;
}
Date num_to_date(unsigned ndays)
{
	Date dt = { 0,0,0 };
	unsigned n;
	if (ndays > 0)
	{
		dt.yr = 1;
		while (1)
		{
			n = leapyear(dt.yr) ? 366 : 365;
			if (ndays <= n)
				break;
			ndays -= n;
			++dt.yr;
		}
		for (dt.mo = 1; dt.mo < 13; dt.mo++)
		{
			n = dys[dt.mo - 1];
			if (dt.mo == 2 && leapyear(dt.yr))
				n++;
			if (ndays <= n)
				break;
			ndays -= n;
		}
	}
	dt.day = ndays;
	return dt;
}
int compare(Date dt1, Date dt2)
{
	unsigned n1, n2, b = 0;
	n1 = date_to_num(dt1);
	n2 = date_to_num(dt2);
	if (n1 > n2)
		b = 1;
	else if (n1 < n2)
		b = -1;
	return b;
}
