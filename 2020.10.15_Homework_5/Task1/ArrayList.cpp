#include "ArrayList.h"

ArrayList::ArrayList(const ArrayList& list)
{
	count = list.count;
	capacity = list.count;
	data = new int[count];
	for (int i = 0; i < count; data[i] = list.data[i], ++i);
	str = nullptr;
}

ArrayList::~ArrayList()
{
	if (data != nullptr)
	{
		delete[] data;
	}
	/*if (str != nullptr)
	{
		delete[] str;
	}*/
}

bool ArrayList::indexValid(int index)
{
	return (index > -1 && index < count);
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
		number *= -1;
	}
	while (number > 9)
	{
		number /= 10;
		++result;
	}
	return result;
}

void ArrayList::addSymbolToStr(int& index, char symbol)
{
	str[index] = symbol;
	++index;
}

void ArrayList::addNumberToStr(int& index, int number)
{
	int length = numLength(number);
	if (number >= 0)
	{
		for (int i = 0; i < length; ++i)
		{
			int digit = number % 10;
			str[index + length - 1 - i] = '0' + digit;
			number /= 10;
		}
		index += length;
	}
	else
	{
		addSymbolToStr(index, '-');
		number *= -1;
		for (int i = 0; i < length - 1; ++i)
		{
			int digit = number % 10;
			str[index + length - 2 - i] = '0' + digit;
			number /= 10;
		}
		index += length - 1;
	}
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
	if (index == count)
	{
		return add(element);
	}
	if (!indexValid(index))
	{
		return false;
	}
	if (count == capacity)
	{
		expand();
	}
	for (int i = count; i > index; --i)
	{
		data[i] = data[i - 1];
	}
	++count;
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
	if (index == count)
	{
		return addAll(list);
	}
	if (!indexValid(index))
	{
		return false;
	}
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
	if (data != nullptr)
	{
		delete[] data;
		data = new int[10];
		capacity = 10;
	}
	if (str != nullptr)
	{
		delete[] str;
		str = nullptr;
	}
}

bool ArrayList::contains(int element)
{
	for (int j = 0; j < count; ++j)
	{
		if (data[j] = element)
		{
			return true;
		}
	}
	return false;
}

int ArrayList::get(int index)
{
	return (!isEmpty() ? (index < count ? data[index] : -1) : -1);
}

bool ArrayList::set(int index, int element)
{
	if (!indexValid(index))
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
	int length = 6 + numLength(count) + numLength(capacity) + 2 * (count - 1);//[/] {} - 6,  
	for (int i = 0; i < count; ++i)
	{
		length += numLength(data[i]);
	}
	str = new char[length];
	int index = 0;
	addSymbolToStr(index, '[');
	addNumberToStr(index, count);
	addSymbolToStr(index, '/');
	addNumberToStr(index, capacity);
	addSymbolToStr(index, ']');
	addSymbolToStr(index, ' ');
	addSymbolToStr(index, '{');
	for (int i = 0; i < count - 1; i++)
	{
		addNumberToStr(index, data[i]);
		addSymbolToStr(index, ',');
		addSymbolToStr(index, ' ');
	}
	addNumberToStr(index, data[count - 1]);
	addSymbolToStr(index, '}');
	addSymbolToStr(index, '\0');
	return str;
}

bool ArrayList::remove(int index)
{
	if (!indexValid(index))
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
	if (!indexValid(index1) || indexValid(index2))
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