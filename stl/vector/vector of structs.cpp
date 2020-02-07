

#include <bits/stdc++.h>

using namespace std;

typedef struct bot{                             // struct of bots

    int x;
    char c;
};

vector < bot > v;

int main()
{

    int t;
    string s , c;

    cin >> t;

    while(t--){

        int con = 0, numA = 0, numB = 0, le = -1, ri =1e9;
        cin >> s >> c;

        v.clear();

        for(int i = 0; i < s.size(); i++){

            if(s[i] != '#'){                        // check if this cell has a bot

                bot b;                              // create new bot
                b.c = s[i];                         // put the letter of this bot
                b.x = i;                            // put the position of this bot
                v.push_back(b);                     // add this bot
            }

            if(s[i] == 'A')numA++;                  // increase the number of bots type(A).  
            else if (s[i] == 'B') numB++;           // increase the number of bots type(B)

        }

        con = 0;
        bool order = false;
        bool wrong = false;

        for(int i = 0; i < c.size() && !wrong; i++){

            if(c[i] == 'A'){

                bot b = v[con++];                           // compare it with robot which have (con) order in the intial state
                if(b.c != 'A' || b.x < i) wrong = true;     // chck if the robot doesn't have the same type or the final position isn't allowed
                numA--;

            } else if (c[i] == 'B'){

                bot b = v[con++];
                if(b.c != 'B' || b.x > i) wrong = true;
                numB--;
            }
        }

        if(!numA && !numB) cout << "Yes\n";             // check if the number of robots of type 1,2 are the same in intial and final state
        else cout << "No\n";
    }

    return 0;
}