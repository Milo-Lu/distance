#include <QCoreApplication>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int f(vector<int>& A){
    if(A.size()==0) return -1;
    if(A.size()==1) return 0;
    vector<int> A1{A};
    vector<int> A2;
    sort(A1.begin(),A1.end());
    unique_copy(A1.begin(),A1.end(),back_inserter(A2));
    int dis{1};

    for(int i=0;i!=A2.size()-1;++i){
        auto index1_for = find(A.begin(),A.end(),A2[i]);
        auto index1_back = find(A.rbegin(),A.rend(),A2[i]);
        int index1_dis_for = distance(A.begin(),index1_for);
        int index1_dis_back = A.size() - distance(A.rbegin(),index1_back) -1;
        auto index2_for = find(A.begin(),A.end(),A2[i+1]);
        auto index2_back = find(A.rbegin(),A.rend(),A2[i+1]);
        int index2_dis_for = distance(A.begin(),index2_for);
        int index2_dis_back = A.size() - distance(A.rbegin(),index2_back) -1;
        if(dis<max(abs(index1_dis_back-index2_dis_for),abs(index1_dis_for-index2_dis_back)))
            dis = max(abs(index1_dis_back-index2_dis_for),abs(index1_dis_for-index2_dis_back));
    }
    return dis;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<int> vi{4,5,34,22,7,5,5,4,4};
    int result = f(vi);
    cout << result << '\n';

    return a.exec();
}
