//
//  main.cpp
//  Queue
//
//  Created by KAM HAYMAN on 7/25/19.
//  Copyright © 2019 KAM HAYMAN. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    queue<int> kam;
    
    kam.push(47);
    kam.push(38);
    kam.push(25);
    
    cout<<kam.size()<<endl<<kam.front()<<endl;
    
    
    return 0;
}
