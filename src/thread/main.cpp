#include <iostream>
#include <map>
#include <thread>
#include <vector>

std::map<int, int> sharedMap;

void readMap(int threadId) {
    for (int i = 0; i < 50000; ++i) { // 减少循环次数以更快触发异常
        if (sharedMap.find(0) != sharedMap.end()) {
            int value = sharedMap.at(0); // 只读访问
        }
        if (i % 500 == 0) { // 减少输出间隔
            std::cout << "Reader thread " << threadId << " i===== " << i << std::endl;
        }
    }
}

void writeMap() {
    for (int i = 0; i < 50000; ++i) { // 减少循环次数以更快触发异常
        sharedMap[0] = i; // 写入操作
        sharedMap[1] = i * 2; // 增加写入操作
        if (i % 500 == 0) { // 减少输出间隔
            std::cout << "Writer thread updated value to " << i << std::endl;
        }
    }
}

void mixedAccess(int threadId) {
    for (int i = 0; i < 50000; ++i) {
        if (i % 3 == 0) {
            sharedMap[0] = i; // 写操作
        } else if (i % 3 == 1) {
            if (sharedMap.find(0) != sharedMap.end()) {
                int value = sharedMap.at(0); // 读操作
            }
        } else {
            sharedMap.erase(0); // 删除操作，增加冲突概率
        }
        if (i % 500 == 0) {
            std::cout << "Mixed thread " << threadId << " i===== " << i << std::endl;
        }
    }
}

int main() {
    // 不初始化 sharedMap，增加访问空容器的风险

    // 创建更多线程进行读写
    std::thread writer1(writeMap);
    std::thread writer2(writeMap); // 增加一个写线程
    std::thread t1(readMap, 1);
    std::thread t2(readMap, 2);
    std::thread t3(mixedAccess, 3); // 混合读写线程
    std::thread t4(mixedAccess, 4); // 混合读写线程
    std::thread t5(mixedAccess, 5); // 再增加一个混合线程

    // Join the threads
    writer1.join();
    writer2.join();
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}