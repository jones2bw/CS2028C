#pragma once
#include <exception>
#include <string>
#include <iostream>

using namespace std;

template <class T> class MiddleIndexList
{
protected:
	const static int MAX_SIZE = 25;
	T* list[MAX_SIZE];
	int size = 0;
	int lowerIndex = 0;
	int higherIndex = 0;

public:
	MiddleIndexList() {
		for (int i = 0; i < MAX_SIZE; i++) {
			list[i] = nullptr;
		}
	}

	~MiddleIndexList() {
		MakeEmpty();
	}

	bool operator>(const T& rhs) {
		return this > rhs;
	}

	bool operator<(const T& rhs) {
		return this < rhs;
	}

	bool operator==(const T& rhs) {
		return this == rhs;
	}

	// adds item at correct location
	void AddItem(T& inVal) {
		int itemIndex = 0;
		if (IsFull()) {
			throw ListOverflow();
		}

		// If list is empty, start in middle
		if (size == 0) {
			list[MAX_SIZE / 2] = new T(inVal);
			size++;
			lowerIndex = MAX_SIZE / 2;
			higherIndex = lowerIndex;
			return;
		}
		else {
			// If inVal is smaller or equal to the smallest value in the list and the first index in the list is not 0, then add inVal to the beginning of the list
			if (*list[lowerIndex] >= inVal && lowerIndex > 0) {
				list[lowerIndex - 1] = new T(inVal);
				lowerIndex--;
			}
			// If inVal is greater than or equal to the biggest value in the list and the last index in the list is not at the furthest right, then add inVal to the end
			else if (*list[higherIndex] <= inVal && higherIndex < MAX_SIZE - 1) {
				list[higherIndex + 1] = new T(inVal);
				higherIndex++;
			}
			// If inVal is less than the middle value, go left
			// If left side is at the first index, shift right first
			else if (inVal < *list[MAX_SIZE / 2]) {
				if (lowerIndex == 0) {
					for (int i = higherIndex; i > 0; i--) {
						list[i + 1] = list[i];
					}
					lowerIndex++;
					higherIndex++;
					list[0] = nullptr;
				}
				for (int i = MAX_SIZE / 2 - 1; i > 0; i--) {
					if (inVal >= *list[i]) {
						itemIndex = i;
						for (int j = lowerIndex - 1; j < itemIndex; j++) {
							list[j] = list[j + 1];
						}
						list[itemIndex] = new T(inVal);
						break;
					}
				}
				lowerIndex--;
			}
			// If inVal is greater than or equal to the middle value, go right
			// If right side is at the max index, shift left first
			else if (inVal >= *list[MAX_SIZE / 2]) {
				if (higherIndex == MAX_SIZE - 1) {
					for (int i = 0; i < MAX_SIZE - 1; i++) {
						list[i] = list[i + 1];
					}
					lowerIndex--;
					higherIndex--;
					list[MAX_SIZE - 1] = nullptr;
				}
				for (int i = MAX_SIZE / 2; i < MAX_SIZE - 1; i++) {
					if (inVal <= *list[i]) {
						itemIndex = i;
						for (int j = higherIndex + 1; j > itemIndex; j--) {
							list[j] = list[j - 1];
						}
						list[itemIndex] = new T(inVal);
						break;
					}
				}
				higherIndex++;
			}
		}
		size++;
	}

	// removes specified item
	T RemoveItem(T& item) {
		bool itemfound = false;
		int itemIndex = 0;
		if (IsEmpty()) {
			throw ListUnderflow();
		}

		if (item == *list[higherIndex]) {
			delete list[higherIndex];
			itemfound = true;
		}
		else {
			for (int i = lowerIndex; i < higherIndex; i++) {
				if (item == *list[i]) {
					itemfound = true;
					itemIndex = i;
					delete list[itemIndex];
					for (int j = itemIndex; j < higherIndex; j++) {
						list[j] = list[j + 1];
					}
					list[higherIndex] = nullptr;
					higherIndex--;
					break;
				}
			}
		}

		if (!itemfound) {
			throw ItemNotFound();
		}
		size--;
	}


	// returns boolean denoting whether the list is empty or not
	bool IsEmpty() {
		return size == 0;
	}

	// returns boolean denoting whether the list is full or not
	bool IsFull() {
		return size == MAX_SIZE;
	}

	// Empties the list
	void MakeEmpty() {
		for (int i = 0; i < size; i++)
			delete list[i];
		size = 0;
	}

	void PrintListPointers() {
		cout << "Pointer array" << endl;
		for (int i = lowerIndex; i < lowerIndex + size; i++) {
			cout << list[i] << " ";
		}
		cout << endl << endl;
	}

	void PrintListValues() {
		cout << "Pointer array values" << endl;
		for (int i = lowerIndex; i < lowerIndex + size; i++) {
			cout << *list[i] << " ";
		}
		cout << endl << endl;
	}

	class ListOverflow : public exception {
	public:
		string msg = "The list is full.";
	};

	class ListUnderflow : public exception {
	public:
		string msg = "The list is empty.";
	};

	class ItemNotFound : public exception {
	public:
		string msg = "The item is not in the list.";
	};

};
