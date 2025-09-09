#pragma once
#include <iostream>
#include "Item.h"
#include <algorithm>

using namespace std;


template <typename T>
class Inventory 
{

private:
	T* pItems_;
	int capacity_;
	int size_;

public:
	Inventory(int capacity = 10)
	{
		if (0 >= capacity) 
		{
			capacity = 1; 
		}
		pItems_ = new T[capacity];
		capacity_ = capacity;
		size_ = 0;
	}
	~Inventory()
	{
		delete[] pItems_; 
		pItems_ = nullptr; 
	}

public:
	void addItem(const T& item)
	{
		if (size_ >= capacity_)  
		{
			cout << "인벤토리가 가득 찼습니다." << endl;
			return; // 
		}
		
		pItems_[size_] = item;
		++size_;
	}

	void SortItems()
	{
		sort(pItems_, pItems_ + size_, compareItemsByPrice);
	}

	static bool compareItemsByPrice(const Item& a, const Item& b)
	{
		return a.GetPrice() < b.GetPrice();
	}

	void RemoveLastItem()
	{
		if (0 >= size_) 
		{
			cout << "인벤토리가 비어있습니다." << endl;
			return;
		}
		--size_;
	}
	
	int GetSize() const 
	{
		return size_; 
	}

	int GetCapacity() const
	{
		return capacity_; 
	}

	void PrintAllItem() const
	{
		if (0 >= size_)
		{
			cout << "(비어있습니다)" << endl;
		}
		
		for (int i = 0; i < size_; i++)
		{
			Item* item = dynamic_cast<Item*>(&pItems_[i]);

			if (nullptr != item)
			{
				item->PirntInfo();
			}
		}
	}
};