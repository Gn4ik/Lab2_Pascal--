#include "HierarchicalList.h"

//��������
bool HierarchicalList::myIterator::operator!=(Node* tmp)
{
	if (itr = tmp)
		return true;
	return false;
}

bool HierarchicalList::myIterator::operator==(Node* tmp)
{
	if (itr!=tmp)
		return false;
	return true;
}


void HierarchicalList::myIterator::inc()
{
	// ����� ������
	if (itr == nullptr) 
		return;
	//����� ���� ���� ����� ����     
	if (itr->child != nullptr) {
		itr = itr->child;
		return;
		//��� �������� ���� ������
	}else if(itr->Next !=nullptr){
		itr = itr->Next;
		return;
	}
	else {
		//����������� ��������� � ��� ������
		itr = itr->parent;
		itr = itr->Next;
	}
}

void HierarchicalList::myIterator::dec()
{
	//��� �����
	if (itr->Last != nullptr) {
		itr = itr->Last;
		// ���� ������� ����� � �������� ��������� ����,�� ���� � ���������� �������
		if (itr->child != nullptr) {
			while (itr->Next != nullptr) {
				itr = itr->Next;
			}
		}
		return;
	}
	else {
		//����������� �� �����
		if (itr->parent != nullptr) {
			itr = itr->parent;
		}
	}
}
//������
void HierarchicalList::remove(string n)
{
	find(n);
	Node* tmp = iter.getitr();
	if (tmp->parent == nullptr) {
		iter.dec();
		tmp = iter.getitr();
		tmp->Next = nullptr;
	}
	else {
		if (tmp->Last != nullptr) {
			iter.dec();
			tmp = iter.getitr();
			tmp->Next = nullptr;
		}
		else {
			iter.dec();
			tmp = iter.getitr();
			tmp->child = nullptr;
		}	
	}
}

void HierarchicalList::insert(string n)
{
	Node* tmp;
	tmp->value = n;
	Node* tmp1 = iter.getitr();
	if (tmp1->Next == nullptr) {
		tmp1->Next = tmp;
		tmp->Last = tmp1;
		tmp->parent = tmp1->parent;
	}
}

void HierarchicalList::insertAsChild(string n)
{
	Node* tmp;
	tmp->value = n;
	Node* tmp1 = iter.getitr();
	if (tmp1->child == nullptr) {
		tmp1->child = tmp;
		tmp->parent = tmp1;
	}
}

void HierarchicalList::find(string n)
{
	myIterator tmp = iter;
	while (iter != nullptr) {
		if (iter.getvalue() == n) {
			return;
		}
		iter.inc();
	}
	if (iter == nullptr)
		iter = tmp;
}
