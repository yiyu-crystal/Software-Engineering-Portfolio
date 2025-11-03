#include "DynamicArray.h" // 包含头文件
#include <iostream>

// 为了简化，这里再次定义模板（T），实际中可能在头文件完成，但此处为实现方便
template <typename T>
// 1. 构造函数：初始化内存
DynamicArray<T>::DynamicArray() {
    capacity = 10;          // 设置初始容量
    currentSize = 0;        // 初始元素数量为0
    data = new T[capacity]; // 手动分配内存
    std::cout << "DynamicArray created with capacity: " << capacity << std::endl;
}

template <typename T>
// 2. 析构函数：释放内存 (至关重要!)
DynamicArray<T>::~DynamicArray() {
    delete[] data;          // 手动释放内存，防止内存泄漏
    data = nullptr;         // 将指针置空，避免野指针
    std::cout << "DynamicArray destroyed, memory released." << std::endl;
}

template <typename T>
// 3. 内存扩容函数：双倍扩容并复制数据
void DynamicArray<T>::resizeAndCopy() {
    int newCapacity = capacity * 2;
    T* newData = new T[newCapacity]; // 分配新的更大的内存块

    // 复制旧数据到新内存
    for (int i = 0; i < currentSize; ++i) {
        newData[i] = data[i];
    }

    delete[] data;          // 释放旧内存
    data = newData;         // 指向新内存
    capacity = newCapacity; // 更新容量
    std::cout << "Array resized to capacity: " << capacity << std::endl;
}

template <typename T>
// 4. 添加元素函数：核心逻辑
void DynamicArray<T>::push_back(const T& element) {
    // 检查是否需要扩容
    if (currentSize == capacity) {
        resizeAndCopy(); 
    }
    
    // 放入新元素并更新大小
    data[currentSize] = element;
    currentSize++;
}

// 额外的辅助函数（方便测试）
template <typename T>
T DynamicArray<T>::get(int index) const {
    // 实际项目中应加入边界检查
    if (index >= 0 && index < currentSize) {
        return data[index];
    }
    // 简化处理，实际中会抛出异常
    return T(); 
}
