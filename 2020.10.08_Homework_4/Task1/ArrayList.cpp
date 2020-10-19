#include "ArrayList.h"

ArrayList::ArrayList()
{
	count = 0;
	capacity = 10;
	data = new int[10];
}

ArrayList::ArrayList(int cap)
{
	count = 0;
	capacity = cap;
	data = new int[cap];
}

ArrayList::~ArrayList()
{
	delete[] data;
}

void expand(int*& data, int& capacity)
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

bool ArrayList::add(int element)
{
	if (count == capacity)
	{
		expand(data, capacity);
	}
	*(data + count) = element;
	++count;
	return true;
}

bool ArrayList::add(int index, int element)
{
	if (count == capacity)
	{
		expand(data, capacity);
	}
	++count;
	for (int i = count - 1; i > index; --i)
	{
		*(data + i) = *(data - 1 + i);
	}
	*(data + index) = element;
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

void ArrayList::clear(ArrayList& list)
{
	list.count = 0;
}

bool ArrayList::contains(int element)
{
	int i = 0;
	for (int j = 0; j < count; ++j)
	{
		i = (*(data + j) == element ? 1 : 0);
	}
	return (i == 0 ? false : true);
}

int ArrayList::get(int index)
{
	return (!isEmpty() ? (index < count ? *(data + index) : -1) : -1);
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

void ArrayList::print()
{
	printf("[%d/%d]{", count, capacity);
	for (int i = 0; i < count; ++i)
	{
		printf("%d%s", *(data + i), (i == count - 1 ? "" : ", "));
	}
	printf("}\n");
}

bool ArrayList::remove(int index)
{
	if (index < 0 || index > count)
	{
		return false;
	}
	for (int i = index; i < count - 1; ++i)
	{
		*(data + i) = *(data + i + 1);
	}
	--count;
	return true;
}

int ArrayList::swap(int index1, int index2)
{
	if (index1 < 0 || index2 < 0 || index1 > count || index2 > count)
	{
		return false;
	}
	int t = *(data + index1);
	*(data + index1) = *(data + index2);
	*(data + index2) = t;
	return true;
}
