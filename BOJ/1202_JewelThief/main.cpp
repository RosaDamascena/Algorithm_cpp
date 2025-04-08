// 1202 - 보석 도둑
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<long long, long long> Jewel; // <무게, 가격>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K; 
    cin >> N >> K;

    vector<Jewel> jewels;
    for (int i = 0; i < N; i++){
        long long weight, price;
        cin >> weight >> price;
        jewels.push_back({weight, price});
    }

    sort(jewels.begin(), jewels.end(), [](const Jewel &a, const Jewel &b) {
        return a.first < b.first;
    });
    
    vector<long long> bags(K);
    for (int i = 0; i < K; i++){
        cin >> bags[i];
    }
    sort(bags.begin(), bags.end());
    
    long long answer = 0;
    int index = 0;
    priority_queue<long long> pq;
    
    for (int i = 0; i < K; i++){
        while (index < N && jewels[index].first <= bags[i]) {
            pq.push(jewels[index].second);
            index++;
        }
        
        if (!pq.empty()){
            answer += pq.top(); // 가격이 가장 높은 보석을 선택
            pq.pop();
        }
    }
    
    cout << answer << "\n";
    return 0;
}
