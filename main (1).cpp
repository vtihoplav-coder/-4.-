// g++ -std=c++17 -O2 main.cpp -o app && ./app
#include <bits/stdc++.h>
using namespace std;

// ---- Перебір ----
void PrintAll(const vector<int>& a){ for(int v: a) cout<<v<<"\n"; }
void PrintReverse(const vector<int>& a){ for(int i=(int)a.size()-1;i>=0;--i) cout<<a[i]<<"\n"; }
void PrintEvenValues(const vector<int>& a){ for(int v: a) if(v%2==0) cout<<v<<"\n"; }
void PrintEveryOther(const vector<int>& a){ for(size_t i=0;i<a.size(); i+=2) cout<<a[i]<<"\n"; }
void PrintUntilMinusOne(const vector<int>& a){
    for(int v: a){ if(v==-1) break; cout<<v<<"\n"; }
}

// ---- Операції з масивом (через std::vector для ясності) ----
vector<int> Append(vector<int> a, int v){ a.push_back(v); return a; }
vector<int> Prepend(vector<int> a, int v){ a.insert(a.begin(), v); return a; }
vector<int> InsertAt(vector<int> a, int pos, int v){
    if(pos<0 || pos>(int)a.size()) throw out_of_range("pos");
    a.insert(a.begin()+pos, v); return a;
}
vector<int> RemoveLast(vector<int> a){ if(a.empty()) throw runtime_error("empty"); a.pop_back(); return a; }
vector<int> RemoveFirst(vector<int> a){ if(a.empty()) throw runtime_error("empty"); a.erase(a.begin()); return a; }
vector<int> RemoveAt(vector<int> a, int pos){
    if(pos<0 || pos>=(int)a.size()) throw out_of_range("pos");
    a.erase(a.begin()+pos); return a;
}
vector<int> Concat(const vector<int>& a, const vector<int>& b){
    vector<int> r; r.reserve(a.size()+b.size());
    r.insert(r.end(), a.begin(), a.end());
    r.insert(r.end(), b.begin(), b.end());
    return r;
}

int main(){
    vector<int> a = {0,1,3,4,5,2,1,-4,-1,10,55};

    cout<<"Блок 1: усі елементи\n";              PrintAll(a);
    cout<<"Блок 2: зворотний порядок\n";         PrintReverse(a);
    cout<<"Блок 3: парні значення\n";            PrintEvenValues(a);
    cout<<"Блок 4: через 1 (індекси 0,2,4,...)\n";PrintEveryOther(a);
    cout<<"Блок 5: до -1 (не включно)\n";         PrintUntilMinusOne(a);

    vector<int> arr = {0,1,3,4,5};
    cout<<"\nBlock 1 add end\n";  arr = Append(arr,10);    PrintAll(arr);
    cout<<"Block 2 add start\n";  arr = Prepend(arr,99);   PrintAll(arr);
    cout<<"Block 3 insert pos=4\n";arr = InsertAt(arr,4,777);PrintAll(arr);
    cout<<"Block 4 remove last\n"; arr = RemoveLast(arr);  PrintAll(arr);
    cout<<"Block 5 remove first\n";arr = RemoveFirst(arr); PrintAll(arr);
    cout<<"Block 6 remove pos=2\n";arr = RemoveAt(arr,2);  PrintAll(arr);
    cout<<"Block 7 concat\n";
    vector<int> b1={1,2,3}, b2={4,5,6};
    vector<int> merged = Concat(b1,b2);           PrintAll(merged);
}
