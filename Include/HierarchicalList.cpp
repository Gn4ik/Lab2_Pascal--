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

void HierarchicalList::myIterator::operator=(Node* tmp)
{
	itr = tmp;
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
	if (iter.itr->value == n) {
		
		if (iter.itr->parent == nullptr) {
			iter.dec();
			
			iter.itr->Next = nullptr;
		}
		else {
			if (iter.itr->Last != nullptr) {
				iter.dec();
			
				iter.itr->Next = nullptr;
			}
			else {
				iter.dec();
			
				iter.itr->child = nullptr;
			}
		}
	}
	
}

void HierarchicalList::insert(string n)
{

	Node* tmp = new Node(n);

	// ���� ��� 1 �������
	
	if (iter.itr->Next == nullptr) {
		iter.itr->Next = tmp;
		tmp->Last = iter.itr;
		tmp->parent = iter.itr->parent;
	}

}



void HierarchicalList::find(string n)
{
	myIterator tmp;
	tmp.itr = HList;
	while ((tmp.itr->child != nullptr)||(tmp.itr->Next!=nullptr)) {
		if (tmp.getvalue() == n) {
			iter.itr = tmp.itr;
			return;
		}
		tmp.inc();
	}
	if (tmp.getvalue() == n) {
		iter.itr = tmp.itr;
		return;
	}
}
