#include "ArrayList.h"

ArrayList::ArrayList(const ArrayList& list)
{
	count = list.count;
	capacity = list.capacity;
	data = list.data;
}

ArrayList::~ArrayList()
{
	delete[] data;
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

bool ArrayList::remove(int index)
{
	if (index < 0 || index >= count)
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

void ArrayList::operator+=(int item)
{
	add(item);
}

void ArrayList::operator-=(int item)
{
	int index = -1;
	for (int i = 0; i < count; ++i)
	{
		if (data[i] == item)
		{
			index = i;
		}
	}
	remove(index);
}

ArrayList& ArrayList::operator=(const ArrayList& list)
{
	count = list.count;
	capacity = list.capacity;
	data = list.data;
	return *this;
}

ArrayList operator+(const ArrayList& list, int item)
{
	ArrayList newlist;
	newlist = list;
	newlist += item;
	return newlist;
}

ArrayList operator+(int item, const ArrayList& list)
{
	ArrayList newlist;
	newlist += item;
	newlist + list;
	return newlist;
}

ArrayList operator+(const ArrayList& list1, const ArrayList& list2)
{
	ArrayList newlist;
	newlist = list1;
	newlist.count += list2.count;
	newlist.capacity += list2.capacity;
	for (int i = 0; i < list2.count; ++i)
	{
		newlist.data[i + list1.count] = list2.data[i];
	}
	return newlist;
}

ArrayList operator-(const ArrayList& list, int item)
{
	ArrayList newlist = list;
	newlist -= item;
	return newlist;
}

ArrayList operator-(int item, const ArrayList& list)
{
	ArrayList newlist = list;
	newlist.remove(newlist.indexOf(item));
	return newlist;
}

std::ostream& operator<<(std::ostream& stream, const ArrayList& list)
{
	stream << "[" << list.count << "/" << list.capacity << "] {";
	for (int i = 0; i < list.count - 1; ++i)
	{
		stream << list.data[i] << ", ";
	}
	stream << list.data[list.count - 1] << "}";
	return stream;
}