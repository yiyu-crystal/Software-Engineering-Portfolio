#include "DynamicArray.h" // 包含头文件
#include <iostream>
#include <string>

// 显式实例化模板 (如果环境需要)
template class DynamicArray<int>;

int main() {
    // 1. 创建 DynamicArray (初始容量 10)
    DynamicArray<int> arr; 

    std::cout << "--- Testing Push and Resize ---" << std::endl;
    
    // 2. 循环添加元素，触发 resizeAndCopy
    for (int i = 0; i < 15; ++i) {
        arr.push_back(i * 10);
        // 观察输出，当 i=10 时，resizeAndCopy 应该被调用
    }

    // 3. 检查最终状态
    std::cout << "--- Final Status ---" << std::endl;
    std::cout << "Elements added: " << arr.size() << std::endl;
    // 实际 capacity 应该在 10 -> 20 之间 (取决于您的 .h 文件中是否暴露了capacity)
    // 假设我们在 .h 文件中添加了 int get_capacity() const;

    // 4. 检查数据准确性 (例如，检查第0个和第14个元素)
    std::cout << "Element at index 0: " << arr.get(0) << std::endl; // 应该输出 0
    std::cout << "Element at index 14: " << arr.get(14) << std::endl; // 应该输出 140

    // 5. 程序结束时，析构函数自动调用，释放内存。

    return 0;
}
