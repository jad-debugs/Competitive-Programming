#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    
    int m; cin >> m;
    
    pair<int, char> mouse[m];

    for(int i = 0; i < m; i++) {
        int a; cin >> a;
        string b; cin >> b;
        if(b == "USB")
            mouse[i] = {a, 'u'};
        else
            mouse[i] = {a, 'p'};
    }

    sort(mouse, mouse+m);

    // usb count
    int usb = 0, ps = 0, mix = 0;
    long long ans = 0;

    for(pair<int, char> &p: mouse) {
        if(usb == a)
            break;
        if(p.second == 'u') {
            usb++; 
            ans += p.first;
            p.second = 'x';
        }
    }

    for(pair<int, char> &p: mouse) {
        if(ps == b)
            break;
        if(p.second == 'p') {
            ps++; 
            ans += p.first;
            p.second = 'x';
        }
        
    }

    for(pair<int, char> p: mouse) {
        if(mix == c)
            break;
        if(p.second != 'x') {
            mix++;
            ans += p.first;
        }
        
    }

    cout << usb + ps + mix << " " << ans;

    return 0;
}

