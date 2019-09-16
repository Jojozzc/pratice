#include <iostream>
#include <vector>
#include <string>
using namespace std;




string hosts[] = {"host0", "host1", "host2", "host3", "host4"};
int HOST_NUM = 5;

int hashCode(int id) {
    // 计算id的hash值示意
    return id;
}

string dispatch(int requestId) {
    return hosts[hashCode(requestId) % HOST_NUM];
}

int main(){
    // 哈希策略负载均衡
    int requestId = 0;
    cin >> requestId;
    cout << "分发到主机:" << dispatch(requestId) << endl;
}