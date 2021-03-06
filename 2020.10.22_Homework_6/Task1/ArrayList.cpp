#include "ArrayList.h"



ArrayList::~ArrayList()
{
	delete[] data;

	if (str != nullptr)
	{
		delete[] str;
	}
}

void ArrayList::expand()
{
	int* newData = new int[capacity * 2];
	for (int i = 0; i < capacity; ++i)
	{
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
	capacity *= 2;
}

int ArrayList::numLength(int number)
{
	int result = 1;
	if (number < 0)
	{
		++result;
		number *= (-1);
	}
	while (number > 9)
	{
		number /= 10;
		result++;
	}
	
	return result;
}

void ArrayList::addToStr(int& index, char symbol)
{
	str[index] = symbol;
	++index;
}

void ArrayList::addToStr(int& index, int number)
{
	int length = numLength(number);
	if (number < 0)
	{
		addToStr(index, '-');
		number *= (-1);
	}
	for (int i = 0; i < length; ++i)
	{
		int digit = number % 10;
		str[index + length - 1 - i] = '0' + digit;
		number /= 10;
	}
	index += length;
}

bool ArrayList::add(int element)
{
	if (count == capacity)
	{
		expand();
	}
	data[count] = element;
	++count;
	return true;
}

bool ArrayList::add(int index, int element)
{
	if (count == capacity)
	{
		expand();
	}
	++count;
	for (int i = count - 1; i > index; --i)
	{
		data[i] = data[1 + i];
	}
	data[index] = element;
	return true;
}

bool ArrayList::addAll(ArrayList& list)
{
	for (int i = 0; i < list.count; ++i)
	{
		add(list.data[i]);
	}
	return true;
}

bool ArrayList::addAll(int index, ArrayList& list)
{
	for (int i = index; i < count; ++i)
	{
		list.add(data[i]);
	}
	count = index;
	addAll(list);
	return true;
}

void ArrayList::clear()
{
	count = 0;
}

bool ArrayList::contains(int element)
{
	int i = 0;
	for (int j = 0; j < count; ++j)
	{
		i = (data[j] == element ? 1 : 0);
	}
	return (i == 0 ? false : true);
}

int ArrayList::get(int index)
{
	return (!isEmpty() ? (index < count ? data[index] : -1) : -1);
}

bool ArrayList::set(int index, int element)
{
	if (index < 0 || index > count)
	{
		return false;
	}
	data[index] = element;
	return true;
}

int ArrayList::indexOf(int element)
{
	for (int j = 0; j < count; ++j)
	{
		if (data[j] == element)
		{
			return j;
		}
	}
	return -1;
}

bool ArrayList::isEmpty()
{
	return (count == 0);
}

char* ArrayList::toString()
{
	if (str != nullptr)
	{
		delete[] str;
		str = nullptr;
	}
	int length = 6 + numLength(count) + numLength(capacity); 

	for (int i = 0; i < count - 1; ++i)//' ,' * count-1
	{
		length += 2;
	}

	for (int i = 0; i < count; ++i)
	{
		length += numLength(data[i]);
	}

	str = new char[length];
	int index = 0;
	addToStr(index, '[');
	addToStr(index, count);
	addToStr(index, '/');
	addToStr(index, capacity);
	addToStr(index, ']');
	addToStr(index, ' ');
	addToStr(index, '{');
	for (int i = 0; i < count - 1; i++)
	{
		addToStr(index, data[i]);
		addToStr(index, ',');
		addToStr(index, ' ');
	}
	addToStr(index, data[count - 1]);
	addToStr(index, '}');
	addToStr(index, '\0');
	return str;
}

bool ArrayList::remove(int index)
{
	if (index < 0 || index > count)
	{
		return false;
	}
	for (int i = index; i < count - 1; ++i)
	{
		data[i] = data[i + 1];
	}
	--count;
	return true;
}

bool ArrayList::swap(int index1, int index2)
{
	if (index1 < 0 || index2 < 0 || index1 > count || index2 > count)
	{
		return false;
	}
	int t = data[index1];
	data[index1] = data[index2];
	data[index2] = t;
	return true;
}

int ArrayList::length()
{
	return count;
}