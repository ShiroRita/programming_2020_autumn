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
	if (count + list.count >= capacity)
	{
		expand(data, capacity);
	}
	for (int i = 0; i < list.count; ++i)
	{
		*(data + count + i) = *(list.data + i);
	}
	count += list.count;
	clear(list);
	return true;
}

bool ArrayList::addAll(int index, ArrayList& list)
{
	if (count + list.count >= capacity)
	{
		expand(data, capacity);
	}
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
	return (isEmpty() == false ? (index < count ? *(data + index) : - 1) : -1);
}

int ArrayList::indexOf(int element)
{
	int index = -1;
	if (isEmpty() == false)
	{
		int i = 0;
		for (int j = 0; j < count; ++j)
		{
			i = (*(data + j) == element ? 1 : 0);
			index = (i == 1 ? j : index);
		}
	}
	return index;
}

bool ArrayList::isEmpty()
{
	return (count != 0 ? false : true);
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
	if (isEmpty() == false | index < count)
	{	
		for (int i = index; i < count - 1; ++i)
		{
			*(data + i) = *(data + i + 1);
		}
		--count;
		return true;
	}
	else
	{
		return false;
	}
}

int ArrayList::swap(int index1, int index2)
{
	if (isEmpty() == true)
	{
		if (index1 < count)
		{
			if (index2 < count)
			{
				int t = 0;
				t = *(data + index1);
				*(data + index1) = *(data + index2);
				*(data + index2) = t;
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
