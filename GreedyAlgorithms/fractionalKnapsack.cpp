/* Write a program to solve the fractional knapsack problem */

/* Greedy method - Sort based on decreasing order of profit/value */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Structure for an item with weight and value
struct Item {
    int profit, weight;
    Item(int v, int w) : profit(v), weight(w) {}
};


double getMaxProfit(int capacity, vector<Item>& items) {
    // first sort values in items[] by profit to weight ratio
    sort(items.begin(), items.end(), [](Item& a, Item& b) {
        return (((double)a.profit/a.weight) > ((double)b.profit/b.weight));
    });

    double maxProfit = 0;
    int itemPtr = 0;
    for (auto& item : items) {
        if (capacity >= item.weight) {
            capacity -= item.weight;
            maxProfit += item.profit;
        } else {
            maxProfit += (item.profit) * ((double)capacity/item.weight);
            break;
        }
    }
    return maxProfit;
}

int main() {
    // 7 items
    vector<Item> items = {
        Item(12, 2),
        Item(17, 5),
        Item(9, 7),
        Item(7, 3),
        Item(5, 1),
        Item(21, 4),
        Item(8, 1)
    };
    
    int capacity = 15;

    double maxValue = getMaxProfit(capacity, items);

    cout << "Maximum value in knapsack = " << maxValue << endl;

    return 0;
}