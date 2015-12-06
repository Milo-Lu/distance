#include <QCoreApplication>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int f(const vector<int>& A){
    if(A.size()==0) return -1;
    vector<pair<int,int>> A2;       //<value,position> pair

    for(int i=0;i!=A.size();++i) A2.push_back({A[i],i});     //book the position of each element

    //compare by value. If two elements have the same value, compare their positions
    sort(A2.begin(),A2.end(),[](pair<int,int> pair1,pair<int,int> pair2){return pair1.first==pair2.first ? (pair1.second<pair2.second) : (pair1.first<pair2.first);});
    int max_dis{};

    for(int i=0;i!=A2.size()-1;++i){
        int index1_min{A2[i].second};
        int index1_max{A2[i].second};

        while(i!=A2.size()-1 && A2[i].first==A2[i+1].first) index1_max = A2[++i].second;        //find the largest position of a duplicated element

        if(i==A2.size()-1) break;

        int index2_min{A2[i+1].second};
        int index2_max{A2[i+1].second};

        while(i!=A2.size()-2 && A2[i+1].first==A2[i+2].first) index2_max = A2[++i].second;

        int dis = abs(index1_max-index2_min) < abs(index2_max-index1_min) ? abs(index2_max-index1_min) : abs(index1_max-index2_min);
        if(max_dis<dis) max_dis = dis;
    }
    return max_dis;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<int> vi{4,5,34,22,7,5,5,4,4};
    int result = f(vi);
    cout << result << '\n';

    return a.exec();
}
