// 日期计算（结构体）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "date.h"
int main()
{
	//Date基础
	int n;
	Date dt1, dt2, dt3;
	printf("Input Date(year,month,day):");
	scanf_s("%d,%d,%d", &dt1.yr, &dt1.mo, &dt1.day);
	printf("Input Date(year,month,day):");
	scanf_s("%d,%d,%d", &dt2.yr, &dt2.mo, &dt2.day);
	if (compare(dt1, dt2) >= 0)
	{
		n = date_to_num(dt1) - date_to_num(dt2);
		printf("%d\n", n);
		dt3 = num_to_date(date_to_num(dt2) + n);
	}
	else
	{
		n = date_to_num(dt2) - date_to_num(dt1);
		printf("%d\n", n);
		dt3 = dt2;//num_to_date(date_to_num(dt1) + n);
	}
	printf("%d-%d-%d\n", dt3.yr, dt3.mo, dt3.day);
	//Date应用//三天打鱼，两天晒网
	unsigned count;
	Date dt5 = { 2000,1,1 }, dt4;
	printf("Input Date(year,month,day):");
	scanf_s("%d,%d,%d", &dt4.yr, &dt4.mo, &dt4.day);
	count = date_to_num(dt4) - date_to_num(dt5) + 1;
	if (count % 5 > 0 && count % 5 < 4)
		printf("Fishing\n");
	else
		printf("Sleeping\n");
    return 0;
}
