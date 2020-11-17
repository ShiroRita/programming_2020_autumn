#include "LinkedList.h"

bool LinkedList::indexValid(int index)
{
	return (index >= 0 && index < count);
}

LinkedList::LinkedList(const LinkedList& list)
{
	tail = head = nullptr;
	count = 0;

	Node* temp = list.head;
	while (temp != nullptr)
	{
		addToTail(temp->data);
		temp = temp->next;
	}
}

LinkedList::~LinkedList()
{
	if (head != nullptr)
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			Node* node = temp;
			temp = temp->next;
			delete node;
		}
	}
}

int LinkedList::length()
{
	return count;
}

bool LinkedList::addToHead(int element)
{
	if (head == nullptr)
	{
		head = tail = new Node(element);
	}
	else
	{
		head = new Node(element, head);
	}
	++count;
	return true;
}

bool LinkedList::addToTail(int element)
{
	if (tail == nullptr)
	{
		head = tail = new Node(element);
	}
	else
	{
		tail->next = new Node(element);
		tail = tail->next;
	}
	++count;
	return true;
}

bool LinkedList::add(int index, int element)
{
	if (index == 0)
	{
		return addToHead(element);
	}
	if (index == count)
	{
		return addToTail(element);
	}
	if (!indexValid(index))
	{
		return false;
	}

	Node* temp = head;
	//int i = 0;  
	while (index > 1)//(i < index - 1)    
	{
		temp = temp->next;
		--index;//++i;
	}
	temp->next = new Node(element, temp->next);
	++count;

	return true;
}

int LinkedList::get(int index)
{
	if (!indexValid(index))
	{
		return -1;
	}
	if (index == 0)
	{
		return head->data;
	}
	if (index == count - 1)
	{
		return tail->data;
	}
	Node* temp = head;
	while (index > 0)
	{
		temp = temp->next;
		--index;
	}
	return temp->data;
}

bool LinkedList::set(int index, int element)
{
	if (!indexValid(index))
	{
		return false;
	}
	if (index == 0)
	{
		head->data = element;
	}
	else if (index == count - 1)
	{
		tail->data = element;
	}
	else
	{
		Node* temp = head;
		while (index > 0)
		{
			temp = temp->next;
			--index;
		}
		temp->data = element;
	}
	return true;
}

void LinkedList::operator+=(int element)
{
	addToTail(element);
}

int& LinkedList::operator[](int index)
{
	if (head == nullptr)
	{
		addToHead(0);
		return head->data;
	}
	if (index <= 0)
	{
		return head->data;
	}
	if (index >= count)
	{
		addToTail(0);
		return tail->data;
	}
	if (index == count - 1)
	{
		return tail->data;
	}
	Node* temp = head;
	while (index > 0)
	{
		temp = temp->next;
		--index;
	}
	return temp->data;
}

int LinkedList::extractHead()
{
	if (head == nullptr)
	{
		return 0;
	}
	else if (head == tail)
	{
		int extracted = tail->data;
		this->head = nullptr;
		this->tail = nullptr;
		count = 0;
		return extracted;
	}
	else
	{
		int extracted = head->data;
		Node* temp = head->next;
		delete head;
		head = temp;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		--count;

		return extracted;
	}
}

int LinkedList::extractTail()
{
	if (head == nullptr)
	{
		return 0;
	}
	else if (head == tail)
	{
		int extracted = tail->data;
		this->head = nullptr;
		this->tail = nullptr;
		count = 0;
		return extracted;
	}
	else {
		int extracted = tail->data;
		Node* temp = head;
		while (temp->next != tail)
		{
			temp = temp->next;
		}
		delete tail;
		temp->next = nullptr;
		tail = temp;
		--count;

		return extracted;
	}
}

int LinkedList::extract(int index)
{
	if (!indexValid(index))
	{
		return 0;
	}
	if (index == 0)
	{
		return extractHead();
	}
	if (index == count - 1)
	{
		return extractTail();
	}
	
	Node* temp = head;
	for (int i = 0; i < index - 1; ++i)
	{
		temp = temp->next;
	}
	Node* temp2 = temp;
	temp = temp->next;
	int extracted = temp->data;
	Node* node = temp;
	temp = temp->next;
	delete node;
	temp2->next = temp;
	for (int i = index; i < count - 2; ++i)
	{
		temp = temp->next;
	}
	temp->next = nullptr;
	--count;
	return extracted;
}

void LinkedList::operator-=(int index)
{
	extract(index);
}

LinkedList& LinkedList::operator=(LinkedList list)
{
	while (count > 0)
	{
		extractTail();
	}
	addToHead(list.head->data);
	Node* temp = list.head;

	for (int i = 0; i < list.count - 1; ++i)
	{
		temp = temp->next;

		addToTail(temp->data);
	}
	count = list.count;

	return *this;
}

int LinkedList::indexOf(int element)
{
	if (head == nullptr)
	{
		return -1;
	}
	Node* temp = head;
	int index = 0;
	while (element != temp->data)
	{
		temp = temp->next;
		++index;
		if (index == count)
		{
			break;
		}
	}
	return (index == count ? -1 : index);
}

bool LinkedList::contains(int element)
{
	return (indexOf(element) != -1);
}

bool LinkedList::swap(int index1, int index2)
{
	if (!indexValid(index1) || !indexValid(index2))
	{
		return false;
	}
	if (index1 > index2)
	{
		int t = index1;
		index1 = index2;
		index2 = t;
	}
	if ((index1 == 0))
	{
		if (index2 > 1)
		{
			Node* temp = head;
			Node* headNext = head->next;
			while (index2 > 1)
			{
				temp = temp->next;
				--index2;
			}
			Node* node = temp;
			temp = temp->next;
			node->next = head;
			node = node->next;
			node->next = temp->next;
			head = temp;
			head->next = headNext;
		}
		else
		{
			Node* temp = head->next;
			head->next = temp->next;
			temp->next = head;
			head = temp;
		}
	}
	else
	{
		if ((index2 - index1) != 1)
		{
			Node* temp = head;
			int i = 0;
			while (i < index1 - 1)
			{
				temp = temp->next;
				++i;
			}
			Node* node1 = temp;
			temp = temp->next;
			++i; //i == index1;
			Node* node1_1 = temp->next;
			while (i < index2 - 1)
			{
				temp = temp->next;
				++i;
			}
			Node* node2 = temp;
			temp = temp->next;// temp == list[index2];
			node2->next = node1->next;
			node2 = node2->next;
			node2->next = temp->next;
			node1->next = temp;
			temp->next = node1_1;
		}
		else
		{
			Node* temp = head;
			for (int i = 0; i < index1 - 1; ++i)
			{
				temp = temp->next;//temp == list[index1 - 1]
			}
			Node* node1 = temp->next; // node1 == list[index1]
			Node* node2 = node1->next;// node2 == list[index2]
			node1->next = node2->next;
			node2->next = node1;
			temp->next = node2;
		}
	}
	return true;
}

std::ostream& operator<<(std::ostream& stream, const LinkedList list)
{
	stream << "[" << list.count << "] {";
	if (list.head == nullptr)
	{
		stream << "EMPTY";
	}
	else
	{
		Node* temp = list.head;
		while (temp != nullptr)
		{
			stream << temp->data;
			if (temp->next != nullptr)
			{
				stream << ", ";
			}
			temp = temp->next;
		}
	}
	stream << "}";

	return stream;
}
