#include <iostream>
#include "Inventory.h"
#include "Item.h"

int main()
{
	// 메모리 누수 감지 코드
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	new int();

	Inventory<Item> inv(5);
	
	inv.addItem(Item("체력 포션", 50));
	inv.addItem(Item("강화 포션", 100));
	inv.addItem(Item("체력 포션", 50));
	inv.addItem(Item("체력 포션", 50));
	inv.addItem(Item("체력 포션", 50));
	
	

	std::cout << "==== 아이템 목록 ====" << std::endl;
	inv.PrintAllItem();

	 inv.RemoveLastItem(); // 아이템 제거해야할때 사용

	 std::cout << "\n==== 아이템 제거 후 ====" << std::endl;
	 inv.PrintAllItem();

	inv.SortItems();

	std::cout << "\n==== 아이템 정렬 후 ====" << std::endl;
	inv.PrintAllItem();

	system("pause");

	return 0;
}