#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#define MAX 50001
#define pb push_back

using namespace std;

const int inf = 1000000000;

struct nod {
       int y, 
           c;
};

vector <nod> V[ MAX ];

deque <int> QUEUE;

int n,
    m,
    dist[ MAX ],
    count[ MAX ];


void read() {

     ifstream fin("bellmanford.in");

     fin>>n>>m;

     int x, 
         c;

     nod t;

     for(int i = 1; i <= m; i++) {

         fin>>x>>t.y>>t.c;

         V[ x ].pb( t );
     }

     fin.close();
};

int BellmanFord() {

    for(int i = 2; i <= n; i++) 

                               dist[ i ] = inf;
    dist[ 1 ] = 0;

    QUEUE.pb( 1 );

    while( !QUEUE.empty() ) {

            int x = QUEUE.front();

            if( dist[ x ] != inf ) {

                 for(int i = 0; i < V[ x ].size(); i++) {

                     int y = V[ x ][ i ].y,

                         c = V[ x ][ i ].c;

                         if( dist[ y ] > dist[ x ] + c ) {

                             dist[ y ] = dist[ x ] + c;

                             QUEUE.pb( y );

                             if(++count[ y ] > n - 1) return 0;  
                         }
                 }
            }

            QUEUE.pop_front();
    } 

    return 1; 
};

void solve() {

    ofstream fout("bellmanford.out");

    if( BellmanFord() ) {

        for(int i = 2; i <= n; i++) {

            fout<<dist[ i ]<<" "; 
        }

    } else {
 
      fout<<"Ciclu negativ!";
    }

    fout.close();  
};

int main() {

    read();

    solve();

    return (0);
}