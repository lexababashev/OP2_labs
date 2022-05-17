#pragma once

struct Date
{
	int day;
	int month;
	int year;
};

struct Product
{
	char name[15];
	Date start;
	Date end;
};