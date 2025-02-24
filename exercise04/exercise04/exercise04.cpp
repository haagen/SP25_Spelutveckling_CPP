
#include <iostream>
#include <vector>
#include <map>
#include <Windows.h>
#include <algorithm>

using namespace std;

void e1_array() {
    const int NUMBERS = 7;
    int my_numbers[NUMBERS];

    double sum = 0;
    for (int i=0;i<NUMBERS;i++){
        cout << "Ange tal " << (i+1) << ": ";
        cin >> my_numbers[i];
        sum += my_numbers[i];
    }

    cout << "Medeltalet av summan (" << sum << ") är: ";
    cout << (sum / NUMBERS) << "\n";
}

void e2_list_vector() {
    const int NUMBERS = 7;
    vector<double> v;

    // Loopa och fråga efter tal
    for (int i=0;i<NUMBERS;i++) {
        double userInput;
        cout << "Ange tal " << (i+1) << " (0-100): ";
        cin >> userInput;
        // Kontrollera att talet är inom rätt "range"
        if (userInput >= 0 && userInput <= 100) {
            v.push_back(userInput);
        } else {
            cout << "Talet måste vara mellan 0 och 100\n";
            i--;    // Om vi har angett ett ogiltigt tal måste vi loopa en gång till
        }
    }

    // Beräkna min och max m.h.a. inbyggda funktioner
    double maxV = 0, minV = 100;
    for (auto value : v) {
        maxV = max(maxV, value);
        minV = min(minV, value);
    }

    // Använd en iterator för att hitta min & max och radera dem
    auto itr = v.begin();
    while (itr != v.end()) {
        if (*itr == minV || *itr == maxV) {
            v.erase(itr);
            itr = v.begin();    // När vi har raderat iteratorn blir den ogiltig, vi börjar om
        } else {
            ++itr;
        }
    }

    double sum = 0;
    for (double value: v) {
        sum += value;
    }
    
    cout << "Minsta talet i listan var " << minV << ". Det raderades.\n";
    cout << "Största talet i listan var " << maxV << ". Det raderades.\n";
    cout << "Medeltalet blir då " << (sum/v.size()) << ".\n";
    
}

void e3_map() {
    // Creates a map and initilizes it
    map<string, double> currencies;
    currencies["USD"] = 0.09383;
    currencies["EUR"] = 0.0897;
    currencies["JPY"] = 14.0045;

    double account_saldo = 145.23;

    // Show our currencies
    cout << "Vi har föjande valutakurser: ";
    for (auto p: currencies) {
        cout << p.first << " ";
    }
    cout << "\n";

    // Ask user for currency and transform it to "upper case"
    cout << "Vilken valuta vill du se ditt saldo i? ";
    string chosenCurrency;
    cin >> chosenCurrency;
    transform(chosenCurrency.begin(), chosenCurrency.end(), chosenCurrency.begin(), ::toupper);

    // Check if valid currency
    if (currencies.count(chosenCurrency) == 0) {
        cout << "Du angav en ogiltig valuta!\n";
        return;
    }

    // Print result to screen
    cout << "Du har " << account_saldo << " SEK på ditt konto ";
    cout << "det motsvarar " << (account_saldo*currencies[chosenCurrency]);
    cout << " " << chosenCurrency << "\n";
}

int main(int argc, char* argv[])
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    
    //e1_array();
    //e2_list_vector();
    e3_map();
    
    return 0;
}
