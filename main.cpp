#include <iostream>
#include "Inventory.h"
#include "Item.h"

int main()
{
	// �޸� ���� ���� �ڵ�
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	new int();

	Inventory<Item> inv(5);
	
	inv.addItem(Item("ü�� ����", 50));
	inv.addItem(Item("��ȭ ����", 100));
	inv.addItem(Item("ü�� ����", 50));
	inv.addItem(Item("ü�� ����", 50));
	inv.addItem(Item("ü�� ����", 50));
	
	

	std::cout << "==== ������ ��� ====" << std::endl;
	inv.PrintAllItem();

	 inv.RemoveLastItem(); // ������ �����ؾ��Ҷ� ���

	 std::cout << "\n==== ������ ���� �� ====" << std::endl;
	 inv.PrintAllItem();

	inv.SortItems();

	std::cout << "\n==== ������ ���� �� ====" << std::endl;
	inv.PrintAllItem();

	system("pause");

	return 0;
}