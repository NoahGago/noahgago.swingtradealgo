//
//  main.cpp
//  SwingTrade
//
//  Created by Noah Gago on 11/18/20.
//  Copyright © 2020 Noah Gago. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class fibStrat {

public:
    struct dataPoint {
    double ticker = 0;
};
    
    double relative_extreme = 0;
    
    void check_retracement_buy(dataPoint stock) {
        if ((stock.ticker / relative_extreme) == 23.6 || (stock.ticker / relative_extreme) == 38.2 ||
           (stock.ticker / relative_extreme) == 61.8 || (stock.ticker / relative_extreme) == 78.6) {
            cout << "Support point reached, enter short position, BUY\n";
            relative_extreme = stock.ticker;
        }
    }
    
    void check_retracement_sell(dataPoint stock) {
        if ((relative_extreme / stock.ticker) == 23.6 || (relative_extreme / stock.ticker) == 38.2 ||
            (relative_extreme / stock.ticker) == 61.8 || (relative_extreme / stock.ticker) == 78.6) {
            cout << "Resistance point reached, enter long position, SELL\n";
            relative_extreme = stock.ticker;
        }
    }
    
    void load_data() {
        ifstream infile;
        infile.open("DATA.txt");
        double time = 0;
        string color = "";
        double ticker = 0;
        infile >> relative_extreme;
        
        
        while (infile >> ticker >> time >> color) {
            if (time >= 17) {
                cout << "Market closed.\n";
                exit(0);
            }
            else if (color == "RED") {
                dataPoint temp;
                temp.ticker = ticker;
                check_retracement_buy(temp);
            }
            else if (color == "GREEN") {
                dataPoint temp;
                temp.ticker = ticker;
                check_retracement_sell(temp);
            }
        }
        
    }
    
    
};

int main() {
    fibStrat prog;
    prog.load_data();
    return 0;
}
